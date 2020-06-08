#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ii = pair <int,int>;
const int N = 502;
int k, a, b, m;
bool mark[N][N];
vector <int> sv[N];

void DFS(int x, int y) {
    mark[x][y] = true;
    if (y+1<N && x+1<N && !mark[x+1][y+1]) {
        sv[x+1].push_back(y+1);
        DFS(x+1,y+1);
    }
    if (x%k==0 && y%k==0 && !mark[x/k][y/k]) {
        sv[x/k].push_back(y/k);
        DFS(x/k,y/k);
    }

    for (int i=0;i<sv[y].size();i++) {
        int z = sv[y][i];
        if (!mark[x][z] && mark[y][z] && x!=z) {
            sv[x].push_back(z);
            DFS(x,z);
        }
    }
}

void init() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N;j++) {
            mark[i][j] = false;
        }
        sv[i].clear();
    }
}

int32_t main(void) {
    FastIO;
    freopen("SET.INP","r",stdin);
    freopen("SET.OUT","w",stdout);
    int T; cin >> T;
    if (T<=5) { // Sub 1, 2
        while (T--) {
            init();
            cin >> k >> a >> b;
            DFS(a,b);
            cin >> m;
            while (m--) {
                int p, q;
                cin >> p >> q;
                cout << (mark[p][q] ? "YES" : "NO") << "\n";
            }
        }
    }
    
    return 0;
}