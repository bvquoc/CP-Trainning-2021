#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int maxdeg;
int n,q;
int a[500005];
int num[500005];
int nx[500005];
vector <int> ed[500005];
int deg[500005];
int query[500005];
int cnt;

void inp()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i],cnt += a[i];
    for (int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        ed[u].push_back(v);
        ed[v].push_back(u);
    }
    for (int i = 1; i <= q; i++)
        cin >> query[i];
}


void sub1()
{
    int u;
    if (cnt >= 2) cout << "1\n";
        else cout << "0\n";
    for (int i = 1; i <= q; i++)
    {
        u = query[i];
        if (a[u] == 1) cnt--;
        else cnt++;
        a[u] = 1 - a[u];
        if (cnt >= 2) cout << "1\n";
        else cout << "0\n";
    }
}

int color;

void ddff(int u,int par)
{
    if (par == 0)
    {
        num[u] = 3;
        for (int v:ed[u])
        {
            ddff(v,u);
            color++;
        }
        return;
    }
    num[u] = color;
    for (int v:ed[u])
    if (v!=par)
    {
        ddff(v,u);
    }
}


void sub2(int sttt)
{
    int u,dem;
    int du[4] = {0,0,0,0};
    ddff(sttt,0);
    for (int i = 1; i <= n; i++)
    if (a[i] == 1) du[num[i]]++;


    for (int j = 0; j < 3; j++) if (du[j] > 0) dem++;
    if (dem == 3) cout << "2\n";
    else if (dem == 2) cout << "1\n";
    else
    {
        if (cnt >= 2) cout << "1\n";
        else cout << "0\n";
    }


    for (int i = 1; i <= q; i++)
    {
        u = query[i];
        if (a[u] == 1) du[num[u]]--,cnt--;
        else du[num[u]]++,cnt++;
        a[u] = 1-a[u];
        dem = 0;
        for (int j = 0; j < 3; j++) if (du[j] > 0) dem++;
        if (dem == 3) cout << "2\n";
        else if (dem == 2) cout << "1\n";
        else
        {
            if (cnt >= 2) cout << "1\n";
            else cout << "0\n";
        }
    }
}


void proc()
{
    int cnt = 0,poss = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxdeg < deg[i])
        {
            poss = i;
            maxdeg = deg[i];
            cnt = 1;
        }
        else if (maxdeg == deg[i])
        {
            cnt++;
        }
    }
    if (maxdeg <= 2) sub1();
    else
    if (maxdeg == 3 && cnt == 1) sub2(poss);
}


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    inp();
    proc();
    return 0;
}
