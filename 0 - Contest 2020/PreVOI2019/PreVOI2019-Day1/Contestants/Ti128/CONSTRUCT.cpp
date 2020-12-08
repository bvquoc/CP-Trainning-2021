#include <bits/stdc++.h>

using namespace std;

int n,m,a[1001],cur[1001],s;

void query()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    for (int i=1; i<=m; ++i)
    {
        int q; cin>>q;
        if (q==1)
        {
            int l,r,k;
            cin>>l>>r>>k;
            for (int i=l; i<=r; ++i)
                a[i]+=k;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            s=a[l];
            for (int i=l+1; i<=r; ++i)
            {
                if (a[i]-a[i-1]>0)
                    s+=a[i]-cur[i]-a[i-1]+cur[i-1];
            }
            cout<<s<<'\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);

    int t; cin>>t;
    while (t--)
        query();

    return 0;
}
