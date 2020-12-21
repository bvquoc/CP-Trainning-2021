#include <bits/stdc++.h>

#define task                "GIFT11"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)       for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)          for(auto (a) : (u))

#define bit(a, i)           (((a) >> (i)) & 1)
#define mask(i)             (1LL << (i))
#define turnon(a, i)        ((a) | mask(i))
#define turnoff(a, i)       ((a) & (~mask(i)))

#define ft                  first
#define sd                  second
#define pb                  push_back
#define mp                  make_pair

#define sz(a)		        (int(a.size()))
#define all(a)		        a.begin(),a.end()

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

typedef long long ll;

const int maxn = 2e3 + 5;
const long long mod = 998244353;
const int base = 26;
const double eps = 0.0000001;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

/** End of template **/

int n, a[maxn], b[maxn], DIGIT[maxn][2];
ll gt[maxn], dp[maxn][1003][12];
bool EVEN[maxn];

void sub2() {
    int en = 0, od = 0;
    rep(i, 1, n) {
        en += DIGIT[i][0];
        od += DIGIT[i][1];
    }
    if((en - od) % 11 == 0)
        cout << gt[n] << "\n";
    else
        cout << "0\n";
}

ll calc(int pos, int PosE, int PosO, int div11) {
    if(PosE > n / 2 + 1 || PosO > n / 2 + 1)
        return 0;
    if(pos == n + 1) {
        if(PosO == PosE + (n % 2 == 1) && div11 == 0)
            return dp[pos][PosE][div11] = (gt[PosE] * gt[PosO]) % mod;
        else
            return dp[pos][PosE][div11] = 0LL;
    }

    if(dp[pos][PosE][div11] >= 0)
        return dp[pos][PosE][div11];

    ll ans = 0;
    int add = 0;
    add = (div11 + DIGIT[pos][1] - DIGIT[pos][0] + 11) % 11;
    EVEN[pos] = false;
    ans += calc(pos + 1, PosE, PosO + 1, add);
    add = (div11 + DIGIT[pos][0] - DIGIT[pos][1] + 11) % 11;
    EVEN[pos] = true;
    ans += calc(pos + 1, PosE + 1, PosO, add);

    ans %= mod;
    return dp[pos][PosE][div11] = ans;
}

void sub3() {
    rep(i, 0, n)
    rep(j, 0, n / 2 + 2)
    rep(k, 0, 11)
    dp[i][j][k] = -1;

    memset(EVEN, 0, sizeof(EVEN));
    cout << calc(1, 0, 0, 0) << "\n";
}

string s[maxn];
void sub1() {
    vector<int> vt(0);
    ll ans = 0;

    rep(i, 1, n) {
        s[i] = "";
        while(a[i] > 0) {
            s[i] = char(a[i] % 10 + '0') + s[i];
            a[i] /= 10;
        }
        vt.pb(i);
    }

    do {
        string finl = "";
        rep(i, 0, n - 1)
        finl += s[vt[i]];

        int sum[2] = {0}, id = 0;
        rep(i, 0, sz(finl) - 1)
        sum[id] += int(finl[i] - '0'), id = 1 - id;

        if((sum[0] - sum[1]) % 11 == 0)
            ans++;
    } while(next_permutation(vt.begin(), vt.end()));

    cout << ans << "\n";
}

void testcase() {
    bool subtask2 = true, subtask3 = true;
    memset(DIGIT, 0, sizeof(DIGIT));
    memset(EVEN, 0, sizeof(EVEN));
    rep(i, 1, n) {
        int id = 1;
        b[i] = a[i];
        while(b[i] > 0) {
            DIGIT[i][id] += b[i] % 10;
            id = 1 - id;
            b[i] /= 10;
        }
        id = 1 - id;
        DIGIT[i][0] %= 11;
        DIGIT[i][1] %= 11;
        if(id == 0)
            EVEN[i] = true;
        if(EVEN[i] == true)
            subtask3 = false;
        else
            subtask2 = false;
    }

    if(subtask2 == true)
        sub2();
    else if(subtask3 == true)
        sub3();
    else
        sub1();
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    fi(task".inp");
    fo(task".out");

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        gt[0] = 1;
        rep(i, 1, n) {
            cin >> a[i];
            gt[i] = 1LL * gt[i - 1] * i % mod;
        }
        testcase();
    }
    return 0;
}

