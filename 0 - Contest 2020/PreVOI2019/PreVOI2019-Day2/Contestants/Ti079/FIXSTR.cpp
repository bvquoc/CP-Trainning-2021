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
#define TASK "FIXSTR"

string S;
string pre[1000 + 100];
int N, M;

int cal(int x, int y) {
    int open = 0, step = 0;
    for (int i = x; i <= y; ++i) {
        if (S[i] == ')') {
            if (open > 0) {
                open--;
            }
            else {
                ++step;
            }
        }
        else {
            ++open;
        }
    }
    return step + open;
}

void Subtask1() {
    for (int i = 1; i <= M; ++i) {
        char type;
        int x, y, k;
        cin >> type;
        if (type == 'C') {
            cin >> x;
            if (S[x] == '(') S[x] = ')';
            else S[x] = '(';
        }
        else
            if (type == 'Q') {
                cin >> x >> y;
                cout << cal(x, y) << '\n';
            }
        else
            if (type == 'U') {
                cin >> k;
                S = pre[k - 1];
            }
        pre[i] = S;
    }
}

struct DATA {
    int optimal;
    int open;
    int close;
    DATA(int opt, int o, int c) {
        optimal = opt;
        open = o;
        close = c;
    }
    DATA() {}
};

const int MAXN = 1e6 + 100;
DATA ST[4 * MAXN];

DATA operator + (DATA left, DATA right) {
    DATA res;
    int tmp = min(left.open, right.close);
    res.optimal = left.optimal + right.optimal + tmp;
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        if (S[l] == '(')
            ST[id] = DATA(0, 1, 0);
        else
            ST[id] = DATA(0, 0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

void update(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        if (ST[id].optimal == 0 && ST[id].open == 1
            && ST[id].close == 0)
            ST[id] = DATA(0, 0, 1);
        else
            ST[id] = DATA(0, 1, 0);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

DATA get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return DATA(0, 0, 0);
    if (u <= l && r <= v) return ST[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v)
            + get(id * 2 + 1, mid + 1, r, u, v);
}

void Subtask2() {
    build(1, 1, N);
    for (int i = 1; i <= M; ++i) {
        char type;
        int x, y, k;
        cin >> type;
        if (type == 'C') {
            cin >> x;
            update(1, 1, N, x, x);
        }
        else
        if (type == 'Q') {
            cin >> x >> y;
            int len = y - x + 1;
            DATA tmp = get(1, 1, N, x, y);
            cout << len - (tmp.optimal * 2) << '\n';
        }
    }
}

main() {
	FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    cin >> S;
    S = " " + S;
    pre[0] = S;
    N = S.size() - 1;
    cin >> M;
    if (N <= 1000 && M <= 1000)
        Subtask1();
    else
        Subtask2();
	return 0;
}
