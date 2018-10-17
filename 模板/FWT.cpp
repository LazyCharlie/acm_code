void FWT(int a[],int n)  
{  
    for(int d=1;d<n;d<<=1)  
        for(int m=d<<1,i=0;i<n;i+=m)  
            for(int j=0;j<d;j++)  
            {  
                int x=a[i+j],y=a[i+j+d];  
                //a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;  
                //xor:
				a[i+j]=x+y,a[i+j+d]=(x-y+mod)%mod;  
                //and:a[i+j]=x+y;  
                //or:a[i+j+d]=x+y;  
            }  
}  
  
void UFWT(int a[],int n)  
{  
    for(int d=1;d<n;d<<=1){
		for(int m=d<<1,i=0;i<n;i+=m) { 
            for(int j=0;j<d;j++)  
            {  
                int x=a[i+j],y=a[i+j+d];  
                //a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
				//xor:
                a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
                //and:a[i+j]=x-y;  
				//or:a[i+j+d]=y-x;  
			}
		}  
	}
	
}  
void solve(int a[],int b[],int n)  
{  
	//求解C[i]=segma(j^k==i?a[j]*b[k]:0),时间复杂度nlogn 
	//可用于求解n个数两两异或能得到哪些数,c[i]!=0表示该数能求解得到。
    FWT(a,n);  
    FWT(b,n);  
    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;  
    UFWT(a,n);  
}  
