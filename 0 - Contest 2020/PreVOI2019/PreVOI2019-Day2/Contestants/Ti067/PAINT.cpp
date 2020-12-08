#include<bits/stdc++.h>

const int maxn = 1e6 + 5;

using namespace std;

int n, nho[maxn];
vector<int> g[30];

void Input()
{
    scanf("%d", &n);
}

void sub1()
{
    int cnt = 0, type;
    char u, v;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &type);
        if(type == 1)
        {
            scanf(" %c ", &u);
            cnt++;
            g[u - 'a' + 1].push_back(cnt);
        }
        else
        {
            scanf(" %c %c ", &u, &v);
            for(int j : g[u - 'a' + 1]) g[v - 'a' + 1].push_back(j);
            g[u - 'a' + 1].clear();
        }
    }
    for(int i = 1; i <= 26; i++)
    {
        for(int j : g[i]) nho[j] = i;
    }
    for(int i = 1; i <= cnt; i++) printf("%c", 'a' + nho[i] - 1);
}

void Solve()
{
    if(n <= 10000) sub1();
    else sub1();
}

#define TASK "PAINT"
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
