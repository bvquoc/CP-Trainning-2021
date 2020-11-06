#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
// #define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 100005;
struct TBox {
    int a, b, id;
    bool operator < (const TBox &X) {
        return a < X.a || (a == X.a && b <= X.b);
    }
};

signed main(void) {
    FastIO;
    freopen("BOX2.INP","r",stdin);
    freopen("BOX2.OUT","w",stdout);
    int n; cin >> n;
    vector <TBox> a(n);
    REP(i,n) {
        cin >> a[i].a >> a[i].b;
        a[i].id = i+1;
        a[i].b *= -1;
    }
    sort(ALL(a));

    vector <int> pos;
    vector <vector <int>> ans;
    REP(i,n) {
        int lo = 0, hi = pos.size()-1, r = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if (a[pos[mid]].b <= a[i].b){
                r = mid;
                lo = mid+1;
            } else hi = mid-1;
        }
        if (++r == (int)pos.size()){
            pos.push_back(0);
            ans.push_back(vector <int>(0));
        }
        pos[r] = i;
        ans[r].push_back(i);
    }
    
    cout << ans.size() << endl;
    for (vector <int> &cur_box: ans){
        cout << cur_box.size() << ' ';
        reverse(ALL(cur_box));
        for (int i: cur_box) cout << a[i].id << ' ';
        cout << endl;
    }
    return 0;
}