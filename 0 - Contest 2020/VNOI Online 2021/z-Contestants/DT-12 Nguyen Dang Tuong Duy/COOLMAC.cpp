#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int N=100000;
int m,n,i,be,en,cnt;
ii p;
vector<ii> a;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    p.first=1e9;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int x;
        cin>>x;
        p.first=min(p.first,x);
    }
    p.second=N;
    sort(a.begin(),a.end());
    be=p.first;
    while (i<a.size()) {
        if (a[i].first>be) break;
        en=-1e9;
        while (i<a.size() && a[i].first<=be) {
            if (a[i].second>be) en=max(en,a[i].second);
            i++;
        }
        cnt++;
        if (en>=p.second) return cout<<cnt,0;
        be=en;
    }
    cout<<-1;
}
