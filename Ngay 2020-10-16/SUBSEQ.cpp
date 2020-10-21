#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1003;
int n, a[N], S = 0;
int res = -1;
bool x[25];
vector <int> ans;

void Try(int id) {
    if (id > n) {
        int cur_S = 0;
        FOR(i,1,n) cur_S += x[i]*(a[i]);
        FOR(i,1,n) if (x[i]) {
            if (cur_S - a[i] > (S/2)) return;
        }
        if (res < cur_S) {
            res = cur_S;
            ans.clear();
            FOR(i,1,n) {
                if (x[i]) ans.push_back(i);
            }
        }
        return;
    }
    FOR(j,0,1) {
        x[id] = j;
        if (id<=n) Try(id+1);
    }
}

signed main(void) {
    FastIO;
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        S += a[i];
    }
    if (n <= 20) Try(1); // Subtask 1: back-tracking
    else if (n <= 100) { // Subtask 2

    } else { // Subtask 3 (n<=100)

    }
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
    return 0;
}