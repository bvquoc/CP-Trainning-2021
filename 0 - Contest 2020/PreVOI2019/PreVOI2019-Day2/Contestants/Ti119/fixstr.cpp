#include<bits/stdc++.h>
#define name "fixstr"
#define input  freopen(name".inp","r",stdin)
#define output freopen(name".out","w",stdout)
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rev(i,a,b) for(int i=a;i>=b;--i)
#define wipe(x) memset(x,0,sizeof(x))
#define sqr(x) ((x)*(x))
#define sz(x) (x.size()-1)
#define pb push_back
#define pp pair<int,int>
#define x first
#define y second
#define ll int64_t
#define ld double
using namespace std;

const int maxn=1e3+5;
int m;
string s[maxn];

int main()
{
    input; output;
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>s[0]>>m;
    rep(i,1,m)
    {
        s[i]=s[i-1];
        char id;
        int x,y;
        cin>>id>>x;
        --x;
        if(id=='U') s[i]=s[x];
        if(id=='C') if(s[i][x]=='(') s[i][x]=')';
                    else s[i][x]='(';
        if(id=='Q')
        {
            cin>>y;
            int d=0, res=0;
            rep(j,x,y-1) if(s[i][j]=='(') ++d;
            else
            {
                --d;
                if(d<0) ++d, ++res;
            }
            cout<<res+d<<'\n';
        }
    }
}