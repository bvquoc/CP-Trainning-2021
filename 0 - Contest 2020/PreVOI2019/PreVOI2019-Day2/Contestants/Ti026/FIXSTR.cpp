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
int n, m;
string s, luu[1005];
int a1[N], a2[N];
int T1[4 * N], T2[4 * N], lazy1[4 * N], lazy2[4 * N];
int calc(int l, int r)
{
    int dem = 0, dem1 = 0;
    FOR(i, l, r)
    {
        if(s[i] == ')')
        {
            if(dem1)
            {
                dem1 --;
            }
            else
            {
                dem ++;
            }
        }
        else
            dem1 ++;
    }
    dem1 = 0;
    FORD(i, r, l)
    {
        if(s[i] == '(')
        {
            if(dem1)
            {
                dem1 --;
            }
            else
                dem ++;
        }
        else
            dem1 ++;
    }
    return dem;
}
void sub1()
{
    FOR(i, 1, m)
    {
        luu[i] = s;
        char x;
        cin >> x;
        if(x == 'C')
        {
            int u;
            cin >> u;
            if(s[u] == '(')
            {
                s[u] = ')';
            }
            else
                s[u] = '(';
        }
        else if(x == 'Q')
        {
            int l, r;
            cin >> l >> r;
            cout << calc(l, r) << "\n";
        }
        else
        {
            int u;
            cin >> u;
            s = luu[u];
        }
//        cout << s << "\n";
    }
}
void init(int id, int l, int r)
{
    if(l == r)
    {
        T1[id] = a1[l];
        T2[id] = a2[l];
        return;
    }
    int mid = (l + r)/2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    T1[id] = max(T1[id * 2], T1[id * 2 + 1]);
    T2[id] = max(T2[id * 2], T2[id * 2 + 1]);
}
void down1(int id)
{
    if(lazy1[id] == 0) return;
    int val = lazy1[id];
    lazy1[id] = 0;
    T1[id * 2] += val;
    T1[id * 2 + 1] += val;
    lazy1[id * 2] += val;
    lazy1[id * 2 + 1] += val;
    return;
}
void update1(int id, int l, int r, int u, int v, int val)
{
    if(l > v || r < u) return;
    if(u <= l && v >= r)
    {
        T1[id] += val;
        lazy1[id] += val;
        return;
    }
    int mid = (l + r)/2;
    down1(id);
    update1(id * 2, l, mid, u, v, val);
    update1(id * 2 + 1, mid + 1, r, u, v, val);
    T1[id] = max(T1[id * 2], T1[id * 2 + 1]);
}
void down2(int id)
{
    if(lazy2[id] == 0) return;
    int val = lazy2[id];
    lazy2[id] = 0;
    T2[id * 2] += val;
    T2[id * 2 + 1] += val;
    lazy2[id * 2] += val;
    lazy2[id * 2 + 1] += val;
    return;
}
void update2(int id, int l, int r, int u, int v, int val)
{
    if(l > v || r < u) return;
    if(u <= l && v >= r)
    {
        T2[id] += val;
        lazy2[id] += val;
        return;
    }
    int mid = (l + r)/2;
    down2(id);
    update2(id * 2, l, mid, u, v, val);
    update2(id * 2 + 1, mid + 1, r, u, v, val);
    T2[id] = max(T2[id * 2], T2[id * 2 + 1]);
}
void up(int pos)
{
    down1(1);
    down2(1);
    if(s[pos] == '(')
    {
        s[pos] = ')';
        update1(1, 1, n, pos, n, +2);
        update2(1, 1, n, 1, pos, -2);
    }
    else
    {
        s[pos] = '(';
        update1(1, 1, n, pos, n, -2);
        update2(1, 1, n, 1, pos, +2);
    }
}
int get1(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return -n-5;
    if(l >= u && r <= v)
    {
        return T1[id];
    }
    int mid = (l + r)/2;
    down1(id);
    return max(get1(id * 2, l, mid, u, v), get1(id * 2 + 1, mid + 1, r, u, v));
}
int get2(int id, int l, int r, int u, int v)
{
    if(l > v || r < u) return -n-5;
    if(l >= u && r <= v)
    {
        return T2[id];
    }
    int mid = (l + r)/2;
    down2(id);
    return max(get2(id * 2, l, mid, u, v), get2(id * 2 + 1, mid + 1, r, u, v));
}
int get(int l, int r)
{
    down1(1);
    down2(1);
    int val1 = get1(1, 1, n, l, r);
    if(l > 1) val1 -= get1(1, 1, n, l - 1, l - 1);
    val1 = max(0, val1);
    int val2 = get2(1, 1, n, l, r);
    if(r < n) val2 -= get2(1, 1, n, r + 1, r + 1);
    val2 = max(0, val2);
    return val1 + val2;
}
void sub2()
{
    FOR(i, 1, n)
    {
        if(s[i] == '(') a1[i] = a1[i - 1] - 1;
        else a1[i] = a1[i - 1] + 1;
    }
    FORD(i, n, 1)
    {
        if(s[i] == '(') a2[i] = a2[i + 1] + 1;
        else a2[i] = a2[i + 1] - 1;
    }
    init(1, 1, n);
    FOR(i, 1, m)
    {
        char x;
        cin >> x;
        if(x == 'U')
        {
            return;
        }
        if(x == 'C')
        {
            int u;
            cin >> u;
            up(u);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << get(l, r) << "\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin >> s;
    n = s.size();
    s = ' ' + s;
    cin >> m;
    if(n <= 1000 && m <= 1000)
    {
        sub1();
    }
    else
    {
        sub2();
    }
    return 0;
}
