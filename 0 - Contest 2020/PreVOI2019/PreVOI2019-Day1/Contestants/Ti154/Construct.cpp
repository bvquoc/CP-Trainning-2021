#include<bits/stdc++.h>

using namespace std;

int a[1005],n,m,t;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++)
        {
            int ty,l,r,x;
            cin>>ty;
            if(ty==1)
            {
                cin>>l>>r>>x;
                for(int i=l;i<=r;i++) a[i]+=x;
            }
            else
            {
                cin>>l>>r;
                int id=0;
                int ans=0;
                for(int i=1;i<=n;i++)
                {
                    if(a[i]>=a[i-1]&&a[i]>=a[i+1])
                    {
                        ans+=a[i]-a[id];
                    }
                    if(a[i]<=a[i-1]&&a[i]<=a[i+1])
                    {
                        id=i;
                    }
                }
                cout<<ans<<'\n';
            }
        }
    }
}
