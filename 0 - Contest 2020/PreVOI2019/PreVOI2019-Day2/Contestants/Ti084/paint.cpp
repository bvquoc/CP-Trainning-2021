#include <bits/stdc++.h>
using namespace std;

//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;

typedef pair<int, int> ii;
typedef pair<long long, long long> ll;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

//emsiHD
#define file "paint"
#define fi first
#define se second
#define y1 Dinh
#define y0 Huy
#define yn Is
#define j1 Me
#define bit(mask, i) ((mask>>(i - 1))&1)

int nquery, n = 0;
int d[400][400], vis[400][400];
char c[N];
vector<pair<char, int> > v[300];

void InOut(){
    freopen (file ".inp", "r", stdin);
    freopen (file ".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void Solve(){
    cin >> nquery;

    for (int i = 'a'; i <= 'z'; i++) for (int j = 'a'; j <= 'z'; j++) vis[i][j] = -1;

    while(nquery--){
        int k;
        cin >> k;
        if (k == 1){
            char x;
            cin >> x;
            c[++n] = x;
            v[(int)x].push_back({x, n});
        } else {
            char x, y;
            cin >> x >> y;
            if (x == y) continue;
            v[(int)x].push_back({y, 0});
            vis[y][x] = v[(int)x].size() - 1;

            for (int i = 'a'; i <= 'z'; i++){
                if (i == (int)x || i == (int)y) continue;
                if (vis[(int)x][i] != -1) {
                    int pos = vis[(int)x][i];
                    cout << v[x][pos].fi << " " << y << "\n";
                    v[(int)i][pos].fi = y, v[(int)i][pos].se = 0;
                    vis[(int)y][i] = pos; vis[(int)x][i] = -1;
                }
            }
        }
    }

    for (int x = 'a'; x <= 'z'; x++) {
        int j = v[x].size() - 1;
        while (j >= 0 && v[x][j].se != 0) j--;
        if (j == -1) continue;
        char ch = v[x][j].fi;
        for (int k = j - 1; k >= 0; k--) {
            int pos = v[x][k].se;
            c[pos] = ch;
        }
    }
    for (int i = 1; i <= n; i++) cout << c[i];
}

main(){
    InOut();

    Solve();

}

