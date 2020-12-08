#include <iostream>
#include <fstream>
#include <string.h>

#define task "MINE"
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ifstream fi(task".inp");
ofstream fo(task".out");

typedef long long int lli;
typedef pair<int, int> II;

const int maxn = 2001;
const lli mod = 1e6+3;

int n, m;
int a[2*maxn];
lli f[2*maxn][2*maxn];
lli dp[maxn];
bool ff[2*maxn][2*maxn];

inline int ReadInt()
{
    char c;
    while (c = fi.get(), c < '0' || c > '9');
    int x = c - '0';
    while (c = fi.get(), c >= '0' && c <= '9')
        x = x*10 + c - '0';
    return x;
}

void WriteInt(lli x)
{
    if (x > 9) WriteInt(x / 10);
    fo.put(x % 10 + '0');
}

//Sub 1 + 2 + 3 + 4:
lli F(int i, int j)
{
    if (ff[i][j])
        return f[i][j];
    ff[i][j] = true;
    if (j == i+1 || i > j)
    {
        f[i][j] = 1;
        return 1;
    }
    f[i][j] = 0;
    for (int k = i+1; k <= j; k+=2)
    {
        if (a[k] - a[i] > m)
            break;
        //f[i][j] = (f[i][j] + F(i+1, k-1)*F(k+1, j) % mod) % mod;
        f[i][j] = (f[i][j] + dp[(k-i-1)/2]*F(k+1, j) % mod) % mod;
    }
    return f[i][j];
}

int main()
{
    n = ReadInt();
    m = ReadInt();
    //Sub 5:
    if (n > 2e5)
        return 0;
    //Init:
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++)
            dp[i] = (dp[i] + dp[j-1]*dp[i-j] % mod) % mod;
    }
    for (int i = 1; i <= 2*n; i++)
        a[i] = ReadInt();
    //Dp:
    memset(ff, false, sizeof(ff));
    reset(f);
    WriteInt(F(1, 2*n));
}
