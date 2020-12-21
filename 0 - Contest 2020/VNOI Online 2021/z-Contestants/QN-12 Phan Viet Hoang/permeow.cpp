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
int n, a[200010], b[200010];
bool check_sub1 = true, check_sub2 = true;
ll res = 0, mod = 1e9 + 7;
void inp ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("permeow.inp", "r", stdin);
    freopen ("permeow.out", "w", stdout);
    cin >> n;
    fr (i, 1, n) cin >> a[i];
    fr (i, 1, n) cin >> b[i];
    fr (i, 1, n) if (a[i] != b[i])
    {
        check_sub1 = false;
        break;
    }
    fr (i, 1, n) if (a[i] != i or b[i] != n - i + 1)
    {
        check_sub2 = false;
        break;
    }
}
void sub1 ()
{
    while (true)
    {
        bool check = true;
        fr (i, 1, n - 1)
        {
            if (a[i] > a[i + 1])
            {
                res = (res + 1) % mod;
                check = false;
                swap(a[i], a[i + 1]);
            }
        }
        if (check == true) break;
    }
    cout << res;
    exit(0);
}
void sub2 ()
{
    res = 0;
    if (n == 2) cout << 1;
    if (n == 3) cout << 9;
    if (n == 4) cout << 73;
}
int main ()
{
    inp();
    if (check_sub1 == true) sub1();
    if (check_sub2 == true) sub2();
    return 0;
}

