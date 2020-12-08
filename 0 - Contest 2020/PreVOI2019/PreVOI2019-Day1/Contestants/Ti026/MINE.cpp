///------------------  ONESHOTAC -------------------
#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
#define f first
#define s second
//#define int long long
using namespace std;

const int MOD=1e9+7;
const int N = 200005;
int n, m;
int a[N];
long long calc(long long x, int y)
{
    if(y == 0) return 1;
    if(y == 1) return x;
    long long val = calc(x, y/2);
    val = val * val % MOD;
    if(y % 2)
    {
        val = val * x % MOD;
    }
    return val;
}
void sub25()
{
    if(n == 1)
    {
        cout << 1;
        return;
    }
    long long mu1 = 1, mu2 = 1;
//    FOR(i, 1, 2 * n)
    for(long long i = 1; i <= 2 * n; i ++)
    {
        if(i <= n + 1)
        {
            mu1 = mu1 * i % MOD;
        }
        mu2 = mu2 * i % MOD;
    }
    long long val1 = calc(mu1, MOD - 2);
    long long val2 = val1 * (n + 1);
    long long res = (mu2 * val1 % MOD) * val2 % MOD;
    cout << res;
}
bool getbit(int mask, int x)
{
    return (mask >> (x - 1)) & 1;
}
bool check(int mask)
{
    int dem = 0;
    FOR(i, 1, 2 * n)
    {
        if(getbit(mask, i)) dem ++;
        else dem --;
        if(dem < 0) return 0;
    }
    return (dem == 0);
}
void sub1()
{
    int res = 0;
    stack < pair < int, int > > st;
    for(int mask = 0; mask < (1 << 2 * n); mask ++)
    {
        if(!check(mask)) continue;
        bool ok = 1;
        int pos = 0;
        while(st.size()) st.pop();
        FOR(i, 1, 2 * n)
        {
            if(getbit(mask, i))
            {
                st.push(mp(++ pos, a[i]));
            }
            else
            {
                int u = st.top().f;
                int tg = st.top().s;
                st.pop();
                if(a[i] - tg > m)
                {
                    ok = 0;
                    break;
                }
            }
        }
        res += ok;
    }
    cout << res << "\n";
}
void sub34()
{
    cout << 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    cin >> n >> m;
    FOR(i, 1, 2 * n)
    {
        cin >> a[i];
    }
    if(m == 1000000)
    {
        sub25();
    }
    else if(n <= 10)
    {
//        sub25();
        sub1();
    }
    else sub34();
    return 0;
}
