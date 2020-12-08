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
int Q;
int a[20];
int dp[100005];
int x, t, dem = 0;
pair < int, int > b[N];
void Reset()
{
    a[1] = 1;
    a[2] = 3;
    a[3] = 5;
    a[4] = 10;
    a[5] = 30;
    a[6] = 50;
    a[7] = 100;
    a[8] = 300;
    a[9] = 500;
    a[10] = 1000;
    a[11] = 3000;
    a[12] = 5000;
    a[13] = 10000;
    a[14] = 30000;
    a[15] = 50000;
}
//void sinh()
//{
//    FOR(i, 1, 100000)
//    {
//        dp[i] = i;
//        FOR(j, 1, 15)
//        {
//            if(i < a[j]) continue;
//            dp[i] = min(dp[i], dp[i - a[j]] + 1);
//        }
//    }
//}
void sub12()
{
    a[16] = x;
    FOR(i, 1, t)
    {
        dp[i] = i;
        FOR(j, 1, 16)
        {
            if(i < a[j])
                continue;
            dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout << dp[t] << "\n";
}
int calc(long long val)
{
    int dd = 0;
    FORD(i, 15, 1)
    {
        while(val >= a[i])
        {
            val -= a[i];
            dd ++;
        }
        if(val == 0)
            break;
    }
    return dd;
}
void sub34()
{
    int mu = 1;
    FOR(i, 1, 15)
    {
        b[i].f = a[i];
        b[i].s = 1;
    }
    b[16].f = x;
    b[16].s = 1;
    b[21] = mp(2, 2);
    b[17] = mp(2000, 2);
    b[18] = mp(200, 2);
    b[19] = mp(20, 2);
    b[20] = mp(20000, 2);
    dem = 21;
    if(x < a[15])
    {
        while(1)
        {
            mu *= 2;
            long long val = 1ll * x * mu;
            b[++ dem] = mp(val, mu);
            int k = calc(val);
            if(k <= mu)
            {
                dem --;
                break;
            }
            if(val > a[15])
            {
                break;
            }
        }
    }
    sort(b + 1, b + dem + 1);
    long long res = 0;
    FORD(i, dem, 1)
    {
        if(t >= b[i].f)
        {
            int val = t / b[i].f;
            t -= val * b[i].f;
            res += b[i].s * val;
        }
        if(t == 0)
            break;
    }
    cout << res << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    cin >> Q;
//    init();
    //Reset();
    //sinh();
    while(Q --)
    {
        Reset();
        cin >> x >> t;
//        int t1 = t;
//        sub12();
//        t = t1;
//        sub34();
        if(x <= 100000 && t <= 100000)
        {
            sub12();
        }
        else
        {
            sub34();
        }
    }
    return 0;
}
