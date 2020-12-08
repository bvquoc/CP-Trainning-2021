#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Task "MINE"

using namespace std;
typedef long long ll;

const int mod = 1e6 + 3;
const int maxn = 405 + 5;

void add(int &a, int b)
{
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

int f[maxn][maxn][maxn];
int N, M;
int a[maxn], pref[maxn];

int solve(int pos, int bac, int last)
{
    int & res = f[pos][bac][last];
    if (res != -1) return res;
    if (pos == N + 1){
        return (bac == 0);
    }
    res = 0;
    if (bac - 1 >= 0){
        if (a[pos] - a[last] <= M && last != 0)
            add(res, solve(pos+1, bac-1, pref[last]));
    }
    pref[pos] = last;
    add(res, solve(pos + 1, bac + 1, pos));
    return res;
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> N >> M;
    N *= 2;
    for (int i=1; i<=N; ++i){
        cin >> a[i];
    }
    memset(f, -1, sizeof f);
    cout << solve(1, 0, 0);
}
