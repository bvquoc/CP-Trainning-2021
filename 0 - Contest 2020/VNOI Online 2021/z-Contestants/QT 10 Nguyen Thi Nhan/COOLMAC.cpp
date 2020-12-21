#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

pair <int,int> nd[100002];

int m,n,st[500002],nho;

void build (int id,int l,int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        st[id] = nd[l].se;return;
    }
    int mid = (l + r) / 2;
    build(id * 2,l,mid);
    build(id * 2 + 1,mid + 1,r);
    st[id] = max(st[id * 2],st[id * 2 + 1]);
}

int get(int id,int l,int r,int u,int v)
{
    if (v < l || r < u) return INT_MIN;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2,l,mid,u,v),get(id * 2 + 1,mid + 1,r,u,v));
}

int main()
{
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> m;
    for (int i = 1;i <= m;i++)
    {
        int l,r;
        cin >> l >> r;
        nd[i] = {l,r};
    }
    cin >> n;
    int MIN = INT_MAX;
    for (int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        MIN = min(MIN,x);
    }
    sort(nd + 1,nd + 1 + m);
    build(1,1,m);
    int ans = 0;
    if (nd[1].fi > MIN) {cout << -1;return 0;}
    nd[m + 1] = make_pair(INT_MAX,INT_MAX);
    while (MIN <= 100000)
    {
        ans++;
        pair <int,int> tam = {MIN,1000000};
        int r = upper_bound(nd + 1,nd + 1 + m,tam) - nd;
        r--;
        int tmp = get(1,1,m,1,r) + 1;
        if (MIN >= tmp)
        {
            cout << -1;return 0;
        }
        else
            MIN = tmp;
    }
    cout << ans;
    return 0;
}
