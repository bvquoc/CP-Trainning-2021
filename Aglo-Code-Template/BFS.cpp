#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector <vector<int>> a;
vector <bool> mark;
vector <int> T, res;

void ReadInput() {
    freopen("BFS.INP","r",stdin);
    cin >> n >> m >> s >> t;
    a.resize(n+1);
    mark.resize(n+1,false);
    T.resize(n+1);
    int u, v;
    for (int i=1;i<=m;i++) {
        cin >> u >> v;
        a[u].push_back(v);
    }
}
void BFS() {
    queue <int> q;
    q.push(s);
    T[s] = -1;
    mark[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: a[u]) 
        if(!mark[v]) {
            q.push(v);
            mark[v] = true;
            T[v] = u;
        }
    }
}
void WriteOutput() {
    freopen("BFS.OUT","w",stdout);
    while (t!=s) {
        res.push_back(t);
        t = T[t];
    } res.push_back(s);
    reverse(res.begin(),res.end());
    for (int i=0; i<res.size(); i++) 
        cout << res[i] << ' ';
}

int32_t main(void) {
    ReadInput();
    BFS();
    WriteOutput();
    return 0;
}