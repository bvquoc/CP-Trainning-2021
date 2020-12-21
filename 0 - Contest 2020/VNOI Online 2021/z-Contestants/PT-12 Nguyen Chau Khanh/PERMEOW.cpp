#include <bits/stdc++.h>

#define eps                     1e-9
#define endl                    '\n'
#define int                     long long
#define ll                      long long
#define double                  long double
#define ii                      pair <int, int>
#define fi                      first
#define se                      second
#define all(x)                  (x).begin(), (x).end()
#define BIT(mask, i)            ((mask) & (1ll << (i)))
#define ONBIT(mask, i)          ((mask) | (1ll << (i)))
#define OFFBIT(mask, i)         ((mask) &~ (1ll << (i)))
#define a(i, j)                 aa[((i) - 1) * (NumRow) + (j)]
#define ID(i, j)                (((i) - 1) * (NumRow) + (j))
#define CIDx(i)                 ((i) / (NumRow)) + ((i) % (NumRow) != 0)
#define CIDy(i)                 ((i) % (NumRow)) + ((i) % (NumRow) == 0) * (numRow)
#define Task "PERMEOW"

using namespace std;

const int INF  = 1e18;
const int MOD  = 1e9 + 7;
const int MAXN = 2 * 1e5 + 7;

int N;
int a[MAXN], b[MAXN];
vector <int> S, T;

bool Check(){
    for (int i = 1; i <= N; ++i){
        if (a[i] != b[i]) return false;
        if (a[i] != i) return false;
    }
    return true;
}

void solve(){
    for (int i = 1; i <= N; ++i) S.push_back(a[i]);
    for (int i = 1; i <= N; ++i) T.push_back(b[i]);

    int ans = 0;
    do {
        for (int i = 0; i < S.size(); ++i){
            for (int j = 0; j < i; ++j){
                ans += bool(S[j] > S[i]);
            }
        }
        if (S == T) break;
    }
    while (next_permutation(all(S)));
    cout << ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(Task".INP", "r", stdin);
    freopen(Task".OUT", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];
    if (Check()) cout << 0;
    else solve();
}
