#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5;
struct data
{
    int l, r;
} a[maxN + 5];
data b[maxN + 5];
int f[maxN + 5];
int n;
bool cmp(data a, data b)
{
    if (a.l != b.l) return a.l < b.l;
    return a.r > b.r;
}
void upd(int p)
{
    for (; p <= maxN; p += p & -p)
        f[p] ++;
}
int getsum(int p)
{
    int ans = 0;
    for (; p > 0; p -= p & -p)
        ans += f[p];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + 1 + n, cmp);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (getsum(maxN) - getsum(a[i].r) <= 0)
        {
            b[++cnt] = a[i];
            upd(a[i].r);
        }
    }
    b[++cnt].l = b[cnt].r = maxN;
    cin >> n;
    int cur = maxN;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cur = min(cur, x);
    }
    int i = 1;
    while (cur > b[i].r) i++;
    int ans = 0;
    while (cur != maxN + 1)
    {
        //cout << i << " " <<  cur << '\n';
        if (b[i].l <= cur && cur <= b[i].r) cur = b[i].r + 1, ans++;
        else
        {
            cout << -1;
            return 0;
        }
        i++;
    }
    cout << ans;
    return 0;
}
