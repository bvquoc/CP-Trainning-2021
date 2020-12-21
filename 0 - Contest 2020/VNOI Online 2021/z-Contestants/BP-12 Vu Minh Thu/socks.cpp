#include<bits/stdc++.h>
using namespace std;

ifstream fi("socks.inp");
ofstream fo("socks.out");

int const N = 5e5 + 5;

int n, q;
int light[N];
int cnt;

vector <vector<int> > adj;

void solve(){
    if(cnt > 1) fo << 1 << "\n";
    for(int i = 1; i <= q; ++i){
        int x;
        fi >> x;
        if(light[x] == 0){
            light[x] = 1;
            ++cnt;
        }
        else{
            light[x] = 0;
            --cnt;
        }
        if(cnt > 1) fo << 1 << "\n";
        else fo << 0 << "\n";
    }
}

int main(){
    fi >> n >> q;
    adj.resize(n + 1);
    for(int i = 1; i <= n; ++i) {
        fi >> light[i];
        cnt += light[i];
    }
    for(int i = 1; i < n; ++i){
        int u, v;
        fi >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve();
}
