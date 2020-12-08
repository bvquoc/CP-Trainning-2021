#include <bits/stdc++.h>
using namespace std;
const int max6 = 1e6 + 6;
const int mod = 1000003;
int a[2*max6],f[max6];
int n,m;


void sub1()
{
    f[0] = 1;
        f[1] = 1;
        f[2] = 2;
        //f[3] = 5;

        for (int i = 3; i <= n; ++i)
            for (int j = 0; j <= i - 1; ++j)
                f[i] = (f[i] + (1ll * f[j] * f[i-j-1]) % mod) % mod;

        printf("%d",f[n]);
}

void sub2()
{
    sub1();
}
int main()
{
#define file "mine."
    freopen(file"inp","r",stdin);
    freopen(file"out","w",stdout);

    scanf("%d %d",&n,&m);
    for (int i = 1; i <= 2*n; ++i)
        scanf("%d",&a[i]);
    if (a[n] - a[1] >= m)
        sub1();
    else sub2();
}
