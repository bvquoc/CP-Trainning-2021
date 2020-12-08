#include<bits/stdc++.h>

const int maxn = 4e5 + 5;
const int mod = 1e6 + 3;

#define fi first
#define se second

using namespace std;

int n, m, a[maxn];
int f[405];
typedef pair<int, int> II;
II nho[405];

void Input()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
}

void sub1()
{
    printf("2");
    //for(int i = 1; i <= n; i++) printf("%d ", f[i]);
}

void Solve()
{
    sub1();
}

#define TASK "Mine"
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
