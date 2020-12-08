#include <bits/stdc++.h>

using namespace std;
int t,n,m,a[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        while (m--)
        {
            int q,x,y,k;
            cin>>q;
            if (q==2)
            {
                cin>>x>>y;
                int ans=a[x];
                for (int i=x+1;i<=y;i+=1)
                    if (a[i]>=a[i-1]) ans+=a[i]-a[i-1];
                cout<<ans<<'\n';
            }
            else
            {
                cin>>x>>y>>k;
                for (int i=x;i<=y;i++)
                    a[i]+=k;
            }
        }
    }
    return 0;
}
