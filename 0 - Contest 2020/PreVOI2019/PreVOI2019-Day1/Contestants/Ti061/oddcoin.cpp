/** Hien Jeony **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) (n^(1<<(i-1)))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))
const int mod=1e9+7;
using namespace std;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
ll n,a[200010],b[200010],t,x,test,res=0;
int np[500010];
void check(){
    ll tg=t;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(np[i]==1){
            ans+=tg/a[i];
            tg%=a[i];
        }
    }
    if(tg==0)
        res=min(res,ans);
}
void duyet(int k){
    if(k>n){
        check();
        return ;
    }
    for(int i=0;i<=1;i++)
    {
        np[k]=i;
        duyet(k+1);
    }
}
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    read(test);
    b[1]=50000;
    b[2]=30000;
    b[3]=10000;
    b[4]=5000;
    b[5]=3000;
    b[6]=1000;
    b[7]=500;
    b[8]=300;
    b[9]=100;
    b[10]=50;
    b[11]=30;
    b[12]=10;
    b[13]=5;
    b[14]=3;
    b[15]=1;
    n=16;
    while(test--){
        read(x); read(t);
        res=LLONG_MAX;
        b[n]=x;
        for(int i=1;i<=n;i++)
            a[i]=b[i];
        sort(a+1,a+n+1,greater<ll> ());
//        for(int i=1;i<=n;i++)
//            cout<<a[i]<<" ";
        duyet(1);
        write(res);
        putchar('\n');
    }
}
