#include <bits/stdc++.h>

using namespace std;
#define task "PERMEOW"
const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
int N;
int A[MAXN];
int B[MAXN];
void Input()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    for(int i = 1; i <= N; i++)
        cin >> B[i];
}
int t[MAXN];
void Upd(int u)
{
    while(u <= N)
    {
        t[u]++;
        u += u & -u;
    }
}
void add(int &x, const int &y)
{
    x += y;
    if(x >= mod)
        x -= mod;
}
int Get(int u)
{
    int ans = 0;
    while(u)
    {
        add(ans, t[u]);
        u -= u & -u;
    }
    return ans;
}
int f[MAXN];
void Init()
{
    f[0] = 1;
    for(int i = 1; i < MAXN; i++)
        f[i] = 1LL * f[i - 1] * i % mod;
}
int Pow(int a, int n)
{
    int ans = 1, temp = a;
    while(n)
    {
        if(n & 1)
            ans = 1LL * ans * temp % mod;
        n >>= 1;
        temp = 1LL * temp * temp % mod;
    }
    return ans;
}
int C(const int &k, const int &n)
{
    if(k > n)
        return 0;
    return 1LL * f[n] * Pow(1LL * f[k] * f[n - k] % mod, mod - 2) % mod;
}
void Output()
{
    int ans = 0;
    do
    {
        memset(t, 0, sizeof t);
        for(int i = N; i >= 1; i--)
        {
            add(ans, Get(A[i]));
            Upd(A[i]);
        }
        bool ok = true;
        for(int i = 1; i <= N; i++)
            if(A[i] != B[i])
        {
            ok = false;
            break ;
        }
        if(ok)
            break ;
    }
    while(next_permutation(A + 1, A + 1 + N));
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Input();
    Init();
    Output();
    return 0;
}
