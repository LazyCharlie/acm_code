#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int c[maxn * 2], p[maxn * 2], n, m, i;//c[i]=1表示水平，2表示竖直
char s[10];
vector<int>ans;
int vis[maxn], cnt;
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
void init()
{
	for (int i = 0; i < maxn * 2; i++)p[i] = i;
}
void NO()
{
	printf("inconsistent\n");
	exit(0);
}
void par(int x, int y)
{
	int fx = find(x);
	int frx = find(x + n);
	int fy = find(y);
	int fry = find(y + n);
	if (fx == fy)return;//no need update
	if (fx == fry || fy == frx)NO();//inconsistent
	cnt++;
	vis[i] = 1;
	p[fx] = fy;
	p[frx] = fry;
	if (c[fy] == 0) {
		c[fy] = c[fx];
		c[fry] = c[frx];
	}
}
void perp(int x, int y)
{
	int fx = find(x);
	int frx = find(x + n);
	int fy = find(y);
	int fry = find(y + n);
	if (fx == fry)return;//no need update
	if (fx == fy || frx == fry)NO();//inconsistent
	cnt++;
	vis[i] = 1;
	p[fx] = fry;
	p[frx] = fy;
	if (c[fy] == 0) {
		c[fy] = c[frx];
		c[fry] = c[fx];
	}
}
int main()
{
	init();
	scanf("%d%d", &n, &m);
	c[n + 1] = 1;
	c[n * 2 + 2] = 2;
	n++;
	for (i = 1; i <= m; i++) {
		scanf("%s", s);
		int x, y;
		scanf("%d", &x);
		if (s[0] == 'p')scanf("%d", &y);
		if (s[0] == 'v')par(x, n);
		else if (s[0] == 'h')perp(x, n);
		else if (s[1] == 'a')par(x, y);
		else perp(x, y);
	}
	printf("consistent\n%d\n", m - cnt);
	for (int i = 1; i <= m; i++) {
		if (!vis[i])ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
	}
}