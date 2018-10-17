#include<bits/stdc++.h>
using namespace std;
char s1[100006], s2[100006];
long long ans = 0;
int main()
{
	int n; scanf("%d", &n);
	scanf("%s%s", s1, s2);
	int c00, c01, c11, c10;
	c00 = c01 = c11 = c10 = 0;
	for (int i = 0; i < n; i++) {
		if (s1[i] == '1'&&s2[i] == '1')c11++;
		else if (s1[i] == '0'&&s2[i] == '0')c00++;
		else if (s1[i] == '0'&&s2[i] == '1')c01++;
		else c10++;
	}
	printf("%lld\n", 1LL * c11*c00 + 1LL * c01*c10 + 1LL * c10*c00);
}