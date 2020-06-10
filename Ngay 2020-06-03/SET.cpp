#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

using ii = pair <int,int>;
const int N = 502;
int k, a, b, m, d;
bool inS[N][N];
vector <int> sv[N];

void DFS(int x, int y) {
    inS[x][y] = true;
    if (y+1<N && x+1<N && !inS[x+1][y+1]) {
        sv[x+1].push_back(y+1);
        DFS(x+1,y+1);
    }
    if (x%k==0 && y%k==0 && !inS[x/k][y/k]) {
        sv[x/k].push_back(y/k);
        DFS(x/k,y/k);
    }

    for (int i=0;i<sv[y].size();i++) {
        int z = sv[y][i];
        if (!inS[x][z] && inS[y][z] && x!=z) {
            sv[x].push_back(z);
            DFS(x,z);
        }
    }
}

void init() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N;j++) {
            inS[i][j] = false;
        }
        sv[i].clear();
    }
}

vector <int> K;
bool check(int p, int q) {
    if (p>=q) return false;
    int dd = q-p;
    return (dd%d==0);
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
                cout << (inS[p][q] ? "YES" : "NO") << "\n";
            }
        }
    } else {  // Sub 1, 2, 3 (AC)
        while (T--) {
            cin >> k >> a >> b;
            d = b-a;
            for (int i=2;i<=sqrt(k);i++) {
                if (k%i == 0) { 
                    K.push_back(i);
                    if (k/i != i) {
                        K.push_back(k/i);
                    }
                }
            }
            while (d%k == 0) {
                d /= k;
            }
            for (int x:K) {
                while (d%x == 0) {
                    d /= x;
                }
            }
            cin >> m;
            while (m--) {
                int p, q;
                cin >> p >> q;
                cout << (check(p,q) ? "YES" : "NO") << "\n";
            }
            K.clear();
        }
    }
    
    return 0;
}