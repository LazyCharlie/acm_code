#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct edge {
	int x, w;
}e[N * 2];

int head[N], nxt[N * 2], cnt;
//建立从u到v的单向边，边权为w
void add_edge(int u, int v, int w) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	e[cnt] = { v,w };
}
int main()
[
	for(int i=1;i<=n;i++)head[i]=-1;
	//以点u为起始点的有向边的遍历
	for(int i=head[u];~i;i=nxt[i]){
		edge p=e[i];	
	}
}