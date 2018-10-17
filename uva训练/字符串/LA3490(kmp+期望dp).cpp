#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int f[maxn], n, m, T, kase;
char t[maxn], ch;
void getFail(const char *T, int *f)//KMP失配函数
{
	f[0] = f[1] = 0;
	m = strlen(T);
	for (int i = 1; i < m; i++)
	{
		int j = f[i];
		while (j&&T[i] != T[j])j = f[j];
		f[i + 1] = (T[i] == T[j]) ? j + 1 : 0;
	}
}
long long dp[maxn];
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, &t);
		getFail(t, f);
		for (int i = 1; i <= m; i++) {
			dp[i] = dp[i - 1] + n;
			for (int j = 0; j < n; j++) {
				ch = 'A' + j;
				int u = i - 1;
				while (u&&ch != t[u])u = f[u];
				if (ch == t[u])u++;
				if (u <= i - 1)dp[i] += dp[i - 1] - dp[u];
			}
		}
		printf("Case %d:\n%lld\n", ++kase, dp[m]);
		if (T)printf("\n");
	}
}