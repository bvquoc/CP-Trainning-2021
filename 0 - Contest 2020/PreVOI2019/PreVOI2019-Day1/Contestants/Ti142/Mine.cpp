#include <bits/stdc++.h>

using namespace std;
const int mod=1000003;
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    cin>>n>>m;
    if (m>=1e6)
    {
        int ans=1;
        for (int i=1;i<=n-1;i++)
        {
            ans*=2;
            ans%=mod;
        }
        cout<<ans<<'\n';
    }
    else cout<<n-1<<'\n';
    return 0;
}
