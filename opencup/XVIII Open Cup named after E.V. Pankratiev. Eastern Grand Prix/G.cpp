#include<bits/stdc++.h>
using namespace std;
const int maxn = 9 * 9 * 9 * 9 * 3;
int st[maxn + 10];//1表示对方下棋，2表示己方下棋
vector<int>ans[maxn + 10];
int f[10];
char s[5];
int cx, cy;
int down(int st, int x, int y, int who)
{
	int p = (x - 1) * 3 + y - 1;
	return st + f[p] * who;
}
int who(int st, int x, int y)
{
	int p = (x - 1) * 3 + y - 1;
	while (p--)st /= 3;
	return st % 3;
}
int win(int x, int k)
{
	for (int i = 1; i <= 3; i++) {
		int ok = 1;
		for (int j = 1; j <= 3; j++) {
			if (who(x, i, j) != k) {
				ok = 0;
				break;
			}
		}
		if (ok)return true;
		ok = 1;
		for (int j = 1; j <= 3; j++) {
			if (who(x, j, i) != k) {
				ok = 0;
				break;
			}
		}
		if (ok)return true;
	}
	if (who(x, 1, 1) == k && who(x, 2, 2) == k && who(x, 3, 3) == k)return true;
	if (who(x, 3, 1) == k && who(x, 2, 2) == k && who(x, 1, 3) == k)return true;
	return false;
}
int dfs(int x, bool y, int d)
{
	if (d == 9) {
		return win(x, 1) ? 0 : 1;
	}
	else if (win(x, 1))return 0;
	else if (win(x, 2))return 1;
	ans[x].resize(9, -1);
	int ok = 1;
	if (!y) {
		for (int i = 0; i < 9; i++) {
			int cx = i / 3 + 1, cy = i % 3 + 1;
			if (who(x, cx, cy) != 0)continue;
			if (dfs(down(x, cx, cy, y + 1), !y, d + 1) == 0)return 0;
			else ans[x][i] = down(x, cx, cy, y + 1);
		}
		return true;
	}
	else for (int i = 0; i < 9; i++) {
		int cx = i / 3 + 1, cy = i % 3 + 1;
		if (who(x, cx, cy) != 0)continue;
		if (dfs(down(x, cx, cy, y + 1), !y, d + 1)) {
			ans[x][i] = down(x, cx, cy, y + 1);
			return 1;
		}
	}
	return 0;
}
void init()
{
	f[0] = 1;
	for (int i = 1; i <= 9; i++)f[i] = f[i - 1] * 3;
}
int main()
{
	init();
	scanf("%s", s);
	dfs(0, s[0] == 'X', 0);
	int st = 0;
	if (s[0] == 'X') {
		for (int i = 0; i < 9; i++) {
			if (ans[st][i] != -1) {
				cx = i / 3 + 1;
				cy = i % 3 + 1;
				printf("%d %d\n", cx, cy);
				st = ans[st][i];
				fflush(stdout);
				break;
			}
		}
	}
	while (ans[st].size()) {
		scanf("%d%d", &cx, &cy);
		st = ans[st][(cx - 1) * 3 + cy - 1];
		if (ans[st].size() == 0)break;
		for (int i = 0; i < 9; i++) {
			if (ans[st][i] != -1) {
				cx = i / 3 + 1;
				cy = i % 3 + 1;
				printf("%d %d\n", cx, cy);
				st = ans[st][i];
				fflush(stdout);
				break;
			}
		}
	}
}