#include<bits/stdc++.h>
using namespace std;
char s[205][205];
char ans[205][205];
int T, h, w;
int query(char s[205][205], int h, int w)
{
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < h; i++) {
		int L = 0;
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '(')L++;
			else if (s[i][j] == ')') {
				if (L)L--;
				else { L = 1; break; }
			}
		}
		if (!L)cnt1++;
	}
	for (int i = 0; i < w; i++) {
		int L = 0;
		for (int j = 0; j < h; j++) {
			if (s[j][i] == '(')L++;
			else if (s[j][i] == ')') {
				if (L)L--;
				else { L = 1; break; }
			}
		}
		if (!L)cnt2++;
	}
	return cnt1 + cnt2;
}
void fill(int r,int st)
{
	for (int i = 0; i < w; i++) {
		if (i % 2 == st)ans[r][i] = '(';
		else ans[r][i] = ')';
	}
	ans[r][0] = '(';
	ans[r][w - 1] = ')';
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &h, &w);
		if (h & 1) {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (j < w / 2)s[i][j] = '(';
					else s[i][j] = ')';
				}
			}
		}
		else if (w & 1) {
			for (int i = 0; i < w; i++) {
				for (int j = 0; j < h; j++) {
					if (j < h / 2)s[j][i] = '(';
					else s[j][i] = ')';
				}
			}
		}
		else {
			if (h < w) {
				for (int i = 0; i < w / 2; i++) {
					for (int j = 0; j < h; j++) {
						if (j % 2 == 0)s[j][i] = '(';
						else s[j][i] = ')';
					}
				}
				for (int i = w / 2; i < w; i++) {
					for (int j = 0; j < h; j++) {
						if (j & 1)s[j][i] = '(';
						else s[j][i] = ')';
					}
					s[0][i] = '(';
					s[h - 1][i] = ')';
				}
			}
			else if (h >= w) {
				for (int i = 0; i < h / 2; i++) {
					for (int j = 0; j < w; j++) {
						if (j % 2 == 0)s[i][j] = '(';
						else s[i][j] = ')';
					}
				}
				for (int i = h / 2; i < h; i++) {
					for (int j = 0; j < w; j++) {
						if (j & 1)s[i][j] = '(';
						else s[i][j] = ')';
					}
					s[i][0] = '(';
					s[i][w - 1] = ')';
				}
			}
		}
		int ans1 = query(s, h, w);
		for (int i = 0; i < h; i++) {
			if (i == 0) {
				for (int j = 0; j < w; j++) {
					ans[i][j] = '(';
				}
			}
			else if (i + 1 == h) {
				for (int j = 0; j < w; j++) {
					ans[i][j] = ')';
				}
			}
			else fill(i, i % 2);
		}
		int ans2 = query(ans, h, w);
		if (ans2 > ans1)memcpy(s, ans, sizeof(ans));
		for (int i = 0; i < h; i++) {
			s[i][w] = '\0';
			printf("%s\n", s[i]);
		}
		//printf("%d\n", ans2);
	}
}
