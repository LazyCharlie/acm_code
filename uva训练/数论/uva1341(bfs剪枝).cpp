#include<bits/stdc++.h>
using namespace std;
//#define LOCAL
const int maxn = 1e7;
const int maxc = 65536 + 10;
int diff, len, n;
int a[5], vis[maxc];
struct node {
	int m, x, pre, cnt;
	node(int M = 0, int X = 0, int p = -1, int c = 1)
	{
		m = M;
		x = X;
		pre = p;
		cnt = c;
	}
};
struct que {
	node q[maxn];
	int f, t;
	node& operator[](const int &pos) { return q[pos]; }
	node& front() { return q[f]; }
	void clear() { f = t = 0; }
	void push(const node&rhs) { q[t++] = rhs; }
	void pop() { f++; }
	int id() {
		return f;
	}
	int size() { return f - t; }
}q;
string ans, tmp;
void dfs(int x, string &s)
{
	if (q[x].pre >= 0)dfs(q[x].pre, s);
	s += q[x].x + '0';
}
string getans(int x)
{
	string ret;
	dfs(x, ret);
	return ret;
}
void bfs()
{	
	for (int i = 0; i < n; i++)vis[i] = 0x3f3f3f3f;
	q.clear();
	for (int i = 1; i <= diff; i++) {
		if (a[i]) {
			q.push(node(a[i] % n, a[i], -1, 1));
			vis[a[i] % n] = 1;
		}
	}
	while (q.size()) {
		int x = q.id();
		node t = q.front(); q.pop();
		if (t.cnt > len)return;
		if (t.m == 0) {
			if (t.cnt < len) {
				ans = getans(x);
				len = t.cnt;
			}
			else if (t.cnt == len) {
				tmp = getans(x);
				if (ans > tmp)ans = tmp;
			}
		}

		for (int i = 1; i <= diff; i++) {
			node tx((t.m * 10 + a[i]) % n, a[i], x, t.cnt + 1);
			if (vis[tx.m] >= tx.cnt) {
				vis[tx.m] = tx.cnt;
				q.push(tx);
			}
		}
	}
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (scanf("%d", &n) == 1 && n) {
		diff = 1; len = 0x3f3f3f3f;
		ans.clear();
		for (int i = 1; i <= 9; i++) {
			a[1] = i;
			bfs();
		}
		if (ans.size()) {
			cout << ans << endl;
			continue;
		}
		diff = 2;
		for (int i = 0; i < 10; i++) {
			a[1] = i;
			for (int j = i + 1; j < 10; j++) {
				a[2] = j;
				bfs();
			}
		}
		cout << ans << endl;
	}
}