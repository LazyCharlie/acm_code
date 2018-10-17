#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long mod = 1e8 + 7;
LL S;
int main()
{
	while (scanf("%lld", &S) == 1 && S) {
		int ok = 0;
		for (LL r = 1; 6 * r*r < S; r++) {
			if ((S - 6 * r*r) % (7 * r))continue;
			LL x = (S - 6*r*r) / (7*r);
			if (6 * r*r + 7 * x*r == S) {
				ok = 1;
				x %= mod;
				LL res = (x * x * 2) % mod;
				printf("Possible Missing Soldiers = %lld\n", res);
			}
		}
		if (!ok) {
			printf("No Solution Possible\n\n");
			continue;
		}
		else printf("\n");
	}
}