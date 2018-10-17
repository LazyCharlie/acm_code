#include<bits/stdc++.h>
using namespace std;
char s[150];
int L, R;
int main()
{
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] != 'A')break;
		L++;
	}
	for (int i = len - 1; i >= 0; i--) {
		if (s[i] != '!')break;
		R++;
	}
	if (L&&R&&L + R == len) {
		printf("Panic!\n");
	}
	else printf("No panic\n");
}