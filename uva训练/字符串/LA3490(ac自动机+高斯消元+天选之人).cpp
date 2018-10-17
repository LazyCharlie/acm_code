#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int f[maxn], n, m, T, kase;
char s[maxn];
const int MAXNODE = 11000;
const int MAXS = 150 + 10;
const int maxm = 28;

struct AhoCorasickAutomata {
	int ch[MAXNODE][maxm];
	int f[MAXNODE];    // fail函数
	int val[MAXNODE];  // 每个字符串的结尾结点都有一个非0的val
	int last[MAXNODE]; // 输出链表的下一个结点
	int cnt[MAXS];
	int sz;

	void init() {
		sz = 1;
		memset(ch[0], 0, sizeof(ch[0]));
		memset(cnt, 0, sizeof(cnt));
	}

	// 字符c的编号
	int idx(char c) {
		return c - 'A';
	}

	// 插入字符串。v必须非0
	void insert(char *s, int v) {
		int u = 0, n = strlen(s);
		for (int i = 0; i < n; i++) {
			int c = idx(s[i]);
			if (!ch[u][c]) {
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
	}

	// 递归打印以结点j结尾的所有字符串
	void print(int j) {
		if (j) {
			cnt[val[j]]++;
			print(last[j]);
		}
	}

	// 在T中找模板
	int find(char* T) {
		int n = strlen(T);
		int j = 0; // 当前结点编号，初始为根结点
		for (int i = 0; i < n; i++) { // 文本串当前指针
			int c = idx(T[i]);
			j = ch[j][c];
			if (val[j]) print(j);
			else if (last[j]) print(last[j]); // 找到了！
		}
	}

	// 计算fail函数
	void getFail() {
		queue<int> q;
		f[0] = 0;
		// 初始化队列
		for (int c = 0; c < m; c++) {
			int u = ch[0][c];
			if (u) { f[u] = 0; q.push(u); last[u] = 0; }
		}
		// 按BFS顺序计算fail
		while (!q.empty()) {
			int r = q.front(); q.pop();
			for (int c = 0; c < m; c++) {
				int u = ch[r][c];
				if (!u) {
					ch[r][c] = ch[f[r]][c];
					continue;
				}
				q.push(u);
				f[u] = ch[f[r]][c];
				last[u] = val[f[u]] ? f[u] : last[f[u]];
			}
		}
	}

};
const double eps = 1e-8;
AhoCorasickAutomata ac;
typedef long long Matrix[maxn][maxn];
Matrix a;
void gauss_jordan(Matrix A, int n, double&ans)
{
	int i, j, k, r;
	for (i = 0; i < n; i++) {
		r = i;
		for (j = i + 1; j < n; j++)
			if (fabs(A[j][i])>fabs(A[r][i]))r = j;
		if (abs(A[r][i]) < eps)continue;//放弃这一行，直接处理下一行
		if (r != i)for (j = 0; j <= n; j++)swap(A[r][j], A[i][j]);

		//与除了第i行以外的行进行消元
		for (k = 0; k < n; k++)if (k != i)
			for (j = n; j >= i; j--)A[k][j] -= A[k][i] / A[i][i] * A[i][j];
	}
	ans = A[0][n] / A[0][0];
}

void gauss(Matrix A, int n)
{
	int i, j, k, r;
	for (i = 0; i < n; i++)
	{
		for (j = n; j >= i; j--)
			for (k = i + 1; k < n; k++)
				A[k][j] -= A[k][i] / A[i][i] * A[i][j];
	}
	for (i = n - 1; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
			A[i][n] -= A[j][n] * A[i][j];
		A[i][n] /= A[i][i];
	}
}


int in[maxn], out[maxn];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		ac.init();
		scanf("%d%s", &m, &s);
		ac.insert(s, 1);
		ac.getFail();
		n = ac.sz - 1;
		memset(a, 0, sizeof(a));
		for (int i = 0; i <= n; i++) {
			a[i][i] = a[i][n + 2] = -m;
		}
		a[n + 1][n + 1] = 1;
		for (int i = 0; i < ac.sz - 1; i++) {
			for (int j = 0; j < m; j++) {
				int u = ac.ch[i][j];//节点i收到j字母后转移到u节点
				a[i + 1][u + 1]++;
			}
		}
		a[0][2]++;
		a[0][1] += m - 1;
		n += 2;
		double ans = 0;
		gauss(a, n);
		printf("Case %d:\n%lld\n", ++kase, a[0][n]);
		if (T)printf("\n");
	}
}
