//用于O(1)计算一个数有多少位是1，需要预处理
#include<bits/stdc++.h>
using namespace std;
const int maxn = 65536 + 5;
int c[maxn];
void init()
{
	for (int i = 1; i < maxn; i++) {
		c[i] = c[i >> 1] + (i & 1);
	}
}
int pop_count(long long x)
{
	return c[x & 65536] + c[x >> 16 & 65536] + c[x >> 32 & 65536] + c[x >> 48];
}