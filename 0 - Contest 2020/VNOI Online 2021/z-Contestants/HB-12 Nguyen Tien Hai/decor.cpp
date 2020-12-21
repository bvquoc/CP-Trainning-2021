#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int nmax=5e5+5;
int n, m, k, f[nmax], cnt=0;
char s[nmax];
vector <pii> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i)
    {
        cin >> s[i];
        if (s[i]=='0') cnt++;
        if (s[i]==s[i-1] && s[i]=='1') f[i] = f[i-1] + 1;
        else f[i]=1;
    }
    if (cnt == n) {cout<<"-1"; return 0;}
    if (cnt <= k) {cout<<1<<" "<<n; return 0;}
    for (int i=1; i<=m; ++i)
    {
        int u,v;
        cin>>u>>v;
        a.push_back({u,v});
    }
    if (m==0 && k==0)
    {
        cout << f[n];
        return 0;
    }
//    if (m==0)
//    {
//        sub2();
//        return 0;
//    }
    cout<<"-1";
    return 0;
}
