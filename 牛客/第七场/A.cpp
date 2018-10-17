#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
using namespace std;
int n;
int ans[500006];
int main()
{
    scanf("%d", &n);
    memset(ans, -1, sizeof(ans));
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] < 0) {
            int tmp = 1, cnt = 0;
            while (tmp - 1 < i)tmp *= 2;
            ans[i] = tmp - 1 - i;
            ans[ans[i]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i], i + 1 == n ? '\n' : ' ');
    }
}