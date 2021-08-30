#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

vector <int> LIS(vector <int> a) {
    int n = a.size();
    vector<int> b(n+1, INT_MAX), t(n);
    // b[k] là giá trị kết thúc của dãy con độ dài k (tại thời điểm đang tính)
    b[0] = INT_MIN;
    int sz = 0;
    FOR(i,0,n-1) {
        int x=a[i];
        int k = lower_bound(b.begin(), b.end(), x+1) - b.begin();
        // đang xét dãy không giảm, muốn dãy tăng thì thay x+1 thành x
        b[k] = x;
        t[i] = k;
        sz = max(sz, k);
    }

    vector <int> ans;
    FORD(i,n-1,0) {
        if (t[i]==sz) {
            ans.push_back(a[i]);
            sz--;
        }
        if (!sz) break;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    
    int n; cin >> n;
    vector <int> a(n), res;
    for (int &x: a) cin >> x;

    res = LIS(a);
    cout << res.size() << endl;
    for (int x: res) cout << x << ' ';
    return 0;
}