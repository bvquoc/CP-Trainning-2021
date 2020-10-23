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

const int N = 1000006;
int n, a[N];
stack <int> S;
int L[N], R[N]; 

signed main(void) {
    FastIO;
    freopen("SHOPSIGN.INP","r",stdin);
    freopen("SHOPSIGN.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i];

    FOR(i,1,n) {
        while(!S.empty() && a[S.top()]>=a[i]) S.pop();
        if(S.empty()) L[i] = 0;
        else L[i] = S.top();
        S.push(i);
    }

    while (!S.empty()) S.pop();
    FORD(i,n,1) {
        while(!S.empty() && a[S.top()] >= a[i]) S.pop();
        if(S.empty()) R[i] = n+1;
        else R[i] = S.top();
        S.push(i);
    }

    int res = 0;
    FOR(i,1,n) {
        if(a[i] <= R[i]-L[i]-1) res = max(res,a[i]);
    }
    cout << res;
    return 0;
}