#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+7, p = 1e9+7;

bool issub1 = 1, issub2 = 1;

int n, a[N], b[N], d[N];

void sub1()
{
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        d[i] = 1;
    }
    for(int i=1; i<=n; i++)
    {
        d[a[i]] = 0;
        for(int j=1; j<a[i]; j++)
            ans += d[j];
    }
    cout<<ans;
    exit(0);
}

void sub2()
{
    long long ans = 0;
    for(long long i=2, gt=1; i<=n; i++, gt = (gt*(i-1))%p)
    {
        ans = ((ans*i)%p+(gt*((i-1)*i/2)%p)%p)%p;
    }
    cout<<ans;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        issub1 &= a[i] == b[i];
        issub2 &= a[i] == i;
        issub2 &= b[i] == n-i+1;
    }
    if(issub1) sub1();
    if(issub2) sub2();
    return 0;
}
