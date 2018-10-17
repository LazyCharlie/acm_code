#include<bits/stdc++.h>
using namespace std;
int T;
long long a, b;
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld", &a, &b);
		long long tot = 1LL * a*a + 2LL * b*b;
		long long q = sqrt(tot + 0.5);
		int ok = 1;
		for (int i = 2; i <= q; i++) {
			if (tot%i == 0) {
				ok = 0;
				break;
			}
		}
		if (a == 0)ok = 0;
		if (ok) {
			printf("Yes\n");
		}
		else printf("No\n");
	}
}