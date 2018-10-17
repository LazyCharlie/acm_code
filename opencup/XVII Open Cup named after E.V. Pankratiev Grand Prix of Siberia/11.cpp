#include <bits/stdc++.h>
#include <ext/hash_map>
using namespace __gnu_cxx;
using namespace std;
int n, T, P;
long long x;
long long p[100050];
long long a[100050], ans1[100050];
pair<int, int>ans2[100050];
int q[100050];
char s[100050];
long long X = 0;
hash_map<int, pair<int,int>>M;
long long fpow(long long a, long long m, long long mod)
{
	long long ret = 1;
	while (m) {
		if (m & 1)ret = ret * a % mod;
		a = a * a % mod;
		m >>= 1;
	}
	return ret;
}
int main()
{
	gets(s);
	n = strlen(s);
	scanf("%d%d", &T, &P);
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (p[i - 1] * 10) % P;
	}
	for (int i = n - 1; i >= 0; i--) {
		a[i] = ((s[i] - '0')*p[n - i - 1] + a[i + 1]) % P;
	}
	for (int i = 0; i < T; i++)scanf("%d", &q[i]);
	long long d, ans = 0;
	int L = 0, R = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < T; j++)
		{
			pair<int, int> k = { 0, 0 };
			d = (a[i] + q[j] * p[n - i]) % P;
			if (M.count(d))k = M[d];
			ans1[j] += k.first;
			if (k.first)
			{
				ans2[j].first = k.second;
				ans2[j].second = i;
			}
		}
		M[a[i]].first++;
		M[a[i]].second = i + 1;
	}
	for (int i = 0; i < T; i++) {
		printf("%lld %d %d\n", ans1[i], ans2[i].first, ans2[i].second);
	}
}