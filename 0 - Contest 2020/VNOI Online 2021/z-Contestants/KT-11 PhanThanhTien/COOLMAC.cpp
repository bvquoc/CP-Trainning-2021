#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;

#define PI (2*acos(0));
#define sqr(x) ((x) * (x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;

template<typename T>void maximize(T &a, T b) {if (a < b) a = b;}
template<typename T>void minimize(T &a, T b) {if (a > b) a = b;}
template<typename T1, typename T2> T1 power(T1 a, T2 b) {if (b == 1) return a; T1 t = power(a, b / 2); return (b & 1 ? t * t * a : t * t);}


const int MOD = 1e9 + 7;
const int N = 1e5;

int m, n;
pair<int, int> tempRange[N + 5], selected = {N, 0};
int temp[N + 5];
int target = MOD;


bool comp(pii a, pii b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> tempRange[i].first >> tempRange[i].second;

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> temp[i], minimize(target, temp[i]);

    sort(tempRange + 1, tempRange + 1 + m, comp);
    for (int i = m; i >= 1; --i) {
        if (tempRange[i].second != N) break;
        
        minimize(selected.first, tempRange[i].first);
        maximize(selected.second, tempRange[i].second);
    }

    if (selected.second != N) {cout << -1; return 0;}
    sort(tempRange + 1, tempRange + 1 + m);

    pair<int, int> target2 = {0, selected.first};
    // pair<int, int> p = make_pair(target, selected.second);
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        auto it = lower_bound(tempRange + 1, tempRange + 1 + n, target2) - tempRange;

        cout << tempRange[it].first << ' ' << tempRange[it].second << '\n';
        if (tempRange[it].first == selected.first) {cout << -1; return 0;}

        // for (int i = it; i >= 1; --i) {
        if (tempRange[it].second >= selected.first) {
            minimize(selected.first, tempRange[it].first);
            ++ans;
        }
        else {cout << -1; cout  << ' ' << selected.first << ' ' << tempRange[it].second << '\n'; return 0;}
        target2 = {tempRange[it].first, selected.first};
        // cout << selected.first << ' ' << selected.second << '\n';
        if (selected.first <= target) break;
    }

    if (selected.first > target || selected.second < N) cout << -1;
    else cout << ans;
    return 0;
}