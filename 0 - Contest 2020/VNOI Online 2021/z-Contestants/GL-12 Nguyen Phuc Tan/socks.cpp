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

int n, q;
bool red[N];

vt<int> g[N];
vt<int> qry;

void sub1()
{
        set<int> s;
        f(i, 1, n) {
                if(red[i])
                        s.insert(i);
        }

        if(sz(s) > 1) {
                cout << 1 << "\n";
        }
        else
                cout << 0 << "\n";
        for(auto i : qry) {
                if(red[i]) {
                        red[i] = 0;
                        s.erase(i);
                }
                else {
                        red[i] = 1;
                        s.insert(i);
                }
                if(sz(s) > 1) {
                        cout << 1;
                }
                else
                        cout << 0;
                cout << "\n";
        }
}

int gr[N];

void dfs(int u, int in, int p)
{
        gr[u] = in;
        for(auto v : g[u]) if(v != p) {
                dfs(v, in, u);
        }
}

void sub2()
{
        int mid = 0;
        f(i, 1, n)
                if(sz(g[i]) == 3)
                        mid = i;
        int cur = 0;
        for(auto i : g[mid]) {
                dfs(i, ++cur, mid);
        }
        set<int> s[4];
        f(i, 1, n) {
                if(i == mid)
                        continue;
                if(red[i])
                        s[gr[i]].insert(i);
        }

        int cnt = 0, ma = 0;
        f(i, 1, 3) {
                if(sz(s[i]) > 0)
                        ++cnt;
                umax(ma, sz(s[i]));
        }
        if(cnt == 3)
                cout << 2 << "\n";
        if(cnt == 2)
                cout << 1 << "\n";
        if(cnt == 1)
                if(ma == 1 && !red[mid])
                        cout << 0 << "\n";
                else
                        cout << 1 << "\n";
        for(auto i : qry) {
                if(i == mid) {
                        red[i] ^= 1;
                }
                else {
                        int anc = gr[i];
                        if(red[i]) {
                                red[i] = 0;
                                s[anc].erase(i);
                        }
                        else {
                                red[i] = 1;
                                s[anc].insert(i);
                        }
                }

                int cnt = 0, ma = 0;
                f(i, 1, 3) {
                        if(sz(s[i]) > 0)
                                ++cnt;
                        umax(ma, sz(s[i]));
                }
                if(cnt == 3)
                        cout << 2 << "\n";
                if(cnt == 2)
                        cout << 1 << "\n";
                if(cnt == 1)
                        if(ma == 1 && !red[mid])
                                cout << 0 << "\n";
                        else
                                cout << 1 << "\n";
        }
}

void test_case()
{
        cin >> n >> q;
        f(i, 1, n)
                cin >> red[i];
        f(i, 1, n - 1) {
                int u, v;
                cin >> u >> v;
                g[u].pb(v);
                g[v].pb(u);
        }
        f(i, 1, q) {
                int x;
                cin >> x;
                qry.pb(x);
        }
        bool ok = 1;
        f(i, 1, n) {
                if(sz(g[i]) > 2)
                        ok = 0;
        }
        if(ok) {
                sub1();
                return;
        }
        ok = 1;
        int cnt3 = 0;
        f(i, 1, n) {
                if(sz(g[i]) == 3)
                        ++cnt3;
                if(sz(g[i]) > 3)
                        ok = 0;
        }
        if(ok && cnt3 == 1) {
                sub2();
                return;
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        auto time = clock();

        #define NAME "socks"
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);

        int test = 1;
        // cin >> test;
        while(test--) {
                test_case();
                // break;
        }

//        Time;
        return 0;
}
