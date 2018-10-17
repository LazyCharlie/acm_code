#include<bits/stdc++.h>
using namespace std;
int n;
struct window {
	int x1, y1, x2, y2;
	window(int X1 = 0, int Y1 = 0) {
		x1 = x2 = X1;
		y2 = y1 = Y1;
	}
	void read()
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	}
	bool include(const window &rhs)const
	{
		return x1 <= rhs.x1&&y1 <= rhs.y1&&x2 >= rhs.x2&&y2 >= rhs.y2;
	}
	bool intersect(const window &rhs)const
	{
		window a(rhs.x1, rhs.y2);
		window b(rhs.x1, rhs.y1);
		window c(rhs.x2, rhs.y1);
		window d(rhs.x2, rhs.y2);
		return (include(a) || include(b) || include(c) || include(d));
	}
}A, B;
bool Separate(window &a, window &b)
{
	return a.x2<b.x1 || a.x1>b.x2 || a.y1 > b.y2 || a.y2 < b.y1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		A.read();
		B.read();
		if (A.include(B)) printf("B in A\n");
		else if (B.include(A))printf("A in B\n");
		else if (Separate(A, B)) {
			printf("Separate\n");
		}
		else printf("Intersect\n");
	}
}