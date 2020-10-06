// https://codeforces.com/problemset/problem/939/D
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

const int N = 100005;
int n; string A, B;

int par[N], rnk[N];

int find(int u) {
    if (par[u] != u) par[u] = find(par[u]);
    return par[u];
}
bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (rnk[u] == rnk[v]) rnk[u]++;
    if (rnk[u] < rnk[v]) par[u] = v;
    else par[v]=u;
    return true;
}

vector <ii> ans;

signed main(void) {
    FastIO;
    // freopen("input.txt","r",stdin);
    cin >> n >> A >> B;
    
    for (int i='a'; i<='z'; i++) {
        par[i] = i;
        rnk[i] = 0;
    }
    FOR(i,0,n-1) {
        if (join(A[i],B[i])) {
            ans.push_back(ii(A[i],B[i]));
        }
    }
    cout << ans.size() << endl;
    for (ii x: ans) {
        cout << char(x.first) << ' ' << char(x.second) << endl;
    }
    return 0;
}