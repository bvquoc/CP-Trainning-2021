#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5; 

string s;
pair<string, int> dict[maxn];
int main() {
#if ONLINE_JUDGE || THEMIS
    freopen("anctext.inp", "r", stdin);
    freopen("anctext.out", "w", stdout);
#endif

#ifdef LDT
    freopen("input.txt", "r", stdin);
    freopen("sub1.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    int n, q;
    cin >> s;
    cin >> n;  
    for (int i = 1; i <= n; ++i) {
        int x;
        string si;
        cin >> x >> si;
        dict[i].first = dict[x].first + si;
        dict[i].second = -i;
    }
    sort(dict + 1, dict + 1 + n);
    // for (int i = 1; i <= n; ++i)
    //     cerr << dict[i].first << '\n';
    
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        int len = r - l + 1;
        int pos = lower_bound(dict + 1, dict + n + 1, make_pair(s.substr(l, len), (int) 1e9)) - dict - 1;
        if (pos <= 0)
            cout << -1 << '\n';
        else 
            cout << -dict[pos].second << '\n';
    }
    return 0;
}
