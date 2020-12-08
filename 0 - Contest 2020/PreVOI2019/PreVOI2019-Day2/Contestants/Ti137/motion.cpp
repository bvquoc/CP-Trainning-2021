#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int t, n, m, xa, ya, xb, yb, xc, yc, yd, xd;
typedef pair<double, double> II;
typedef pair<int, int> ii;
typedef pair<double, II> III;
II ddx[10004], ddy[10004];
III x[10004], y[10004];

double kc(double x, double y, double z, double t)
{
    double kq = sqrt(1.0 * (x - z) * (x - z) + 1.0 * (y - t) * (y - t));
    return kq;
}

void tinh()
{
    int slx = 0, sly = 0;
    int a1, a2, b1, b2, c1, c2;
    double x1 = 1.0 * (xb - xa) * n /(yb - ya);
    double y1 = 0;
    if(yb < ya) y1 = 0;
    else y1 = n;
    II tx = II(kc(xa, ya, x1, y1), kc(xa, ya, xb, yb));
    double x3 = -x1;
    if(xb < xa) x3 = -abs(x3);
    else x3 = abs(x3);
    x1 = xa + x3;
    ddx[0] = II(xa, ya);
    while(x1 <= m && x1 >= 0)
    {
        b1 = xa - x1, a1 = -(ya - y1);
        c1 = -(a1 * xa + b1 * ya);
        x[++slx] = III(a1, II(b1, c1));
        ddx[slx] = II(x1, y1);
        if(y1 == n) y1 = 0;
        else y1 = n;
        x1 += x3;
    }
    double x2 = 1.0 * (xd - xc) * n/(yd - yc);
    double y2 = 0;
    if(yd < yc) y2 = 0;
    else y2 = n;
    II ty = II(kc(xc, yc, xd, yd), kc(xc, yc, x2, y2));
    x3 = x2;
    if(xd < xc) x3 = - abs(x3);
    else x3 = abs(x3);
    x2 = xc + x3;
    ddy[0] = II(xc, yc);
    while(x2 <= m && x2 >= 0)
    {
        b2 = xc - x2, a2 = -(yc - y2);
        c2 = -(a2 * xc + b2 * yc);
        y[++sly] = III(a2, II(b2, c2));
        ddy[sly] = II(x2, y2);
        if(y2 == n) y2 = 0;
        else y2 = n;
        x2 += x3;
    }
    double ds = 2e9;
    ii kq = ii(1, 1);
    for(int i = 1; i <= slx; ++i)
        for(int j = 1; j <= sly; ++j)
        {
            a1 = x[i].fi, b1 = x[i].se.fi, c1 = x[i].se.se;
            a2 = y[j].fi, b2 = y[j].se.fi, c2 = y[j].se.se;
            if(a1 * b2 - a2 * b1 != 0)
            {
                x1 = (1.0 * (c2 * b1 - c1 * b2))/(1.0 * (a1 * b2 - a2 * b1));
                y1 = 1.0 * (-c1 - a1 * x1)/(1.0 * b1);
                if(x1 >= 0 && x1 <= m && y1 >= 0 && y1 <= n)
                {
                   // if(i == 2) cout<<ddx[i].fi<<" "<<ddx[i].se<<" "<<ddy[j].fi<<" "<<ddy[j].se<<endl;
                    double t1 = kc(x1, y1, ddx[i - 1].fi, ddx[i - 1].se);
                    double t2 = kc(x1, y1, ddy[j - 1].fi, ddy[j - 1].se);
                    t1 += (i - 1) * tx.se;
                    t2 += (j - 1) * ty.se;
                    if(1.0 * t1 / tx.fi >= 1.0 * t2 / ty.fi && 1.0 * t1/tx.fi < ds)
                    {
                        ds = 1.0 * t1/tx.fi;
                        kq.fi = int(t1); kq.se = int(tx.fi);
                        int e = __gcd(kq.fi, kq.se);
                        kq.fi /= e; kq.se /= e;
                    }
                    else if(1.0 * t1 / tx.fi < 1.0 * t2 / ty.fi && 1.0 * t2/ty.fi < ds)
                    {
                        ds = 1.0 * t2/ty.fi;
                        kq.fi = (int)t2; kq.se = (int)ty.fi;
                        int e = __gcd(kq.fi, kq.se);
                        kq.fi /= e; kq.se /= e;
                    }
                }
            }
        }
        if(ds == 2e9){printf("-1\n"); return;}
        printf("%d %d\n", kq.fi, kq.se);
}

int main()
{
    freopen("motion.inp", "r", stdin);
    freopen("motion.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
        scanf("%d %d %d %d", &xc, &yc, &xd, &yd);
        tinh();
    }
}
