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

#define Task "GIFT11"
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

typedef long long ll;

const int maxn = 1e5 + 5;
const ll MOD = 998244353;

int n, t;
vector <string> s[11];

void Read(int i){
    cin >> n;
    s[i].resize(n);
    for (int j = 0; j < n; ++ j){
        cin >> s[i][j];
    }
}

namespace Sub1{

    int p[11];

    void Solve(){
        for (int i = 1; i <= t; ++ i){
            n = s[i].size();
            for (int j = 0; j < n; ++ j)
                p[j] = j;
            int res = 0;
            do{
                int pos = 0;
                int sumodd = 0, sumeven = 0;
                for (int j = n - 1; j >= 0; -- j){
                    int u = p[j];
                    for (int h = (int)s[i][u].size() - 1; h >= 0; -- h){
                        ++ pos;
                        if (pos&1) sumodd += s[i][u][h] - '0';
                        else sumeven += s[i][u][h] - '0';
                    }
                }
                if ((MOD * 11 + sumodd - sumeven) % 11 == 0) ++ res;
            }while (next_permutation(p, p + n));
            cout << res << "\n";
        }
    }
}

namespace Sub2{

    void Solve(int pos){
        int res1 = 0, res2 = 0;
        ll ans = 1;
        for (int i = 0; i < (int)s[pos].size(); ++ i){
            for (int j = 0; j < (int)s[pos][i].size(); ++ j){
                if (j & 1) res2 += s[pos][i][j] - '0';
                else res1 += s[pos][i][j] - '0';
            }
            ans = (ans * (i + 1)) % MOD;
        }
        if ((MOD * 11 + res1 - res2) % 11 == 0) cout << ans << "\n";
        else cout << 0 << "\n";
    }

}

namespace Sub3{

    void Solve(int i){

    }

}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if(fopen(Task".inp", "r")){
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> t;
    int S = 0;
    for (int i = 1; i <= t; ++ i){
        Read(i);
        S += s[i].size();
    }
    if (S <= 8){
        Sub1::Solve();
    }
    else{
        for (int i = 1; i <= t; ++ i){
            bool sub2 = 1;
            bool sub3 = 1;
            for (int j = 0; j < (int)s[i].size(); ++ j){
                int u = s[i][j].size();
                if (u & 1) sub2 = 0;
                else sub3 = 0;
            }
            if (sub2) Sub2::Solve(i);
            else if (sub3) Sub3::Solve(i);
        }
    }
    return 0;
}
