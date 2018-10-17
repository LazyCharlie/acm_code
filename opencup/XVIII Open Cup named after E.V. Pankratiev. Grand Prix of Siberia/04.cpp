//对于整个决策，所有点要么向左连边，要么向下连边
//那么整个图就是带基座的连边问题
#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const int INF = 0x3f3f3f3f;
struct node {
	int x, y;
}p[maxn];
struct res {
	int x1, y1;
	int x2, y2;
	res(){}
	res(int x, int y, int a, int b)
	{
		if (x < a)swap(x, a), swap(y, b);
		if (y < b)swap(x, a), swap(y, b);
		x1 = x;
		y1 = y;
		x2 = a;
		y2 = b;
	}
};
vector<res>ans;
int vis[maxn][maxn], n;
int d[maxn][maxn], s[maxn][maxn];//d[i][j]表示i向下连，j向左连的最少花费
void dp(int l, int r)
{
	if (l + 1 >= r)return;
	if (vis[l][r])return;
	vis[l][r] = 1;
	d[l][r] = INF;
	for (int i = l; i < r; i++) {
		dp(l, i);
		dp(i + 1, r);
		if (d[l][i] + d[i + 1][r] + (p[i].x - p[l].x) + (p[i + 1].y - p[r].y) < d[l][r]) {
			d[l][r] = d[l][i] + d[i + 1][r] + (p[i].x - p[l].x) + (p[i + 1].y - p[r].y);
			s[l][r] = i;
		}
	}
}
void dfs(int l, int r)
{
	if (l + 1 >= r)return;
	int mid = s[l][r];
	if (p[l].x < p[mid].x)ans.push_back(res(p[l].x, p[mid].y, p[mid].x, p[mid].y));
	if (p[mid + 1].y > p[r].y)ans.push_back(res(p[mid + 1].x, p[mid + 1].y, p[mid + 1].x, p[r].y));
	dfs(l, mid);
	dfs(mid + 1, r);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d%d", &p[i].x, &p[i].y);
	dp(1, n);
	d[1][n] += p[1].y + p[n].x;
	if (p[1].x > 0)ans.push_back(res(0, 0, p[1].x, 0));
	if (p[n].y > 0)ans.push_back(res(p[1].x, 0, p[1].x, p[n].y));
	if (p[1].y > p[n].y)ans.push_back(res(p[1].x, p[n].y, p[1].x, p[1].y));
	if (p[n].x > p[1].x)ans.push_back(res(p[1].x, p[n].y, p[n].x, p[n].y));
	dfs(1, n);
	printf("%d %d\n", ans.size(), d[1][n]);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d %d %d\n", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2);
	}
}