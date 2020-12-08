#include<bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i=x; i<=y; i++)
#define ft(i, x, y) for (int i=y; i>=x; i--)
#define pb push_back
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
using namespace std ;
int n;
pll a[20];
bool cmd (pll a, pll b)
{
    if (a.se<b.se)
        return a<b;
}
void inp ()
{
    freopen ("oddcoin.inp", "r", stdin);
    freopen ("oddcoin.out", "w", stdout);
    scanf ("%d", &n);
    a[1].fi=1;
    a[2].fi=3;
    a[3].fi=5;
    a[4].fi=10;
    a[5].fi=30;
    a[6].fi=50;
    a[7].fi=100;
    a[8].fi=300;
    a[9].fi=500;
    a[10].fi=1000;
    a[11].fi=3000;
    a[12].fi=5000;
    a[13].fi=10000;
    a[14].fi=30000;
    a[15].fi=50000;
    a[1].se=1;
    a[2].se=2;
    a[3].se=3;
    a[4].se=4;
    a[5].se=5;
    a[6].se=6;
    a[7].se=7;
    a[8].se=8;
    a[9].se=9;
    a[10].se=10;
    a[11].se=11;
    a[12].se=12;
    a[13].se=13;
    a[14].se=14;
    a[15].se=15;
}
void sub1 ()
{
    fr (i, 1, n)
    {
        ll x, t;
        scanf ("%lld%lld", &x, &t);
        a[16].fi=x;
        a[16].se=16;
        sort (a+1, a+17);
        ll res1=0, res2=0, res;
        ll tt=t;
        while (t>0)
        {
            int l=1;
            int r=16;
            while (l<r)
            {
                int mid=(l+r+1)/2;
                if (a[mid].fi<=t)
                    l=mid;
                else
                    r=mid-1;
            }
            int times=t/a[r].fi;
            ll mi=times*a[r].fi;
            res1+=times;
            t-=mi;
        }
        t=tt;
        while (t>0)
        {
            int ck=50010, num=0;
            fr (i, 2, 16)
            {
                if (t<a[i].fi) break;
                if (t%a[i].fi<=ck)
                {
                    ck=t%a[i].fi;
                    num=a[i].fi;
                }
            }
            if (num==0) num=1;
            int times=t/num;
            ll mi=times*num;
            res2+=times;
            t-=mi;
        }
        res=min(res1, res2);
        printf ("%lld\n", res);
        fr (j, 1, 16)
        {
            swap(a[j].fi, a[j].se);
        }
        sort (a+1, a+17);
        fr (j, 1, 16)
        {
            swap(a[j].fi, a[j].se);
        }
    }
}
int main ()
{
    inp ();
    sub1 ();
    return 0;
}

