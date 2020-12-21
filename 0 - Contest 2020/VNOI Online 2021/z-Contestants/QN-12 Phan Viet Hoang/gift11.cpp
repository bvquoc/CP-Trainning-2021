#include <bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i = x; i <= y; ++i)
#define ft(i, x, y) for (int i = y; i >= x; --i)
#define pii pair <int, int>
#define getbit(x, k) ((x) & (1 << (k)))
#define flip(x, k) ((x) ^ (1 << (k)))
#define ll long long
using namespace std;
int T, n, num[100010], c[100010], fact[1000010];
ll mod = 998244353, res = 0;
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("gift11.inp", "r", stdin);
    freopen ("gift11.out", "w", stdout);
    cin >> T;
}
void sub1 ()
{
    fr (i, 1, n) num[i] = i;
    do
    {
        ll sum_odd = 0, sum_even = 0;
        int pos = 0;
        fr (i, 1, n)
        {
            int number = c[num[i]];
            while (number > 0)
            {
                pos++;
                if (pos & 1) sum_odd += number % 10;
                else sum_even += number % 10;
                number /= 10;
            }
        }
        if (abs(sum_odd - sum_even) % 11 == 0) res = (res + 1) % mod;
    } while (next_permutation(num + 1, num + n + 1));
    cout << res << "\n";
}
void sub2 ()
{
    ll sum_odd = 0, sum_even = 0;
    int pos = 0;
    fr (i, 1, n)
    {
        int number = c[i];
        while (number > 0)
        {
            pos++;
            if (pos & 1) sum_odd += number % 10;
            else sum_even += number % 10;
            number /= 10;
        }
    }
    if (abs(sum_odd - sum_even) % 11 == 0) res = fact[n];
    cout << res << "\n";
}
int main ()
{
    inp();
    fact[0] = 1;
    fr (i, 1, 1e6) fact[i] = (fact[i - 1] * i) % mod;
    while (T--)
    {
        res = 0;
        bool ok = true;
        cin >> n;
        fr (i, 1, n)
        {
            cin >> c[i];
            int number = c[i], cnt = 0;
            while (number > 0)
            {
                cnt++;
                number /= 10;
            }
            if (cnt & 1) ok = false;
        }
        if (n <= 8) sub1();
        else sub2();
    }
    return 0;
}




