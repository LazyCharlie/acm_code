#include<bits/stdc++.h>
using namespace std;
const int maxn = 65536 + 5;
int c[maxn];
long long n;
void init()
{
	for (int i = 1; i < maxn; i++) {
		c[i] = c[i >> 1] + (i & 1);
	}
}
int pop_count(long long x)
{
	return c[x & 65535] + c[x >> 16 & 65535] + c[x >> 32 & 65535] + c[x >> 48];
}
int main()
{
	init();
	scanf("%lld", &n);
	int one = 0, cnt = 0;
	while (n) {
		cnt++;
		if (n & 1)one++;
		n >>= 1;
	}
	long long ub = sqrt(min((1LL << cnt) - 1, (long long)1e18));
	long long lb = sqrt(1LL << (cnt - 1)) + 0.99999999;
	long long val = lb * lb, add = lb * 2 + 1;
	long long top = min((1LL << cnt) - 1, (long long)1e18);
	int ans = 0;
	for (val; val <= top; val += add, add += 2) {
		if (pop_count(val) == one) {
			ans++;
		}
	}
	printf("%d\n", ans);
}