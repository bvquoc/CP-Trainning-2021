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
#define task "FIXSTR"
using namespace std;
const int N=1001;
string s1[N];
int a[N],n;
string s;
int check(int u,int v)
{
    memset(a,0,sizeof a);
    forinc(i,u,v)
    {
        if(s[i]=='(') a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }
    int z=1;
    forinc(i,u,v) if(s[i]=='(') {z=i;break;}
    int cnt=0,tmp=0;
    forinc(i,u,v) if((i-u+1)>2*a[i]+cnt) cnt++;
    int v1=a[v]-a[u-1];
    int u1=v-z+1;
    cnt+=v1-(u1-v1)>0?v1-(u1-v1):0;
    return cnt;

}
main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
    n=s.size();
	s=' '+s;
	int m;
	cin>>m;
	forinc(i,1,m)
	{
	    s1[i]=s;
        char x;
        cin>>x;
        if(x=='C')
        {
            int u;
            cin>>u;
            if(s[u]==')') s[u]='(';
            else if(s[u]=='(') s[u]=')';
        }
        else if(x=='Q')
        {
            int u,v;
            cin>>u>>v;
            cout<<check(u,v)<<"\n";
        }
        else if(x=='U')
        {
            int u;
            cin>>u;
            s=s1[u];
        }
	}
}
