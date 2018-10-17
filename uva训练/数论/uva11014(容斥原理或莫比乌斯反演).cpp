#include<bits/stdc++.h>
using namespace std;
const int maxn = 200006;
int n, kase;
int vis[maxn];
vector<int>prime;
long long f[maxn];
long long p3(long long a)
{
	return a * a*a;
}
void seive(int n)
{
	vis[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i])prime.push_back(i), vis[i] = i;
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i > n)break;
			vis[prime[j] * i] = prime[j];
			if (i%prime[j] == 0)break;
		}
	}
}
int find(int n)
{
	int cnt = 0;
	while (n > 1) {
		int k = vis[n];
		n /= k;
		cnt++;
		if (vis[n] == k)return 0;
	}
	return (cnt & 1) ? -1 : 1;
}
int main()
{
	seive(100000);
	while (scanf("%d", &n) == 1 && n) {
		long long tot = (n + 1)*(n + 1)*(n / 2 + 1) - 1;
		for (int i = 1; i <= n / 2; i++) {
			f[i] = p3(n / 2 / i * 2 + 1) - 1;
		}
		long long ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			ans += find(i)*f[i];
		}
		printf("Crystal %d: %lld\n",++kase, ans);
	}
}