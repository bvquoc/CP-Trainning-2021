#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)#define onbit(x,i) (x|(1<<(i-1)))#define offbit(x,i) (x&~(1<<(i-1)))
const int N=1e6+5;
int n,m,dd[27][N],nx[27][N];
pii a[N];
int DFS(int i,int j)
{
    if(j==n+1) return i;
    if(dd[i][j]) return dd[i][j];
    return dd[i][j]=DFS(nx[i][j],j+1);
}
char gc()
{
    char c=getchar();
    while(c<'a'||c>'z') c=getchar();
    return c;
}
int main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    n=in;
    forinc(i,1,n)
    {
        int it=in;
        if(it==1) a[++m]={gc()-'a'+1,i};
        else
        {
            char a=gc(),b=gc();
            nx[a-'a'+1][i]=b-'a'+1;
        }
        forinc(j,1,26) if(!nx[j][i]) nx[j][i]=j;
    }
    forinc(i,1,m) cout<<char(DFS(a[i].fi,a[i].se)-1+'a');
}
