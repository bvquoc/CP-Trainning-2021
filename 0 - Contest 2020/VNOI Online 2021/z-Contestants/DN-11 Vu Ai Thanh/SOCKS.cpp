// i'm wutan
#include <bits/stdc++.h>
#define io_faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define EL cout<<'\n'
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "SOCKS"

using namespace std;
typedef long long ll;
typedef double db;

void file(){
#ifndef ONLINE_JUDGE
    freopen(PROB".inp","r",stdin);
    freopen(PROB".out","w",stdout);
#endif
}

const int N = 5e5 + 2;
int n, q, deg[N], c[N], in[N];
bool vis[N];
vector < vector < int > > a;
int nhanh[N];

void readinp(){
    cin >> n >> q;
    a.resize(n + 1);
    FU(i, 1, n) cin >> c[i];
    FU(i, 2, n){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
}

bool sub1(){
    FU(i, 1, n) if (deg[i] > 2) return false;
    return true;
}

bool sub2(){
    FU(i, 1, n) if (deg[i] > 3) return false;
    return true;
}

void solve(){
    if (sub1()){
        int cnt = 0;
        FU(i, 1, n) cnt+= c[i];
        while (q--){
            int u; cin >> u;
            if (c[u] == 0) cnt++;
            else cnt--;
            c[u] = 1 - c[u];
            if (cnt >= 2) cout << 1;
            else cout << 0;
            EL;
        }
    }
    else if (sub2()){
        int root = 0;
        FU(i, 1, n) if (deg[i] == 3) root = i;
        vis[root] = true;
        int nh = 0;
        for (auto v : a[root]){
            nh ++;
            queue < int > Q;
            Q.push(v); vis[v] = true;
            while (!Q.empty()){
                int u = Q.front();
                Q.pop();
                in[u] = nh;
                for (auto ke : a[u]){
                    if (!vis[ke]){
                        vis[ke] = true;
                        Q.push(ke);
                    }
                }
            }
        }

        while (q--){
            int u; cin >> u;
            if (c[u]) nhanh[in[u]]--;
            else nhanh[in[u]]++;
            c[u] = 1 - c[u];
            int t = 0;
            t+= (nhanh[1] != 0);
            t+= (nhanh[2] != 0);
            t+= (nhanh[3] != 0);

            if (t == 0) cout << 0;
            else if (t <= 2) cout << 1;
            else cout << 2;
            EL;
        }
    }

}

int main(){
    io_faster
    file();
    int t = 1;
//    cin >> t;
    while (t--){
        readinp();
        solve();
    }
}


