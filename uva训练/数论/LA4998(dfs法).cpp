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
void init()
{
	P[0] = 1;
	for (int i = 1; i <= 12; i++)P[i] = P[i - 1] * 10;
}
LL dfs(int x, LL cur)
{
	if (x == 12) {
		if (fpow(k1, cur, P[x]) == cur % P[x])return cur;
		return 0;
	}
	int s = (x == 11);
	for (int i = s; i < 10; i++) {
		LL nc = cur + P[x] * i;
		if (fpow(k1, nc, P[x]) == (nc % P[x])) {
			LL ans = dfs(x + 1, nc);
			if (ans)return ans;
		}
	}
	return 0;
}
int kase = 0;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	init();
	while (scanf("%lld", &k1) == 1 && k1) {
		printf("Case %d: Public Key = %lld Private Key = %lld\n", ++kase,k1,dfs(0, 0));
	}
}