#include<bits/stdc++.h>
using namespace std;

const int SIGMA_SIZE = 26;
const int MAXNODE = 110;
const int MAXS = 150 + 10;
int kase, n, m;
char word[30];

//map<string, int> ms;
struct AhoCorasickAutomata {
	int ch[MAXNODE][SIGMA_SIZE];
	int f[MAXNODE];    // fail函数
	int val[MAXNODE];  // 每个字符串的结尾结点都有一个非0的val
	int last[MAXNODE]; // 输出链表的下一个结点
	int cnt[MAXS];
	long long d[26][MAXNODE][1 << 11];
	int vis[26][MAXNODE][1 << 11];
	int sz;

	void init() {
		sz = 1;
		memset(ch[0], 0, sizeof(ch[0]));
		memset(cnt, 0, sizeof(cnt));
		//ms.clear();
	}

	// 字符c的编号
	int idx(char c) {
		return c - 'a';
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
		//ms[string(s)] = v;
	}

	// 递归打印以结点j结尾的所有字符串
	void print(int j) {
		if (j) {
			cnt[val[j]]++;
			print(last[j]);
		}
	}

	// 在T中找模板
	void print(int c, int x, int s) {
		long long &ans = d[c][x][s];
		if (!ans)return;
		if (c == n) {
			if (s == (1 << m) - 1) {
				word[c] = 0;
				printf("%s\n", word);
			}
			return;
		}
		for (int i = 0; i < 26; i++) {
			word[c] = 'a' + i;
			int nc = ch[x][i];
			print(c + 1, nc, s | val[nc]);
		}
	}


	long long dp(int c, int x, int s)
	{
		long long &ans = d[c][x][s];
		if (vis[c][x][s] == kase)return ans;
		vis[c][x][s] = kase, ans = 0;
		if (c == n) {
			if (s == (1 << m) - 1)return ans = 1;
			return ans = 0;
		}
		for (int i = 0; i < SIGMA_SIZE; i++) {
			int nc = ch[x][i];
			ans += dp(c + 1, nc, s | val[nc]);
		}
		return ans;
	}
	// 计算fail函数
	void getFail() {
		queue<int> q;
		f[0] = 0;
		// 初始化队列
		for (int c = 0; c < SIGMA_SIZE; c++) {
			int u = ch[0][c];
			if (u) { f[u] = 0; q.push(u); last[u] = 0; }
		}
		// 按BFS顺序计算fail
		while (!q.empty()) {
			int r = q.front(); q.pop();
			val[r] |= val[last[r]];
			for (int c = 0; c < SIGMA_SIZE; c++) {
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
char txt[15][15];
int st[15];
int main()
{
	while (scanf("%d%d", &n, &m) == 2 && n) {
		++kase;
		ac.init();
		for (int i = 0; i < m; i++) {
			scanf("%s", txt[i]);
			st[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (!strcmp(txt[i], txt[j]))st[i] |= 1 << j;
			}
		}
		for (int i = 0; i < m; i++) {
			ac.insert(txt[i], st[i]);
		}
		ac.getFail();
		long long ans = ac.dp(0, 0, 0);
		printf("Case %d: %lld suspects\n", kase, ans);
		if (ans <= 42) ac.print(0, 0, 0);
	}
}