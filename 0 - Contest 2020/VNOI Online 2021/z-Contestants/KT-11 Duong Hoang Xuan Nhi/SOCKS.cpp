#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 5;

int n, q;
bool color[N];
vector<int> graph[N];

int dem[N];

namespace Sub1 {

int dem = 0;

void solve() {
    for(int i = 1; i <= n; ++i)
        dem += color[i];

    if(dem <= 1) cout << 0 << '\n';
    else cout << 1 << '\n';

    for(int i = 1; i <= q; ++i) {
        int x; cin >> x;
        if(color[x]) dem--;
        else dem++;

        color[x] = !color[x];

        if(dem <= 1) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
}

}//namespace Sub1

namespace Sub2 {



void solve() {
    for(int i = 1; i <= q; ++i) {
        int x; cin >> x;

        color[x] = !color[x];
    }
}

}//namespace Sub2

int main() {
#ifdef DN
    //freopen("in.txt", "r", stdin);
#endif
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> color[i];

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);

        dem[u] = graph[u].size();
        dem[v] = graph[v].size();
    }

    int x = 0, cnt = 0;
    for(int i = 1; i <= n; ++ i) {
        x = max(x, dem[i]);

        if(dem[i] == 3) cnt++;
    }

    if(x == 2)
        Sub1::solve();
    else if(x == 3 && cnt == 1)
        Sub2::solve();

    return 0;
}
/*
5 3
0 0 0 0 0
1 2
2 3
3 4
4 5
1
2
1


*/
