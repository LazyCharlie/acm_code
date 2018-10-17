#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int g[maxn], f[maxn];//g[i]表示以g[i]为结尾。f[i]表示以f[i]为开头的长度
int T, n;
vector<int>a;
set<pair<int, int>>S;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		S.clear();
		scanf("%d", &n); a.resize(n);
		for (auto &x : a)scanf("%d", &x);

		for (int i = 0; i < n; i++) {
			g[i] = 1;
			if (i&&a[i - 1] < a[i])g[i] += g[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) {
			f[i] = 1;
			if (i < n - 1 && a[i] < a[i + 1])f[i] += f[i + 1];
		}

		int ans = 1;
		S.insert({ a[0],g[0] });
		for (int i = 1; i < n; i++) {
			auto it = S.upper_bound({ a[i],0 });
			if (it != S.begin()) {
				it--;
				ans = max(ans, f[i] + it->second);
			}

			it = S.upper_bound({ a[i],0 });
			if (it != S.end() && it->first == a[i]) {
				if (it->second >= g[i])continue;
				else S.erase(it);
			}

			auto it2 = it = S.upper_bound({ a[i],0 });
			if (it != S.begin()) {
				it2--;
				if (it2->second >= g[i])continue;
			}

			while (it != S.end() && it->second <= g[i])it = S.erase(it);
			S.insert({ a[i],g[i] });
		}
		printf("%d\n", ans);
	}
}