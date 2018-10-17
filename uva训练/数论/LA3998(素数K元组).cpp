#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxc = 1e7 + 10;
bitset<maxc>S;
bool vis[maxn];
vector<long long>prime;
int T;
void seive(int n)
{
	vis[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i])prime.push_back(i);
		for (int j = 0; j < prime.size(); j++) {
			if (prime[j] * i > n)break;
			vis[prime[j] * i] = 1;
			if (i%prime[j] == 0)break;
		}
	}
}
int solve()
{
	int a, b, k, s, cnt = 0;
	scanf("%d%d%d%d", &a, &b, &k, &s);
	if (a > b)return 0;
	S.reset();
	int sz = sqrt(b);
	for (int i = 0; i < prime.size() && prime[i] <= sz; i++) {
		long long L = a / prime[i] * prime[i];
		if (L < a)L += prime[i];
		if (L == prime[i])L += prime[i];
		L = max(L, prime[i] * prime[i]);
		for (L; L <= b; L += prime[i]) {
			S[L - a] = 1;
		}
	}
	vector<int>p;
	for (int i = 0; i <= b - a; i++) {
		if (!S[i])p.push_back(i + a);
	}
	for (int i = 0; i + k - 1 < p.size(); i++) {
		if (p[i + k - 1] - p[i] == s)cnt++;
	}
	return cnt;
}
int main()
{
	seive(100000);
	scanf("%d", &T);
	while (T--) {
		printf("%d\n", solve());
	}
}