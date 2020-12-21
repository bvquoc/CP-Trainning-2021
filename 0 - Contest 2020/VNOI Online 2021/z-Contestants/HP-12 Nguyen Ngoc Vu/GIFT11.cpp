#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(i,x) for(auto &i:x)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r)
{
    return l+rng()%(r-l+1);
}
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define pii pair<int,int>
#define fi first
#define se second
#define batbit(i,x) (x|(1ll<<i))
#define getbit(i,x) ((x>>i)&1)

const int mn=2010,mod=998244353;
int n,a[mn],val[mn],sl[mn],res;

main()
{
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        forinc(i,1,n) val[i]=0;
        int ok=1;
        forinc(i,1,n)
        {
            int x;
            cin >> x;
            int tmp=0,cnt=0;
            while(x!=0)
            {
                tmp=tmp*10+x%10;
                x/=10;
                cnt++;
            }
            if(cnt%2) ok=0;
            x=tmp;
            cnt=0;
            while(x!=0)
            {
                cnt++;
                if(cnt%2) val[i]+=x%10;
                else val[i]-=x%10;
                x/=10;
            }
            sl[i]=cnt;
        }
        if(ok)
        {
            int tmp=0;
            forinc(i,1,n) tmp+=val[i];
            if(tmp%11==0)
            {
                res=1;
                forinc(i,1,n) res=(res*i)%mod;
                cout << res << "\n";
            }
            else cout << 0 << "\n";

        }
        else
        {
            forinc(i,1,n) a[i]=i;
            res=0;
            do
            {
                int dem=1,tmp=0;
                forinc(i,1,n)
                {
                    if(dem%2) tmp+=val[a[i]];
                    else tmp-=val[a[i]];
                    dem+=sl[a[i]];
                }
                if(tmp%11==0) res++;
            }while(next_permutation(a+1,a+n+1));
            cout << res%mod << "\n";
        }
    }
}
