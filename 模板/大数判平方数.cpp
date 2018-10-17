#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 4;
long long prime[20];
int n;
char s[maxn];
bool is_prime(long long x)
{
	long long m = sqrt(x + 0.5);
	for (int i = 2; i <= m; i++) {
		if (x%i == 0)return false;
	}
	return true;
}
void init()
{
	int cnt = 0;
	for (long long i = 1e9;; i++) {
		if (is_prime(i))prime[cnt] = i, cnt++;
		if (cnt >= 20)break;
	}
}
long long fpow(long long a, long long m, long long mod)
{
	long long ret = 1;
	while (m) {
		if (m & 1)ret = ret * a%mod;
		m >>= 1;
		a = a * a%mod;
	}
	return ret;
}
long long mod(long long x)
{
	long long r = 0;
	for (int i = 0; i < n; i++) {
		r = r * 10 + (s[i] - '0');
		r %= x;
	}
	return r;
}
bool is_quadratic_residue(long long a, long long p)
{
	if (a == 0 || a == 1)return true;
	if (fpow(a, p >> 1, p) != 1)return false;
	return true;
}
bool check()
{
	for (int i = 0; i < 20; i++) {
		long long r = mod(prime[i]);
		if (!is_quadratic_residue(r, prime[i]))return false;
	}
	return true;
}
int main()
{
	init();
	scanf("%s", s);
	n = strlen(s);
	printf(check() ? "YES\n" : "NO\n");
}