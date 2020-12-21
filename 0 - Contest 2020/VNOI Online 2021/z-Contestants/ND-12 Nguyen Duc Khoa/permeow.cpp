#include <bits/stdc++.h>
#define N 200009
#define ll long long

using namespace std;
int a[N], b[N];
int n;

//--------------------------------------------
void sub_1()
{
    int res = 0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<i; ++j)
            if(a[j] > a[i])
                res++;
    }
    cout << res;
    exit(0);
}

//---------------------------------------------------
const ll mod = 1e9 +7;
ll p[N];
void sub_2()
{
    if(n == 2)
    {
        cout << 1;
        exit(0);
    }
    if(n == 1)
    {
        cout << 0;
        exit(0);
    }

    p[2] = 1;
    ll sum = (n * n - n) /2;
    for(int i=3; i<=n; ++i)
        p[i] = (p[i -1] * i) % mod;

    sum%= mod;
    sum = (sum * p[n]) % mod;
    cout << sum;
    exit(0);
}

//--------------------------------------------------------------------
ll ans[N], resa, resb;
int f[N *4], d[N];
int get(int k, int l, int r, int L, int R)
{
    if(l > L || L > r)
        return 0;
    if(l >= L && R >= r)
        return f[k];
    int mid = (l + r) /2;
    return get(k *2, l, mid, L, R)
         + get(k *2 +1, mid +1, r, L, R);
}

void update(int k, int l, int r, int pos, int val)
{
    if(pos < l || pos > r)
        return ;
    if(pos == l && pos == r)
    {
        f[k] = val;
        return ;
    }
    int mid = (l + r) /2;
    update(k *2, l, mid, pos, val);
    update(k *2 +1, mid +1, r, pos, val);
    f[k] = f[k *2] + f[k *2 +1];
    return ;
}
void sub_3()
{
    //-------khoi tao------------------------------------------
    p[2] = 1;
    ll sum = (n * n - n) /2;
    for(int i=3; i<=n; ++i)
        p[i] = (p[i -1] * i) % mod;

    ans[1] = 0; ans[2] = 1;
    for(int i=3; i<=n; ++i)
    {
        ans[i] = ((i * i -i) /2) % mod;
        ans[i] = (ans[i] * p[i]) % mod;
    }

    ll res = 0, dem, sl, tmp;
    for(int i=1; i<=n; ++i)
        update(1, 1, n, i, 1),
        p[i] = (p[i] *2) % mod;
    p[1] = 1;

    //----------tinh day < a --------------------------------------
    tmp = 0;
    for(int i=1; i<n; ++i)
    {
        if(i > 1 && a[i -1] > 1)
        tmp+= get(1, 1, n, 1, a[i -1]);

        dem = 0;
        for(int j=1; j<a[i]; ++j)
            if(d[j] == 0)
        {
            dem++;
            if(j > 1)
                sl = get(1, 1, n, 1, j -1);
            else sl = 0;
            res = (res + ans[n - i]) % mod;
            res = (res + (p[n - i] * sl) % mod) % mod;
        }

        res = (res + (tmp * dem) % mod * p[n - i] % mod) % mod;
        d[a[i]] = 1;
        update(1, 1, n, a[i], 0);
    }
    resa = res;

    //--------tinh day < b---------------------------------------
    res = 0;
    for(int i=1; i<=n; ++i)
        update(1, 1, n, i, 1);

    tmp = 0;
    memset(d, 0, sizeof(d));
    for(int i=1; i<n; ++i)
    {
        if(i > 1 && b[i -1] > 1)
        tmp+= get(1, 1, n, 1, b[i -1]);

        dem = 0;
        for(int j=1; j<b[i]; ++j)
            if(d[j] == 0)
        {
            dem++;
            if(j > 1)
                sl = get(1, 1, n, 1, j -1);
            else sl = 0;
            res = (res + ans[n - i]) % mod;
            res = (res + (p[n - i] * sl) % mod) % mod;
        }

        res = (res + (tmp * dem) % mod * p[n - i] % mod) % mod;
        d[b[i]] = 1;
        update(1, 1, n, b[i], 0);
    }
    resb = res;
    for(int i=2; i<=n; ++i)
        for(int j=1; j<i; ++j)
            if(b[j] > b[i])
                resb++;
    cout << resb - resa;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);

    cin >> n;
    int kt1 = 0, kt2 = 0;
    for(int i=1; i<=n; ++i)
    {
        cin >> a[i];
        if(a[i] != i)
            kt2 = 1;
    }
    for(int i=1; i<=n; ++i)
    {
        cin >> b[i];
        if(b[i] != a[i])
            kt1 = 1;
        if(b[i] != n - i +1)
            kt2 = 1;
    }

    if(kt1 == 0)
        sub_1();
    if(kt2 == 0)
        sub_2();
    sub_3();
    return 0;
}
