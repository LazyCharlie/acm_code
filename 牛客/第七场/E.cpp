#include<bits/stdc++.h>
using namespace std;
int k, n;
long long C[100], D[100];
int G[100][100];
void init()
{
	for (int i = 3; i <= 75; i++) {
		C[i] = i * (i - 1LL)*(i - 2LL) / 6;
		if (i >= 4)D[i] = i * (i - 1LL)*(i - 2LL)*(i - 3LL) / 24;
	}
}
bool dfs(int cur, int p)
{
	if (p + n == 75 || cur == 0) {
		if (cur == 0)return true;
		return false;
	}
	for (int i = 0; i <= n; i++) {
		if (C[i] > cur)break;
		if (dfs(cur - C[i], p + 1)) {
			for (int j = 1; j <= i; j++) {
				G[j][p + n + 1] = G[p + n + 1][j] = 1;
			}
			return true;
		}
	}
	return false;
}
int main()
{
	init();
	scanf("%d", &k);
	n = 4;
	for (int i = 4; i <= 70; i++) {
		if (D[i] <= k)n = i;
	}
	k -= D[n];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			G[i][j] = G[j][i] = 1;
		}
	}
	if (dfs(k, 0)) {
		int cnt = 0;
		for (int i = 1; i <= 75; i++) {
			for (int j = i + 1; j <= 75; j++) {
				cnt += G[i][j];
			}
		}
		printf("75 %d\n", cnt);
		for (int i = 1; i <= 75; i++) {
			for (int j = i + 1; j <= 75; j++) {
				if (G[i][j]) {
					printf("%d %d\n", i, j);
				}
			}
		}
	}
}