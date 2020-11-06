#include<bits/stdc++.h>
using namespace std;

long long k, res = 1e18, tmpk;

bool square(long long x)
{
    long long t = sqrt(x);
    return t * t == x;
}

void check(long long i)
{
    long long n = k / i + i;
    if (n % 2 != 0) return;
    n /= 2;
    if (tmpk > 0) res = min(res, n);
    else res = min(res, abs(n - i));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;
    if (k == 0)
    {
        cout << 0;
        return 0;
    }
    tmpk = k;
    k = abs(k);
    for (long long i = 1; i <= sqrt(k); i++)
    {
        if (k % i == 0)
        {
            check(i);
            check(k / i);
        }
    }
    if (k == 0) res = 0;
    if (res == 1e18) cout << "none";
    else cout << res;
    return 0;
}
