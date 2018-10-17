#include<bits/stdc++.h>
using namespace std;
int n;
struct node {
	int id, a, b, c, d;
	bool operator<(const node rhs)const {
		int sum = a + b + c + d;
		int sum2 = rhs.a + rhs.b + rhs.c + rhs.d;
		return sum > sum2 || sum == sum2 && id < rhs.id;
	}
}s[1006];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &s[i].a, &s[i].b, &s[i].c, &s[i].d);
		s[i].id = i + 1;
	}
	sort(s, s + n);
	for (int i = 0; i < n; i++) {
		if (s[i].id == 1) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
}