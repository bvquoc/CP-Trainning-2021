//Gear4snamekmen
#include <bits/stdc++.h>
#define GEAR4 "Mine"
#define nmax 400005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define oo 1000000009
#define mod 1000003
#define PB push_back
#define foR(i, r, k) for(int i = r; i <= k; i++)
#define foG(i, r, k) for(int i = k; i >= r; i--)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
int n, m, a[nmax], n2, dem = 0, res[nmax], kq = oo;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(GEAR4".inp","r",stdin);
    freopen(GEAR4".out","w",stdout);
    cin >> n >> m;
    n2 = 2 * n;
    foR(i, 1, n2) cin >> a[i];
    foR(i, 1, (n2 - 1)) {
        if(a[i] == a[i + 1])
            dem++;
    }
    reset(res);
    if(dem == 0)
        memset(res, 1, sizeof res);
    for(int i = 1; i < n - 2; i++) {
        for(int j = i + 1; j <= n - 2; j++) {
            if(a[j] - a[i] <= m) {
                res[a[i]] ++;
            }
        }
        for(int i = 1; i < n - 2; i++)
            cout << res[a[i]] << ' ';
    }

}
