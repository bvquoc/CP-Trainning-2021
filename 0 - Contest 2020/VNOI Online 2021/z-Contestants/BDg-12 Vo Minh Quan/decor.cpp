#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;


int n,m,k;
int ans;
int num[500005];
vector <int> ed[500005];
int a[500005];
int sang[500005];
int d[500005];
string sss;

void inp()
{
    cin >> n >> m >> k;
    cin >> sss;
    for (int i = 1; i <= n; i++)
    {
        a[i] = sss[i-1]-'0';
    }
    for (int i = 1; i <= m; i++)
    {
        int x,y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
}


int cnt;

void dfs(int u)
{
    num[u] = cnt;
    if (a[u] == 1) sang[cnt]++;
    for (int v:ed[u])
    if (num[v] == 0)
    {
        dfs(v);
    }
}


void pre()
{
    for (int i = 1; i <= n; i++)
    if (num[i] == 0)
    {
        cnt++;
        dfs(i);
    }
}


void proc()
{
    int ans = -1,l,r,j=1,o;
    int ned = 0;
    for (int i = 1; i <= n; i++)
    {
        o = num[i];
        d[o]++;
        if (d[o] > sang[o]) ned++;
        while (ned > k)
        {
            d[num[j]]--;
            if (d[num[j]] >= sang[num[j]]) ned--;
            j++;
        }
        if (i - j + 1 > ans)
        {
            ans = i - j + 1;
            l = j;
            r = i;
        }
    }
    if (ans <= 0) cout << -1;
    else cout << l << ' ' << r;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("decor.inp","r",stdin);
    freopen("decor.out","w",stdout);
    inp();
    pre();
    proc();
    return 0;
}
