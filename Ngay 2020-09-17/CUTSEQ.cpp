#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

const int N = 205;
int n, m;
int f[N][N][N], kq[N][N][N];
string s; char a[100000];
int vt[10000], d[1005][1005];

int solve(int i, int j, int k) {
    int t, x1, x2, nho;
    if (i>j) return k*k;
    if (i==j) return (k+1)*(k+1);
    if (kq[i][j][k]==1) return f[i][j][k];

    int res=0;

    nho=0;
    FOR(t,i+1,j) {
        if (a[t]!=a[i]) {
            res = (t-i+k)*(t-i+k) + solve(t,j,0);
            break;
        }
    }

    t = d[i][a[i]];
    while (t>0 && t<=j) {
        res = max(res,solve(i+1,t-1,0)+solve(t,j,k+1));
        t=d[t][a[t]];
    }
    kq[i][j][k] = 1;
    return f[i][j][k] = res;;
}

signed main() {
    FastIO;
    freopen("CUTSEQ.INP","r",stdin);
    freopen("CUTSEQ.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FORD(i,n,1) {
        for (int j='0';j<='9';j++)
            d[i][j] = vt[j];
        vt[a[i]] = i;
    }
    int ans = solve(1,n,0);
    cout << ans;
    return 0;
}

