#include <bits/stdc++.h>
#define debug(x) cerr << #x << "=" << x << endl;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define task "GIFT11"
using namespace std;
const int mod = 998244353;
const int MaxN_backtrack = 21;
const int MaxN = 20001;
int t, n, a[MaxN], x[MaxN_backtrack], ans, fac[MaxN];
bool mark[MaxN_backtrack];
void print()
{
    for (int i=1; i<=n; i++)
    {
        cout << x[i] << " ";
    }
    cout << '\n';
}
string int_to_string(int x)
{
    string res = "";
    while (x != 0)
    {
        res = (char)(x%10+48)+res;
        x /= 10;
    }
    return res;
}
bool check()
{
    string res = "";
    int t1 = 0, t2 = 0;
    for (int i=1; i<=n; i++)
    {
        res += int_to_string(a[x[i]]);
    }
    //cout << res << '\n';
    for (int i=0; i<res.size(); i++)
    {
        if (i%2 == 0) t1 += (int)(res[i]-48);
        else t2 += (int)(res[i]-48);
    }
    if ((t1-t2)%11 == 0) return true;
    return false;
}
void backtrack(int i)
{
    for (int j=1; j<=n; j++)
    {
        if(!mark[j])
        {
            x[i] = j;
            mark[j] = true;
            if (i == n)
            {
                if (check()) ans++;
                //print();
            }
            else backtrack(i+1);
            mark[j] = false;
        }
    }
}
int main()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[1] = 1;
    for (int i=2; i<MaxN; i++)
    {
        fac[i] = (fac[i-1]*i)%mod;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
        }
        if (n <= 8)
        {
            backtrack(1);
            cout << ans << '\n';
            ans = 0;
            for (int i=1; i<=n; i++)
            {
                mark[i] = false;
            }
        }
        else
        {
            int t1 = 0, t2 = 0;
            for (int i=1; i<=n; i++)
            {
                string tmp = int_to_string(a[i]);
                for (int j=0; j<tmp.size(); j++)
                {
                    if (j%2 == 0) t1 += (int)(tmp[j]-48);
                    else t2 += (int)(tmp[j]-48);
                }
            }
            //cout << t1 << " " << t2;
            if ((t1-t2)%11 == 0) cout << fac[n] << '\n';
            else cout << 0 << '\n';
        }
    }
#ifdef dungctb
    cerr << "Time collapse : " << fixed << setprecision(3) << 1.000*clock()/CLOCKS_PER_SEC;
#endif // dungctb

    return 0;
}
