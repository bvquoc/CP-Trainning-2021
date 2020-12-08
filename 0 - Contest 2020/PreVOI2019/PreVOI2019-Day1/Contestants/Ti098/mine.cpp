#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ins insert
#define era erase
#define mod 1000003
#define N 2000009

using namespace std;
int f[6000][6000];
int n, m, a[2 * N], x[2 * N], k[2 * N], res, z[2009][2009];
deque < int > Qr, Qv;
int thu(int u, int sl)
{
    if(u == 2 * n)
    {
        return (sl == 0);
    }

    if(sl < 0)return 0;
    if(f[u][sl + n] != -1)return f[u][sl + n];

    int res = 0;
    if(2 * n - u > sl)res = (res + thu(u +1, sl +1)) % mod;
    if(sl > 0)res = (res + thu(u +1, sl -1)) % mod;

    return f[u][sl + n] = res;
}

void sub_2()
{
    memset(f, -1, sizeof(f));
    cout << thu(0, 0);
    exit(0);
}

void dem(int u)
{
    if(u > 2 *n)
    {
        if(Qv.empty() && Qr.empty())
        {
            res = (res + 1) % mod;
            /*for(int i=1; i<=n; ++i)
                cout << x[i] << ' ' << k[i] << '\n';
            cout << "xxx";*/
        }

        return ;
    }

    int d;
    d = Qr.front();

    // cho thang cuoi ra
    if(Qr.size())
    {
        d = Qr.back();
        if(x[d] + m < a[u])return;
        Qr.pop_back();
        k[d] = a[u];
        dem(u +1);
        Qr.push_back(d);
    }

    // cho thang moi vao
    if(Qv.size())
    {
        d = Qv.front(); Qv.pop_front();
        Qr.pb(d);
        x[d] = a[u]; // thoi diem vao
        dem(u +1);
        Qr.pop_back();
        Qv.push_front(d);
    }
}

void sub_1()
{
    for(int i=2; i<=n; ++i)
        Qv.push_back(i);

    Qr.push_back(1);
    x[1] = a[1];
    res = 0;
    dem(2);
    cout << res;
    exit(0);
}

void sub_3()
{
    for(int i=1; i<2*n; ++i)
        if(a[i] + m >= a[i +1])
            z[i][i +1] = 1;
        else
        {
            cout << 0;
            exit(0);
        }

    for(int kc = 2; kc<=n; ++kc)
        for(int i=1; i<=2 * n; ++i)
    {
        int j = i + kc * 2 -1;
        if(a[i] + m < a[j])continue;
        if(j > 2 * n)continue;
        for(int k=i +1; k<j; ++k)
            if((k - i) % 2 == 1)
            z[i][j] = (z[i][j] + z[i][k] * z[k +1][j]);
        //cout << i << ' ' << j << ' ' << z[i][j] << '\n';
    }
    cout << z[1][n];
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    #endif //ONLINE_JUDGE
    cin >> n >> m;
    for(int i=1; i<=2*n; ++i)cin >> a[i];
    if(m >= a[2 * n])sub_2();
    if(n <= 10)
        sub_1();
    sub_3();
    return 0;
}
