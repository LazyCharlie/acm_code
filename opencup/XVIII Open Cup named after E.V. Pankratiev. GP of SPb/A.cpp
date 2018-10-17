#include<bits/stdc++.h>
using namespace std;
char a[500006], b[500006];
int ans[10000006];
int main()
{
	scanf("%s%s", a, b);
	int la = strlen(a), lb = strlen(b);
	int len = min(la, lb);
	for (int i = 0; i < len; i++) {
		ans[i] = (a[la - i - 1] - '0' + 0) + (b[lb - i - 1] - '0');
	}
	for (int i = len; i < max(la, lb); i++) {
		ans[i] = la > lb ? (a[la - i - 1] - '0') : (b[lb - i - 1] - '0');
	}
	for (int i = 0; i < 10000000; i++) {
		if (ans[i] > 1) {
			while (ans[i] > 1) {
				ans[i] -= 2;
				ans[i + 2]++;
				ans[i + 3]++;
			}
		}
	}
	int ml = 0;
	for (int i = 0; i < 10000000; i++) {
		if (ans[i] == 1)ml = i;
	}
	for (int i = ml; i >= 0; i--) {
		printf("%d", ans[i]);
	}
}