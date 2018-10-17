#include<bits/stdc++.h>
int f[100006];//失配转移函数,f[i]表示如果第i个失配应该转移到哪里
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
int KMP(const char *S, const  char *T, int *f)
{
	getFail(T, f);
	int ans = 0, sn = strlen(S), tn = strlen(T),j = 0;
	for (int i = 0, j = 0; i < sn; i++)
	{
		while (j&&S[i] != T[j])j = f[j];
		if (S[i] == T[j])j++;
		if (j == tn)ans++;//j=0 表示不考虑重叠串 printf("%d\n",i-m+1);
	}
	return ans;
}
