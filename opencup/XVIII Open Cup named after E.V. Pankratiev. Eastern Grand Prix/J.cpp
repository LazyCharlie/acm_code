#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, c;
int x, y, z, t1, t2;
int tree[86410 << 2], lazy[86410 << 2];
struct node {
	int x, y, w;
	void set(int _x = 0,int _y = 0,int _w = 0)
	{
		x = _x;
		y = _y;
		w = _w;
	}
	bool operator<(const node&rhs)
	{
		return x < rhs.x;
	}
}a[86400 + 10];
void push_down(int x)
{
	tree[x << 1] = max(lazy[x], tree[x << 1]);
	tree[x << 1 | 1] = max(lazy[x], tree[x << 1 | 1]);
	lazy[x << 1] = max(lazy[x << 1], lazy[x]);
	lazy[x << 1 | 1] = max(lazy[x << 1 | 1], lazy[x]);
	lazy[x] = 0;
}
void update(int x, int L, int R, int ls, int rs, int v)
{
	if (L == ls && R == rs) {
		tree[x] = max(v, tree[x]);
		lazy[x] = max(lazy[x], v);
		return;
	}
	if (lazy[x])push_down(x);
	int mid = L + R >> 1;
	if (rs <= mid)update(x << 1, L, mid, ls, rs, v);
	else if (ls > mid)update(x << 1 | 1, mid + 1, R, ls, rs, v);
	else update(x << 1, L, mid, ls, mid, v), update(x << 1 | 1, mid + 1, R, mid + 1, rs, v);
	tree[x] = max(tree[x << 1 | 1], tree[x << 1]);
}
int query(int x, int L, int R, int ls, int rs)
{
	if (L == ls && R == rs) {
		return tree[x];
	}
	if (lazy[x])push_down(x);
	int mid = L + R >> 1;
	if (rs <= mid)return query(x << 1, L, mid, ls, rs);
	else if (ls > mid)return query(x << 1 | 1, mid + 1, R, ls, rs);
	else return	max(query(x << 1, L, mid, ls, mid), query(x << 1 | 1, mid + 1, R, mid + 1, rs));
}
int Time()
{
	scanf("%lld:%lld:%lld", &x, &y, &z);
	return x * 3600 + y * 60 + z + 2;
}
signed main()
{
	scanf("%lld%lld", &n, &c);
	for (int i = 0; i < n; i++) {
		t1 = Time(); t2 = Time();
		scanf("%lld", &x);
		a[i].set(t1, t2 - 1, x - (t2 - t1)*c);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int maxk = query(1, 1, 86402, 1, a[i].x - 1);
		update(1, 1, 86402, a[i].y, 86402, maxk + a[i].w);
	}
	printf("%lld\n", query(1, 1, 86402, 1, 86402));
}