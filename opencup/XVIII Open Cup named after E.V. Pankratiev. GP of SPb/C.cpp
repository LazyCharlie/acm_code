#include<bits/stdc++.h>
using namespace std;
vector<int>c, e;
int n;
int main()
{
	scanf("%d", &n);
	c.resize(n), e.resize(n);
	for (int &x : c)scanf("%d", &x);
	for (int &x : e)scanf("%d", &x);

	sort(c.begin(), c.end());
	sort(e.begin(), e.end());

	int cur = 0, ans = 1;
	for (int i = 0; i < e.size(); i++) {
		while (cur < c.size() && c[cur] <= e[i])cur++;
		int r = cur - i;
		ans *= max(0, r);
	}
	printf("%d\n", ans);
}