#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1005;

int n, m, k, cur;
long long dist[MAX][MAX], r, l;
vector<long long> Edge[MAX];
long long  d[MAX][MAX];
int MatchX[MAX], Used[MAX];
bool DFS(int u, int val){
    if (Used[u] == cur) return 0;
    Used[u] = cur;
    for (int v : Edge[u])
        if (d[u][v] >= val)
            if (MatchX[v] == 0|| DFS(MatchX[v], val)){
                MatchX[v] = u;
                return 1;
            }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long  w;
            cin >> w;
            Edge[i].push_back(j), d[i][j] = w;
        }
    }
    l = 0, r = 1e9+5;
    while (l <= r){
        long long mid = (l + r) >> 1;
        memset(Used, 0,sizeof(Used));
        memset(MatchX, 0,sizeof(MatchX));
        long long  res = 0;
        for (cur = n; cur >= 1; cur--)
            res += DFS(cur, mid);
        if (res < n) r = mid - 1;
            else l = mid + 1;
    }
    cout << r;
    return 0;
}
