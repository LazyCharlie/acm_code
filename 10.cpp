#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
long long M, N, L;
struct node {
	long long a, t;
	bool operator<(const node&rhs)const {
		return a > rhs.a;
	}
};
node p[1000006];
int main()
{
	scanf("%lld", &M);
	while (M--) {
		scanf("%lld%lld", &N, &L);
		for (int i = 0; i < N; i++) {
			scanf("%lld%lld", &p[i].a, &p[i].t);
		}
		sort(p, p + N);
		L *= 1000;
		double run = 0, cur = 0, t = 0;
		for (int i = 0; i < N; i++) {
			double nxt = cur + p[i].t / 1000000.0*p[i].a;
			double dis = (nxt + cur) / 2.0*p[i].t / 1000000.0;
			if (run + dis + eps >= L) {
				t += (sqrt(cur*cur + 2.0*p[i].a*(L - run)) - cur) / (p[i].a*1.0);
				run = L;
				break;
			}
			else {
				t += p[i].t / 1000000.0;
				cur = nxt;
				run += dis;
			}
		}
		if (run + eps < L) {
			t += (L - run) / cur;
		}
		printf("%.10lf\n", t);
	}
}