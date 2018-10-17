#include<bits/stdc++.h>
using namespace std;
int T, N, M;
const int maxn = 10000 + 10;
long long a[maxn], d[2][maxn];
int s[2][maxn], kase;
long long w(int i, int j)
{
	return (a[j] - a[i])*(a[j] - a[i]);
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a + 1, a + N + 1);
		int c = 0;
		for (int i = 1; i <= N; i++)d[c][i] = w(1,i), s[c][i] = 1;
		for (int i = 2; i <= M; i++) {
			s[c^1][N + 1] = N;
			for (int j = N; j >= i; j--) {
				d[c^1][j] = LLONG_MAX;
				for (int k = max(i, s[c][j]); k <= min(s[c^1][j + 1], j); k++) {
					if (d[c][k - 1] + w(k,j) < d[c^1][j]) {
						s[c^1][j] = k;
						d[c^1][j] = d[c][k - 1] + w(k, j);
					}
				}
			}
			c ^= 1;
		}
		printf("Case %d: %lld\n", ++kase, d[c][N]);
	}
}