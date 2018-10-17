#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn = 3e5 + 10;
char s[maxn];
int p[maxn * 2], T;
char Ma[maxn * 2];
void Manacher(char s[], int len) {
	int l = 0;
	Ma[l++] = '$';
	Ma[l++] = '#';
	for (int i = 0; i < len; i++) {
		Ma[l++] = s[i];
		Ma[l++] = '#';
	}
	Ma[l] = 0;
	int pos = 0, R = 0;
	for (int i = 0; i < l; i++) {
		if (i < R)p[i] = min(p[pos * 2 - i], R - i);
		else p[i] = 1;
		while (Ma[i + p[i]] == Ma[i - p[i]])p[i]++;
		if (i + p[i] > R) R = i + p[i], pos = i;
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		n = strlen(s);
		Manacher(s, n);
		int ans = 0;
		for (int i = 1; i <= n * 2 + 1; i += 2) {
			if (p[i] == 1)continue;
			for (int L = (p[i] - 1) / 4; L > ans; L--) {
				if (p[i - L * 2] - 1 >= 2*L && p[i + L * 2] - 1 >= 2*L)ans = L;
			}
		}
		printf("%d\n", ans * 4);
	}
}