//计算phi(x) ,复杂度O(sqrt(n));
int euler_phi(int n)
{
	int m = (int)sqrt(n + 0.5);
	int ans = n;
	for (int i = 2; i <= m; i++)if (n%i == 0) {
		ans = ans / i * (i - 1);
		while (n%i == 0)n /= i;
	}
	if (n > 1)ans = ans / n * (n - 1);
	return ans;
}

//用类似方法以复杂度o(nloglogn)计算phi表
int phi[maxn];
void phi_table(int n)
{
	for(int i=2;i<=n;i++)if (!phi[i])
		for(int j=i;j<=n;j+=i){
			if (!phi[j])phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
}