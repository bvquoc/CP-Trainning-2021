#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define FILE_NAME "GIFT11"

using namespace std;

const ll MOD = 998244353;
ll t, n, _min, _max;
ll a[2005];

ll Sub_1()
{
    ll res = 0;

    if (_min == _max) {
        ll o_sum = 0, e_sum = 0, len = 0;
        for (int i = 1; i <= n; ++i) {
            ll tmp = a[1];
            while(tmp > 0) {
                len++;
                if (len&1)
                    o_sum += tmp%10;
                else e_sum += tmp%10;
                tmp /= 10;
            }
        }
        if (abs(o_sum-e_sum)%11 == 0) {
            ll fac = 1;
            for (int i = 1; i <= n; ++i)
                fac = (fac%MOD*i%MOD)%MOD;
            res = fac;
        }
    }
    else {
        sort(a+1, a+n+1);
        do {
            ll o_sum = 0, e_sum = 0, len = 0;
            for (int i = n; i >= 1; --i) {
                ll tmp = a[i];
                while(tmp > 0) {
                    len++;
                    if (len&1)
                        o_sum += tmp%10;
                    else e_sum += tmp%10;
                    tmp /= 10;
                }
            }
            if (abs(o_sum-e_sum)%11 == 0) {
                res++;
                res %= MOD;
            }
        } while(next_permutation(a+1, a+n+1));
    }
    return res;
}

int main()
{
    freopen(FILE_NAME".INP", "r", stdin);
    freopen(FILE_NAME".OUT", "w", stdout);

    cin >> t;
    while (t--) {
        _min = LLONG_MAX; _max = LLONG_MIN;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            _min = min(_min, a[i]);
            _max = max(_max, a[i]);
        }
        if (n <= 10)
            cout << Sub_1() << '\n';
    }

    return 0;
}
