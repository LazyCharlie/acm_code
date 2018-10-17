#include<bits/stdc++.h>
using namespace std;
long long a, b;
int main()
{
	scanf("%lld%lld", &a, &b);
	long long tot = a + b - 2;
	tot = (1 + tot)*tot / 2;
	if ((a + b) & 1)printf("%lld\n", tot + a);
	else {
		printf("%lld\n", tot + b);
	}
}