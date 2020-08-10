// http://lqdoj.edu.vn/problem/knapsack2
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

const int N = 102;
int n, W, w[N], v[N];
int f[N][100005], S_v = 0;

signed main(void) {
    FastIO;
    freopen("input.txt","r",stdin);
    cin >> n >> W;
    FOR(i,1,n) {
        cin >> w[i] >> v[i];
        S_v += v[i];
    }
    FOR(i,1,n) {
        
    }
    
    FORD(i,S_v,0) {
        if (f[n][i]<=W) {
            cout << i;
            break;
        }
    }
    return 0;
}