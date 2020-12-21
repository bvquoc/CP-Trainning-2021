#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define ins insert
#define era erase
#define ll long long
#define pii pair < int, int >
#define N 2009

using namespace std;
const ll mod = 998244353;
vector < int > vt[N], vec;
int n, t, d;
ll sum, res, x;
int p[N];

//------------------------------------------------
void sub_1()
{
    for(int i=1; i<=n; ++i)
        p[i] = i;

    res = 0;
    do
    {
        vec.resize(0);
        for(int i=1; i<=n; ++i)
        {
            d = p[i];
            for(int j=0; j<vt[d].size(); ++j)
                vec.pb(vt[d][j]);
        }
        d = -1; sum = 0;
        for(int i=0; i<vec.size(); ++i)
        {
            sum = sum * 10 + vec[i];
            d = -d;
        }
        if(sum % 11 == 0)
            res++;
    }while(next_permutation(p +1, p + n +1));
    cout << res << '\n';
}

//----------------------------------------------------------
ll gt[N];
void sub_2()
{
    vec.resize(0);
    for(int i=1; i<=n; ++i)
    {
        for(int j=0; j<vt[i].size(); ++j)
            vec.pb(vt[i][j]);
    }
    sum = 0;
    d = -1; sum = 0;
    for(int i=0; i<vec.size(); ++i)
    {
        sum = sum + vec[i] * d;
        d = -d;
    }
    if(sum % 11 == 0)
        cout << gt[n];
    else cout << 0;
    cout << '\n';
}

//-------------------------------------------------------------------
ll f[N][1009][12];
int S[N];
void sub_3()
{
    sum = 0;
    for(int i=1; i<=n; ++i)
    {
        S[i] = 0;
        d = 1;
        for(int j=0; j<vt[i].size(); ++j)
            S[i] = (S[i] + vt[i][j] * d + 22) % 11;
        sum = (sum + S[i]) % 11;
    }

    res = 0;
    int n2 = n /2 + (n % 2), ndu;
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;
    for(int sl=1; sl<=n2; ++sl)
        for(int i=1; i<=n; ++i)
            for(int du=0; du<=10; ++du)
    {
        ndu = (du - S[i] +22) % 11;
        f[i][sl][du]= (f[i -1][sl -1][ndu] + f[i -1][sl][du]) % mod;
    }

    for(int i=0; i<=10; ++i)
        if((2 * i - sum + 99) % 11 == 0)
        {
            cout << i << '\n';
            cout << f[n][n2][i] << '\n';
            ll tmp = (f[n][n2][i] * gt[n2] % mod + mod * mod) % mod;
            tmp = (tmp * gt[n - n2] % mod + mod * mod) % mod;
            res = (res + tmp) % mod;
        }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    #endif // ONLINE_JUDGE
    gt[0] = 1;
    for(int i=1; i<=2009; ++i)
        gt[i] = (gt[i -1] * i) % mod;
    cin >> t;

    while(t--)
    {
        cin >> n;
        int kt = 0;
        for(int i=1; i<=n; ++i)
        {
            vt[i].resize(0);
            cin >> x;
            while(x)
            {
                vt[i].pb(x % 10);
                x/= 10;
                reverse(vt[i].begin(), vt[i].end());
            }
            if(vt[i].size() % 2)
                kt = 1;
        }

        if(n <= 9)
            sub_1();
        else
        if(kt == 0)
            sub_2();
        else sub_3();
    }
    return 0;
}
