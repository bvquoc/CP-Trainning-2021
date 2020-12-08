///------------------  ONESHOTAC -------------------
#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
//#define f first
//#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
const int N = 1000005;
int T, n, m;
int a[N];
long long T1[4 * N], T2[4 * N];
void init(int id, int l, int r)
{
    if(l == r)
    {
        if(l != 1) T2[id] = max(0, a[l] - a[l - 1]);
        else T2[id] = 0;
        T1[id] = a[l];
        return;
    }
    int mid = (l + r)/2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    T2[id] = T2[id * 2] + T2[id * 2 + 1];
}
void down(int id)
{
    if(T1[id] == 0) return;
    int val = T1[id];
    T1[id * 2] += val;
    T1[id * 2 + 1] += val;
    T1[id] = 0;
}
int get1(int id, int l, int r, int pos)
{
    if(l > pos || r < pos) return 0;
    if(l == r)
    {
        return T1[id];
    }
    int mid = (l + r)/2;
    down(id);
    if(pos <= mid) return get1(id * 2, l, mid, pos);
    else return get1(id * 2 + 1, mid + 1, r, pos);
}
long long get2(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return 0;
    if(l >= u && r <= v)
    {
        return T2[id];
    }
    int mid = (l + r)/2;
    return get2(id * 2, l, mid, u, v) + get2(id * 2 + 1, mid + 1, r, u, v);
}
void update1(int id, int l, int r, int u, int v, int val)
{
    if(l > v || r < u) return;
    if(u <= l && v >= r)
    {
        T1[id] += val;
        return;
    }
    int mid = (l + r)/2;
    down(id);
    update1(id * 2, l, mid, u, v, val);
    update1(id * 2 + 1, mid + 1, r, u, v, val);
}
void update2(int id, int l, int r, int pos, int val)
{
    if(l > pos || r < pos) return;
    if(l == r)
    {
        T2[id] = val;
        return;
    }
    int mid = (l + r)/2;
    update2(id * 2, l, mid, pos, val);
    update2(id * 2 + 1, mid + 1, r, pos, val);
    T2[id] = T2[id * 2] + T2[id * 2 + 1];
}
void solve()
{
    init(1, 1, n);
    FOR(i, 1, m)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1)
        {
            int x;
            cin >> x;
            update1(1, 1, n, l, r, x);
            if(l != 1)
            {
                int val1 = max(0, get1(1, 1, n, l) - get1(1, 1, n, l - 1));
                update2(1, 1, n, l, val1);
            }
            if(r != n)
            {
                int val1 = max(0, get1(1, 1, n, r + 1) - get1(1, 1, n, r));
                update2(1, 1, n, r + 1, val1);
            }
        }
        else
        {
            int x = get1(1, 1, n, l);
            cout << get2(1, 1, n, l + 1, r) + x << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CONSTRUCT.inp","r",stdin);
    freopen("CONSTRUCT.out","w",stdout);
    cin >> T;
    while(T --)
    {
        cin >> n >> m;
        FOR(i, 1, n) cin >> a[i];
        solve();
    }
    return 0;
}
