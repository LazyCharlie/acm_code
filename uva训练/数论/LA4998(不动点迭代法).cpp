#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k1;
LL P[20];
LL mul_mod(LL a, LL b, LL mod)
{
	LL p = 1LL << 20;
	LL a1 = a / p, a2 = a % p, b1 = b / p, b2 = b % p;
	LL ret = 0;
	ret = ((a1*b1*p % mod)*p) % mod;
	ret += (((a1*b2 + a2 * b1) % mod)*p) % mod;
	ret %= mod;
	ret += (a2*b2) % mod;
	ret %= mod;
	return ret;
}
LL fpow(LL a, LL m, LL mod)
{
	LL ret = 1;
	while (m) {
		if (m & 1)ret = mul_mod(ret, a, mod);
		a = mul_mod(a, a, mod);
		m >>= 1;
	}
	return ret;
}
LL solve()
{
	LL tmp = 1e12 + 9;
	while (1) {
		LL r = fpow(k1, tmp, 1e12 + 0.5);
		if (r == tmp)return r;
		else tmp = r;
	}
}
int kase = 0;
int main()
{
	while (scanf("%lld", &k1) == 1 && k1) {
		printf("Case %d: Public Key = %lld Private Key = %lld\n", ++kase, k1, solve());
	}
}