#include <iostream>
#include <cstdio>
using namespace std;


string s[2005];
string tt;
int n;

void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
}

bool check[2005];
int a[2005];
long long ans = 0;
const long long mod = 998244353;

void tryy(int p)
{
    for (int i = 1; i <= n; i++)
    if (!check[i])
    {
        check[i] = true;
        a[p] = i;
        if (p == n)
        {
            tt = "";
            for (int j = 1; j <= n; j++)
                tt = tt + s[a[j]];
            int o = 1;
            int sum = 0;
            for (char v:tt)
            {
                o = -o;
                sum += o*(v - '0');
            }
            if (sum%11 == 0) ans++;
        }
        else tryy(p+1);
        check[i] = false;
    }
}

long long gt[2005];

void init()
{
    gt[0] = 1;
    for (long long i = 1; i <= 2000; i++)
    gt[i] = gt[i-1]*i%mod;
}


void sub1()
{
    ans = 0;
    tryy(1);
    ans %= mod;
    cout << ans << '\n';
}


void sub2()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
        tt = tt + s[i];
    int o = 1;
    int sum = 0;
    for (char v:tt)
    {
        o = -o;
        sum += o*(v-'0');
    }
    if (sum%11 == 0) ans = gt[n];
    //cout << tt << '\n';
    cout << ans << '\n';
}



void mult()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        inp();
        tt = "";
        if (n <= 8) sub1();
        else sub2();
    }
}


int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    mult();
    return 0;
}
