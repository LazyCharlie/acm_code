#include<bits/stdc++.h>
using namespace std;
int n, m;
char s[1006];
int G[1006][1006];
int L[1006][1006], U[1006][1006];
int p[60];
int need[60];
int id(char ch)
{
	if (islower(ch))return ch - 'a';
	return ch - 'A' + 26;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) {
			G[i][j] = id(s[j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(p, 0, sizeof(p));
		for (int j = 1; j <= m; j++) {
			L[i][j] = L[i][j - 1] + 1;
			int v = G[i][j];
			L[i][j] = min(L[i][j], j - p[v]);
			p[v] = j;
		}
	}
	for (int j = 1; j <= m; j++) {
		memset(p, 0, sizeof(p));
		for (int i = 1; i <= n; i++) {
			U[i][j] = U[i - 1][j] + 1;
			int v = G[i][j];
			U[i][j] = min(U[i][j], i - p[v]);
			p[v] = i;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k <= 52; k++)need[k] = 52;
			for (int d = 0; d < 52 && d < i; d++) {
				for (int k = L[i - d][j] + 1; k <= 52 && need[52 - k] > d; k++) {
					need[52 - k] = d;
				}
			}
			for (int k = min(52, j); k >= 1; k--) {
				need[52 - k] = min(U[i][j - k + 1], need[52 - k]);
			}
			int h = 0x3f3f3f3f;
			int inc = 0;
			for (int k = 1; k <= 52; k++) {
				h = min(h, need[52 - k]);
				ans += h;
			}
		}
	}
	printf("%lld\n", ans);
}