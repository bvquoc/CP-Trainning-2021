#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, b, a) for (int i = b; i >= a; --i)
#define FORV(v, H) for (auto &v: H)

#define ii pair <int, int>
#define fi first
#define se second
#define ll long long

#define vi vector <int>
#define vii vector <ii>
#define pb push_back

#define reset(f, val) memset(f, val, sizeof(f))

#define MASK(i) (1ll << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) ((mask) | (1ll << (i)))
#define OFFBIT(mask, i) ((mask) &~ (1ll << (i)))

const int MAXN = 2005;
const int  MOD = 998244353;

int T, S = 0, N;
int A[MAXN];

string convertstr(int num) {
    string ans = "";
    while (num > 0) {
        int k = num % 10;
        ans = (char) (k + '0') + ans;
        num /= 10;
    }
    return ans;
}

namespace Subtask1 {
    int visit[MAXN], B[MAXN];
    int H1[MAXN], H2[MAXN];
    string S[20];
    string convertstr(int num) {
        string ans = "";
        while (num > 0) {
            int k = num % 10;
            ans = (char) (k + '0') + ans;
            num /= 10;
        }
        return ans;
    }

    int ANS = 0;

    void W() {
        int sum = 0, pos = 1;
        FOR(i, 1, N) {
            if (pos % 2) sum += H2[B[i]];
            else sum += H1[B[i]];
            pos += (int) S[B[i]].size();
//            cout << B[i] << ' ';
        }
        if (sum % 11) return;
        ++ANS;
//        FOR(i, 1, N) cout << S[B[i]];
//        cout << '\n';
    }

    void Try(int i) {
        FOR(j, 1, N) {
            if (visit[j]) continue;
            visit[j] = 1;
            B[i] = j;
            if (i == N) W();
            else Try(i + 1);
            visit[j] = 0;
        }
    }

    void SOLVE() {
        FOR(i, 1, N) {
            S[i] = convertstr(A[i]);
        }
        FOR(i, 1, N) {
            H1[i] = 0;
            H2[i] = 0;
            int k = -1;
            FOR(j, 0, (int) S[i].size() - 1) {
                H1[i] += (int) (S[i][j] - '0') * k;
                H2[i] -= (int) (S[i][j] - '0') * k;
                k *= -1;
            }
        }

//        FOR(i, 1, N) cout << i << ' ' << H1[i] << ' ' << H2[i] << '\n';
//        cout << '\n';
        ANS = 0;
        Try(1);
        cout << ANS % MOD << '\n';
    }
}

namespace Subtask2 {
#define int long long
    string S[MAXN];
    string convertstr(int num) {
        string ans = "";
        while (num > 0) {
            int k = num % 10;
            ans = (char) (k + '0') + ans;
            num /= 10;
        }
        return ans;
    }

    void SOLVE() {
        FOR(i, 1, N) {
            S[i] = convertstr(A[i]);
        }
        int sum = 0;
        FOR(i, 1, N) {
            int k = 1;
            FOR(j, 0, (int) S[i].size() - 1) {
                sum += (int) (S[i][j] - '0') * k;
                sum += 11 * 11;
                k *= -1;
            }
        }
        if (sum % 11 != 0) {
            cout << 0 << '\n';
            return;
        }
        int ANS = 1;
        FOR(i, 1, N) {
            ANS *= i;
            ANS %= MOD;
        }
        cout << ANS << '\n';
    }
#undef int
}

bool checkSubtask2() {
    FOR(i, 1, N) {
        if ((int) convertstr(A[i]).size() % 2) return 0;
    }
    return 1;
}

bool checkSubtask3() {
    FOR(i, 1, N) {
        if ((int) convertstr(A[i]).size() % 2 == 0) return 0;
    }
    return 1;
}

#define vi vector <int>
#define vvi vector <vi>
#define vvvi vector <vvi>

namespace Subtask3 {
    string S[MAXN];
    int H1[MAXN], H2[MAXN]; // H1 la cong vao vi tri le
    int END = 0;
//    int dp[MAXN][MAXN][12];
    vvvi dp;

    void FIXMOD(int &val) {
        if (val >= MOD) val -= MOD;
    }

