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
#define TASK "ODDCOIN"

const int oo = 1e9 + 7;
int qu, x, t, ANS_Sub1;
int A[1000], B[1000];

void W() {
    int sum = 0, sl = 0;
    for (int i = 0; i <= 4; ++i) {
        sum += A[i] * B[i];
        sl += B[i];
    }
    if (sum == t) {
        ANS_Sub1 = min(ANS_Sub1, sl);
    }
}

void Try(int i) {
    for (int j = 0; j <= t / A[i]; ++j) {
        B[i] = j;
        if (i == 4) W(); else Try(i + 1);
    }
}

void Subtask1() {
    ANS_Sub1 = +oo;
    Try(0);
    cout << ANS_Sub1 << '\n';
}

int f[17][100000 + 100];

int solve(int i, int sum) { // 16
    if (i == 16) {
        if (sum == 0) return 0;
        else return +oo;
    }
    if (f[i][sum] != -1) return f[i][sum];
    int cur = +oo;
    for (int sl = 0; sl <= sum / A[i]; ++sl) {
        if (sum - A[i] * sl >= 0) {
            cur = min(cur, solve(i + 1, sum - A[i] * sl)
                      + sl);
        }
    }
    return f[i][sum] = cur;
}

void Subtask1_1() {
    for (int i = 0; i <= 16; ++i)
        for (int j = 0; j <= t + 1; ++j)
            f[i][j] = -1;
    cout << solve(0, t) << '\n';
}

int dp[10000000 + 100];
void Subtask2() {
    dp[0] = 0;
    for (int i = 1; i <= t; ++i) {
        dp[i] = +oo;
        for (int j = 0; j <= 15; ++j)
            if (A[j] <= i)
                dp[i] = min(dp[i], dp[i - A[j]] + 1);
    }
    cout << dp[t] << '\n';
}

main() {
	FASTIOS;
#ifndef ONLINE_JUDGE
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif

    A[1] = 1;
    A[2] = 3;
    A[3] = 5;
    A[4] = 10;
    A[5] = 30;
    A[6] = 50;
    A[7] = 100;
    A[8] = 300;
    A[9] = 500;
    A[10]= 1000;
    A[11]= 3000;
    A[12]= 5000;
    A[13]= 10000;
    A[14]= 30000;
    A[15]= 50000;

    cin >> qu;
    for (int i = 1; i <= qu; ++i) {
        cin >> x >> t;
        A[0] = x;
        if (x <= 20 && t <= 20) {
            Subtask1_1();
        }
        else
            Subtask2();
    }
	return 0;
}
