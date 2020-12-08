#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 100005

using namespace std;
int t,n,m,a[maxn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        while(m--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int l,r,k;
                cin>>l>>r>>k;
                for(int i=l;i<=r;i++)
                    a[i]+=k;
            }
            else
            {
                int l,r,res=0;
                cin>>l>>r;
                if(l==r)
                {
                    cout<<a[l]<<'\n';
                    continue;
                }
                int pre=0;
                for(int i=l;i<r;i++)
                {
                    while(a[i]<=a[i+1]&&i<r)
                        i++;
                    res=res+a[i]-pre;
                    pre=a[i+1];
                }
                cout<<res<<'\n';
            }
        }
    }
}
