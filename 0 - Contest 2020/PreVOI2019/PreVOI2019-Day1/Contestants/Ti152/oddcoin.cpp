#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int m = 16;
const int d = 1e5;
int a[20] = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int q,x,t;
int f[100005];

void inp()
{
    cin >> a[15];
    cin >> x;
}


void proc()
{
    //for (int i = 1; i <= x; i++) f[i] = i;

    for (int i = 1; i <= d; i++)
    {
        f[i] = i;
        for (int j = 0; j < m; j++)
        if (i - a[j] >= 0)
        {
            f[i] = min(f[i],f[i-a[j]]+1);
        }
    }
}


void sub12()
{
    cout << f[x] << endl;
}


void sub34()
{
    int ans = x;
    for (int i = 0; i <= d; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int diff = x - i;
            if (diff < 0 || diff % a[j] != 0) continue;
            ans = min(ans,f[i]+diff/a[j]);
        }
    }
    cout << ans << endl;
}


int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    cin >> q;
    while (q--)
    {
        inp();
        proc();
        if (x <= d)
        sub12();
        else
        sub34();
    }
    return 0;
}
