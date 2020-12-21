#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<ll> vll;
void fast_io() {ios::sync_with_stdio(0); cin.tie(0);}

/***Main Code***/
#define DEBUG 0
#define FILE_IO 0

int m, n;
const int N = 1e5+5;
pair<int, int> a[N];
const int maxR = 1e5+1;
int tree[N];
int dp[N];

void Input() {
    cin >> m;
    for(int i = 0; i < m;++i) {
        cin >> a[i].F >> a[i].S;
        a[i].F++;
        a[i].S++;
    }
    sort(a, a+m);
}

void update(int key, int val) {
    for(int i = key; i < N; i += i&-i) {
        tree[i] = min(tree[i], val);
    }
}

int getMin(int key) {
    int ans = N;
    for(int i = key; i > 0; i -= i&-i) {
        ans = min(ans, tree[i]);
    }
    return ans;
}

void Solve() {
    fill(tree, tree+N, N);
    for(int i = m-1; i >= 0; --i) {
        dp[i] = N;
        if (a[i].S == maxR) dp[i] = 1;
        else dp[i] = min(dp[i], getMin(a[i].S)+1);
        update(a[i].F, dp[i]);
    }

    cin >> n;
    int minT = N;
    for(int i = 0; i < n; ++i) {
        int t; cin >> t; t++;
        minT = min(t, minT);
    }
    int ans = getMin(minT);
    if (ans <= m) cout << ans;
    else cout << -1;
}

int main()
{
    fast_io();
    #define task "coolmac"
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    Input(), Solve();

    if (DEBUG) cout << "\nTime: " << clock()/1000.0 << "s";
    return 0;
}
