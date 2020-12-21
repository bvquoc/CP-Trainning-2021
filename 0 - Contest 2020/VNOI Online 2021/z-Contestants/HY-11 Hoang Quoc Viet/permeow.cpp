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

#define Task "permeow"
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

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;

int n;
int a[maxn], b[maxn];
bool sub1 = 1;
bool sub2 = 1;

void Read(){
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i){
        cin >> b[i];
        if (b[i] != a[i]) sub1 = 0;
        if (b[i] != n - a[i] + 1) sub2 = 0;
    }
}

namespace Sub1{

    ll res = 0;

    void Solve(){
        for (int i = 1; i <= n; ++ i){
            int pos = 0;
            if (a[i] == i) continue;
            for (int j = i + 1; j <= n; ++ j)
                if (a[j] == i){
                    pos = j;
                    break;
                }
            for (int j = pos; j > i; -- j){
                swap(a[j-1], a[j]);
                ++ res;
            }
        }
        cout << res;
    }

}

namespace Sub2{

    int p[maxn];

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
        if (sub1) Sub1::Solve();
        else if (sub2) Sub2::Solve();
    }
    return 0;
}
