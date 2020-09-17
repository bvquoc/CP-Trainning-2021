#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

int x, dx;
int d, dd;
int t, dt;
int v, dv;
int res = -1;
int M, Mx, Md, Mt, Mv;

signed main(void) {
    FastIO;
    freopen("BRVY.INP","r",stdin);
    freopen("BRVY.OUT","w",stdout);
    cin >> x >> dx;
    cin >> d >> dd;
    cin >> t >> dt;
    cin >> v >> dv;

    FOR(i,1,x) {
        M = i*dx;
        if (M%dt==0 && M/dt<=t) {
            Mt = M/dt;
            Mx = i;
        }
    }
    FOR(i,1,d) {
        M = i*dd;
        if (M%dv==0 && M/dv<=v) {
            int l = M*(Mt*dt);
            if (l>=res) {
                res = l;
                Mv = M/dv;
                Md = i;
            }
        }
    }
    
    res = Mx*dx*Md*dd;
    cout << res << endl;
    cout << Mx << ' ' << Md << ' ' << Mt << ' ' << Mv;
    return 0;
}
