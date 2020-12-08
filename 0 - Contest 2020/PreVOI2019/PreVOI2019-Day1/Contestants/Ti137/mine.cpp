#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5, mod = 1e6 + 3;

int n, m, a[2 * maxn], dd[2 * maxn], ds = 0;

void tinh(int i, int j)
{
    dd[i] = 1; dd[j] = 1;
    if(j == i + 1)
    {
        for(int k = j + 1; k <= 2 * n; ++k)
            for(int l = k + 1; l <= 2 * n && a[k] + m >= a[l]; ++l)
            if((l - k) % 2 && dd[k] == 0 && dd[l] == 0) tinh(k, l);
    }
    else{
        for(int k = i + 1; k < j; ++k)
            for(int l = k + 1; l < j && a[k] + m >= a[l]; ++l)
            if((l - k) % 2 && dd[k] == 0 && dd[l] == 0) tinh(k, l);
    }
    bool ok = true;
    for(int k = 1; k <= 2 * n; ++k) if(dd[k] == 0){ok = false; break;}
    if(ok == true) ds++, ds %= mod;
    dd[i] = 0; dd[j] = 0;
}

void sub1()
{
    for(int i = 2; i <= 2 * n && a[1] + m >= a[i]; ++i)
    if(i % 2 == 0) tinh(1, i);
    printf("%d", ds);
}

int main()
{
    freopen("mine.inp", "r", stdin);
    freopen("mine.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 2 * n; ++i) scanf("%d", &a[i]);
    sub1();

}
