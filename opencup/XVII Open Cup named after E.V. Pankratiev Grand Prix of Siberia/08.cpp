#include<bits/stdc++.h>
using namespace std;
int n, k;
const int maxn = 1e6 + 10;
long long a[maxn + 10], len[maxn + 10];
int x, y, c;
int L[maxn], R[maxn];
vector<int>g[maxn];
long long tr[maxn << 2 | 50];
int cnt;
void dfs(int x)
{
	L[x] = ++cnt;
	for (int i = 0; i < g[x].size(); i++) {
		int u = g[x][i];
		dfs(u);
	}
	R[x] = ++cnt;
}
void update(int x, int L, int R, int pos, long long v)
{
	if (L == R && L == pos) {
		tr[x] = v;
		return;
	}
	int mid = L + R >> 1;
	if (pos <= mid)update(x << 1, L, mid, pos, v);
	else update(x << 1 | 1, mid + 1, R, pos, v);
	tr[x] = tr[x << 1] + tr[x << 1 | 1];
}
long long query(int x, int L, int R, int ls, int rs)
{
	if (L == ls && R == rs) {
		return tr[x];
	}
	int mid = L + R >> 1;
	if (rs <= mid)return query(x << 1, L, mid, ls, rs);
	else if (ls > mid)return query(x << 1 | 1, mid + 1, R, ls, rs);
	else return query(x << 1, L, mid, ls, mid) + query(x << 1 | 1, mid + 1, R, mid + 1, rs);
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n + 1; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &len[i]);
		scanf("%d%d", &x, &y);
		if (x > 0)g[i].push_back(x);
		else g[i].push_back(-x + n);
		if (y > 0)g[i].push_back(y);
		else g[i].push_back(-y + n);
	}
	dfs(1);
	for (int i = 1; i <= n + 1; i++) {
		update(1, 1, cnt, L[i + n], a[i]);
		update(1, 1, cnt, R[i + n], a[i]);
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &c);
		if (c == 1) {
			scanf("%d%d", &x, &y);
			update(1, 1, cnt, L[x + n], y);
			update(1, 1, cnt, R[x + n], y);
		}
		else {
			scanf("%d", &x);
			int a = g[x][0], b = g[x][1];
			long long SL = query(1, 1, cnt, L[a], R[a]) / 2;
			long long SR = query(1, 1, cnt, L[b], R[b]) / 2;
			long long L = len[x];
			printf("%.15lf\n", (SR*L + 0.0) / (SR + SL + 0.0));
		}
	}
}