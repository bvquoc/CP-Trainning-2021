#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define PB(x) push_back(x)
#define ll long long
#define oo 999999999
#define maxn 100005

using namespace std;

const ll MOD = 1e9 + 7;

struct state{
    int u,melon;
    state(){}
    state(int _u , int _melon){
    u = _u , melon = _melon;
    }



};
bool operator < (state a , state b){
        return a.u < b.u;
    }

#define pis pair<int,state>

vector<pii> ke[maxn];
int melon[maxn];
int n,m,k,l;
int res = oo;
vector<vi> d;

void dijkstra(){

    d.assign(n+1,vi(32,oo));
    priority_queue<pis , vector<pis> , greater<pis> > Q;
    d[1][melon[1]] = 0;
    Q.push(pis(0,state(1,melon[1])));
    while (!Q.empty()){
        int du = Q.top().F;
        int u = Q.top().S.u;
        int umelon = Q.top().S.melon;
        Q.pop();

        if (du != d[u][umelon]) continue;

        for (int i = 0 ; i < ke[u].size() ; i++){
            int v = ke[u][i].F;
            int w = ke[u][i].S;
            int c = umelon | melon[v];
            if (d[v][c] > d[u][umelon] + w){
                d[v][c] = d[u][umelon] + w;
                Q.push(pis(d[v][c], state(v,c)));
            }
        }
    }
}

int count1(int x){
    int res = 0;
    while (x){
        res += x & 1;
        x >>= 1;
    }
    return res;
}

int main()
{
    ifstream cin("DHAKA.inp");
    ofstream cout("DHAKA.out");
    cin >> n >> m >> k >> l;
    for (int i = 1 ; i <= n ; i++){
        int t;
        cin >> t;
        while (t--){
            int u;
             cin >> u;
             melon[i] |= (1 << (u-1));
        }
    }

    for (int i = 0 ; i < m ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        ke[u].push_back(pii(v,w));
        ke[v].push_back(pii(u,w));
    }

    dijkstra();

    for (int i = 0 ; i < 1 << k ; i++)
        if (count1(i) >= l) res = min(res,d[n][i]);


    if (res == oo) cout << -1;
     else cout << res;


    return 0;
}
