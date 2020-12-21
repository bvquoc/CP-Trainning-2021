#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pli = pair< long long, int >;
using pii = pair< int, int >;

const int N = 2e5 + 7;
const ll mod = 1e9 + 7;
int n;
int a[N], b[N];
ll f[N];
ll res;


bool _digit(char c) {
    return '0' <= c && c <= '9';
}

int _read() {
    char c;
    ll val = 0;

    while (!_digit(c = getchar()));
    do {
        val = val * 10 + c - '0';
    } while (_digit(c = getchar()));
    return val;
}


void _sub1() {
    for (int i = n; i >= 1; --i) {
        int pos;
        for (int j = 1; j <= n; ++j)
            if (a[j] == i) {
                pos = j;
                break;
            }
        res += i - pos;
        for (int j = pos; j < i; ++j)
            swap(a[j], a[j + 1]);
    }
}


//void _sub2() {
//    f[1] = 1;
//    for (int i = 2; i <= n; ++i)
//        f[i] = (f[i - 1] * i) % mod;
//
//    for (int i = 1; i < n; ++i)
//        for (int j = i + 1; j <= n; ++j)
//            res = (res + (j - i) * f[n - i]) % mod;
//}

int main()
{
//    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);

    n = _read();
    for (int i = 1; i <= n; ++i)
        a[i] = _read();
    for (int i = 1; i <= n; ++i)
        b[i] = _read();


    bool s1, s2;
    s1 = s2 = (n <= 2000);
    for (int i = 1; i <= n; ++i) {
        s1 &= (a[i] == b[i]);
        s2 &= (a[i] == i) && (b[i] == n - i + 1);
    }

    if (s1)
        _sub1();
//    else if (s2)
//        _sub2();

    cout << res;

    return 0;
}
