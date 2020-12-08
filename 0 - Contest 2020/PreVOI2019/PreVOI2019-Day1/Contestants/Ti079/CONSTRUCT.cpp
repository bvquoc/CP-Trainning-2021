#include <bits/stdc++.h>
using namespace std;
long long MUL(long long A, long long B, long long MOD) {long long r = 0;while (B) {r = (r + (A * (B % 2) % MOD)) % MOD;A = (A + A) % MOD;B /= 2;}return r;}
long long POW(long long A, long long B, long long MOD) {long long RES = 1;A %= MOD;assert(B >= 0);for(; B; B >>= 1) {if (B & 1) RES = MUL(RES, A, MOD);A = MUL(A, A, MOD);}return RES;}
long long GCD(long long A, long long B) {return B == 0 ? A : GCD(B, A % B);}
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0,  0, 1, 0,-1};
#define __gcd GCD
#define in ({int x=0,n=0,c=getchar();for(;!isdigit(c);c=getchar())n=(c=='-');for(;isdigit(c);c=getchar())x=x*10+c-'0';(n)?-x:x;})
#define inc ({char c=0;for(;c=='\n'||c==' ';c=getchar());c=getchar();c;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define ii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define db double
#define vi vector <int>
#define vii vector <ii>
#define reset(f, val) memset(f, val, sizeof(f))
#define all(v) v.begin(), v.end()
#define bit(mask, i) (mask & (1ll << i))
#define onbit(mask, i) (mask | (1ll << i))
#define offbit(mask, i) (mask &~ (1ll << i))
#define sz(v) (int) v.size()
#define debug1(a) cout << #a << " = " << a << ";"
#define debug1l(a) cout << #a << " = " << a << ";" << '\n'
#define debug2(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; "
#define debug2l(a, b) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << '\n'
#define debug3(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; "
#define debug3l(a, b, c) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << '\n'
#define debug4(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << #d << " = " << d << "; "
#define debug4l(a, b, c, d) cout << #a << " = " << a << "; " << #b << " = " << b << "; " << #c << " = " << c << "; " << #d << " = " << d << "; " << '\n'
#define FASTIOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TASK "CONSTRUCT"
#define int long long

const int   oo = 1e18;
const int MAXN = 1e5 + 100;

int N, M;
int A[MAXN], H[MAXN];
int ST[4 * MAXN], lazy[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = A[l];
        lazy[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
    lazy[id] = 0;
}

void down(int id, int l, int r) {
    if (lazy[id] == 0) return;
    if (l != r) {
        int t = lazy[id];
        ST[id * 2] += t;
        lazy[id * 2] += t;

        ST[id * 2 + 1] += t;
        lazy[id * 2 + 1] += t;
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        ST[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    down(id, l, r);
    if (v < l || r < u) return +oo;
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v),
               get(id * 2 + 1, mid + 1, r, u, v));
}

int t;
main() {
	FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    cin >> t;
    while (t--) {
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) {
            cin >> A[i];
            H[i] = 0;
        }
        build(1, 1, N);

        for (int i = 1; i <= M; ++i) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r, k;
                cin >> l >> r >> k;
                update(1, 1, N, l, r, k);
            }
            else {
                int l, r;
                cin >> l >> r;
                for (int j = l; j <= r; ++j) {
                    A[j] = get(1, 1, N, j, j);
                    H[j] = 0;
                }
                int ok = 1, sum = 0, sl = 0;
                while (l <= r) {
                    int tmp = get(1, 1, N, l, r);
                    sum += tmp - H[l];
                    for (int j = l; j <= r; ++j)
                        H[j] = tmp;

                    if (H[l] < A[l]) {
                        int step = A[l] - H[l];
                        H[l] = A[l];
                        sum += step;
                        for (int j = l + 1; j <= r; ++j)
                            if (H[j] < A[j] && A[j] - H[j] >= 1) {
                                H[j] += step;
                            }
                            else break;
                    }
                    ++l;
                }
                cout << sum << '\n';
            }
        }
    }
	return 0;
}
