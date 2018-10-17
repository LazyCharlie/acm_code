#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
vector<int>ans;
int a[200006], b[200006], n;
int check(int mid)
{
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int r = mid - a[i];
		int p = upper_bound(b, b + n, r) - b;
		ret += p;
	}
	return ret;
}
signed main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &b[i]);
	}
	sort(b, b + n);
	int ls = n * (n - 1LL) / 2LL + 1;
	int rs = n * (n + 1LL) / 2LL;
	int L = 0, R = 2e9 + 1;
	int La = 2e9, Ra = 2e9;
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid) >= ls) {
			La = min(La, mid);
			R = mid - 1;
		}
		else L = mid + 1;
	}
	L = 0, R = 2e9 + 1;
	while (L <= R) {
		int mid = L + R >> 1;
		if (check(mid) >= rs) {
			Ra = min(Ra, mid);
			R = mid - 1;
		}
		else L = mid + 1;
	}
	for (int i = 0; i < n; i++) {
		int r = La - a[i];
		int p = upper_bound(b, b + n, r) - b;
		for (int j = p; j < n&&b[j] < Ra - a[i]; j++) {
			ans.push_back(a[i] + b[j]);
		}
	}
	sort(ans.begin(), ans.end());
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int r = La - a[i];
		int p = upper_bound(b, b + n, r) - b;
		cnt += p;//
	}
	int tot = 0;
	for (int i = 0; i < cnt - ls + 1; i++) {
		tot++;
		printf("%lld%c", La, tot == n ? '\n' : ' ');
		if (tot == n)break;
	}
	for (auto i : ans) {
		tot++;
		printf("%lld%c", i, tot == n ? '\n' : ' ');
	}
	while (tot < n) {
		tot++;
		printf("%lld%c", Ra, tot == n ? '\n' : ' ');
	}
}