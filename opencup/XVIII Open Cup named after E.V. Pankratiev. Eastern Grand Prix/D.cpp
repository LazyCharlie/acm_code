#include<bits/stdc++.h>
using namespace std;
int minx;
char s[100006];
int ans = 10;
int main()
{
	scanf("%s", s);
	int len = strlen(s), ok = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] == '0') {
			ok = 0;
			continue;
		}
		if (s[i] - '0' < ans)
		{
			ans = s[i] - '0', ok = 1;
			continue;
		}
		if (s[i] != '9')ok = 0;
	}
	if (ok)printf("%d\n", ans);
	else printf("%d\n", max(1, ans - 1));
}