//欧拉降幂公式
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MOD(x,m) (x>m)?m+x%m:x
int n, m, a[20];
int phi[10000 + 10], kase;
void phi_table(int n)
{
	for (int i = 2; i <= n; i++)if (!phi[i])
		for (int j = i; j <= n; j += i) {
			if (!phi[j])phi[j] = j;
			phi[j] = phi[j] / i * (i - 1);
		}
}
LL fpow(LL a, LL m, LL mod)
{
	LL ret = 1;
	while (m) {
		if(m&1)ret = MOD(ret * a, mod);
		a = MOD(a * a, mod);
		m >>= 1;
	}
	return ret;
}
bool read()
{
	char ch;
	while (scanf("%c", &ch) && ch == '\n');
	if (ch == '#')return false;
	cin.putback(ch);
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	return true;
}
LL solve(int x, int mod)
{
	if (x + 1 == n || mod == 1)return MOD(a[x], mod);
	LL tmp = solve(x + 1, phi[mod]);
	return fpow(a[x], tmp, mod);
}
int main()
{
	phi_table(10000);
	while (read()) {
		printf("Case #%d: %lld\n",++kase, solve(0, m) % m);
	}
}