#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
int T;
vector<int>prime;
vector<LL> p[65];
int vis[105], mu[105];
LL n;
void seive(int n)
{
    mu[1] = vis[1] = 1;
    for(int i = 2; i <= n; ++i) {
        if (!vis[i]) prime.push_back(i), mu[i] = -1;
        for(int j = 0; j < prime.size(); ++j) {
            if (prime[j]*i > n) break;
            vis[prime[j]*i] = 1;
            if (i % prime[j] == 0) { mu[i*prime[j]] = 0; break; }
            mu[prime[j]*i] = -mu[i];
        }
    }
}
void init()
{
    seive(100);
    for (LL i = 1; i <= 1000000LL; ++i){
        LL cur = i*i*i;
        for (int j = 3;j <= 62; ++j) {
            p[j].push_back(cur);
            //printf("%d %lld\n", j, cur);
            if (cur>INF/i)break;
            cur *= i;
        }
    }
    //for (int i = 0; i <= p[3].size(); ++i) printf("%lld\n", p[3][i]);
}
int main()
{
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        LL x = sqrt(n + 0.5);
        LL ans = mu[2]*(x - 1);
        for (int i = 3; i <= 60; ++i) {
            LL k = upper_bound(p[i].begin(), p[i].end(), n) - p[i].begin() - 1;
            //cout << k << endl;
            ans += k*mu[i];
        }
        printf("%lld\n", ans + n - 1);
    }
}
