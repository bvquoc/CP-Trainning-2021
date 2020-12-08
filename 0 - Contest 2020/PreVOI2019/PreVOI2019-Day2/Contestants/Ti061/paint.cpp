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
int T,n,a[1000010],vt[30][1000010],xc[30];
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
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    read(T);
    n=0;
    while(T--){
        int x;
        read(x);
        if(x==1){
            char c;
            c=getchar();
            n++;
            a[n]=c-'a'+1;
            xc[a[n]]++;
            vt[a[n]][xc[a[n]]]=n;
         //   putchar(c);
          //  cout<<" "<<n<<" "<<a[n]<<" ";
         //   putchar('\n');
        }
        else{
            char c,d;
            c=getchar(); d=getchar();
            d=getchar();
            int x1,y;
         //   cout<<c<<" "<<d<<endl;
            x1=c-'a'+1;
            y=d-'a'+1;
        //   cout<<x1<<" "<<y<< endl;
            for(int i=1;i<=xc[x1];i++){
               // cout<<vt[x1][i]<<" ";
                xc[y]++;
               // cout<<xc[y]<<" "<<y<<"  ";
                vt[y][xc[y]]=vt[x1][i];
              //  cout<<vt[y][xc[y]]<<endl;
            }
            xc[x1]=0;
          //  cout<<endl;
        }
    }
    for(int i=1;i<=26;i++)
        for(int j=1;j<=xc[i];j++)
            a[vt[i][j]]=i;
    for(int i=1;i<=n;i++){
        char c=a[i]+'a'-1;
        putchar(c);
    }
}
