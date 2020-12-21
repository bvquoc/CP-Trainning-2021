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

#define Task "decor"
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

int n, m, k;
bool a[maxn];

void Read(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i){
        char ch; cin >> ch;
        a[i] = ch - '0';
    }
}

namespace Sub1{

    void Solve(){
        int cnt = 0;
        int res = 0;
        int l = 0, r = 0;
        for (int i = 1; i <= n + 1; ++ i){
            if (a[i] == 1) ++ cnt;
            else{
                if (res < cnt){
                    res = cnt;
                    l = i - cnt;
                    r = i - 1;
                }
                cnt = 0;
            }
        }
        if (res == 0){
            cout << -1;
            return;
        }
        cout << l << " " << r;
    }

}

namespace Sub2{

    int s[maxn];

    bool Check(int l, int r){
        int c = s[r] - s[l-1];
        if (c > k) return 0;
        return 1;
    }

    void Solve(){
        for (int i = 1; i <= n; ++ i){
            if (a[i] == 0) s[i] = s[i-1] + 1;
            else s[i] = s[i-1];
        }
        int res = 0, resL = 0, resR = 0;
        for (int i = 1; i <= n; ++ i){
            int l = 0, r = i + 1;
            while (r - l > 1){
                int mid = (l + r) >> 1;
                if (Check(mid, i))
                    r = mid;
                else
                    l = mid;
            }
            if (res < i - r + 1){
                res = i - r + 1;
                resL = r;
                resR = i;
            }
        }
        if (res == 0){
            cout << -1;
            return;
        }
        cout << resL << " " << resR;
    }
}

namespace Sub3{

    int Root[maxn], Rank[maxn];
    int dd[2005];

    int Get_Root(int u){
        if (Root[u] != u) Root[u] = Get_Root(Root[u]);
        return Root[u];
    }

    void Solve(){
        for (int i = 1; i <= n; ++ i){
            Root[i] = i;
            Rank[i] = a[i];
        }
        for (int i = 1; i <= m; ++ i){
            int u, v;
            cin >> u >> v;
            u = Get_Root(u);
            v = Get_Root(v);
            if (u > v) swap(u, v);
            Root[v] = u;
            Rank[u] += Rank[v];
        }
        int res = 0, resL = 0, resR = 0;
        for (int i = 1; i <= n; ++ i){
            int cnt = 0;
            memset(dd, 0, sizeof(dd));
            for (int j = i; j >= 1; -- j){
                if (a[j] == 0){
                    ++ cnt;
                    int c = Get_Root(j);
                    dd[c] ++;
                    int dem = cnt - min(dd[c], Rank[c]);
                    if (dem <= k){
                        if (res < i - j + 1){
                            res = i - j + 1;
                            resL = j;
                            resR = i;
                        }
                    }
                }
                else{
                    int c = Get_Root(j);
                    dd[c] --;
                }
            }
        }
        if (res == 0){
            cout << -1;
            return;
        }
        cout << resL << " " << resR;
    }

}

namespace Sub4{

    void Solve(){

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
        if (m == 0){
            if (k == 0) Sub1::Solve();
            else Sub2::Solve();
        }
        else{
            if (n <= 2000) Sub3::Solve();
            else Sub4::Solve();
        }
    }
    return 0;
}
