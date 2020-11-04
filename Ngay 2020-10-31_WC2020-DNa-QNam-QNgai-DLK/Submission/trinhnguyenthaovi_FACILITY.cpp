#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 1e6 + 5, oo = 1e9, mod = 1e9 + 7;

struct apply
{
    int s, d;
    ll r;
};

bool cmp(apply x, apply y)
{
    return x.d < y.d || (x.d == y.d && x.s < y.s);
}

apply a[N];
int n, k, sth[N];
ll f[N], ans;

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].s >> a[i].d >> a[i].r;
        a[i].d = a[i].s + a[i].d; /// d trở thành thời điểm kết thúc
    }
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; ++i) sth[i] = a[i].d;
    f[0] = 0;
    ans = 0;

    for(int i = 1; i <= n; ++i)
    {
        if(a[i].s < k) f[i] = max (f[i - 1], a[i].r);
        else
        {
            int j = upper_bound (sth + 1, sth + 1 + n, a[i].s - k) - sth - 1;
            f[i] = max (f[i - 1], f[j] + a[i].r); /// max tiền thuê (lấy đến i, lấy đến ptử j luôn)
        }
        ans = max (ans, f[i]);
    }

    cout << ans;
    return 0;
}
