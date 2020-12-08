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
#define task "ODDCOIN"
using namespace std;
const int N=100;
set<int >s;
int a[N]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	forinc(i,1,15) s.insert(a[i]);
	int cnt=15;
	forinc(i,1,n)
	{
	    int res=0;
	    int x,t;
	    cin>>x>>t;
	    a[++cnt]=x;
	    sort(a+1,a+cnt+1);
	    s.insert(x);
        if(s.count(t)==1)
        {
            cout<<1<<"\n";
        }
        else
        {
            int k=t;
            forout(j,cnt,1)
            {
                if(a[j]<=k)
                {
                    res+=k/a[j];
                    k%=a[j];
                }
                if(k==1) {res++;break;}
                if(k<=1) break;
            }
            forinc(j,2,res)
            {
                forinc(p,0,cnt) if((t-a[p])%j==0&&s.count((t-a[p])/j))
                {
                    if(a[p]==0) res=min(res,j);
                    else res=min(res,j+1);
                }
            }
            cout<<res<<"\n";
        }
	}
}
