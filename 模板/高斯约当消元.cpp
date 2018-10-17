const int maxn=100+10;
typedef double Matrix[maxn][maxn];
void gauss_jordan(Matrix A,int n)
{
	int i,j,k,r;
	for(i = 0;i<n;i++){
		r=i;
		for(j=i+1;j<n;j++)
			if (fabs(A[j][i])>fabs(A[r][i]))r=j;
		if (fabs(A[r][i])<eps)continue;//放弃这一行，直接处理下一行
		if (r!=i)for(j=0;j<=n;j++)swap(A[r][i],A[i][j]);
		
		//与除了第i行以外的行进行消元
		for(k=0;k<n;k++)if (k!=i)
			for(j=n;j>=i;j--)A[k][j]-=A[k][i]/A[i][i]*A[i][j];
	}
}