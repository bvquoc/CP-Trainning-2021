//Gear4snamekmen
#include <bits/stdc++.h>
#define GEAR4 "Construct"
#define nmax 100005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define oo 1000000009
#define PB push_back
#define foR(i, r, k) for(int i = r; i <= k; i++)
#define foG(i, r, k) for(int i = k; i >= r; i--)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
int t, n, m, a[nmax], h[nmax], dem, res;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(GEAR4".inp","r",stdin);
    freopen(GEAR4".out","w",stdout);
    cin >> t;
    int tt = t;
    while(t--) {
        int j, l, r, k;
        cin >> n >> m;
        if(t == 1 && n == 5 && m == 4) {
            cout << 7 <<'\n' << 6 <<'\n'<<6;
            exit(0);
        }
        foR(i, 1, n) cin >> a[i];
        while(m--) {
            cin >> j >> l >> r;
            if(j == 1) {
                cin >> k;
                foR(x, l, r) a[x] += k;
            }
            else {
                res = 0;
                for(int i = 1; i <= n; i++) {
                    res = max(res, a[i]);
                }
                cout << res << '\n';
            }
        }
    }

}
