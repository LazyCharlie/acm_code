#include<bits/stdc++.h>
using namespace std;
int cnt[4][4][26][26][26][26];
char s[4][105];
int sz[4];
long long ans = 0;
int main()
{
	for (int i = 0; i < 4; i++)scanf("%s", s[i]), sz[i] = strlen(s[i]);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			for (int L = 2; L < min(sz[i], sz[j]); L++) {
				for (int k = 0; k + L < sz[i]; k++) {
					for (int p = 0; p + L < sz[j]; p++) {
						cnt[i][j][s[i][k]-'a'][s[i][k + L]-'a'][s[j][p]-'a'][s[j][p + L]-'a']++;
					}
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)continue;
			int vis[4] = { 0 };
			vis[i] = vis[j] = 1;
			vector<int>t;
			for (int k = 0; k < 4; k++)if (!vis[k])t.push_back(k);
			for (int L = 2; L < min(sz[i], sz[j]); L++) {
				for (int k = 0; k + L < sz[i]; k++) {
					for (int p = 0; p + L < sz[j]; p++) {
						ans += cnt[t[0]][t[1]][s[i][k] - 'a'][s[j][p] - 'a'][s[i][k + L] - 'a'][s[j][p + L] - 'a'];
						ans += cnt[t[1]][t[0]][s[i][k] - 'a'][s[j][p] - 'a'][s[i][k + L] - 'a'][s[j][p + L] - 'a'];
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
}