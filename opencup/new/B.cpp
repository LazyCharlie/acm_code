#include<bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1e5 + 10;
int a[maxn];
map<int, int>M;
int mx = 0, id;
vector<int>p;
int cnt = 0;
int main()
{
	scanf("%d%d", &n, &m);
	int q = sqrt(n + 0.5);
	for (int i = 0; i < m; i++)scanf("%d", &a[i]), M[a[i]]++;
	for (auto it = M.begin(); it != M.end(); it++) {
		mx = max(it->second, mx);
		id = max(id, it->first);
	}
	for (int i = 1; i <= q; i++) {
		if (n%i == 0) {
			if (n / i >= id && i >= mx){
				cnt++;
			}
			if (n / i >= mx && i >= id && i*i != n) {
				cnt++;
			}
		}
	}
	if (cnt == 1) {
		printf("YES\n");
	}
	else printf("NO\n");
}