#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
char s[maxn];
pair<int, int>tree[maxn << 2];
struct cmp {
	bool operator()(const int &a, const int& b)const {
		return a > b;
	}
};
void build(int x, int L, int R)
{
	if (L == R) {
		tree[x].first = (s[L] == '(');
		tree[x].second = (s[R] == ')');
		return;
	}
	int mid = L + R >> 1;
	build(x << 1, L, mid);
	build(x << 1 | 1, mid + 1, R);
	tree[x].first = tree[x << 1].first + tree[x << 1 | 1].first;
	tree[x].second = tree[x << 1].second + tree[x << 1 | 1].second;
}
bool query(int x, int L, int R, int ls, int rs)
{
	int mid = L + R >> 1;
	if (tree[x << 1 | 1].second == 0)return query(x << 1, L, mid, ls, min(rs, mid));
	else if (tree[x << 1].first == 0)return query(x << 1 | 1, mid + 1, R, max(mid + 1, ls), rs);
	else return false;
}
void update(int x, int L, int R, int pos)
{
	if (L == R) {
		tree[x].first = tree[x].second = 0;
		return;
	}
	int mid = L + R >> 1;
	if (pos <= mid)update(x << 1, L, mid, pos);
	else update(x << 1 | 1, mid + 1, R, pos);
	tree[x].first = tree[x << 1].first + tree[x << 1 | 1].first;
	tree[x].second = tree[x << 1].second + tree[x << 1 | 1].second;
}
set<int,cmp>S;
int L[maxn], R[maxn], n, q, x, y;
int vis[maxn];
void del(int x)
{
	R[L[x]] = R[x];
	L[R[x]] = L[x];
}
void init_link()
{
	for (int i = 0; i <= n; i++)R[i] = i + 1, L[i + 1] = i;
	for (int i = 1; i <= n; i++)S.insert(i);
	build(1, 1, n);
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	init_link();
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		if (query(1, 1, n, x, y)) {
			printf("0\n");
			continue;
		}
		int cnt = 0, ok = 0;
		auto it = S.lower_bound(y);
		if (it == S.end()) {
			printf("0\n");
			continue;
		}
		int p = *it;
		int mL = p;
		for (int i = p; i >=x; i = L[i]) {
			if (s[i] == ')')cnt++;
			if (s[i] == '('&&cnt)cnt--, ok++, vis[i] = 1, mL = i;
		}
		int c1 = ok, c2 = ok; cnt = 0;
		if (ok == 0) {
			printf("0\n");
			continue;
		}
		for (int i = mL; i <= y && c1 + c2; i = R[i]) {
			if (s[i] == '('&&vis[i]) {
				cnt++;
				S.erase(i);
				del(i);
				c1--;
				update(1, 1, n, i);
			}
			else if (cnt&&s[i] == ')') {
				S.erase(i);
				del(i);
				cnt--;
				c2--;
				update(1, 1, n, i);
			}
		}
		printf("%d\n", ok * 2);
	}
}