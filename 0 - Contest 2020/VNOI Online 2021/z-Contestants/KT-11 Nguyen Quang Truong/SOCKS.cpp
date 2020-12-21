#include <bits/stdc++.h>

const int N = 5e5 + 5;

int n, q;
std::vector<int> g[N];
bool stat[N];
int query[N];
std::map<int, int> cnt;

namespace sub1 {
std::set<int> enabled;

void ngangMatLenTroi_hanDoiVoDoi() {
    for (int i = 1; i <= n; i++) {
        if (stat[i]) {
            enabled.insert(i);
        }
    }

    std::cout << !enabled.empty() << '\n';

    for (int i = 1; i <= q; i++) {
        stat[query[i]] ^= 1;

        if (stat[query[i]]) {
            enabled.insert(query[i]);
        }
        else {
            enabled.erase(query[i]);
        }

        std::cout << !enabled.empty() << '\n';
    }
}
} // namespace sub1

namespace sub2 {
std::set<int> enabled[3];
int ID[N];

void findRoute(int u, int p, int i) {
    for (int v : g[u]) {
        if (v == p) continue;
        findRoute(v, u, i);
    }

    ID[u] = i;
}

void getAns() {
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        cnt += !enabled[i].empty();
    }

    switch (cnt) {
        case 0:
            std::cout << 0 << '\n';
            break;
        case 1:
        case 2:
            std::cout << 1 << '\n';
            break;
        case 3:
            std::cout << 2 << '\n';
            break;
        default:
            assert(false);
    }
}

void ngangMatLenTroi_hanDoiVoDoi() {
    int center = -1;

    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 3) {
            center = i;
            break;
        }
    }

    assert(center != -1);

    for (int i = 0; i < 3; i++) {
        findRoute(g[center][i], center, i);
    }

    for (int i = 1; i <= n; i++) {
        if (!stat[i]) continue;
        enabled[ID[i]].insert(i);
    }

    getAns();

    for (int i = 1; i <= q; i++) {
        stat[query[i]] ^= 1;

        if (stat[query[i]]) {
            enabled[ID[query[i]]].insert(query[i]);
        }
        else {
            enabled[ID[query[i]]].erase(query[i]);
        }

        getAns();
    }
}
} // namespace sub2

signed main() {
#ifndef LOCAL
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        std::cin >> stat[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= q; i++) {
        std::cin >> query[i];
    }

    for (int i = 1; i <= n; i++) {
        ++cnt[g[i].size()];
    }

    if (cnt[1] + cnt[2] == n) {
        sub1::ngangMatLenTroi_hanDoiVoDoi();
    }
    else if (cnt[1] + cnt[2] + cnt[3] == n and cnt[3] == 1) {
        sub2::ngangMatLenTroi_hanDoiVoDoi();
    }
    else {
        assert(false);
    }

    return 0;
}
