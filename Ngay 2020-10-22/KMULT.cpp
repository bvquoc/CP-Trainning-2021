#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 10004, K = 102;

int n, k, a[N];
int f[N][K];
int x[N];

signed main(void) {
    FastIO;
    freopen("KMULT.INP","r",stdin);
    freopen("KMULT.OUT","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
        a[i] = (a[i]%k + k) % k;
    }

    f[1][a[1]] = 1;
    FOR(i,2,n) FOR(j,0,k-1) {
        if (f[i-1][j]!=0) {
            f[i][(j+a[i])%k]=1;
            f[i][((j-a[i])%k+k)%k]=-1;
        }
    }
    
    if (f[n][0] == 0) {
        putchar('0');
        exit(0);
    }

    putchar('1'); putchar(endl);
    int j = 0;
    FORD(i,n,2) {
        x[i] = f[i][j];
        if (f[i][j]==1) j = ((j-a[i])%k+k)%k;
        else j = (j+a[i]) % k;
    }
    FOR(i,2,n) {
        if (x[i] == 1) putchar('+'); 
        else putchar('-');
    }
    return 0;
}