#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

const long long mod = 1e6 + 3;
const int maxn = 4e5 + 1;
int n, m, a[maxn]; stack<int> S;
long long factorialNumInverse[maxn], naturalNumInverse[maxn], fact[maxn];
long long dp[4001][4001];

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
}

bool Check(int state)
{
    while (!S.empty()) S.pop();
    for (int i = 0; i < 2 * n; i++)
    if ((state >> i) & 1)
        S.push(i + 1);
    else
    {
        if (S.empty()) return false;
        int j = S.top(); S.pop();
        if (a[i + 1] - a[j] > m)
            return false;
    }
    if (!S.empty()) return false;
    return true;
}

void Sub1() // Quay lui
{
    int res = 0;
    for (int i = 0; i < (1 << (2 * n)); i++)
    if (Check(i)) res++;
    cout << res;
}

void InverseofNumber()
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i < maxn; i++)
        naturalNumInverse[i] = naturalNumInverse[mod % i] * (mod - mod / i) % mod;
}

void InverseofFactorial()
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i < maxn; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % mod;
}

void factorial()
{
    fact[0] = 1;
    for (int i = 1; i < maxn; i++)
        fact[i] = (fact[i - 1] * i) % mod;
}

int C(int n)
{
    return ((fact[2 * n] * factorialNumInverse[n]) % mod * factorialNumInverse[n + 1]) % mod;
}

void Prepare()
{
    InverseofNumber();
    InverseofFactorial();
    factorial();
}

void Sub2() // So day ngoac dung do dai 2 * n
{
    int res = C(n);
    cout << res;
}

int Get(int low, int high)
{
    if (low > high)
        return dp[low][high] = 1;
    if (dp[low][high] != -1)
        return dp[low][high];
    if ((high - low + 1) % 2 == 1)
        return dp[low][high] = 0;

    dp[low][high] = 0;
    if (a[high] - a[low] <= m)
        dp[low][high] = Get(low + 1, high - 1);
    for (int k = low + 1; k < high - 1; k++)
    {
        if (a[k] - a[low] > m) break;
        int s = (Get(low + 1, k - 1) * (long long) Get(k + 1, high)) % mod;
        dp[low][high] += s; if (dp[low][high] >= mod) dp[low][high] -= mod;
    }
    return dp[low][high];
}

void Sub3()
{
    for (int i = 1; i <= 2 * n; i++)
    for (int j = 1; j <= 2 * n; j++)
        dp[i][j] = -1;
    cout << Get(1, 2 * n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("test.inp" , "r" , stdin);
    //freopen("test.out" , "w" , stdout);

    freopen("mine.inp" , "r" , stdin);
    freopen("mine.out" , "w" , stdout);

    Input();
    if (n <= 10) Sub1();
    else
    {
        if (a[2 * n] - a[1] <= m)
        {
            Prepare();
            Sub2();
        }
        else Sub3();
    }
}

