#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int K[maxn];
void init()
{
	int c = 0;
	for (int i = 1; i < maxn; i++) {
		if ((1 << (c + 1)) <= i)c++;
		K[i] = c;
	}
}
struct RMQ {
	int a[maxn], n;
	int d[maxn][25];
	void clear() { n = 0; }
	void RMQ_init()
	{
		for (int i = 0; i < n; i++)d[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	int query(int L, int R)
	{
		int k = K[R - L + 1];
		return min(d[L][k], d[R - (1 << k) + 1][k]);
	}
};

