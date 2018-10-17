#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef vector<int> vint;
int n, x, y, t, kase, a[105];
vint f, g, ans;
void read(int &x, vint* f)
{
	scanf("%d", &x);
	for (int i = 0; i <= x; i++) {
		scanf("%d", &t);
		f->push_back(t);
	}
}
long long fpow(long long a, long long m, long long mod)
{
	long long ret = 1;
	while (m) {
		if (m & 1)ret = ret * a%mod;
		m >>= 1;
		a = a * a%mod;
	}
	return ret;
}

vint gcd(vint a, vint b)
{
	if (b.size() == 0)return a;
	int t = a.size() - b.size();
	for (int i = 0; i <= t; i++) {
		if (a[i] == 0)continue;
		long long tmp = fpow(b[0], n - 2, n)*a[i] % n;
		for (int j = i; j < i + b.size(); j++) {
			a[j] = ((a[j] - b[j - i] * tmp) % n + n) % n;
		}
	}
	vector<int> c;
	for (int i = 0; i < a.size(); i++) {
		if (a[i]) {
			for (int j = i; j < a.size(); j++)c.push_back(a[j]);
			break;
		}
	}
	return gcd(b, c);
}
int main()
{
	while (scanf("%d", &n) == 1 && n) {
		f.clear();
		g.clear();
		read(x, &f);
		read(y, &g);
		printf("Case %d:", ++kase);
		ans = gcd(f, g);
		printf(" %d", ans.size() - 1);
		long long tmp = fpow(ans[0], n - 2, n);
		for (int i = 0; i < ans.size(); i++) {
			printf(" %d", ans[i] * tmp%n);
		}
		printf("\n");
	}
	
}