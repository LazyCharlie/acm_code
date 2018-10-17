#include<bits/stdc++.h>
using namespace std;
char s[20000006];
int w[256];
int cnt;
vector<unsigned int>ans;
int read(int x, int t)
{
	int ret = 0;
	for (int i = 0; i < t; i++) {
		ret += x & (1LL << i);
	}
	return ret;
}
void print_hex(unsigned int x)
{
	int flag = 0;
	for (int i = 7; i >= 0; i--) {
		if (x&(0xfu << i * 4)) {
			flag = 1;
			printf("%X", (x>>i*4)&(0xfu));
		}
		else if (flag) {
			printf("%X", (x >> i * 4)&(0xfu));
		}
	}
	if (!flag)printf("0");
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	for (int i = 0; i < 10; i++)w[i + '0'] = i;
	for (int i = 0; i < 6; i++) w[i + 'A'] = 10 + i;
	for (int i = 0; scanf("%s", s + i) == 1; i += 2);
	int len = strlen(s);
	for (int i = 0; i < len - 1; i += 2) {
		if (i & 1)continue;
		ans.clear();
		int c = w[s[i]] * 16 + w[s[i + 1]], cnt = 0;
		for (int i = 7; i >= 0; i--) {
			if (c&(1 << i))cnt++;
			else break;
		}
		if (cnt == 1 || cnt == 8)continue;
		while (1 && i < len - 1) {
			int c = w[s[i]] * 16 + w[s[i + 1]], cnt = 0;
			for (int i = 7; i >= 0; i--) {
				if (c&(1 << i))cnt++;
				else break;
			}
			if (cnt == 1 || cnt == 8)break;
			if (cnt == 0)cnt++;
			unsigned int v = 0;
			int ok = 1;
			for (int k = 0; k < cnt; k++) {
				if (k == 0) {
					if (cnt == 1)v = read(w[s[i + k * 2]] * 16 + w[s[i + k * 2 + 1]], 7);
					else v = read(w[s[i + k * 2]] * 16 + w[s[i + k * 2 + 1]], 7 - cnt);
				}
				else {
					if (w[s[i + k * 2]] >= 12 || w[s[i + k * 2]] < 8) {
						ok = 0;
						break;
					}
					v = v << 6 | read(w[s[i + k * 2]] * 16 + w[s[i + k * 2 + 1]], 6);
				}
			}
			if (!ok)break;
			ans.push_back(v);
			i += 2 * cnt;
		}
		if (ans.size())i -= 2;
		if (ans.size() >= 3) {
			for (int i = 0; i < ans.size(); i++) {
				print_hex(ans[i]);
				if (i + 1 < ans.size())printf(" ");
				else printf("\n");
			}
		}
	}
}