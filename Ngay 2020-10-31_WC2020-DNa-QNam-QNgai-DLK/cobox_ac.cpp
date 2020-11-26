#include<bits/stdc++.h>
using namespace std;

struct Box {
    int a, b, index;

    bool operator < (const Box &x) {
        return a != x.a ? a < x.a : b > x.b;
    }
};

typedef pair<int, int> pii;

int n;
Box a[100005];

vector<vector<int>> ans;
vector<pii> d;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    freopen("box2.inp", "r", stdin);
    freopen("box2.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
        a[i].index = i;
    }
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        pii mx = pii(0, 0);
        for (auto u : d) if (u.first < a[i].b) mx = max(mx, u);
        if (mx.first == 0) {
            ans.push_back(vector<int>(1, a[i].index));
            d.push_back(pii(a[i].b, (int)d.size()));
        } else {
            ans[mx.second].push_back(a[i].index);
            d[mx.second].first = a[i].b;
        }
    }

    cout << (int)ans.size() << '\n';
    for (auto i : ans) {
        cout << (int)i.size() << ' ';
        for (int j = (int)i.size()-1; j >= 0; j--) cout << i[j] << ' ';
        cout << '\n';
    }

    return 0;
}