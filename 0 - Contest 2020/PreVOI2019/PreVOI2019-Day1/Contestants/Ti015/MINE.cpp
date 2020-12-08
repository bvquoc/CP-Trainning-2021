#include <bits/stdc++.h>
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
const int MOD = 1000003;
int in[105],out[105],n,m,i,A[10005],ans,f[10005],stk[105],top;
int F[4005][4005];
bool check()
{
    int nin = 0;
    int nout = 0;
    int cnt = 0;
    top = 0;
    for (int i = 1; i <=2 * n; i++)
    {
        if (f[i] == 1)
        {
            in[++nin] = A[i];
            cnt++;
            stk[++top] = nin;
        }
        else {
            out[stk[top--]] = A[i];
            cnt--;
        }
        if (cnt < 0) return false;
    }

    if (cnt != 0) return false;
    for (i = 1; i <= n;i ++)
    {
        if (out[i] - in[i] > m) return false;
    }
    return true;
}
int bina(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        f[i] = j;
        if (i == 2 * n)
        {
            if (check()) ans++;
        }
        else bina(i + 1);
    }
}
void init()
{
    //reset(F);
    F[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int sum = 1; sum <= 2 * n; sum++)
        {
            F[i][sum] += F[i - 1][sum + 1];
            F[i][sum] %= MOD;
            F[i][sum] += F[i - 1][sum - 1];
            F[i][sum] %= MOD;
        }
        F[i][0] += F[i - 1][1];
        F[i][0] %= MOD;
    }
}
void solve()
{
    //reset(f);
    f[0] = 1;
    for (int i = 2; i <= 2 * n; i+= 2)
    {
        for (int j = i - 2; j >= 0; j -= 2)
        {
            if (A[i] - A[j + 1] > m) break;
            f[i] += (F[i - j - 2][0] * f[j]) % MOD;
            f[i]%= MOD;
        }
    }
}
void gentest()
{
    n = rand() % 10 + 1;
    m = rand() % 1000+ 2;
    for (int i = 1; i <= 2 * n; i++)
    {
        A[i] =(rand() % (m - 1)) + 1 + A[i-1];
    }
}
void checker()
{
    for (int i = 1; i <= 10; i++)
    {
        gentest();
        cout << n << " " << m << endl;
        for (int j = 1; j <= n; j++)
        {
            cout << A[j] << " ";
        }
        cout << endl;
        ans = 0;
        bina(1);
        init();
        solve();
        cout << "ans = " << ans << endl;
        cout << "out = " << f[2*n] << endl;
        if (ans == f[2*n]) cout << "TEST "  << i << "  OK !!" << endl;
        else
        {
            cout << "WA!!" << endl;
            break;
        }
    }
}
int main()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    cin >> n >> m;
    for (i = 1; i <= 2 * n; i++)
    {
        cin >> A[i];
    }
    init();
    solve();
    cout << f[2 * n];
    //checker();
    return 0;
}
