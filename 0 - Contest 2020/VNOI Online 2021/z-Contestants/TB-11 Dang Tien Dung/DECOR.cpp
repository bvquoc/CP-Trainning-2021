#include <bits/stdc++.h>
#define debug(x) cerr << #x << "=" << x << endl;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define task "DECOR"
using namespace std;
const int MaxN = 500001;
const int oo = 1e9;
int n, m, k, ans = -oo, cnt = 0, cnt0 = 0, cnt1 = 0, l, r, sz = -1;
bool a[MaxN];
pair<int, int> b[MaxN];
struct data1
{
    int first, second, l;
};
vector<data1> f;
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == '1') a[i] = true;
        else
        {
            a[i] = false;
            cnt0++;
        }
    }
    if (cnt0 <= k)
    {
        cout << 1 << " " << n;
        return 0;
    }
    if (cnt0 == n)
    {
        cout << -1;
        return 0;
    }
    k = min(k, cnt0);
    for (int i=1; i<=m; i++)
    {
        cin >> b[i].first >> b[i].second;
    }
    if (m==0 && k==0)
    {
        for (int i=1; i<=n; i++)
        {
            if (a[i] == true) cnt++;
            else
            {
                if (ans < cnt)
                {
                    ans = cnt;
                    r = i-1;
                    l = i-ans;
                }
                cnt = 0;
            }
        }
        if (ans < cnt)
        {
            ans = cnt;
            r = n;
            l = n-ans+1;
        }
        cout << l << " " << r;
        return 0;
    }
    if (m == 0)
    {
        cnt = 1;
        l = 1;
        for (int i=2; i<=n; i++)
        {
            if (a[i] != a[i-1])
            {
                f.push_back({cnt, a[i-1], l});
                sz++;
                cnt = 1;
                l = i;
            }
            else
            {
                cnt++;
            }
        }
        f.push_back({cnt, a[n], l});
        sz++;
//        for (int i=0; i<f.size(); i++)
//        {
//            cout << f[i].first << " " << f[i].second << " " << f[i].l << '\n';
//        }
        for (int i=2; i<sz; i++)
        {
            if (f[i].second == 1)
            {
                if (ans < f[i-2].first+f[i-1].first+f[i].first)
                {
                    ans = f[i-2].first+f[i-1].first+f[i].first;
                    l = f[i-2].l;
                    r = f[i+1].l-1;
                }
            }
            else
            {
                if (ans < f[i].first+f[i-1].first+f[i+1].first)
                {
                    ans = f[i].first+f[i-1].first+f[i+1].first;
                    l = f[i-1].l;
                    r = f[i+2].l-1;
                }
            }
        }
        cout << l << " " << r;
        return 0;
    }
#ifdef dungctb
    cerr << "Time collapse : " << fixed << setprecision(3) << 1.000*clock()/CLOCKS_PER_SEC;
#endif // dungctb

    return 0;
}
//2 1
//1 0
//1 1
//1 0
