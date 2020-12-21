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

#define MOD (ll)(1e9 + 7)
#define ii pair<int, int>
#define oo (ll)(1e9 + 7)
#define N (ll)(1e6 + 5)

int n, m, k;
int a[N], b[N];
string s;

void sub1()
{
        int ma = 0, cnt = 0;
        int l, r;
        f(i, 1, n) {
                if(s[i] == '1') {
                        ++cnt;
                        if(umax(ma, cnt))
                                r = i, l = i - cnt + 1;
                }
                else
                        cnt = 0;
        }
        if(umax(ma, cnt))
                r = n, l = r - cnt + 1;
        if(ma == 0)
                cout << -1 << "\n";
        else
                cout << l << " " << r << "\n";
}

void sub2()
{
        vt<int> S(n + 1, 0);
        f(i, 1, n)
                S[i] = S[i - 1] + (s[i] == '1');

        int le = -1, ri = -1;
        auto sum = [&](int l, int r) -> int
        {
                if(l > r)
                        return 0;
                return S[r] - S[l - 1];
        };

        auto chk = [&](int len) -> bool
        {
                f(i, 1, n - len + 1) {
                        if(len - sum(i, i + len - 1) <= k) {
                                le = i, ri = i + len - 1;
                                return 1;
                        }
                }
                return 0;
        };

        int l = 0, r = n, res = 0;
        while(l <= r) {
                int mid = (l + r) >> 1;
                if(chk(mid))
                        l = mid + 1;
                else
                        r = mid - 1;
        }

        if(le == -1 && ri == -1)
                cout << -1 << "\n";
        else
                cout << le << " " << ri << "\n";
}

void sub3()
{
//        int l = 0, r = n;
//        while(l <= r) {
//                int mid = (l + r) >> 1;
//                if(chk(mid))
//
//        }
//        if(le == -1 && ri == -1)
//                cout << -1 << "\n";
//        else
//                cout << le << " " << ri << "\n";
}

void test_case()
{
        cin >> n >> m >> k;
        cin >> s; s = ' ' + s;
        f(i, 1, m) {
                cin >> a[i] >> b[i];
        }

        if(m == 0 && k == 0) {
                sub1();
                return;
        }

        if(m == 0) {
                sub2();
                return;
        }

        if(n <= 2000) {
                sub3();
                return;
        }

        if(n - count(all(s), '1') <= k) {
                cout << 1 << " " << n << "\n";
        }
        else
                cout << -1 << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        auto time = clock();

        #define NAME "decor"
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);

        int test = 1;
//        cin >> test;
        while(test--) {
                test_case();
                // break;
        }

        Time;
        return 0;
}
