// He always smiles :)
#include <bits/stdc++.h>
#define maxn 1000005
#define mod 1000000007
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define task "PAINT"
#define ll long long
#define reset(x, a) memset(x, a, sizeof(x))
#define endl "\n"

using namespace std;

int n, m, k;
char kq[maxn];
vector<int> a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> n;
    while(n --)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            char x;
            cin >> x;
            a[x].pb(++m);
        }
        else
        {
            char x, y;
            cin >> x >> y;
            for (int v : a[x]) a[y].pb(v);
            a[x].clear();
        }
    }
    for (int i = 'a' ; i <= 'z' ; i ++)
        for (int v : a[i]) kq[v] = i;
    for (int i = 1 ; i <= m ; i ++) cout << kq[i];
    return 0;
}
