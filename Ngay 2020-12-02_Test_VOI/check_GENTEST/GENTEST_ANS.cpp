#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef pair<int, int> pii;
const int INF = 1e9 + 1;

int n, m;
vector<int> v;

int pushToList(int x) {
    int l = 0, r = (int)v.size() - 1;
    int res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int tmp = x + mid;

        if (tmp > v[mid]) {
            res = tmp;
            l = mid + 1;
        } else r = mid - 1;
    }

    v.insert(v.begin() + res - x + 1, res);
    return res;
}

ll cntBef(int u) {
    return 1LL * n * (n - 1) / 2
        - 1LL * (n-u) * (n-u-1) / 2;
}

void query(ll id) {
    int u, v;
    int l = 1, r = n-1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (cntBef(mid) >= id) {
            u = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    v = id - cntBef(u-1) + u;
    cout << u << ' ' << v << '\n';
}

signed main(int argc, char *argv[]) {
	if (argc >= 3) {
		freopen(argv[1], "r", stdin);
		freopen(argv[2], "w", stdout);
	}

    cin >> n >> m;

    v.push_back(0);
    v.push_back(INF);

    while (m--) {
        ll x; cin >> x;
        ll id = pushToList(x);
        query(id);
    }

    // cout << "\nTime: " << clock() << "ms";

    return 0;
}