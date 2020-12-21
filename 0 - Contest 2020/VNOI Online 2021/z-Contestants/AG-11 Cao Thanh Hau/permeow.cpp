#include<bits/stdc++.h>

using namespace std;

const int N=2*1e5+5;
const long long module=1e9+7;

int a[N], b[N];

void solve()
{
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>a[i];

    long long r=0;
    for (int i=1;i<=n;i++)
    {
        int p;
        for (p=1;p<=n;p++) if (a[p]==i) break;

        r+=(long long)p-i;
        r%=module;
        for (;p>i;p--) a[p]=a[p-1];
        a[i]=i;
    }
    cout<<r;
}

int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    solve();

    return 0;
}
