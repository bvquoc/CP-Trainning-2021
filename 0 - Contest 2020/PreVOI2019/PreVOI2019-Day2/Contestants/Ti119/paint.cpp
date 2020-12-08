#include<bits/stdc++.h>
#define name "paint"
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

const int maxn=1e6+5;
int n, d=0;
char a[maxn];

int main()
{
    input; output;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    while(n--)
    {
        int id;
        char x,y;
        cin>>id>>x;
        if(id==1) a[++d]=x;
        else
        {
            cin>>y;
            rep(i,1,d) if(a[i]==x) a[i]=y;
        }
    }
    rep(i,1,d) cout<<a[i];
}