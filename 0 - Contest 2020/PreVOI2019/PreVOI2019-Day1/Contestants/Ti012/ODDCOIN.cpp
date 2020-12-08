#include <bits/stdc++.h>
#define task "ODDCOIN"
#define nmax 100005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define len(s) int(s.length())
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int coin[] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int q, x[nmax], t[nmax], res = 1e9, f[nmax];
bool sub1 = true;
map <int, bool> mp;
void backtrack(int i, int sum, int j, int want)
{
    if (i > 5)
    {
        if (sum == want && j < res) res = j;
        return;
    }
    for (int k = 1; k <= 5; k++)
    {
        backtrack(i + 1, sum + coin[k], j + 1, want);
        backtrack(i + 1, sum, j, want);
    }
}

void solvesub1()
{
    for (int i = 1; i <= q; i++)
    {
        coin[5] = x[i];
        res = 1e9;
        backtrack(1,0,0,t[i]);
        cout << res << endl;
    }
    exit(0);
}

void solve(int money)
{
    for (int i = 1; i <= money; i++)
    {
        f[i] = 1e9;
        if (mp.find(i) == mp.end())
        {
            for (int j = i - 1; j >= i / 2; j--)
                f[i] = min(f[i], f[j] + f[i - j]);
        }
        else f[i] = 1;
    }
    cout << f[money] << endl;
}
void solvesub2()
{
    for (int i = 1; i <= 15; i++) mp[coin[i]] = 1;
    for (int i = 1; i <= q; i++)
    {
        res = 1e9;
        if (!mp[x[i]])
        {
            mp[x[i]] = 1;
            solve(t[i]);
            mp[x[i]] = 0;
        }
        else solve(t[i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> x[i] >> t[i];
        if (t[i] > 20 or x[i] > 20)
            sub1 = false;
    }
    if (sub1) solvesub1();
    else solvesub2();
}
