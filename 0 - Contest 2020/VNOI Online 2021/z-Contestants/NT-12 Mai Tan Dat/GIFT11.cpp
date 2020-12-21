#include <bits/stdc++.h>
using namespace std;
using pii = pair< int, int >;
using ll = long long;

const int N = 2e3 + 7;
const ll mod = 998244353;
int tc, n[15], sumn;
string s[15][N];
ll res;


bool _bit(int mask, int j) {
    return (mask >> j) & 1;
}

string a;
void _cal1(int i, int mask = 0) {
    if (mask == (1 << (n[i] + 1)) - 2) {
        int sumodd = 0, sumeven = 0, len = a.size();

        for (int j = 0; j < len; ++j)
            if (((len - j) & 1))
                sumodd += a[j] - '0';
            else
                sumeven += a[j] - '0';
        if (abs(sumodd - sumeven) % 11 == 0)
            ++res;
        return;
    }

    for (int j = 1; j <= n[i]; ++j)
        if (!_bit(mask, j)) {
            a += s[i][j];
            _cal1(i, mask | (1 << j));
            a.resize(a.size() - s[i][j].size());
        }
}

void _sub1() {
    for (int i = 1; i <= tc; ++i) {
        res = 0;
        _cal1(i);

        cout << res << '\n';
    }
}

void _sub2() {
    for (int i = 1; i <= tc; ++i) {
        int sumodd = 0, sumeven = 0;
        for (int j = 1; j <= n[i]; ++j) {
            int len = s[i][j].size();
            for (int k = 0; k < len; ++k)
                if ((k & 1))
                    sumodd += s[i][j][k] - '0';
                else
                    sumeven += s[i][j][k] - '0';
        }
        if (abs(sumodd - sumeven) % 11 == 0) {
            res = 1;
            for (int j = 1; j <= n[i]; ++j)
                res = (res * j) % mod;
        }
        else
            res = 0;

        cout << res << '\n';
    }
}

void _read() {
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);

    cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        cin >> n[i];
        sumn += n[i];
        for (int j = 1; j <= n[i]; ++j)
            cin >> s[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    _read();

    if (sumn <= 20)
        _sub1();
    else {
        bool s2 = true;
        for (int i = 1; i <= tc; ++i)
            for (int j = 1; j <= n[i]; ++j)
                if ((s[i][j].size() & 1))
                    s2 = false;
        if (s2)
            _sub2();
    }


    return 0;
}
