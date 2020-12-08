#include<bits/stdc++.h>
#define name "oddcoin"
#define input  freopen(name".inp","r",stdin)
#define output freopen(name".out","w",stdout)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rev(i,a,b) for(int i=a;i>=b;--i)
#define wipe(x) memset(x,0,sizeof(x))
#define sqr(x) ((x)*(x))
#define sz(x) (x.size())
#define pb push_back
#define pp pair<int,int>
#define x first
#define y second
#define ll int64_t
#define ld double
using namespace std;

const int maxn=1e6;
int test,d=0;
int arr[100], f[maxn];

void prep()
{
    int a=1,b=3,c=5;
    rep(i,1,5)
    {
        arr[++d]=a; a*=10;
        arr[++d]=b; b*=10;
        arr[++d]=c; c*=10;
    }
}

int main()
{
    input; output;
    scanf("%d",&test);
    prep();
    while(test--)
    {
        int x,t;
        scanf("%d %d",&x,&t);
        arr[++d]=x;
        rep(i,1,t) f[i]=1e9;
        rep(i,0,t-1) if(f[i]<1e9) rep(j,1,d) f[i+arr[j]]=min(f[i+arr[j]],f[i]+1);
        printf("%d\n",f[t]);
    }
}