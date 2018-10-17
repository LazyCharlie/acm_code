#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, r, x;
set<LL>S;
int kase;
void exgcd(LL a, LL b, LL &g, LL&x, LL&y)
{
	if (!b)g = a, x = 1, y = 0;
	else exgcd(b, a%b, g, y, x), y -= x * (a / b);
}
void cal(LL a, LL b)
{
	LL g, x, y;
	exgcd(a, b, g, x, y);
	if ((2 * r) % g)return;
	LL p = 2 * r / g;
	LL sx = x * p;
	LL step = abs(b / g);
	sx = ((sx%step) + step) % step;
	LL R = (r + (sx*(-a))) % (step*(-a));
	while (R < n) {
		if (R >= 1)S.insert(R);
		R += step * (-a);
	}
}
int main()
{
	while (scanf("%lld%lld%lld", &x, &n, &r) == 3 && x) {
		S.clear();
		int m = sqrt(n + 0.5);
		for (int i = 1; i <= m; i++) {//a=i,b=n/i
			if (n%i == 0) {
				cal(-i, n / i);
				cal(-n / i, i);
			}
		}
		printf("Case %d:", ++kase);
		for (auto it = S.begin(); it != S.end(); it++) {
			printf(" %lld", *it);
		}
		printf("\n");
	}
}