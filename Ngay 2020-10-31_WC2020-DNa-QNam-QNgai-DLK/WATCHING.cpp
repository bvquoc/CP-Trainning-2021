#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 1000006;

int n, m, t, k;
int a[N], b[N];

signed main(void) {
    FastIO;
    freopen("WATCHING.INP","r",stdin);
    freopen("WATCHING.OUT","w",stdout);
    cin >> n >> m >> t >> k;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) cin >> b[i];

    int time_A = 0, time_B = 0;
    int i = 1, j = 1, cur_t = 0;
    bool isA = 1;

    while (cur_t <= t) {
        if (isA) {
            while (i <= n && a[i] <= cur_t) i++;

            if (i > n || a[i] >= t) {
                if (a[i-1] + k < t) time_A += t - max(a[i-1] + k, cur_t);
                break;
            }

            time_A += a[i] - max(a[i-1] + k, cur_t);
            cur_t = a[i];
            isA = false;
        } else {
            while (j <= m && b[j] <= cur_t) j++;

            if (j > m || b[j] >= t) {
                if (b[j-1] + k < t) time_B += t - max(b[j-1] + k, cur_t);
                break;
            }

            time_B += b[j] - max(b[j-1] + k, cur_t);
            cur_t = b[j];
            isA = true;
        }
    }
    
    cout << time_A << ' ' << time_B;
    return 0;
}