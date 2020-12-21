/*input
4
2
1 1
3
1 31 12
3
12345 67 84
9
1 2 3 4 5 6 7 8 9
*/
#include <bits/stdc++.h>
#define task "GIFT11"
#define endl '\n'
#define MASK(i) (1LL << (i))
#define c_bit(i) __builtin_popcountll(i)
#define BIT(x, i) ((x) & MASK(i))
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) &~ MASK(i))
#define int long long
#define ii pair<int,int>

using namespace std;


const int oo = 1e9 + 7;
const int MOD = 998244353;

int n, t, a[5000], need;
int f[1050][1050][15], f2[2050][2050][12];
vector <int> le, chan, permu;


string toStr(int x) {
    string ret; while (x > 0) {
        ret += char(x % 10 + '0');
        x /= 10;
    }
    if (ret.empty()) ret = "0";
    reverse(ret.begin(), ret.end());
    return ret;
}

int length(int x)
{
    int res = 0;
    while (x > 0)
    {
        x /= 10;
        res ++;
    }
    return res % 2;
}

int dp1(int l, int c, int sum)
{
    if (l == 0 && c == 0)
        if (sum % 11 == need)
            return 1;
        else return 0;
    if (f[l][c][sum] != -1)
        return f[l][c][sum];
    int id = le.size() - (l + c);
    string s = toStr(le[id]);
    int th1 = 0, th2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
            th1 = (th1 + (s[i] - '0')) % 11;
        else th2 = (th2 + (s[i] - '0')) % 11;
    }
    int res = 0;
    if (l > 0) res = (l * dp1(l - 1, c, (sum + th1 - th2 + 11) % 11)) % MOD;
    if (c > 0) res = (res + c * dp1(l, c - 1, (sum + th2 - th1 + 11) % 11)) % MOD;
    return res;
}

int dp2(int id, int l, int sum)
{
    if (id >= chan.size())
    {
        need = (11 - sum) % 11;

        return dp1(le.size() - le.size() / 2, le.size() / 2, 0);
    }
    if (f2[id][l][sum] != -1)
        return f2[id][l][sum];
    string s = toStr(chan[id]);
    int th1 = 0, th2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
            th1 = (th1 + (s[i] - '0')) % 11;
        else th2 = (th2 + (s[i] - '0')) % 11;
    }
    int res = 0;
    res = (res + l * dp2(id + 1, l + 1, (sum + th1 - th2 + 11) % 11)) % MOD;
    res = (res + (id + (le.size() + 1) / 2 - l + 1) * dp2(id + 1, l, (sum + th2 - th1 + 11) % 11)) % MOD;
    return res;

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
exit(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        le.clear();
        chan.clear();
        permu.clear();
        int num = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (length(a[i]))
                le.push_back(a[i]);
            else chan.push_back(a[i]);
            permu.push_back(i);
            num *= i;
        }
        if (chan.size() == 0)
        {
            need = 0;
            memset(f, -1, sizeof f);
            cout << dp1(le.size() - le.size() / 2, le.size() / 2, 0) << endl;
            continue;
        }
        if (le.size() == 0)
        {
            int th1 = 0, th2 = 0;
            for (int i = 1; i <= n; i++)
            {
                string s = toStr(a[i]);
                for (int i = 0; i < s.length(); i++)
                {
                    if (i % 2 == 0)
                        th1 = (th1 + (s[i] - '0')) % 11;
                    else th2 = (th2 + (s[i] - '0')) % 11;
                }
            }
            if ((th1 - th2 + 11) % 11 == 0)
            {
                int res = 1;
                for (int i = 1; i <= n; i++)
                    res = (res * i) % MOD;
                cout << res << endl;
            }
            else cout << 0 << endl;
            continue;
        }
        memset(f, -1, sizeof f);
        memset(f2, -1, sizeof f);
        cout << dp2(0, (le.size() + 1) / 2, 0) << endl;
    }

}
