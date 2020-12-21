#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
const int maxN=2e5+5;
queue<pii> mem;
int m, n;
pii a[maxN];
bool comp(pii A, pii B){
    return ((A.fi==B.fi) ? (A.se>B.se) : (A.fi<B.fi));
}
int main()
{
    ifstream cin("COOLMAC.INP");
    ofstream cout("COOLMAC.OUT");
    cin >> m;
    for (int i=1; i<=m; ++i)
        cin >> a[i].fi >> a[i].se;
    cin >> n;
    int mins=maxN;
    for (int i=1; i<=n; ++i){
        int x;
        cin >> x;
        mins=min(mins, x);
    }

    sort(a+1, a+m+1, comp);

    int maxs=-1;
    mem.push({mins, 0});
    for (int i=1; i<=m; ++i){
        if (a[i].se<=maxs) continue;

        while (mem.size() && mem.front().fi<a[i].fi) mem.pop();
        if (mem.size()==0) break;
        if (a[i].se>mins) mem.push({a[i].se, mem.front().se+1});
        else mem.push({a[i].se, 1});
        maxs=a[i].se;
    }
    if (maxs<100000) cout << -1;
    else{
        cout << mem.back().se;
    }
    return 0;
}
