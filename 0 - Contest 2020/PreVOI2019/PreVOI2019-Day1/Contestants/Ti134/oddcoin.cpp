#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> ii;
const int max6 = 1e6 + 6;
const int oo = 1e9 + 9;
set <ii> s;
int f[max6];
int a[100];
int n,q,x,t;

void sub1()
{
    a[++n] = x;
    for (int i = 1; i <= t; ++i)
        f[i] = oo;
    for (int i = 1; i <= n; ++i)
        f[a[i]] = 1;
    for (int i = 1; i <= t; ++i)
        for (int j = 1; j <= n; ++j)
            if (i - a[j] >= 1 && f[i-a[j]] != oo)
                f[i] = min(f[i],f[i-a[j]] + 1);
    printf("%d\n",f[t]);
    n--;
}

void sub2()
{
    s.insert({x,n+1});
    int cnt = 0;
    while (t > 0)
    {
        auto var = s.upper_bound({t,oo});
        var--;
        t = t - (*var).first;
        cnt++;
    }

    printf("%d\n",cnt);
    s.erase({x,n+1});
}
int main()
{
#define file "oddcoin."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d",&q);
    n = 0;
    int tmp = 1;
    for (int i = 1; i <= 5; ++i)
    {
        a[++n] = 1 * tmp;
        a[++n] = 3 * tmp;
        a[++n] = 5 * tmp;
        tmp = tmp * 10;
    }

    for (int i = 1; i <= n; ++i)
        s.insert({a[i],i});

    while (q -- )
    {
        scanf("%d %d",&x,&t);
        if (n <= 100000 && t <= 100000)
            sub1();
        else
            sub2();
    }
}
