#include <bits/stdc++.h>
#define MAXN 2000
#define MOD 998244353

using namespace std;
int n;
string a[MAXN];
int pos[MAXN];
bool ok;
void read()
{
    ok = 1;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i].size() % 2) ok = 0;
        pos[i] = i;
    }
}
long long dem;
void check(string s)
{
    int N = s.length();
    s = " " + s;
    long long sum1 = 0, sum2 = 0;
    for(int i = 1; i <= N; ++i)
    {
        if(i % 2) sum1 += s[i] - '0';
        else sum2 += s[i] - '0';
    }
    long long sum = sum1 - sum2;
    if(sum % 11 == 0) dem = (dem + 1) % MOD;
}
void sub1()
{
    dem = 0;
    do{
        string s = "";
        for(int i = 1; i <= n; ++i)
        {
            s += a[pos[i]];
        }
        check(s);
    }while(next_permutation(pos+1, pos+n+1));
}
long long gt[MAXN];
void init()
{
    gt[0] = 1;
    for(int i = 1; i < MAXN; ++i)
    {
        gt[i] = (gt[i-1] * i) % MOD;
    }
}
void sub2()
{
    long long sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < a[i].size(); ++j)
        {
            if((j+1) % 2) sum1 += a[i][j] - '0';
            else sum2 += a[i][j] - '0';
        }
    }
    long long sum = sum1 - sum2;
    if(sum % 11 == 0) dem = gt[n];
    else dem = 0;
}
void out()
{
    cout << dem%MOD << '\n';
}
int main()
{
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    int t;
    cin >> t;
    init();
    while(t--)
    {
        read();
        if(ok)
        {
            sub2();
        }
        else
        {
            sub1();
        }
        out();
    }
    return 0;
}
