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
set<int> s;
ll n,a[500010],h[500010],tg[500010],test,m,res;
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
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    read(test);
    while(test--){
        read(n);
        read(m);
        for(int i=1;i<=n;i++)
            read(a[i]);
        while(m--){
            int tt,l,r;
            read(tt); read(l); read(r);
            if(tt==1){
                ll x;
                read(x);
                for(int i=l;i<=r;i++){
                    a[i]+=x;
                }
            }
            else{
                res=0;
                for(int i=1;i<=n;i++){
                    h[i]=0;
                    if(i<l||i>r)
                        tg[i]=0;
                    else
                        tg[i]=a[i];
                }
                while(1){
                    int cnt=0;
                    for(int j=1;j<=n;j++){
                        int ok=0;
                        while(tg[j]>h[j]&&j<=n){
                            cnt++;
                            ok=1;
                            h[j]++;
                            j++;
                        }
                        res+=ok;
                        if(ok==1)
                            j--;
                    }
                    if(cnt==0)
                        break;
                }
                write(res);
                putchar('\n');
            }

        }
    }
}
