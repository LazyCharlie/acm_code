#include<bits/stdc++.h>
using namespace std;
long long n;
int kase = 0;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a%b);
}
long long LCM(long long a, long long b, long long c)
{
	long long x = a * b / gcd(a, b);
	return x * c / gcd(x, c);
}
int main()
{
	while (scanf("%lld", &n) == 1&&n) {
		printf("Scenario %d:\n",++kase);
		int ok = 0;
		for (int i = 1; i <= min(n, 1000000LL); i++) {
			if (n%i)continue;
			for (int j = 1; j < 25; j++) {
				if (n % (i + j))continue;
				for (int k = j + 1; k <= 25 && i + k <= 1000000LL; k++) {
					if (n % (i + k))continue;
					if (LCM(i, i + j, i + k) == n) {
						printf("%d %d %d\n", i, i + j, i + k);
						ok = 1;
					}
				}
			}
		}
		if (!ok)printf("Such bells don't exist\n");
		printf("\n");
	}
}