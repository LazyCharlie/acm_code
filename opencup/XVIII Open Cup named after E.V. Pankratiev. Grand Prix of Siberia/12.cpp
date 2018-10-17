#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int T, ok = 1;
int f1[maxn], f2[maxn];
char s1[maxn], s2[maxn], s3[maxn];
void getFail(const char *T, int *f)//KMP失配函数
{
	f[0] = 0; f[1] = 0;
	int m = strlen(T);
	for (int i = 1; i<m; i++)
	{
		int j = f[i];
		while (j&&T[i] != T[j])j = f[j];
		f[i + 1] = (T[i] == T[j]) ? j + 1 : 0;
	}
}
int KMP(int st, int i, const char *S, const  char *T, int *f)
{
	getFail(T, f);
	int sn = strlen(S), tn = strlen(T), j = 0;
	for (j = 0; i < sn; i++)
	{
		while (j&&S[i] != T[j])j = f[j];
		if (S[i] == T[j])j++;
		if (j == tn)return i + 1;//j=0 表示不考虑重叠串 printf("%d\n",i-m+1);
	}
	if (st)ok--;
	return i;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%s%s%s", s1, s2, s3);
		ok = 2;
		getFail(s2, f1);
		getFail(s3, f2);
		int s = KMP(0,0, s1, s2, f1);
		KMP(1,s, s1, s3, f2);
		s = KMP(0,0, s1, s3, f2);
		KMP(1,s, s1, s2, f1);
		printf(ok ? "YES\n" : "NO\n");
	}
}