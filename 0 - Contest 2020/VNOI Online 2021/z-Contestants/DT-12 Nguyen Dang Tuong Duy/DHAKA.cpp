#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> ii;
const long long oo=1e18;
const int N=1e5+5;
int n,m,k,l,ch,r,ma,s[N];
long long tmp,d[N];
vector<int> type[10];
vector<ii> a[N];
void nhap() {
    cin>>n>>m>>k>>l;
    if (k==1) ch=1;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        if (ch && s[i]==1 && r==0) r=i;
        for (int j=1;j<=s[i];j++) {
            int x;
            cin>>x;
            ma=max(ma,x);
            type[s[i]].push_back(x);
        }
    }
    for (int i=1;i<=m;i++) {
        int x,y;
        long long z;
        cin>>x>>y>>z;
        a[x].push_back(ii(z,y));
        a[y].push_back(ii(z,x));
    }
}
void dijkstra(int x, int y) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for (int i=1;i<=n;i++) d[i]=oo;
    d[x]=0;
    pq.push(ii(d[x],x));
    while (pq.size()) {
        int u=pq.top().second;
        long long du=pq.top().first;
        pq.pop();
        if (u==y) {
            d[y]=du;
            return;
        }
        for (ii v:a[u]) {
            if (d[v.second]>du+v.first) {
                d[v.second]=du+v.first;
                pq.push(ii(d[v.second],v.second));
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("DHAKA.INP","r",stdin);
    freopen("DHAKA.OUT","w",stdout);
    nhap();
    if (ma<l) return cout<<-1,0;
    if (l==0) {
        dijkstra(1,n);
        if (d[n]==oo) return cout<<-1,0;
        else return cout<<d[n],0;
    }
    else if (ch) {
        dijkstra(1,r);
        if (d[r]==oo) return cout<<-1,0;
        tmp=d[r];
        dijkstra(r,n);
        if (d[n]==oo) return cout<<-1,0;
        return cout<<tmp+d[n],0;
    }
}
