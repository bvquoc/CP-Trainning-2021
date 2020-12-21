#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (ll i = (a); i <= (b); ++i)
#define ff first
#define ss second
#define pb push_back
#define sz size()
#define name "gift11"
const ll maxn = 2e3 + 7, oo = 1e18, mod = 998244353, base = 90013;
ll t, n[12], sumN, vis[maxn], res, ok[maxn], gt[maxn], odd[12][maxn], even[12][maxn], du11[3][12][maxn];
string s[12][maxn];
void solve(int nTest)
{
    string stmp = "";
    rep (i, 1, n[nTest])
        stmp += s[nTest][ok[i]];
    int len = stmp.sz;
    stmp = " " + stmp;
    int le = 0;
    int chan = 0;
    rep (i, 1, len)
    {
        if (i % 2 == 1)
            le += (stmp[i] - '0');
        else chan += (stmp[i] - '0');
    }
    if ((le - chan + base) % 11 == 0)
        ++res;
}
void sub1(int nTest, int i)
{
    if (i > n[nTest])
    {
        solve(nTest);
        return;
    }
    rep (j, 1, n[nTest])
        if (vis[j] == 0)
        {
            ok[i] = j; // vi tri thu i la la bai thu j
            vis[j] = 1;
            sub1(nTest, i + 1);
            ok[i] = 0;
            vis[j] = 0;
        }
}
bool issub2()
{
    rep (i, 1, t)
        rep (j, 1, n[i])
            if (s[i][j].sz % 2 != 0)
                return false;
    return true;
}
bool check()
{
    int le, chan;
    le = chan = 0;
    rep (i, 1, t)
        rep (j, 1, n[i])
        {
            string tmp = s[i][j];
            int len = tmp.sz;
            tmp = " " + tmp;
            rep (h, 1, len)
            {
                if (h % 2 == 1)
                    le += (tmp[h] - '0');
                else chan += (tmp[h] - '0');
            }
        }
    if ((le - chan + base) % 11 == 0)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen(name".inp", "r", stdin);
    freopen(name".out", "w", stdout);
    cin >> t;
    rep (i, 1, t)
    {
        cin >> n[i];
        rep (j, 1, n[i])
            cin >> s[i][j];
        sumN += n[i];
    }
    if (sumN <= 8)
    {
        rep (i, 1, t)
        {
            res = 0;
            sub1(i, 1);
            cout << res << '\n';
        }
        return 0;
    }
    gt[0] = 1;
    rep (i, 1, 2000)
        gt[i] = (gt[i - 1] * i) % mod;
    if (issub2())
    {
        if (check())
            rep (i, 1, t)
                cout << gt[n[i]] << '\n';
        else rep (i, 1, t)
            cout << 0 << '\n';
        return 0;
    }
}
