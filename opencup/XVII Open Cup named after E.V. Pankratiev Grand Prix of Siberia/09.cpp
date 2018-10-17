#include<bits/stdc++.h>
using namespace std;
int n, k;
priority_queue<int, vector<int>, less<int>>q;
priority_queue<int, vector<int>, greater<int>>p;
int x, y;
long long sum = 0;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (p.size() < k) {
			p.push(x);
			sum += x;
		}
		else q.push(x);
		while (q.size() && q.top() > p.top()) {
			x = q.top();
			y = p.top();
			sum += x - y;
			p.pop(); q.pop();
			p.push(x);
			q.push(y);
		}
		if (i + 1 >= k) {
			printf("%lld%c", sum, i + 1 == n ? '\n' : ' ');
		}
	}
}