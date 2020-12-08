#include<bits/stdc++.h>

const int maxn = 1e5 + 5;
const int INF = 2e9 + 5;

using namespace std;

int Q, val, T;
int a[25], b[25], x[25], Ds1;
int f[maxn];

void Input()
{
    scanf("%d", &Q);
}

void Process()
{
    int cnt = 0, dem = 0, Tmp = T;
    for(int i = 1; i <= 5; i++) if(x[i]) b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    if(cnt == 0) return;
    for(int i = cnt; i >= 1; i--)
    {
        if(Tmp < b[i]) return;
        while(Tmp >= b[i])
        {
            Tmp -= b[i];
            dem++;
        }
    }
    if(Tmp != 0) return;
    Ds1 = min(Ds1, dem);
}

void Try(int k)
{
    if(k > 5)
    {
        Process();
        return;
    }
    for(int i = 0; i <= 1; i++)
    {
        x[k] = i;
        Try(k + 1);
    }
}

void sub1()
{
    a[1] = 1, a[2] = 3, a[3] = 5, a[4] = 10, a[5] = val;
    Ds1 = INF;
    Try(1);
    printf("%d\n", Ds1);
}

void sub2()
{
    a[1] = 1, a[2] = 3, a[3] = 5, a[4] = 10, a[5] = 30, a[6] = 50, a[7] = 100, a[8] = 300, a[9] = 500;
    a[10] = 1000, a[11] = 3000, a[12] = 5000, a[13] = 10000, a[14] = 30000, a[15] = 50000, a[16] = val;
    sort(a + 1, a + 17);
    f[0] = 0;
    for(int x = 1; x <= T; x++) f[x] = INF;
    for(int x = 1; x <= T; x++)
    {
        for(int i = 1; i <= 16 && a[i] <= x; i++)
        {
            if(f[x - a[i]] != INF) f[x] = min(f[x], f[x - a[i]] + 1);
        }
    }
    printf("%d\n", f[T]);
}

void Solve()
{
    while(Q--)
    {
        scanf("%d %d", &val, &T);
        if(val <= 20 && T <= 20) sub1();
        else sub2();
    }
}

#define TASK "Oddcoin"
int main()
{
    #ifdef TASK
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    #else
    freopen("1.inp", "r", stdin);
    #endif // TASK
    Input();
    Solve();
}
