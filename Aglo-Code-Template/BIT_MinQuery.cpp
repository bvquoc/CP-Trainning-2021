#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

struct BIT_MinQuery {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;
    BIT_MinQuery() {}
    BIT_MinQuery(int n) {
        this->n = n;
        bit.assign(n+1, INF);
    }
    void assign (int n) {
        this->n = n;
        bit.assign(n+1, INF);
    }

    BIT_MinQuery(vector<int> a) : BIT_MinQuery(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getMin(int r) {
        int ret = INF;
        for (; r >= 1; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx <= n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};

signed main(void) {
    FastIO;
    BIT_MinQuery BIT(6);
    BIT.update(1, 3);
    BIT.update(2, 2);
    BIT.update(3, 5);
    BIT.update(4, 6);
    BIT.update(5, 8);
    BIT.update(6, 7);
    // [] = {3, 2, 5, 6, 8, 7}
    cout << BIT.getMin(1) << endl;
    cout << BIT.getMin(2) << endl;
    cout << BIT.getMin(3) << endl;
    cout << BIT.getMin(4) << endl;
    cout << BIT.getMin(5) << endl;
    cout << BIT.getMin(6) << endl;
    return 0;
}