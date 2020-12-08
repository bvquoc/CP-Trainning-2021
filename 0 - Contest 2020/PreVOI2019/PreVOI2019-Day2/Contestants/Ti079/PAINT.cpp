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
#define TASK "PAINT"

const int MAXN = 1e6 + 100;
int N;
char A[MAXN], B[MAXN];

void Subtask1() {
    int cur = 0;
    for (int i = 1; i <= N; ++i) {
        int type;
        char x, y;
        cin >> type;
        if (type == 1) {
            cin >> x;
            A[++cur] = x;
        }
        else {
            cin >> x >> y;
            for (int j = 1; j <= cur; ++j)
                if (A[j] == x) A[j] = y;
        }
    }

    for (int i = 1; i <= cur; ++i)
        cout << A[i];
}

vector <int> v[5000];

void Subtask2() {
    int cur = 0;
    for (int i = 1; i <= N; ++i) {
        int type;
        char x, y;
        cin >> type;
        if (type == 1) {
            cin >> x;
            ++cur;
            v[x].pb(cur);
        }
        else {
            cin >> x >> y;
            if (x == y) continue;
            for (auto h: v[x])
                v[y].pb(h);
            v[x].clear();
        }
    }

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        for (auto pos: v[ch]) {
            B[pos] = ch;
        }
    }

    for (int i = 1; i <= cur; ++i)
        cout << B[i];
}

main() {
	FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    cin >> N;
    if (N <= 10000) Subtask1();
    else
        Subtask2();
	return 0;
}
