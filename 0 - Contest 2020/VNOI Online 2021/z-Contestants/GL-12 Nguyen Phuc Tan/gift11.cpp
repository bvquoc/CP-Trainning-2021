#include<bits/stdc++.h>
using namespace std;

#define f(a, b, c) for(int a = (b), _c = (c); a <= _c; ++a)
#define fr(a, b, c) for(int a = (b), _c = (c); a >= _c; --a)
#define ff first
#define ss second
#define ld long double
#define ll long long
#define vt vector                       //   \|/          (__)
#define pb push_back                    //        `\------(oo)
#define all(x) (x).begin(), (x).end()   //          ||    (__)
#define sz(x) ((int)((x).size()))       //          ||-vv||     \|/
#define ar array                        //      \|/
#define lb lower_bound
#define ub upper_bound
#define bit(x, i) (((x) >> (i)) & 1ll)
#define mask(i) (1ll << (i))
#define Time cerr<<"[It took "<<fixed<<setprecision(3)<<double(clock()-time)/CLOCKS_PER_SEC<<"s]"<<"\n"
#define dbg(...) cout<<"#"<<__LINE__<<":["<<#__VA_ARGS__<<"] = [",DBG(__VA_ARGS__)

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

void DBG() { cout << "]" << endl; }

template<class H, class... T> void DBG(H h, T... t) {
        cout << to_string(h); if(sizeof...(t)) cout << ", "; DBG(t...);
}

template<class T> bool umin(T& a, const T& b) {
        return b<a?a=b, 1:0;
}

template<class T> bool umax(T& a, const T& b) {
        return a<b?a=b, 1:0;
}
// init done

#define MOD (ll)(998244353)
#define ii pair<int, int>
#define oo (ll)(1e9 + 7)
#define N (ll)(2002)

int t;
int n[11];
int a[11][N];

int cntDigit(int val)
{
        int res = 0;
        while(val > 0)
                val /= 10, ++res;
        return res;
}

void sub1()
{
        f(i, 1, t) {
                int ans = 0;
                vt<int> per(n[i], 0);
                iota(all(per), 1);
                do {
                        int odd = 0, even = 0, cur = 1;
                        for(auto j : per) {
                                int tmp = a[i][j];
                                while(tmp > 0) {
                                        if(cur & 1)
                                                odd += tmp % 10;
                                        else
                                                even += tmp % 10;
                                        ++cur;
                                        tmp /= 10;
                                }
                        }

                        if((odd - even) % 11 == 0)
                                ++ans;
                }
                while(next_permutation(all(per)));
                cout << ans % MOD << "\n";
        }
}

int fact[N];

void init()
{
        fact[0] = 1;
        f(i, 1, 2000)
                fact[i] = 1ll * fact[i - 1] * i % MOD;
}

void sub2(int i_th)
{
        int m = n[i_th];
        vt<int> b(m + 1, 0);
        f(i, 1, m)
                b[i] = a[i_th][i];

        int odd = 0, even = 0, cur = 1;
        f(i, 1, m) {
                int tmp = b[i];
                while(tmp > 0) {
                        if(cur & 1)
                                odd += tmp % 10;
                        else
                                even += tmp % 10;
                        ++cur;
                        tmp /= 10;
                }
        }

        if((odd - even) % 11 == 0) {
                cout << fact[m] << "\n";
//                dbg(999);
        }
        else
                cout << 0 << "\n";
}

ii hand(int val)
{
        int odd = 0, even = 0, cur = 1;
        int tmp = val;
        while(tmp > 0) {
                while(tmp > 0) {
                        if(cur & 1)
                                odd += tmp % 10;
                        else
                                even += tmp % 10;
                        ++cur;
                        tmp /= 10;
                }
        }
        odd %= 11, even %= 11;
        return  {odd, even};
}

void sub3(int i_th)
{
//        int m = n[i_th];
//        vt<int> b(m + 1, 0);
//        f(i, 1, m)
//                b[i] = a[i_th][i];
//
//        vt<ii> cha(m + 1, {0, 0});
//        f(i, 1, m)
//                cha[i] = hand(b[i]);
//        vt<vt<vt<int>>> dp(m + 1, vt<vt<int>> (11, vt<int> (2, 0)));
//        dp[0][0][1] = 1;
//        f(i, 0, m - 1) f(mo, 0, 10) f(sta, 0, 1) if(dp[i][mo][sta]) {
//                f(k, 1, )
//                ii tmp = cha[b[i + 1]];
//                int bonus;
//                if(sta)
//                        bonus = (tmp.ff - tmp.ss + 11) % 11;
//                else
//                        bonus = (tmp.ss - tmp.ff + 11) % 11;
//                dbg(i, mo, sta, bonus);
//                int nxtMo = (mo + bonus + 11) % 11;
//                int numPut;
//                if(sta)
//                        numPut = i / 2 + 1;
//                else
//                        numPut = i / 2 + 1;
//                dp[i + 1][nxtMo][!sta] = (dp[i + 1][nxtMo][!sta]
//                                          + 1ll * numPut * dp[i][mo][sta]) % MOD;
//        }
//
//        int ans = 0;
//        f(i, 0, 1)
//                ans = (ans + dp[m][0][i]) % MOD;
//        cout << ans << "\n";
}

void solve()
{
        if(accumulate(n + 1, n + t + 1, 0) <= 8) {
                sub1();
                return;
        }

        init();
        f(i, 1, t) {
                bool ok = 1;
                f(j, 1, n[i]) {
                        if(cntDigit(a[i][j]) & 1) {
                                ok = 0;
                                break;
                        }
                }
                if(ok)
                        sub2(i);
        }
        cout << 0 << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        auto time = clock();

        #define NAME "gift11"
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);

        cin >> t;
        f(i, 1, t) {
                cin >> n[i];
                f(j, 1, n[i]) {
                        cin >> a[i][j];
                }
        }
        solve();

//        Time;
        return 0;
}
