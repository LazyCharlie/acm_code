#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int cnt = 0, n, m;
int a[maxn], c[maxn];
int root[maxn];
struct Node {
	int sum;
	int ls, rs;

}tree[maxn << 5];
int createNode(int s, int L, int R)
{
	tree[++cnt].sum = s;
	tree[cnt].ls = L;
	tree[cnt].rs = R;
	return cnt;
}
void insert(int &root, int pre, int pos, int L, int R)
{
	root = createNode(tree[pre].sum + 1, tree[pre].ls, tree[pre].rs);
	if (L == R)return;
	int M = L + R >> 1;
	if (pos <= M) {
		insert(tree[root].ls, tree[pre].ls, pos, L, M);
	}
	else insert(tree[root].rs, tree[pre].rs, pos, M + 1, R);
}
int query(int e, int c, int L, int R, int k)
{
	if (L == R)return L;
	int M = L + R >> 1;
	int lsum = tree[tree[c].ls].sum - tree[tree[e].ls].sum;
	if (lsum >= k) return query(tree[e].ls, tree[c].ls, L, M, k);
	else return query(tree[e].rs, tree[c].rs, M + 1, R, k - lsum);
}
int main()
{
	int T; scanf("%d", &T);
	while (T--) {
		cnt = 0;
		root[0] = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)scanf("%d", &a[i]), c[i] = a[i];
		sort(c + 1, c + n + 1);
		int sz = unique(c + 1, c + n + 1) - (c + 1);
		for (int i = 1; i <= n; i++) {
			int pos = lower_bound(c + 1, c + sz + 1, a[i]) - c;
			insert(root[i], root[i - 1], pos, 1, sz);
		}
		int l, r, k;
		while (m--) {
			scanf("%d%d%d", &l, &r, &k);
			int pos = query(root[l - 1], root[r], 1, sz, k);
			printf("%d\n", c[pos]);
		}
	}
}