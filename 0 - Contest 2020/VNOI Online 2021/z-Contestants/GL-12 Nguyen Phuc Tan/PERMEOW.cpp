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

int n;
vt<int> a, b;

int cal(const vt<int> &v)
{
        vt<int> p = v;
        int res = 0;
        f(i, 1, n) {
                int pos;
                f(j, 1, n)
                        if(p[j] == i) {
                                pos = j;
                        }
                while(pos > i) {
                        swap(p[pos], p[pos - 1]);
                        --pos;
                        ++res;
                }
        }
        return res;
}

void sub1()
{
        cout << cal(a) << "\n";
}

void sub2()
{
//        auto cal = [&](const vt<int> &v) -> int
//        {
//                vt<int> p = v;
//                int res = 0;
//                f(i, 1, n) {
//                        int pos;
//                        f(j, 1, n)
//                                if(p[j] == i) {
//                                        pos = j;
//                                }
//                        while(pos > i) {
//                                swap(p[pos], p[pos - 1]);
//                                --pos;
//                                ++res;
//                        }
//                }
//                return res;
//        };
//
//        vt<int> per(n);
//        iota(all(per), 1);
//
//        int ans = 0;
//        do {
//                for(auto i : per)
//                        cout << i << " ";
//                cout << " : ";
//                vt<int> p(n + 1, 0);
//                f(i, 1, n)
//                        p[i] = per[i - 1];
////                f(i, 1, n)
////                        cout << p[i] << " ";
////                cout << "\n";
//                int tmp = cal(p);
//              cout << tmp;
//              ans += tmp;
//
//                cout << endl;
//        }
//        while(next_permutation(all(per)));
//        cout << ans << "\n";

        int ans = 1;
        f(i, 1, n)
                ans = 1ll * ans * i % MOD;
        ans = (1ll * ans * n * (n - 1) / 2) % MOD;
        ans = (ans / 2ll) % MOD;
        cout << ans << "\n";
}

void sub3()
{

}

void test_case()
{
        cin >> n;
        a.assign(n + 1, 0);
        b.assign(n + 1, 0);
        f(i, 1, n)
                cin >> a[i];
        f(i, 1, n)
                cin >> b[i];

        if(a == b) {
                sub1();
                return;
        }

        vt<int> tmp = b;
        reverse(tmp.begin() + 1, tmp.end());
        if(tmp == a) {
                sub2();
                return;
        }

        if(n <= 2000) {
                sub3();
                return;
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        auto time = clock();

        #define NAME "permeow"
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
