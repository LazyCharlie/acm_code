#include<bits/stdc++.h>
using namespace std;

const int maxn = 128000 + 10;

int n, m, root[maxn], id;
long long a[maxn], d[maxn], sorted[maxn], sumd[maxn];

struct node {
	int cnt;
	int ls, rs;
	long long sum;
	void init(long long s, int c = 0, int L = 0, int R = 0)
	{
		sum = s;
		cnt = c;
		ls = L;
		rs = R;
	}
}tree[maxn << 5];

int creatNode(long long sum, int cnt, int L, int R)
{
	tree[++id].init(sum, cnt, L, R);
	return id;
}
void insert(int &root, int pre, int L, int R, int pos,long long m)
{
	root = creatNode(tree[pre].sum + m, tree[pre].cnt + 1, tree[pre].ls, tree[pre].rs);
	if (L == R)return;
	int M = L + R >> 1;
	if (pos <= M)insert(tree[root].ls, tree[pre].ls, L, M, pos, m);
	else insert(tree[root].rs, tree[pre].rs, M + 1, R, pos, m);
}
long long query(int pre, int cur, int L, int R, int k)
{
	if (tree[cur].cnt - tree[pre].cnt == 0)return 0;
	if (L == R) {
		long long sum = (tree[cur].sum - tree[pre].sum) / (tree[cur].cnt - tree[pre].cnt)*k;
		return sum;
	}
	int M = L + R >> 1;
	int lsum = tree[tree[cur].ls].cnt - tree[tree[pre].ls].cnt;
	long long S = tree[tree[cur].ls].sum - tree[tree[pre].ls].sum;
	if (k <= lsum)return query(tree[pre].ls, tree[cur].ls, L, M, k);
	else return S + query(tree[pre].rs, tree[cur].rs, M + 1, R, k - lsum);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		sorted[i] = d[i] - a[i];
		sumd[i] = sumd[i - 1] + d[i];
	}
	sort(sorted + 1, sorted + n + 1);
	int sz = unique(sorted + 1, sorted + n + 1) - (sorted + 1);
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(sorted + 1, sorted + 1 + sz, d[i] - a[i]) - sorted;
		insert(root[i], root[i - 1], 1, sz, pos, d[i] - a[i]);
	}
	scanf("%d", &m);
	int l, r;
	while (m--) {
		scanf("%d%d", &l, &r);
		long long ans = (sumd[r] - sumd[l - 1]) * 2;
		ans -= query(root[l - 1], root[r], 1, sz, (r - l + 1) / 3);
		ans -= query(root[l - 1], root[r], 1, sz, (r - l + 1) * 2 / 3);
		printf("%lld.%d\n", ans / 2, ans % 2 == 0 ? 0 : 5);
	}
}