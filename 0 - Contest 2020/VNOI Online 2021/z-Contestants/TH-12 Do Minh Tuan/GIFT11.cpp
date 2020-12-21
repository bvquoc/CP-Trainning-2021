#include <bits/stdc++.h>
#define tkn "GIFT11"
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 998244353;
int test;
int n;
const int N = 2007;
int a[N];
vector<int> save[N];
bool chosen[17];
vector<int> current;
ll ans;
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
void init() {
    for (int i = 1; i <= n; i++) {
        save[i].clear();
        while (a[i] != 0) {
            save[i].pb(a[i] % 10);
            a[i] /= 10;
        }
        reverse(save[i].begin(), save[i].end());
    }
    for (int i = 1; i <= n; i++)
        chosen[i] = 0;
}
bool check() {
    int odd = 0, even = 0;
    for (int i = 0; i < current.size(); i += 2)
        odd += current[i];
    for (int i = 1; i < current.size(); i += 2)
        even += current[i];
    if ((odd - even) % 11 == 0) return 1;
    else return 0;
}
void bf(int id) {
    if (id == n) {
        ans += check();
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!chosen[i]) {
            chosen[i] = 1;
            for (auto p : save[i])
                current.pb(p);
            bf(id + 1);
            chosen[i] = 0;
            for (int j = 0; j < save[i].size(); j++)
                current.pop_back();
        }
}
void solve() {
    ans = 0;
    bf(0);
}
bool checkSub2() {
    for (int i = 1; i <= n; i++)
        if (save[i].size() % 2 != 0) return 0;
    return 1;
}
void sub2() {
    int even = 0, odd = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < save[i].size(); j += 2)
            odd += save[i][j];
        for (int j = 1; j < save[i].size(); j += 2)
            even += save[i][j];
    }
    ans = 1;
    if ((even - odd) % 11 == 0) {
        for (int i = 1; i <= n; i++)
            ans = (ans * i) % mod;
    }
    else ans = 0;
}
void sub3() {

}
int main() {
    ios_base::sync_with_stdio(0);
    freopen(tkn".inp", "r", stdin);
    freopen(tkn".out", "w", stdout);
    cin.tie(0);  cout.tie(0);

    cin >> test;
    while (test--) {
        input();
        init();
        if (checkSub2()) sub2();
        else {
            /*if (checkSub3()) sub3();
            else */solve();
        }
        cout << ans << '\n';
    }

    return 0;
}
