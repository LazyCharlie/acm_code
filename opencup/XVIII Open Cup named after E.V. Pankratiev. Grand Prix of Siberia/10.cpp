#include<bits/stdc++.h>
using namespace std;
char s[10], t[10];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%s%s", s, t);
	int n = strlen(s), cnt = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] < t[i])cnt++;
		else if (s[i] > t[i])cnt2++;
	}
	printf("%d\n%d\n", cnt, cnt2);
}