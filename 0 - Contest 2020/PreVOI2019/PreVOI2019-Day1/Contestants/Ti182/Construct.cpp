#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1003];
int n,m;

void solve(int l,int r)
{
    ll kq=a[l];
    for(int i=l+1;i<=r;++i)
    {
        if(a[i]>a[i-1]) kq+=a[i]-a[i-1];
    }
    cout<<kq<<endl;
}
int main()
{
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    int q;
    cin>>q;
    while(q--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        while(m--)
        {
            int w;cin>>w;
            if(w==1)
            {
                int l,r; ll k;
                cin>>l>>r>>k;
                for(int i=l;i<=r;++i)
                {
                    a[i]+=k;
                }
            }
            else
            {
                int l,r;
                cin>>l>>r;
                solve(l,r);
            }
        }
    }
    return 0;
}
