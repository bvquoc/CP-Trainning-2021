#include <bits/stdc++.h>

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using namespace std;

struct trie {
    vector <int> nxt[2];

    void reset() {
        nxt[0].clear();
        nxt[1].clear();
        nxt[0].emplace_back();
        nxt[1].emplace_back();
    }

    void insert(int x) {
        int pt = 0;
        for (int i = 30; ~i; i--) {
            int b = x >> i & 1;
            //cerr << b;
            if (!nxt[b][pt]) {
                nxt[b][pt] = nxt[0].size();
                nxt[0].emplace_back();
                nxt[1].emplace_back();
            }
            pt = nxt[b][pt];
        }
    }

    int query(int x) {
        int res = 0, pt = 0;
        for (int i = 30; ~i; i--) {
            int b = x >> i & 1;
            if (nxt[1 - b][pt]) {
                res += 1 << i;
                pt = nxt[1 - b][pt];
            }
            else pt = nxt[b][pt];
        }
        return res;
    }
} tr;

int main() {
    freopen("xor.inp", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, x, res = 0;
        cin >> n >> x;
        tr.reset(); tr.insert(x);
        while (--n) {
            cin >> x;
            cmax(res, tr.query(x));
            tr.insert(x);
        }
        cout << res << '\n';
    }
}

