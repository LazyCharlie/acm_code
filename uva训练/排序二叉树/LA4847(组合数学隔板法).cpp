#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
const long long mod = 9999991;
int T, n, cnt = 0;
int a[maxn], node[maxn];
int L[maxn], R[maxn];
long long C[105][105], ans[200], num[200];
void init()
{
	C[0][0] = 1;
	for (int i = 1; i <= 100; i++) {
		C[i][i] = C[i][0] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
}
void insert(int x, int v)
{
	if (!cnt) {
		++cnt;
		a[cnt] = v;
		return;
	}
	if (v > a[x]) {
		if (R[x] == 0) {
			R[x] = ++cnt;
			a[cnt] = v;
		}
		else insert(R[x], v);
	}
	else {
		if (L[x] == 0) {
			L[x] = ++cnt;
			a[cnt] = v;
		}
		else insert(L[x], v);
	}
}
void dfs(int x)
{
	if (L[x] == 0 && R[x] == 0) {
		ans[x] = num[x] = 1;
		return;
	}
	int l = 0, lans = 1, rans = 1, r = 0;
	if (L[x])dfs(L[x]), l = num[L[x]], lans = ans[L[x]];
	if (R[x])dfs(R[x]), r = num[R[x]], rans = ans[R[x]];
	num[x] = l + r + 1;
	ans[x] = (C[l + r][r] * lans%mod)*rans%mod;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1; i <= 24; i++)L[i] = R[i] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			insert(1, a[i]);
		}
		dfs(1);
		printf("%lld\n", ans[1]);
	}
}