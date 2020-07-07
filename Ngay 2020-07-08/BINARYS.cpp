#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector <int> a;

int32_t main(void) {
    FastIO;
    freopen("BINARYS.INP","r",stdin);
    freopen("BINARYS.OUT","w",stdout);
    cin >> n;
    a.resize(n);
    for (int &x:a) {
        cin >> x;
    }
    sort(a.begin(),a.end());
    cin >> n;
    while (n--) {
        int x; cin >> x;
        size_t p = lower_bound(a.begin(),a.end(),x)-a.begin()+1;
        if (a[p-1]!=x || p<=0 || p>a.size()) {
            p = -1;
        }
        cout << p << '\n';
    }
    return 0;
}