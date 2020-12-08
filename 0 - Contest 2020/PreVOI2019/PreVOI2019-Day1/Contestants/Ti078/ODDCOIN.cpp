///Thu Thaoo

#include <bits/stdc++.h>

#define ll long long
#define I freopen(Task".inp", "r", stdin)
#define O freopen(Task".out", "w", stdout)
#define vt vector <int>
#define rt(O) return O
#define pii pair <int, int>
#define st first
#define nd second
#define rd third
#define th fourth
#define pusf push_front
#define popf pop_front
#define popb pop_back
#define pusb push_back
#define Task "oddcoin"
#define MOD 1000000007
#define uns unsigned
#define int ll
#define read_fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORU(i, l, n) for (int i=l; i<=n; i++)
#define FORD(i, n, l) for (int i=n; i>=l; i--)
#define reset(x) memset (x, 0, sizeof(x))
#define ignLine cout<<endl
#define mg menhgia

using namespace std;
const int N = 1e5 + 3;
int menhgia[17] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000, 0};
int q, x, t;
int n;
int kount = 0;
int res = 0;
int X[22];
int cs[11];
int up;

void process1()
{
    kount = 0;
    int sum = 0;
    FORU(i, 1, n)
    {
        sum += menhgia[i]*X[i];
        kount += X[i];
    }
    if (sum == t) res = min(res, kount);
}
void tachcs(int x)
{
    reset(cs);
    up = 0;
    int z = x;
    while (z > 0)
    {
        cs[++up] = z % 10;
        z = z / 10;
        if (cs[up] == 0) break;
    }
    FORU(i, 1, up)
    {
        cs[i] = cs[i] * pow(10, i-1);
        t = t - cs[i];
    }
}
void process2()
{
    tachcs(t);
    FORU(i, 1, up)
    {
        while (cs[i] > 0)
        {
            FORD(j, 16, 1)
            {
                if (cs[i] % mg[j] == 0)
                {
                    res++;
                    cs[i] -= mg[j];
                    break;
                }
            }
        }
    }
    int res1 = 0, res2 = 0;
    int v1 = t, v2 = t;
    int check1 = 0;
    while (v1 > 0)
    {
        check1 = 0;
        FORD(j, 16, 1)
        {
            while (v1 - mg[j] >= 0)
            {
                res1++;
                v1 -= mg[j];
                check1 = 1;
                break;
            }
            if (check1 == 1) break;
        }
    }
    while (v2 > 0)
    {
//        check2 = 0;
        FORD(j, 16, 1)
        {
            if (v2 % mg[j] == 0)
            {
                res2++;
                v2 -= mg[j];
                break;
            }
        }
    }
    res = res + min (res1, res2);
}
void btr(int i)
{
    for (int j=0; j<=2; j++)
    {
        X[i] = j;
        if (i == n) process1();
        else btr(i+1);
    }
}
void Input1()
{
    res = 0;
    cin>>x>>t;
    menhgia[1] = 1; menhgia[2] = 3; menhgia[3] = 5;
    menhgia[4] = 10; menhgia[5] = 30; menhgia[6] = 50;
    menhgia[7] = 100; menhgia[8] = 300; menhgia[9] = 500;
    menhgia[10] = 1000; menhgia[11] = 3000; menhgia[12] = 5000;
    menhgia[13] = 10000; menhgia[14] = 30000; menhgia[15] = 50000;
    menhgia[16] = x;
    reset(X);
    sort(menhgia + 1, menhgia + 17);
    if (x <= 1e5 && t <= 1e5)
    {
        n = 0; res = 1e9;
        for (int i=1; i<=16; i++)
        {
            if (menhgia[i] <= t) n++;
        }
        btr(1);
    }
    else
        process2();
    cout<<res<<endl;
    process1();
}
main()
{
    I;
    O;
    cin>>q;
    FORU(i, 1, q)
    {
        Input1();
    }
//    process();
    rt(0);
}
