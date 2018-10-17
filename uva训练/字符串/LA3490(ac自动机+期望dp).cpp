#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int f[maxn], n, m, T, kase;
char s[maxn];
const int MAXNODE = 110000;
const int MAXS = 1500 + 10;
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
AhoCorasickAutomata ac;
long long dp[maxn];
int main()
{
	scanf("%d", &T);
	while (T--) {
		ac.init();
		scanf("%d%s", &m, &s);
		ac.insert(s, 1);
		ac.getFail();
		n = ac.sz;
		for (int i = 1; i < ac.sz; i++) {
			dp[i] = dp[i - 1] + m;
			for (int j = 0; j < m; j++) {
				int u = ac.ch[i - 1][j];//节点i收到j字母后转移到u节点
				if (u <= i - 1)dp[i] += dp[i - 1] - dp[u];
			}
		}
		printf("Case %d:\n%lld\n", ++kase, dp[n - 1]);
		if (T)printf("\n");
	}
}