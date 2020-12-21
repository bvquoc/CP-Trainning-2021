// link:
#include <bits/stdc++.h>

#define task "DHAKA"
#define ll long long
#define f0(i, a, b) for(int i = (a); i <= (b); i++)
#define f1(i, a, b) for(int i = (a); i >= (b); i--)
#define pii pair<ll, int>
#define fi first
#define se second
#define MASK(i) (1ll << (i))
#define BIT(i, x) (((x) >> (i)) & 1ll)
#define turn_on(i, x) ((1ll << (i)) | (x))
#define turn_off(i, x) ((x) & ~(1ll << (i)))
#define __builtin_popcount __builtin_popcountll

//---------------DO NOT TRY---------------//
using namespace std;

const ll inf = 1e18 + 7;
const int mxN = 1e5 + 7;
int numVer, numEdge, numType, want;
vector<pii> adj[mxN];
int type[mxN];
void input(void){
    cin >> numVer >> numEdge >> numType >> want;
    int num, ele;
    f0(i, 1, numVer){
        cin >> num;
        if(num > 0)
        f0(j, 1, num){
            cin >> ele;
            if(BIT(ele, type[i]) == 0)
                type[i] = turn_on(ele, type[i]);
        }
    }
    int u, v;
    ll w;
    f0(i, 1, numEdge){
        cin >> u >> v >> w;
        adj[u].push_back(pii(w, v));
        adj[v].push_back(pii(w, u));
    }
}
//
ll dis[mxN];
void sub2(void){
    f0(i, 1, numVer){
        dis[i] = inf;
    }
    dis[1] = 0ll;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0ll, 1));
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        int u = top.se;
        if(dis[u] > top.fi) continue;
        if(adj[u].size() > 0)
        f0(i, 0, adj[u].size() - 1){
            int v = adj[u][i].se;
            ll w = adj[u][i].fi;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push(pii(dis[v], v));
            }
        }
    }
    if(dis[numVer] == inf) cout << -1;
    else cout << dis[numVer];
}
struct pvh{
    int ver;
    ll cost, state;
    pvh(){};
    pvh(int _ver, ll _cost, ll _state){
        ver = _ver, state = _state, cost = _cost;
    }
};
struct cmp{
    bool operator() (const pvh &a, const pvh &b){
        int tmpA = __builtin_popcount(a.state);
        int tmpB = __builtin_popcount(b.state);
        if(tmpA == tmpB)
            if(a.cost == b.cost) return a.ver < b.ver;
            else return a.cost > b.cost;
        else return tmpA < tmpB;
    }
};
bool Found = false;
int st[mxN];
void subFull(void){
    int mx = 0;
    f0(i, 1, numVer){
        dis[i] = inf;
    }
    dis[1] = 0ll;
    priority_queue<pvh, vector<pvh>, cmp> pq;
    pq.push(pvh(1, 0ll, 1ll*type[1]));
    while(!pq.empty()){
        pvh top = pq.top();
        pq.pop();
        int u = top.ver;
        if(u == numVer){
            if(__builtin_popcount(top.state) >= want){
                Found = true;
                continue;
            }
        }
        else
            if(dis[u] > top.cost) continue;
        if(adj[u].size() > 0)
        f0(i, 0, adj[u].size() - 1){
            int v = adj[u][i].se;
            ll w = adj[u][i].fi;
            if(v == numVer){
                if(Found == false){
                    ll newState = top.state | (1ll*type[v]);
                    mx = max(mx, __builtin_popcount(newState));
                    dis[v] = dis[u] + w;
                    pq.push(pvh(v, dis[v], newState));
                }
                else{
                    ll newState = top.state | (1ll*type[v]);
                    mx = max(mx, __builtin_popcount(newState));
                    if(dis[v] > dis[u] + w && (__builtin_popcount(newState)) >= want){
                        dis[v] = dis[u] + w;
                        pq.push(pvh(v, dis[v], newState));
                    }
                }
            }
            else{
            if(dis[v] > dis[u] + w){
                ll newState = top.state | (1ll*type[v]);
                mx = max(mx, __builtin_popcount(newState));
                dis[v] = dis[u] + w;
                pq.push(pvh(v, dis[v], newState));
            }
            }
        }
    }
    if(dis[numVer] == inf || mx < want) cout << -1;
    else cout << dis[numVer];
}
void solve(void){
    if(want == 0){
        sub2();
        return;
    }
    subFull();
}

int main(){
    //
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
    //
    input();
    solve();
}
