#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define int long long
using namespace std;
const int N = 2e5+3, mod = 1e9+7;

int n, a[N], b[N];

void sub1()
{
    int res = 0;
    while(true)
    {
        forinc(i,1,n-1) if(a[i] > a[i+1])
        {
            swap(a[i], a[i+1]);
            res++;
        }
        bool sorted = 1;
        forinc(i,1,n-1) if(a[i] > a[i+1]) sorted = 0;
        if(sorted) break;
    }

    cout << res;
    exit(0);
}

void sub2()
{
    int gt = 1;
    forinc(i,1,n) gt = gt*i % mod;
    cout << gt * (n*(n-1)/4 % mod) % mod;
}

main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    bool s1 = 1;
    forinc(i,1,n) cin >> a[i];
    forinc(i,1,n)
    {
        cin >> b[i];
        if(a[i] != b[i]) s1 = 0;
    }
    if(s1) sub1();
    else sub2();
}
