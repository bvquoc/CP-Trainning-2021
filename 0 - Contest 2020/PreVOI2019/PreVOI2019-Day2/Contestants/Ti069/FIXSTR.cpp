// He always smiles :)
#include <bits/stdc++.h>
#define maxn 10000005
#define mod 1000000007
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define task "FIXSTR"
#define ll long long
#define reset(x, a) memset(x, a, sizeof(x))
#define endl "\n"

using namespace std;
string s, str[maxn];
int n, m;
pii t[maxn];
void init(int k, int l, int r, string s)
{
    if(l == r)
    {
        if(s[l] == '(') t[k] = {1, 0};
        else t[k] = {-1, 1};
        return;
    }
    int mid = (l + r) / 2;
    init(k * 2, l, mid, s);
    init(k * 2 + 1, mid + 1, r, s);
    t[k].fi = t[k * 2].fi + t[k * 2 + 1].fi;
    t[k].se = max(t[k * 2 + 1].se - t[k * 2].fi, t[k * 2].se);
}
void update(int k, int l, int r, int u, string s)
{
    if(l > u || r < u) return;
    if(l == r && l == u)
    {
        if(s[l] == '(') t[k] = {1, 0};
        else t[k] = {-1, 1};
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, s);
    update(k * 2 + 1, mid + 1, r, u, s);
    t[k].fi = t[k * 2].fi + t[k * 2 + 1].fi;
    t[k].se = max(t[k * 2 + 1].se - t[k * 2].fi, t[k * 2].se);
}
pii get(int k, int l, int r, int u, int v)
{
    if(l > v || r < u) return {0, 0};
    if(l >= u && r <= v)
        return t[k];
    int mid = (l + r) / 2;
    pii trai = get(k * 2, l, mid, u, v);
    pii phai = get(k * 2 + 1, mid + 1, r, u, v);
    return {trai.fi + phai.fi, max(phai.se - trai.fi, trai.se)};
}
void sub1()
{
    str[0] = s;
    for (int lenh = 1 ; lenh <= m ; lenh ++)
    {
        str[lenh] = str[lenh - 1];
        char type;
        cin >> type;
        if(type == 'C')
        {
            int i;
            cin >> i;
            if(str[lenh][i] == '(') str[lenh][i] = ')';
            else str[lenh][i] = '(';

        }
        else if(type == 'Q')
        {
            int i, j;
            cin >> i >> j;
            int dem(0), ans(0);
            for (int l = i ; l <= j ; l ++)
                if(str[lenh][l] == '(') ++dem;
                else
                {
                    if(dem) --dem;
                    else ++ans;
                }
            cout << ans + dem << endl;
        }
        else
        {
            int k;
            cin >> k;
            str[lenh] = str[k - 1];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> s;
    n = s.length();
    s = " " + s;
    init(1, 1, n, s);
    cin >> m;
    if(n <= 1000 && m <= 1000)
    {
        sub1();
        return 0;
    }
    str[0] = s;
    for (int lenh = 1 ; lenh <= m ; lenh ++)
    {
        str[lenh] = str[lenh - 1];
        char type;
        cin >> type;
        if(type == 'C')
        {
            int i;
            cin >> i;
            if(str[lenh][i] == '(') str[lenh][i] = ')';
            else str[lenh][i] = '(';
            update(1, 1, n, i, str[lenh]);

        }
        else if(type == 'Q')
        {
            int i, j;
            cin >> i >> j;
            pii x = get(1, 1, n, i, j);
            cout << 2 * x.se + x.fi << endl;
        }
        else
        {
            int k;
            cin >> k;
            str[lenh] = str[k - 1];
            init(1, 1, n, str[lenh]);
        }
    }
    return 0;
}
