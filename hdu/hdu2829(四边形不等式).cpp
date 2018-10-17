#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, m;
long long a[maxn], d[maxn][maxn];//d[i][j]表示把1~j炸i次能取到的最小值  d[i][j]=min{d[i-1][k-1]+w[k][j]}  //i+1<=j   i+1<=k<=j
long long w[maxn][maxn];//w[i][j]表示完整的i~j段获得的贡献
long long sum[maxn];
int s[maxn][maxn];
int main()
{
	while (scanf("%d%d", &n, &m) == 2 && n) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++) {
			w[i][i] = 0;
			s[0][i] = 1;
			for (int j = i + 1; j <= n; j++) {
				w[i][j] = w[i][j - 1] + (sum[j - 1] - sum[i - 1])*a[j];
			}
		}
		for (int i = 1; i <= n; i++)d[0][i] = w[1][i];
		for (int i = 1; i <= m; i++) {
			s[i][n + 1] = n;
			for (int j = n; j >= i + 1; j--) {
				d[i][j] = 1LL << 60;
				for (int k = max(i + 1, s[i - 1][j]); k <= min(j, s[i][j + 1]); k++) {
					if (d[i - 1][k - 1] + w[k][j] < d[i][j]) {
						s[i][j] = k;
						d[i][j] = d[i - 1][k - 1] + w[k][j];
					}
				}
			}
		}
		printf("%lld\n", d[m][n]);
	}
}