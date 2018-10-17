#include<bits/stdc++.h>
using namespace std;
int n, m, q;
int w[16], k;
char s[500006][15], tmp[15];
int cnt[1 << 12 | 20];
int ans[1 << 12 | 20][125];
void init()
{
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
		int tot = 0;
			for (int k = 0; k < n; k++) {
				if (((i >> (n-k-1)) & 1) == ((j >> (n - k - 1)) & 1))tot += w[k];
			}
			if (tot <= 100)ans[i][tot] += cnt[j];
		}
		for (int j = 1; j <= 100; j++) {
			ans[i][j] += ans[i][j - 1];
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)scanf("%d", &w[i]);
	for (int i = 0; i < m; i++) {
		scanf("%s", s[i]);
		int tot = 0;
		for (int j = 0; j < n; j++) {
			tot = tot * 2 + (s[i][j] - '0');
		}
		cnt[tot]++;
	}
	init();
	int k;
	for (int i = 0; i < q; i++) {
		scanf("%s%d", tmp, &k);
		int tot = 0;
		for (int j = 0; j < n; j++) {
			tot = tot * 2 + (tmp[j] - '0');
		}
		printf("%d\n", ans[tot][min(100,k)]);
	}
}