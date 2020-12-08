#include<bits/stdc++.h>

using namespace std;

int q, x, t, a[20], a1[20], b[20], dd[20], ds;

void xuli()
{
    int sl = 0;
    for(int i = 1; i <= 16; ++i) if(dd[i] == 1) b[++sl] = a1[i];
    if(b[sl] > t) return;
    int dem = 0, t1 = t;
    for(int i = sl; i >= 1; --i)
    {
        dem += t1/b[i];
        t1 -= t1/b[i] * b[i];
        if(t1 == 0) {ds = min(ds, dem); return;}
    }
}

void thu(int u)
{
    if(u > 16){xuli(); return;}
    for(int i = 0; i <= 1; ++i)
    {
        dd[u] = i;
        thu(u + 1);
    }
}

void sub1()
{
    for(int i = 1; i <= 15; ++i) a1[i] = a[i];
    a1[16] = x;
    sort(a1 + 1, a1 + 17);
    ds = 2e9 + 9;
    thu(1);
    printf("%d\n", ds);
}

int main()
{
    freopen("oddcoin.inp", "r", stdin);
    freopen("oddcoin.out", "w", stdout);
    scanf("%d", &q);
    a[1] = 1; a[2] = 3; a[3] = 5; a[4] = 10; a[5] = 30;
    a[6] = 50; a[7] = 100; a[8] = 300; a[9] = 500; a[10] = 1000;
    a[11] = 3000; a[12] = 5000; a[13] = 10000; a[14] = 30000; a[15] = 50000;
    for(int i = 1; i <= q; ++i)
    {
        scanf("%d %d", &x, &t);
        sub1();
    }

}
