#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define forout(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pii pair<int,int>
#define fi first
#define se second
#define sz(s) (int)(s.size())
#define pb push_back
#define int long long
char inchar() {char c=getchar();while(c==' '||c=='\n') c=getchar();return c;}
#define inchar inchar()
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define bit(x,i) ((x>>i)&1)
#define batbit(x,i) (x|(1ll<<i))
#define tatbit(x,i) (x&~(1ll<<i))
#define task "PAINT"
using namespace std;
string s;
main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int cnt=0;
	forinc(i,1,n)
	{
	    int x;
	    cin>>x;
	    if(x==1)
        {
            char u;
            cin>>u;
            s.push_back(u);
            cnt++;
        }
        else if(x==2)
        {
            char u,v;
            cin>>u>>v;
            forinc(j,0,cnt-1) if(s[j]==u)
            {
                s[j]=v;
            }
        }
	}
	cout<<s;

}