    int solve(int i, int cnt, int sum) {
        if (cnt > END) return 0;
        if (i == N + 1) {
            if (cnt != END || sum) return 0;
            return 1;
        }
        if (dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
        int cur = 0;
        cur += solve(i + 1, cnt + 1, (sum + H1[i] + 11 * 11) % 11);
        FIXMOD(cur);
        cur += solve(i + 1, cnt, (sum + H2[i] + 11 * 11) % 11);
        FIXMOD(cur);
        return dp[i][cnt][sum] = cur;
    }

    void SOLVE() {
        FOR(i, 1, N) {
            S[i] = convertstr(A[i]);
        }
        FOR(i, 1, N) {
            H1[i] = 0;
            H2[i] = 0;
            int k = 1;
            FOR(j, 0, (int) S[i].size() - 1) {
                H1[i] += (int) (S[i][j] - '0') * k;
                H2[i] -= (int) (S[i][j] - '0') * k;
                k *= -1;
            }
//            cout << H1[i] << ' ' << H2[i] << '\n';
        }
        END = N / 2 + (N % 2);

        dp.assign(N + 5, vvi(END + 5, vi(12, -1)));

//        reset(dp, -1);
        ll ANS = solve(1, 0, 0) % MOD;
        FOR(i, 1, END) {
            ANS = (1ll * ANS * i) % MOD;
        }

        FOR(i, 1, N - END) {
            ANS = (1ll * ANS * i) % MOD;
        }
        cout << ANS % MOD << '\n';
    }
}

namespace SubtaskFULL {
    string S[MAXN];
    int H1[MAXN], H2[MAXN]; // H1 la cong vao vi tri le
    int END;
//    int dp[MAXN][MAXN][12];
    vvvi dp;

    void FIXMOD(int &val) {
        if (val >= MOD) val -= MOD;
    }

    int solve(int i, int cnt, int sum) {
        if (cnt > END) return 0;
        if (i == N + 1) {
            if (cnt != END || sum) return 0;
            return 1;
        }
        if (dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
        int cur = 0;
        cur += solve(i + 1, cnt + 1, (sum + H1[i] + 11) % 11);
        FIXMOD(cur);
        cur += solve(i + 1, cnt, (sum + H2[i] + 11) % 11);
        FIXMOD(cur);
        return dp[i][cnt][sum] = cur;
    }

    void SOLVE() {
        S[1] = convertstr(A[1]);
        int pos = (int) S[1].size();
        END = 1;
        FOR(i, 2, N) {
            if (pos % 2 == 0) ++END;
            S[i] = convertstr(A[i]);
            pos += (int) S[i].size();
//            if (pos % 2 == 1) ++END;
        }

//        cout << "*" << END << '\n';

        FOR(i, 1, N) {
            H1[i] = 0;
            H2[i] = 0;
            int k = 1;
            FOR(j, 0, (int) S[i].size() - 1) {
                H1[i] += (int) (S[i][j] - '0') * k;
                H2[i] -= (int) (S[i][j] - '0') * k;
                k *= -1;
            }
//            cout << H1[i] << ' ' << H2[i] << '\n';
        }

//        cout << "*" << END << '\n';

        dp.assign(N + 5, vvi(END + 5, vi(13, -1)));

//        reset(dp, -1);
        ll ANS = solve(1, 0, 0) % MOD;

//        cout << ANS << '\n';

        FOR(i, 1, END) {
            ANS = (1ll * ANS * i) % MOD;
        }

        FOR(i, 1, N - END) {
            ANS = (1ll * ANS * i) % MOD;
        }

        cout << ANS % MOD << '\n';
    }
}

void PROCESS() {
    if (N <= 8) {
        Subtask1 :: SOLVE();
        return;
    }

    if (checkSubtask2()) {
        Subtask2 :: SOLVE();
        return;
    }

    if (checkSubtask3()) {
        Subtask3 :: SOLVE();
        return;
    }
    SubtaskFULL :: SOLVE();
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);

    cin >> T;
    FOR(i, 1, T) {
        cin >> N;
        FOR(j, 1, N) cin >> A[j];
//        SubtaskFULL :: SOLVE();
        PROCESS();
//        Subtask3 :: SOLVE();
    }

    return 0;
}
