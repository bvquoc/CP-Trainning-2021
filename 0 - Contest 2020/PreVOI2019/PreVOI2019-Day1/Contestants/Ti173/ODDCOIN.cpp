#include <bits/stdc++.h>

using namespace std;

long long q, t, x;
long long a[20] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

long long tinh(long long money)
{
    long long res = 0;
    for (long long i = 14; i >= 0; i--)
    {
        res += money / a[i];
        money = money % a[i];
    }
    return res;
}

long long Xuly(long long money, long long x)
{
    long long res = 2e9;
    if (x > 50000)
    {
        for (long long i = 0; i * x <= money; i++)
        {
            res = min(res, tinh(money - i * x) + i);
        }
    }
    else
    {
        for (long long i = 0; i * x <= money && i <= 50000; i++)
        {
            res = min(res, tinh(money - i * x) + i);
        }
    }
    
    return res;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ODDCOIN.inp", "r", stdin);
    freopen("ODDCOIN.out", "w", stdout);
    cin >> q;
    while (q--)
    {
        cin >> x >> t;
        if (t < x || binary_search(a, a + 15, x))
        {
            cout << tinh(t) << '\n';
            continue;
        }
        cout << Xuly(t,x) << '\n';
        
    }
    
    return 0;
}