#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int maxc = 1e5 + 5;
int vis[maxn], ans[maxc];
int sum[maxn], kase, n;
void seive(int x)
{
	for (int i = 1; i <= maxc; i++)ans[i] = -1;
	for (int i = 1; i <= x; i++) {
		for (int j = i; j <= x; j+=i) {
			sum[j] += i;
		}
	}
	for (int i = 1; i <= x; i++) {
		ans[sum[i]] = max(ans[sum[i]], i);
	}
}
int main()
{
	seive(1000);
	while (scanf("%d", &n) == 1 && n) {
		printf("Case %d: %d\n", ++kase, ans[n]);
	}
}