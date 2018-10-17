#include<bits/stdc++.h>
using namespace std;
int n, m, k;
struct node {
	int x, y;
	bool operator<(const node&rhs)const {
		return x < rhs.x || x == rhs.x&&y < rhs.y;
	}
	void read()
	{
		scanf("%d%d", &x, &y);
	}
}p[1006];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	p[0] = { 1,1 };
	for (int i = 1; i <= k; i++)p[i].read();
	sort(p, p + k + 1);
	for (int i = 1; i <= k; i++) {
		if (p[i].x >= p[i - 1].x&&p[i].y >= p[i - 1].y)continue;
		else {
			printf("Impossible\n");
			return 0;
		}
	}
	p[++k] = { n,m };
	for (int i = 1; i <= k; i++) {
		int D = p[i].x - p[i - 1].x;
		int R = p[i].y - p[i - 1].y;
		while (D--)printf("D");
		while (R--)printf("R");
	}
}