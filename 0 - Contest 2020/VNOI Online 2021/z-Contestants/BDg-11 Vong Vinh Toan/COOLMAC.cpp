#include <bits/stdc++.h>

using namespace std;

struct Seg
{
    int l, r;

    void read()
    {
        cin>>l>>r;
    }

    bool operator < (Seg a)
    {
        return r > a.r;
    }
};

const int N = 1e5+7;

int n, m, t, ans;
Seg B[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    cin>>m;
    for(int i=1; i<=m; i++) B[i].read();
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(i==1) t = x;
        t = min(t, x);
    }
    B[++m] = {-1, t};
    sort(B+1, B+1+m, [&](Seg a, Seg b){if(a.l==b.l) return a.r>b.r; return a.l<b.l;});
    //for(int i=1; i<=m; i++) cout<<B[i].l<<" "<<B[i].r<<"\n";
    int Max = -1;
    int i = 1;
    while(i<=m)
    {
        int tmp = Max;
        while(i<=m && B[i].l <= Max)
        {
            tmp = max(tmp, B[i].r);
            i++;
        }
        if(tmp == Max)
        {
            cout<<"-1";
            return 0;
        }
        Max = tmp;
        ans++;
    }
    if(Max!=100000) cout<<"-1";
    else cout<<ans-1;
    return 0;
}
