#include<bits/stdc++.h>
using namespace std;
int n;
int s[1 << 19];
long long ans[1 << 18], st[20];
long long res = 0;
void dfs(vector<int>&S, int x)
{
    if (S.size() == 1) {
        if (S[0])ans[x]++;
        return;
    }
    vector<int>res;
    for (int i = 0; i < S.size(); i += 2) {
        res.push_back(S[i] ^ S[i + 1]);
    }
    dfs(res, x);
    res.clear();
    for (int i = 0; i < S.size(); i += 2) {
        res.push_back(S[i] & S[i + 1]);
    }
    dfs(res, x);
    res.clear();
    for (int i = 0; i < S.size(); i += 2) {
        res.push_back(S[i] | S[i + 1]);
    }
    dfs(res, x);
}
void init()
{
    int p = 16;
    for (int i = 0; i < (1 << 16); i++) {
        vector<int>S;
        for (int j = 15; j >= 0; j--) {
            S.push_back((i >> j) & 1);
        }
        dfs(S, i);
    }
}
void dfs2(vector<int>&S, int n)
{
    if (n == 4) {
        int x = 0;
        for (int i = 0; i < 16; i++) {
            x = x * 2 + S[i];
        }
        res += ans[x];
        return;
    }
    if (n == 0) {
        if (S[0] == 1)res++;
        return;
    }
    vector<int>res;
    for (int i = 0; i < S.size(); i += 2) {
        res.push_back(S[i] ^ S[i + 1]);
    }
    dfs2(res, n - 1);
    res.clear();
    for (int i = 0; i < S.size(); i += 2) {
        res.push_back(S[i] & S[i + 1]);
    }
    dfs2(res, n - 1);
    res.clear();
    for (int i = 0; i < S.size(); i += 2) {
        res.push_back(S[i] | S[i + 1]);
    }
    dfs2(res, n - 1);
}
int main()
{
    init();
    scanf("%d", &n);
    vector<int>S;
    for (int i = 0; i < (1 << n); i++) {
        int x; scanf("%1d", &x);
        S.push_back(x);
    }
    dfs2(S, n);
    printf("%lld\n", res);
}