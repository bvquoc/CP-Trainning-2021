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

const int N = 2000006;
int n, Z[N];
string S;

signed main(void) {
    FastIO;
    freopen("SIMI.INP","r",stdin);
    freopen("SIMI.OUT","w",stdout);
    cin >> S; int sz = S.length();
    S = '*'+S+'*'+S;
    n = S.length()-1;
    int L = 0, R = 0, x;
    Z[0] = 0;
    FOR(k,2,n) {
        if (k>R) x = 1;
        else x = min(Z[k-L+1],R-k+1)+1;
        while (k+x-1<=n && S[x]==S[x+k-1]) x++;
        Z[k] = x-1;
        if (k+Z[k]-1>=R) {
            L = k;
            R = k+Z[k]-1;
        }
    }

    int res = 0;
    FOR(i,sz+1,n) res += Z[i];
    cout << res;
    return 0;
}