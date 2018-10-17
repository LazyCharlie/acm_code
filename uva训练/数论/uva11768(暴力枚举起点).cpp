#include<bits/stdc++.h>
using namespace std;
typedef long long LL ;
int T;
LL x[2], y[2];
LL gcd(LL a, LL b)
{
	return b == 0 ? a : gcd(b, a%b);
}
void read(LL &x)
{
	LL a, b;
	scanf("%lld.%lld", &a, &b);
	x = a * 10 + b;
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		for (LL i = 0; i < 2; i++)read(x[i]), read(y[i]);
		/*for (int i = 0; i < 2; i++) {
			x[i] = (rand() % 200 + 1) * 10;
			y[i] = (rand() % 200 + 1) * 10;
		}*/
		//printf("%d %d %d %d\n", x[0], y[0], x[1], y[1]);
		if (x[0] > x[1] || x[0] == x[1] && y[1] > y[0]) {
			swap(x[0], x[1]);
			swap(y[0], y[1]);
		}
		if (x[0] == x[1] && (x[0] % 10) || y[0] == y[1] && (y[0] % 10)) {
			printf("0\n");
			continue;
		}
		if (x[0] == x[1] && y[0] == y[1]) {
			if (x[0] % 10 == 0 && y[0] % 10 == 0) {
				printf("1\n");
			}
			else printf("0\n");
			continue;
		}
		LL dx = abs(x[0] - x[1]);
		LL dy = abs(y[0] - y[1]);
		LL g = gcd(dx, dy);
		LL st = dx / g;
		LL cx = x[0], cy = y[0];
		LL ans = 0;
		for (LL i = 0; i <= 100 && cx <= x[1] && (cy - y[0])*(cy - y[1]) <= 0; i++) {
			if (cx % 10 == 0 && cy % 10 == 0) {
				long long gc = gcd(gcd(st, 10), gcd(dy / g, 10));
				LL t = 10 / gcd(gcd(st, 10), gcd(dy / g, 10));
				if (st)ans = 1 + (x[1] - cx) / (t*st);
				else ans = abs(y[1] - cy) / (dy / g * t) + 1;
				break;
			}
			cx += st;
			cy += (y[1] - y[0]) / g;
		}
		printf("%lld\n", ans);
	}
}