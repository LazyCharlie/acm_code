#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL fpow(LL a,LL m,LL mod)
{
	LL ret=1;
	while (m){
		if (m&1)ret=ret*a%mod;
		a=a*a%mod;
		m>>=1;
	}
	return ret;
}