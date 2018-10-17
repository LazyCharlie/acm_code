#include<bits/stdc++.h>
using namespace std;
struct node {
	long long x, y, z;
	node(long long  X = 0, long long Y = 0, long long Z = 0) {
		x = X;
		y = Y;
		z = Z;
	}
	bool operator<(const node&rhs)const {
		return x < rhs.x || x==rhs.x&&y < rhs.y;
	}
	void read()
	{
		scanf("%lld%lld%lld", &x, &y, &z);
	}
};
bool cmp(const node&a, const node& b)
{
	return a.z > b.z;
}

const int maxn = 100000 + 10;
long long n, m;
node p[maxn];
set<node>S;

long long add(const node&a) 
{
	long long ret = 0;
	node tmp = a;
	auto it1 = S.lower_bound(a);
	auto it2 = --S.upper_bound(a);
	if (it1->x == a.x || it1->y >= a.y)return 0;
	node pre(a.x, it1->y);
	tmp.x = it2->x;
	long long maxy = 0;
	while (it2->y <= a.y) {
		ret += (a.x - it2->x)*(it2->y - pre.y);
		tmp.x = it2->x;
		maxy = max(maxy, it2->y);
		pre = *it2;
		S.erase(it2);
		it2 = --S.upper_bound(tmp);
	}
	ret += (a.x - it2->x)*(a.y - pre.y);
	S.insert(a);
	return ret;
}

long long solve()
{	
	long long ans = m * m*m;
	for (int i = 1; i <= n; i++)p[i].read();
	sort(p + 1, p + n + 1, cmp);
	S.clear();
	S.insert(node(0, m + 1, m));
	S.insert(node(m + 1, 0, m));
	for (int i = 1; i <= n; i++) {
		ans -= add(p[i])*p[i].z;
	}
	return ans;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while (scanf("%lld%lld", &n, &m) == 2 && n) {
		printf("%lld\n", solve());
	}
}