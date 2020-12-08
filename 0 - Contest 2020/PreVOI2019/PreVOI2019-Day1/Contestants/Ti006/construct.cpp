#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    int t,m,n,a[10009],l,r,k,c;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        for (int i=1;i<=m;i++)
        {
            cin>>c;
            if (c==1)
            {
                cin>>l>>r>>k;
                for (int z=l;z<=l;z++)a[z]+=k;
                sort(a+1,a+n+1);
            }
            else
            {
                cin>>l>>r;
                cout<<a[r]<<"\n";
            }
        }
    }
    return 0;
}
