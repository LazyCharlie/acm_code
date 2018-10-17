#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans[64][64];
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (long long i = 1; i <= 1000000000LL; i++) {
		n = i * i;
		int c1 = 0, c2 = 0;
		while (n) {
			if (n & 1)c1++;
			c2++;
			n >>= 1;
		}
		ans[c2][n]++;
	}
	for (int i = 0; i < 64; i++) {
		printf("{");
		for (int j = 0; j < 64; j++) {
			printf("%lld%c", ans[i][j], j + 1 == 64 ? '}' : ',');
		}
		printf(",");
	}
}
