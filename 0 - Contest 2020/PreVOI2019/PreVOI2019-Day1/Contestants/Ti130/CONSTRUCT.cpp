#include<bits/stdc++.h>
#define int long long
using namespace std;
int h[100000],a[100000];
main()
{
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        while(m--)
        {
            int x;
            cin>>x;
            if(x==1)
            {
                int l,r,k;
                cin>>l>>r>>k;
                for(int i=l;i<=r;i++)a[i]+=k;
            }
            if(x==2)
            {
                int l,r;
                cin>>l>>r;
                for(int i=l;i<=r;i++)
                {
                    h[i]=a[i];
                }
                r++;
                h[r]=0;
                int dem=0;
                while(1)
                {
                    bool check=0;
                    for(int i=l;i<=r;i++)
                    {
                        if(h[i]!=0)
                        {
                            check=1;
                            break;
                        }
                    }
                    int minn=1e18,chot=l-1;
                    if(check==0)
                    {
                        cout<<dem<<'\n';
                        break;
                    }
                    for(int i=l;i<=r;i++)
                    {
                        if(h[i]==0)
                        {
                            for(int j=i-1;j>chot;j--)
                            {
                                h[j]-=minn;
                            }
                            if(minn!=1e18)dem+=minn;
                            chot=i;
                            minn=1e18;
                        }
                        else minn=min(minn,h[i]);
                    }
                }
            }
        }
    }
}
