#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Tree_chain_dissection {//树链剖分
	struct edge {
		int x, w;
	}e[N * 2];
	int head[N], cnt;
	int nxt[N * 2];
	int dep[N], fa[N], sz[N], top[N], rk[N], id[N], son[N], tot;
	void init(int n = 100000)
	{
		for (int i = 1; i <= n; i++)head[i] = -1;
		cnt = 0;
	}
	void add_edge(int u, int v, int w = 0)//u->v;
	{
		nxt[++cnt] = head[u];
		head[u] = cnt;
		e[cnt] = { v,w };
	}
	void dfs1(int x)
	{
		son[x] = 0; sz[x] = 1;
		for (int i = head[x]; ~i; i = nxt[i]) {
			edge u = e[i];
			if (fa[x] != u.x) {
				fa[u.x] = x;
				dep[u.x] = dep[x] + 1;
				dfs1(u.x);
				sz[x] += sz[u.x];
				if (sz[u.x] > sz[son[x]])son[x] = u.x;//重儿子
			}
		}
	}
	void dfs2(int x, int tp)
	{
		top[x] = tp; id[x] = ++tot; rk[tot] = x;
		if (son[x])dfs2(son[x], tp);
		for (int i = head[x]; ~i; i = nxt[i]) {
			edge u = e[i];
			if (u.x == fa[x] || u.x == son[x])continue;
			dfs2(u.x, u.x);
		}
	}
	void prework(int root = 1)
	{
		fa[root] = root; dep[root] = 1;
		dfs1(root); dfs2(root, root);
	}
	int LCA(int u, int v)
	{
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]])swap(u, v);
			u = fa[top[u]];
		}
		return dep[u] > dep[v] ? v : u;
	}
}tcd;
int T, n, u, v;
int in[N];
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		tcd.init(n);
		for (int i = 1; i <= n; i++)in[i] = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			tcd.add_edge(u, v);
			in[v]++;
		}
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				tcd.prework(i);//以i节点为根节点进行预处理
				break;
			}
		}
		scanf("%d%d", &u, &v);
		printf("%d\n", tcd.LCA(u, v));
	}
}