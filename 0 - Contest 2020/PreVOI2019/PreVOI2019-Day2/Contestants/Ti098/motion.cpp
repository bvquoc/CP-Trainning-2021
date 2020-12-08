#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ins insert
#define era erase
#define pii pair < int, int >
using namespace std;
pii vta, vtb, maX, mbX, maY, mbY;
int t, n, m, xa, ya, xb, yb, xc, yc, xd, yd, ca, cb, resa, resb, sd1, sd2;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
    #endif //ONLINE_JUDGE
    cin >> t;
    while(t--)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        vta.F = xb - xa; vta.S = yb - ya;
        vtb.F = xd - xc; vtb.S = yd - yc;
        swap(vta.F, vta.S);
        vta.S = - vta.S;
        swap(vtb.F, vtb.S);
        vtb.S = - vtb.S;
        ca = (xa * vta.F + ya * vta.S);cb = (xc * vtb.F + yc * vtb.S);

        resa = 10000; resb = 1;
        for(int ms = 1; ms<=10; ++ms)
            for(int ts = 0; ts <= 10000; ++ts)
        {
            maX.F = ts; maX.S = ms;
            mbX.F = ts; mbX.S = ms;

            maY.F = ca * ms - ts * vta.F; maY.S = ms * vta.S;
            mbY.F = cb * ms - ts * vtb.F; mbY.S = ms * vtb.S;

            sd1 = (ts / ms); sd1 = sd1 / m;
            sd2 = (maY.F / maY.S); sd2 = sd2 / n;
        }
        cout << -1 << '\n';
    }
    return 0;
}
