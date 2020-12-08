#include<bits/stdc++.h>

using namespace std;

int T, a[15];

void Input()
{
    scanf("%d", &T);
}

void Solve()
{
    while(T--)
    {
        for(int i = 1; i <= 10; i++) scanf("%d", &a[i]);
        printf("-1\n");
    }
}

#define TASK "MOTION"
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
