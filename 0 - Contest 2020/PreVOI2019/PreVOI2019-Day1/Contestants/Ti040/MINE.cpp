#include <bits/stdc++.h>

using namespace std;
#define taskname "MINE"
typedef int64_t ll;
const ll mod = 1000003;

int n, m, n2;
int a[400005];
ll fact[400005];
int b[25], tin[25], res, bit1, bit0, stk[25];

void Try(int x)
{
    if (x > n2)
    {
        int sum = 0;
        for (int i = 1; i <= n2; i++)
            if (b[i] == 0)
                sum++;
            else
            {
                sum--;
                if (sum < 0)
                    return;
            }
        if (sum != 0)
            return;
        int cur = 0, pos = 0, pp = 0;
        for (int i = 1; i <= n2; i++)
            if (b[i] == 0)
            {
                cur++;
                stk[++pp] = cur;
                tin[cur] = a[i];
            }
            else
            {
                pos = stk[pp]; pp--;
                if (a[i] - tin[pos] > m)
                    return;
            }
        res++;
        return;
    }
    if (bit0 < n)
    {
        bit0++;
        b[x] = 0;
        Try(x + 1);
        bit0--;
    }
    if (bit1 < n)
    {
        bit1++;
        b[x] = 1;
        Try(x + 1);
        bit1--;
    }
}

ll pw(ll A, int P)
{
    ll tmp = 1;
    while (P > 0)
    {
        if ((P & 1))
            tmp = tmp * A % mod;
        A = A * A % mod;
        P >>= 1;
    }
    return tmp;
}

int main()
{
    if (fopen (taskname".inp", "r"))
    {
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> m;
    n2 = n + n;
    for (int i = 1; i <= n2; i++)
        cin >> a[i];
    if (n <= 10)
    {
        Try(1);
        cout << res;
        return 0;
        cout << '\n';
    }
    if (m >= (a[n2] - a[1]))
    {
        fact[0] = 1;
        for (int i = 1; i <= n2; i++)
            fact[i] = fact[i - 1] * (ll)i % mod;
        cout << (fact[n2] * pw(fact[n], mod - 2) % mod) * pw(fact[n + 1], mod - 2) % mod;
        return 0;
        cout << '\n';
    }
}
