#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long lli;
typedef pair<int, int> pii;
const int maxn = 2e6 + 5;
int n;

int to[100];
char ans[maxn];
int cnt = 0;

int lab[maxn];

void ReadInput()
{
    cin >> n;
}

int Find(int u)
{
    return lab[u] < 0 ? u : lab[u] = Find(lab[u]);
}

void Union(int u, int v)
{
    if(lab[u] < lab[v]) swap(u, v);
    lab[v] += lab[u];
    lab[u] = v;
}

void Solve()
{
    fill(begin(to), end(to), -1);
    fill(begin(lab), end(lab), -1);
    for(; n > 0; --n)
    {
        int type;
        char x, y;
        cin >> type >> x;
        if(type == 1)
        {
            ++cnt;
            if(to[x - 'a'] == -1)
                to[x - 'a'] = cnt;
            else
            {
                int u = to[x - 'a'], v = cnt;
                u = Find(u); v = Find(v);
                if(u != v) Union(u, v);
            }
        }
        else
        {
            cin >> y;
            int u = to[x - 'a'], v = to[y - 'a'];
            if(u == -1) continue;
            if(v == -1)
            {
                to[x - 'a'] = -1;
                to[y - 'a'] = u;
                continue;
            }
            u = Find(u); v = Find(v);
            if(u != v) Union(u, v);
            to[x - 'a'] = -1;
        }
    }

    for(int i = 0; i < 26; ++i)
    {
        int u = to[i];
        if(u == -1) continue;
        u = Find(u);
        ans[u] = i + 'a';
    }

    for(int i = 1; i <= cnt; ++i)
    {
        int u = i;
        u = Find(u);
        ans[i] = ans[u];
    }

    for(int i = 1; i <= cnt; ++i)
        cout << ans[i];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    ReadInput();
    Solve();
}
