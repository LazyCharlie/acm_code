#include<bits/stdc++.h>
using namespace std;
void seive(int n)
{
	vis[1]=1;
	for(int i=2;i<=n;i++){
		if (!vis[i])prime.push_back(i);
		for(int j=0;j<prime.size();j++){
			if (prime[j]*i>n)break;
			vis[prime[j]*i]=1;
			if (i%prime[j]==0)break;
		}
	}
}