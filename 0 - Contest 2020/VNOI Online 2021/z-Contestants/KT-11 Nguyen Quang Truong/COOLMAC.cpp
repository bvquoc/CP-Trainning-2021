#include <bits/stdc++.h>

const int N = 1e5;
const int INF = 1e9;

int n, m;
std::pair<int, int> jacket[N + 5];
int min = INF;
int max = 0;

namespace sub1 {
std::vector<int> chosen;
int ans = INF;

void ngangMatLenTroi_hanDoiVoDoi() {
    // iterate through all possible subsets of jackets
    for (int mask = 1; mask < (1 << m); mask++) {
        chosen.clear();

        for (int i = 0; i < m; i++) {
            if (mask >> i & 1) chosen.push_back(i + 1);
        }

        // check if chosen jackets satisfy the condition
        if (min < jacket[chosen[0]].first) {
            continue;
        }
        if (jacket[chosen.back()].second < N) {
            continue;
        }

        bool ok = true;
        for (int i = 1; i < (int) chosen.size(); i++) {
            ok &= jacket[chosen[i - 1]].second >= jacket[chosen[i]].first;
        }

        if (ok) {
            ans = std::min(ans, (int) chosen.size());
        }
    }

    if (ans == INF) ans = -1;
    std::cout << ans;
}
} // namespace sub1

namespace sub3 {
void solve() {
    std::set<int> st;
    st.insert(jacket[1].second);

    // auto printSet = [&]() {
    //     std::cout << "set:";
    //     for (int x : st) std::cout << ' ' << x;
    //     std::cout << '\n';
    // };

    for (int i = 2; i <= m; i++) {
        if (jacket[i].second <= *(--st.end())) {
            continue;
        }

        auto it = st.upper_bound(jacket[i].first);

        if (it == st.end()) {
            --it;
            if (*it < jacket[i].first) {
                std::cout << -1;
                return;
            }
            else if (*it == jacket[i].first) {
                st.insert(jacket[i].second);
            }
        }
        else {
            ++it;
            if (it != st.end()) {
                st.erase(it);
            }
            st.insert(jacket[i].second);
        }

        // printSet();
    }

    std::cout << st.size();
}
} // namespace sub3

signed main() {
#ifndef LOCAL
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> m;

    for (int i = 1; i <= m; i++) {
        std::cin >> jacket[i].first >> jacket[i].second;
        max = std::max(max, jacket[i].second);
    }

    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        min = std::min(min, x);
    }

    std::sort(jacket + 1, jacket + m + 1,
        [&](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
            if (lhs.first == rhs.first) return lhs.second > rhs.second;
            return lhs.first < rhs.first;
        }
    );

    if (min < jacket[1].first || max < N) {
        std::cout << -1;
        return 0;
    }

    if (n <= 10 and m <= 16) {
        sub1::ngangMatLenTroi_hanDoiVoDoi();
    }
    else {
        sub3::solve();
    }

    return 0;
}
