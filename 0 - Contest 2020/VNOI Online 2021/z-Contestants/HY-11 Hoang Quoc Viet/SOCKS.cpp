/* -> Written by <-
   -----------
  K_A_Z_A_M_A
  ___________|
  |    _    |
  |   (^_^)   |
  |  /( | )\  |
  |____|_|____|
    H O A N G
*/

#define Task "SOCKS"
#define F first
#define S second
#define push_back pb
#define bit(x, i) ((x >> i) & 1)
#define inf 1e9 + 7
#define INF 1e18 + 7

#define ckd iml

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

const int maxn = 5e5 + 5;

int n, q, a[maxn];
vector <int> ke[maxn];
bool sub1 = 1;

void Read(){
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i < n; ++ i){
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
        ke[v].pb(u);
        if ((int)ke[u].size() > 2) sub1 = 0;
        if ((int)ke[v].size() > 2) sub1 = 0;
    }
}

namespace Sub1{

    void Solve(){
        int dem = 0;
        for (int i = 1; i <= n; ++ i) dem += a[i];
        cout << (dem > 1) << "\n";
        for (int i = 1; i <= q; ++ i){
            int x; cin >> x; a[x] = 1 - a[x];
            if (a[x] == 0) -- dem;
            else ++ dem;
            cout << (dem > 1) << "\n";
        }
    }
}

namespace Sub2{

    int cur;
    int dd[maxn];
    int dem[4];

    void dfs(int u, int cnt, int p){
        for (auto v : ke[u])
            if (v != p){
                if (u == cur) ++ cnt;
                dd[v] = cnt;
                dfs(v, cnt, u);
            }
    }

    void Solve(int pos){
        cur = pos;
        dfs(pos, 0, -1);
        for (int i = 1; i <= n; ++ i){
            if (a[i]){
                dem[dd[i]] ++;
            }
        }
        pair <int, bool> cnt = {0, 0};
        for (int i = 1; i <= 3; ++ i)
            if (dem[i] >= 1){
                ++ cnt.F;
                if (dem[i] >= 2) cnt.S = 1;
            }
        if (cnt.F == 3){
            cout << 2 << "\n";
        }
        else if (cnt.F == 2){
            cout << 1 << "\n";
        }
        else if (cnt.F == 1) {
            if (cnt.S) cout << (cnt.S) << "\n";
            else{
                if (a[cur]) cout << 1 << "\n";
                else cout << 0 << "\n";
            }
        }
        else
            cout << 0 << "\n";
        for (int i = 1; i <= q; ++ i){
            int x; cin >> x;
            a[x] = 1 - a[x];
            if (a[x] == 0) dem[dd[x]] --;
            else dem[dd[x]] ++;
            cnt = {0, 0};
            for (int i = 1; i <= 3; ++ i)
                if (dem[i] >= 1){
                    ++ cnt.F;
                    if (dem[i] >= 2) cnt.S = 1;
                }
            if (cnt.F == 3){
                cout << 2 << "\n";
            }
            else if (cnt.F == 2){
                cout << 1 << "\n";
            }
            else if (cnt.F == 1) {
                if (cnt.S) cout << (cnt.S) << "\n";
                else {
                    if (a[cur]) cout << 1 << "\n";
                    else cout << 0 << "\n";
                }
            }
            else
                cout << 0 << "\n";
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if(fopen(Task".inp", "r")){
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    int test_case = 1;
//     cin >> test_case;
    while (test_case --){
        Read();
        if (sub1) Sub1::Solve();
        else{
            int sub2 = 0, dem = 0, pos;
            for (int i = 1; i <= n; ++ i)
                if ((int)ke[i].size() == 3){
                    ++ sub2;
                    pos = i;
                }
                else if ((int)ke[i].size() <= 2) ++ dem;
            if (sub2 == 1 && dem == n - 1) Sub2::Solve(pos);
        }
    }
    return 0;
}
