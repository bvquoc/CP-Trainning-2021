#include <bits/stdc++.h>

using namespace std;

const string TASK = "construct";

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) a.begin(), a.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second

vector<ll> diff_fen, val_fen;
vector<int> A;
void upd(vector<ll> &fen, int i, ll x)
{
    if (x == 0) return;
    for (; i < (int) fen.size(); i += i & (-i)) {
        fen[i] += x;
    }
}

ll get(vector<ll> &fen, int i)
{
    ll ans = 0;
    for (; i; i -= i & (-i)) {
        ans += fen[i];
    }
    return ans;
}

int main()
{
    freopen((TASK + ".inp").c_str(), "r", stdin);
    freopen((TASK + ".out").c_str(), "w", stdout);
//    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        diff_fen.assign(N + 2, 0);
        val_fen.assign(N + 2, 0);
        A.resize(N + 2);

        A[0] = A[N + 1] = 0;
        FOR(i, 1, N) scanf("%d", &A[i]);

        // initialize
        FOR(i, 1, N + 1) {
            if (A[i] > A[i - 1]) {
                upd(diff_fen, i, A[i] - A[i - 1]);
            }
            upd(val_fen, i, A[i] - A[i - 1]);
        }

        // solve
        while (M--) {
            int type, l, r, k;
            ll a, b;
            scanf("%d %d %d", &type, &l, &r);
            if (type == 1) {
                scanf("%d", &k);

                a = get(val_fen, l - 1), b = get(val_fen, l);
                upd(diff_fen, l, max(0ll, b + k - a) - max(0ll, b - a));

                a = get(val_fen, r), b = get(val_fen, r + 1);
                upd(diff_fen, r + 1, max(0ll, b - a - k) - max(0ll, b - a));

                upd(val_fen, l, k);
                upd(val_fen, r + 1, -k);
            } else {
                ll ans = get(val_fen, l) + (get(diff_fen, r) - get(diff_fen, l));
                printf("%lld\n", ans);
            }
        }
    }
}

/*
1
5 4
1 3 1 4 5
2 1 5
1 3 4 2
2 2 4
2 1 5
*/
