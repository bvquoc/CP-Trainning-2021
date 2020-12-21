#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
// using namespace __gnu_pbds;

#define PI (2*acos(0));
#define sqr(x) ((x) * (x))
#define pb push_back
#define fi first
#define se second
typedef int64_t ll;
typedef pair<int, int> pii;

template<typename T>void maximize(T &a, T b) {if (a < b) a = b;}
template<typename T>void minimize(T &a, T b) {if (a > b) a = b;}
template<typename T1, typename T2> T1 power(T1 a, T2 b) {if (b == 1) return a; T1 t = power(a, b / 2); return (b & 1 ? t * t * a : t * t);}


const int N = 2005;
const int MOD = 998244353;

int64_t n;


int64_t ans, a[100];
string arr[10];
bool flag[100];


bool check(string s) {
    int64_t odd = 0, even = 0;
    for(int i = 0; i < s.size(); ++i) {
        if ((i + 1) % 2) odd += s[i] - '0';
        else even += s[i] - '0';
    }

    if ((odd - even) % 11) return false;
    else return true;
}

void _try(int64_t x) {
    for (int i = 1; i <= n; ++i) {
        if (flag[i] == false) {
            a[x] = i;
            if (x == n) {
                string s = "";
                for (int k = 1; k <= n; ++k)
                    s += arr[a[k]];
                if (check(s) == true) ++ans;
            }
            else {
                flag[i] = true;
                _try(x + 1);
                flag[i] = false;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    memset(flag, 0, sizeof(flag));
    memset(a, 0, sizeof(a));
    ans = 0;

    _try(1);

    cout << ans % MOD << '\n';
}


int main() {
    // freopen("GIFT11.inp", "r", stdin);
    // freopen("GIFT11.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        solve();
    }

    return 0;
}
