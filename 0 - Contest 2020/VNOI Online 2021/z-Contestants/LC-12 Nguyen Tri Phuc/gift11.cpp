#include <bits/stdc++.h>
#define fore(it,a)       for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define forr(i, a, b)    for(int i = (a); i <= (b); ++i)
#define ford(i, a, b)    for(int i = (a); i >= (b); --i)
#define repp(i, a, b)    for(int i = (a); i < (b); ++i)
#define repd(i, a, b)    for(int i = (a); i > (b); --i)
#define mem(a, x)        memset(x, (a), sizeof(x))
#define bitcount(x)      __builtin_popcountll((x))
#define OFFBIT(mask, i)  ((mask) &~ (1ll << (i)))
#define ONBIT(mask, i)   ((mask) | (1ll << (i)))
#define reset(x)         memset(x, 0, sizeof(x))
#define all(a)           (a).begin(), (a).end()
#define BIT(x, i)        (((x) >> (i)) & 1)
#define ii               pair<int, int>
#define MASK(i)          (1LL << (i))
#define mp               make_pair
#define se               second
#define fi               first

using namespace std;

mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD  = 998244353;
const int inf  = 2000000000;
const int mod  = 1007050321;
const double e = 0.000001;
const int N    = 2005;
const bool aut = 788480;
const int base = 521;

int n, a[N];

void sub1() {
    int ans = 0;
    vector<int> b;
    forr(i, 1, n)
    b.push_back(i);
    do {
        int s1 = 0, pos = 0;
        forr(i, 1, n) {
            int x = a[b[i-1]];
            string t;
            while(x) {
                t += char(x % 10 + '0');
                x /= 10;
            }
            reverse(all(t));
            for(char c : t) {
                if(pos == 0)
                    s1 = (s1 + c - '0') % 11;
                else
                    s1 = (s1 - (c - '0')) % 11;
                pos = 1 - pos;
            }
        }
        ans += s1 == 0;
    } while(next_permutation(all(b)));
    cout << ans << "\n";
}

void sub2() {
    int s1 = 0, pos = 0;
    forr(i, 1, n) {
        int x = a[i];
        string t;
        while(x) {
            t += char(x % 10 + '0');
            x /= 10;
        }
        reverse(all(t));
        for(char c : t) {
            if(pos == 0)
                s1 = (s1 + c - '0') % 11;
            else
                s1 = (s1 - (c - '0')) % 11;
            pos = 1 - pos;
        }
    }
    if(s1 == 0) {
        int ans = 1;
        forr(i, 1, n)
        ans = 1LL * ans * i % MOD;
        cout << ans << "\n";
    } else
        cout << 0 << "\n";
}

int sum[N][5], le, chan, gt1, gt2, dp[N][N][15];

int calc(int cnt1, int cnt2, int val) {
    if(cnt1 + cnt2 == n)
        return val == 0;
    if(dp[cnt1][cnt2][val] != -1)
        return dp[cnt1][cnt2][val];
    int res = 0, id = cnt1 + cnt2 + 1;
    if(cnt1 < le)
        res = (res + calc(cnt1+1, cnt2, (val + sum[id][1] + 11)%11)) % MOD;
    if(cnt2 < chan)
        res = (res + calc(cnt1, cnt2+1, (val + sum[id][2] + 11)%11)) % MOD;
    return dp[cnt1][cnt2][val] = res;
}

void sub3() {
    mem(-1, dp);
    forr(i, 1, n)
    forr(j, 1, 2) {
        int x = a[i], s1 = 0, pos = (j+1) % 2;
        string t;
        while(x) {
            t += char(x % 10 + '0');
            x /= 10;
        }
        reverse(all(t));
        for(char c : t) {
            if(pos == 0)
                s1 = (s1 + c - '0') % 11;
            else
                s1 = (s1 - (c - '0')) % 11;
            pos = 1 - pos;
        }
        sum[i][j] = s1;
    }
    le = (n + 1) / 2;
    chan = n / 2;
    gt1 = 1, gt2 =  1;
    forr(i, 1, le)
    gt1 = 1LL * gt1 * i % MOD;
    forr(i, 1, chan)
    gt2 = 1LL * gt2 * i % MOD;
    cout << 1LL * calc(0, 0, 0) * gt1 % MOD * gt2 % MOD << "\n";
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define     task "gift11"
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    int tc;
    cin >> tc;
    forr(i, 1, tc) {
        cin >> n;
        forr(i, 1, n) cin >> a[i];
        bool ok = true, ok1 = true;
        forr(i, 1, n) {
            int dem = 0, x = a[i];
            while(x) {
                dem++;
                x /= 10;
            }
            if(dem % 2)
                ok = false;
            if(dem % 2 == 0)
                ok1 = false;
        }
        if(ok)
            sub2();
        else if(n <= 8)
            sub1();
        else if(ok1)
            sub3();
        else
            cout << "0\n";
    }

    return 0;
}
