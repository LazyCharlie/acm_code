#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	int q = sqrt(n - 0.5) + 1;
	int cur = n;
	int seg = q;
	cur -= q;
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ++cur, i == n ? '\n' : ' ');
		if (i%seg == 0)cur -= seg * 2;
		if (cur < 0)cur = 0;
	}
}