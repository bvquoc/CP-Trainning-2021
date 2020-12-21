#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define pow2(i) (1<<i)
#define eb emplace_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define FOR(_i, _s, _n) 	for (int _i = _s; _i <= _n; ++_i)
#define FOD(_i, _s, _n)	    for (int _i = _s; _i >= _n; --_i)
#define firstbit(_mask)     __builtin_ctz(_mask)
#define lastbit(_mask)      __builtin_clz(_mask)
#define countbit(_mask)     __builtin_popcount(_mask)
int getbit(int mask, int i) {
    return (mask >> i) & 1;
}
void flipbit(int &mask, int i) {
    mask ^= (1 << i);
}
void setbit(int &mask, int i) {
    mask |= (1 << i);
}
template <typename T> inline void read(T &x) {
    x = 0; char c;
    while (!isdigit(c = getchar()));
    do x = x*10 + c - '0';
    while (isdigit(c = getchar()));
}
template <typename T> inline void write(T x) {
    if (x > 9) write(x/10);
    putchar(x % 10 + 48);
}
const int dd[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
#define PROBLEMS            "decor"
#ifdef PROBLEMS
    #define cin fi
    #define cout fo
    ifstream fi (PROBLEMS".inp");
    ofstream fo (PROBLEMS".out");
#endif
#define camnguyenmeow ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
vector<int> a[500005];
int need[500005];
int main()
{
    camnguyenmeow;
    string s;
    int n, m, k, u, v;
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if (m == 0 && k == 0) {
        int ans = 0, savel, saver, cnt = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == '1') ++cnt;
            else {
                if (cnt > ans) {
                    ans = cnt;
                    savel = i - cnt + 1;
                    saver = i;
                }
                cnt = 0;
            }
        if (cnt > ans) {
            savel = n - cnt + 1;
            saver = n;
        }
        if (ans == 0) cout << -1;
        else cout << savel <<' '<< saver;
        return 0;
    }
    if (m == 0) {
        int savel = 0, saver = 0, ans = 0;
        for (int i = 1; i <= n; ++i)
            if (s[i-1] == '0')
                need[i] = need[i-1] + 1;
            else {
                need[i] = need[i-1];
                ans = 1;
            }
        if (need[n] <= k) {
            cout << 1 <<' '<< n; return 0;
        }
        for (int i = 1; i <= n; ++i) {
            int lwb = upper_bound(&need[i], &need[n+1], k + need[i-1]) - &need[0];
            if (lwb > n) {
                if (n - i + 1 > ans) {
                    ans = n - i + 1;
                    savel = i; saver = n;
                }
                break;
            }
            while (lwb > i && need[lwb] - need[i-1] > k)
                --lwb;
            if (need[lwb] - need[i-1] <= k) {
                if (lwb - i + 1 > ans) {
                    ans = lwb - i + 1;
                    savel = i; saver = lwb;
                }
            }
        }
        if (ans == 1) {
            for (int i = 0; i < n; ++i)
                if (s[i] == 1) {
                    cout << i+1 <<' '<< i+1; return 0;
                }
        }
        if (ans == 0) cout << -1;
        else cout << savel <<' '<< saver;
        return 0;
    }
    cout << -1;
    return 0;
}
