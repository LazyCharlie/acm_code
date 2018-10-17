typedef long long LL;
//扩展欧几里德递归实现 版本1
void exgcd(LL a, LL b, LL& g, LL& x, LL& y)
{
	if (!b) g = a, x = 1, y = 0;
	else exgcd(b, a%b, g, y, x), y -= x * (a / b);
}

//扩展欧几里德递归实现  版本2
//求(x,y),满足 a*x+b*y==1。返回值r即gcd(a,b)的值
int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a%b, x, y);
    int t = y;
    y = x - (a/b) * y;
    x = t;
    return r;
}

//扩展欧几里德的非递归实现，返回值表示gcd(m,n); 
int exgcd(int m, int n, int &x, int &y) {
    if (n == 0) {
        x = 1; y = 0;
        return m;
    }
    int a, a1, b, b1, c, d, q, r, t;
    a1 = b = 1;
    a = b1 = 0;
    c = m; d = n;

    q = c/d; r = c%d;
    while (r) {
        c = d;
        d = r;
        t = a1;
        a1 = a;
        a = t - q * a;
        t = b1;
        b1 = b;
        b = t - q * b;

        q = c/d;
        r = c%d;
    }
    x = a; y = b;
    return d;
} 