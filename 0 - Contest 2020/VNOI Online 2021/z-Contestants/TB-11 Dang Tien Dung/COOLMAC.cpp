#include <bits/stdc++.h>
#define debug(x) cerr << #x << "=" << x << endl;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define task "COOLMAC"
using namespace std;
const int MaxN = 100001;
const int oo = 1e9;
int n, m, b = oo, x[17], ans = oo;
pair<int, int> a[MaxN], tmp[MaxN+1];
void check()
{
    int cnt = 0;
    for (int i=1; i<=m; i++)
    {
        if (x[i] == 1)
        {
            cnt++;
            tmp[cnt] = a[i];
        }
    }
    if (cnt == 0) return;
//    for (int i=1; i<=cnt; i++)
//    {
//        cout << tmp[i].first << " " << tmp[i].second << '\n';
//    }
//    cout << '\n' << '\n';
    if (tmp[1].first > b) return;
    if (cnt == 1)
    {
        if (tmp[1].second < 100000) return;
        else
        {
            cout << 1;
            exit(0);
        }
    }
    if (cnt > ans) return;
    tmp[cnt+1] = {100000, 100001};
    for (int i=1; i<cnt; i++)
    {
        if (tmp[i].second < tmp[i+1].first)
        {
            if (tmp[i].second+1 > b) return;
        }
    }
    ans = min(ans, cnt);
}
void print()
{
    for (int i=1; i<=m; i++)
    {
        cout << x[i] << " ";
    }
    cout << '\n';
}
void backtrack(int i)
{
    for (int j=0; j<=1; j++)
    {
        x[i] = j;
        if (i == m) check();
        else backtrack(i+1);
    }
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i=1; i<=m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1, a+1+m);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int tmp;
        cin >> tmp;
        b = min(tmp, b);
    }
    if (n<=10 && m<=16)
    {
        backtrack(1);
        if (ans != oo) cout << ans;
        else cout << -1;
        return 0;
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (a[i].second == 100000)
            {
                if (a[i].first <= b)
                {
                    cout << 1;
                    exit(0);
                }
            }
        }
        cout << -1;
    }
#ifdef dungctb
    cerr << "Time collapse : " << fixed << setprecision(3) << 1.000*clock()/CLOCKS_PER_SEC;
#endif // dungctb

    return 0;
}
