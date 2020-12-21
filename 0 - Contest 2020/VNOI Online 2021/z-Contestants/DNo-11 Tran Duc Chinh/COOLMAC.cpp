#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define int long long
using namespace std;
struct kaka{
     int u,v;
};
kaka a[100005];
bool cmd(const kaka &g, const kaka &h)
{
    if (g.v == h.v) return g.u < h.u;
    return g.v < h.v;
}
int n,m,k,qq = 1e9,z,s,x,y,tamu;
signed main()
{
    FastIO;
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].u >> a[i].v;
    cin >> m;
    while (m--)
    {
        cin >> k;
        if (qq > k)
            qq = k;
    }
    sort(a+1,a+n+1,cmd);
    if (a[n].v != 100000)
    {
        cout << -1;
        return 0;
    }
    z = n;
    while (z > 0)
    {
        if (a[z].v == a[z-1].v)
        {
            z--;
            continue;
        }
        if (a[z].v == 100000)
        {
            x = a[z].u;
            tamu = x;
        }
        if (a[z].v > x && a[z].u < tamu)
        {
            tamu = a[z].u;
        }
        if (a[z].v < x)
        {
            if (tamu == x)
            {
                cout <<-1;
                return 0;
            }
            s++;
            x = tamu;
            z++;
        }
        z--;
        if (x <= qq)
            break;
    }
    if (x <= qq)
        cout << s + 1;
    else cout << -1;
    return 0;
}
