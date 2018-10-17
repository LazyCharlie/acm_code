#include<bits/stdc++.h>
using namespace std;
const int maxc = 1e7;
int K;
int a[100006];
int vis[10000007];
vector<int>ans;
int main()
{
	scanf("%d", &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &a[i]);
		vis[a[i]]++;
	}
	for (int i = 1; i <= maxc; i++) {
		if (vis[i] == 1) {
			int ok = 1;
			for (int j = i * 2; j <= maxc; j += i) {
				if (vis[j]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				ans.push_back(i);
			}
		}
	}
	for (int i = 0; i < ans.size();i++) {
		printf("%d%c", ans[i], ans.size() == i + 1 ? '\n' : ' ');
	}
}