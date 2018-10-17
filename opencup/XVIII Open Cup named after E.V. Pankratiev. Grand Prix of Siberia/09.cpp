#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;
int vis[maxn];
vector<int>prime;
vector<int>p;
long long n, q;
void seive(int x)
{
	for (int i = 2; i <= x; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i > x)break;
			vis[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
long long fpow(long long a, long long m, long long mod)
{
	long long ret = 1;
	while (m) {
		if (m & 1)ret = ret * a%mod;
		a = a * a%mod;
		m >>= 1;
	}
	return ret;
}
vector<int>S;
int main()
{
	seive(1e7 + 0.5);
	scanf("%lld%lld", &q, &n);
	long long m = sqrt(n + 1);
	int tn = n;
	for (int i = 2; i <= m; i++) {
		if (tn%i == 0) {
			while (tn%i == 0)tn /= i;
			p.push_back(i);
		}
	}
	if (tn > 1)p.push_back(tn);
	for (int i = 0; i < prime.size(); i++) {
		long long res = fpow(q, n, prime[i]);
		if (res == 1) {
			int ok = 1;
			for (int j = 0; j < p.size(); j++) {
				if (fpow(q, n / p[j], prime[i]) == 1) {
					ok = 0;
					break;
				}
			}
			if (ok)S.push_back(prime[i]);
		}
	}
	printf("%d\n", S.size());
	for (int i = 0; i < S.size(); i++) {
		printf("%d%c", S[i], i + 1 == S.size() ? '\n' : ' ');
	}
}