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

#define Task "COOLMAC"
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

const int maxn = 1e5 + 5;
const int maxc = 1e5;

int m, n;
pair <int, int> a[maxn];
int t[maxn];
int ret = inf;
int dq[maxn];
int r, l;

void Read(){
    cin >> m;
    for (int i = 1; i <= m; ++ i)
        cin >> a[i].F >> a[i].S;
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> t[i];
        ret = min(ret, t[i]);
    }
}

void Push(int i){
    if (r >= 1 && a[i].F >= a[dq[r]].F) return;
    if (r >= 1 && a[i].S < a[dq[r]].F){
        cout << -1;
        exit(0);
    }
    while (l <= r && a[dq[r-1]].F <= a[i].S) -- r;
    dq[++r] = i;
}

bool comp(pair <int, int> p, pair <int, int> q){
    if (p.S == q.S) return p.F > q.F;
    return p.S > q.S;
}

void Solve(){
    sort(a + 1, a + 1 + m, comp);
    l = 1, r = 0;
    a[0].F = 1e5;
    for (int i = 1; i <= m; ++ i){
        if (a[i].S >= ret && a[dq[r]].F > ret) Push(i);
    }
    if (a[dq[r]].F <= ret){
        cout << (r - l + 1);
        return;
    }
    cout << -1;
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
        Solve();
    }
    return 0;
}
