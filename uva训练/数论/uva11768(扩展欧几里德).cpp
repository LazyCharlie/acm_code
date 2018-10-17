#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T;
LL x[2], y[2];
void read(LL &x)
{
	LL a, b;
	scanf("%lld.%lld", &a, &b);
	x = a * 10 + b;
}
void exgcd(LL a, LL b, LL& g, LL& x, LL& y)
{
	if (!b) g = a, x = 1, y = 0;
	else exgcd(b, a%b, g, y, x), y -= x * (a / b);
}
LL solve()
{
	LL ans = 0;
	for (int i = 0; i < 2; i++)read(x[i]), read(y[i]);
	if (x[0] > x[1] || x[0] == x[1] && y[0] > y[1]) {
		swap(x[0], x[1]);
		swap(y[0], y[1]);
	}

	if (x[0] == x[1]) {
		if (x[0] % 10)return 0;
		return max(0LL, y[1] / 10 - (y[0] + 9) / 10 + 1);
	}
	if (y[0] == y[1]) {
		if (y[0] % 10)return 0;
		return max(0LL, x[1] / 10 - (x[0] + 9) / 10 + 1);
	}

	LL a, b, g, X, Y;
	a = (y[1] - y[0]) * 10;
	b = (x[0] - x[1]) * 10;
	exgcd(a, b, g, X, Y);
	LL c = x[0] * y[1] - x[1] * y[0];
	if (c%g)return 0;
	X = X * c / g;
	x[0] = (x[0] + 9) / 10;
	x[1] = x[1] / 10;
	if (x[0] > x[1])return 0;
	LL st = abs(b / g);
	LL cx = X - (X - x[0]) / st * st;
	if (cx < x[0])cx += st;
	if (cx > x[1])return 0;
	return (x[1] - cx) / st + 1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		printf("%lld\n", solve());
	}
}