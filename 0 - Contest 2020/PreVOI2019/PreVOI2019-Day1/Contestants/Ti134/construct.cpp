
#include <bits/stdc++.h>
using namespace std;
const int max6 = 1e6 + 6;
const int oo = 1e9 + 9;
int it[4*max6],dt[4*max6];
int a[max6],h[max6],tmp[max6];
int n,m;

void update(int r,int k,int l,int u,int v,int delta)
{
    if (k > v || u > l)
        return ;
    if (u <= k && l <= v)
    {
        dt[r] += delta;
        return;
    }

    int g = (k + l) / 2;
    dt[2*r] += dt[r];
    dt[2*r+1] += dt[r];
    dt[r] = 0;

    update(2*r,k,g,u,v,delta);
    update(2*r+1,g+1,l,u,v,delta);

    it[r] = it[2*r] + dt[2*r] * (g-k+1) + it[2*r+1] + dt[2*r+1] * (l-g);
}

int get(int r,int k,int l,int u,int v)
{
    if (k > v || u > l)
        return 0;
    if (u <= k && l <= v)
        return it[r] + dt[r] * (l-k+1);

    int g = (k + l) / 2;
    dt[2*r] += dt[r];
    dt[2*r+1] += dt[r];
    dt[r] = 0;

    int tl = get(2*r,k,g,u,v);
    int tr = get(2*r+1,g+1,l,u,v);

    it[r] = it[2*r] + dt[2*r] * (g-k+1) + it[2*r+1] + dt[2*r+1] * (l-g);
    return tl + tr;
}

int main()
{
#define file "construct."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    int t;
    scanf("%d",&t);

    while (t -- )
    {
        scanf("%d %d",&n,&m);
        for (int i = 1; i <= 4 * n; ++i)
            it[i] = dt[i] = 0;

        for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&a[i]);
            update(1,1,n,i,i,a[i]);
        }
        while (m -- )
        {
            int type,l,r;
            scanf("%d %d %d",&type,&l,&r);
            if (type == 1)
            {
                int k;
                scanf("%d",&k);
                update(1,1,n,l,r,k);
            }
            else
            {
                int res = 0;
                for (int i = 1; i <= n; ++i)
                    tmp[i] = (i >= l && i <= r) ? get(1,1,n,i,i) : 0;
                while (1)
                {
                    int gmin = oo;
                    int dd = 0;
                    int cnt = 0;
                    for (int i = 1; i <= n; ++i)
                        if (tmp[i] != 0)
                        {
                            if (dd == 0)
                            {
                                dd = 1;
                                cnt++;
                            }
                            gmin = min(gmin,tmp[i]);
                        }
                        else
                            dd = 0;
                    bool all_zero = true;
                    for (int i = 1; i <= n; ++i)
                    {
                        if (tmp[i] > 0)
                            tmp[i] = tmp[i] - gmin;
                        if (tmp[i] != 0)
                            all_zero = false;
                    }
                    res = res + gmin * cnt;
                    if (all_zero)
                        break;
                }
                printf("%d\n",res);
            }
        }
    }
}
