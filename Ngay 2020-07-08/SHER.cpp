#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, k, p;
set <int> S;
vector <int> large;
int ans;

int32_t main(void) {
    FastIO;
    freopen("SHER.INP","r",stdin);
    freopen("SHER.OUT","w",stdout);
    int T; cin >> T;
    while (T--) {
        cin >> n >> k >> p;
        for (int i=1; i<=min(n,100000); i++) {
            S.insert(i);
        }
        for (int i=1; i<=k; i++) {
            int x; cin >> x;
            if (x>100000) large.push_back(x);
            else S.erase(x);
        }
        if (p>n-k) ans = -1;
        else {
            sort(large.begin(),large.end());
            int end_num = *S.end();
            if (S.size()>p) {
                int cnt = 0;
                for (int x:S) {
                    cnt++;
                    if (cnt==p) {
                        ans = x;
                        break;
                    }
                }
            } else {
                p -= S.size();
                ans = end_num + p;
            }
        }
        cout << ans << '\n';
        S.clear();
    }
    return 0;
}