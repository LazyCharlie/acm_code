//普通快读，w为符号，s为绝对值
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<='0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
//fread快读
struct ios {
    inline char read(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }

    template <typename _Tp> inline ios & operator >> (_Tp&x){
        static char c11,boo;
        for(c11=read(),boo=0;!isdigit(c11);c11=read()){
            if(c11==-1)return *this;
            boo|=c11=='-';
        }
        for(x=0;isdigit(c11);c11=read())x=x*10+(c11^'0');
        boo&&(x=-x);
        return *this;
    }
} io;


---------------------
作者：DimitryL 
来源：CSDN 
原文：https://blog.csdn.net/qq_40515553/article/details/80732719?utm_source=copy 
版权声明：本文为博主原创文章，转载请附上博文链接！
