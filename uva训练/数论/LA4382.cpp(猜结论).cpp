#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
int vis[maxn], T, n;
vector<int>prime, p;
int ans[maxn];
void seive(int n)
{
	vis[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			prime.push_back(i);
			if (i >= 10 && i % 3 == 1) {
				ans[(i - 7) / 3] = 1;
			}
		}
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i > n)break;
			vis[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
void init()
{
	seive(3000007);
	for (int i = 1; i <= 1000000; i++)ans[i] += ans[i - 1];
}
int main()
{
	init();
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
}