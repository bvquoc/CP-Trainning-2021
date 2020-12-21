#include <algorithm>
#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

void file(const string FILE = "Test")
{
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}

char __;
template<typename T>
void getUnsign(T &x)
{
    while (__ = getchar(), __ < '0' || __ > '9');

    x = __ - '0';
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');
}

template<typename T> inline void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> inline void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
const int MAXN = 1e5 + 15;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

/// ====*====*====*====*====*====*====*====*====*====*====

int n;
vector<int> a;
vector<int> odd;
vector<int> eve;

int brute()
{
    int res = 0;
    vector<int> p(n);
    iota(all(p), 0);

    int pw10[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = a[p[i]];
            for (int j = 0; j < 9; ++j)
            {
                if (x < pw10[j])
                {
                    sum = (1LL * pw10[j] * sum + x) % 11;
                    break;
                }
            }
        }

        res += (sum == 0);
    } while (next_permutation(all(p)));

    return res;
}

void fixing()
{
    odd.clear();
    eve.clear();
    for (int x : a)
    {
        vector<int> d;
        for (; x > 0; x /= 10)
            d.push_back(x % 10);

        reverse(all(d));
        int sum_odd = 0, sum_eve = 0;
        for (int i = 0; i < d.size(); i += 2) sum_odd += d[i];
        for (int i = 1; i < d.size(); i += 2) sum_eve += d[i];
        x = (sum_odd - sum_eve) % 11;
        if (x < 0) x += 11;

        if (d.size() & 1)
        {
            odd.push_back(x);
        }
        else
        {
            eve.push_back(x);
        }
    }
}

int brute_2()
{
    int res = 0;
    vector<int> p(n);
    iota(all(p), 0);

    int k = odd.size();
    do {
        int sum = 0, ext = +1;
        for (int i = 0; i < n; ++i)
        {
            bool oddlength = (p[i] < k);
            int v = oddlength ? odd[p[i]] : eve[p[i] - k];
            if (oddlength) ext = -ext;
            sum += v * ext;
            sum %= 11;
            if (sum < 0) sum += 11;
        }

        res += (sum == 0);
    } while (next_permutation(all(p)));

    return res;
}

vector<vector<int> > f;
int bitmasking(int i = 0, int sum = 0, int ext = +1, int mask = 0)
{
    if (i >= n) return (sum == 0);

    int &res = f[sum][mask];
    if (res != -1) return res;

    res = 0;
    for (int j = 0; j < n; ++j)
    {
        if (mask >> j & 1) continue;
        bool oddlength = (j < odd.size());
        int v = oddlength ? odd[j] : eve[j - odd.size()];
        int n_ext = oddlength ? -ext : ext;
        int n_val = (sum + v * ext) % 11;
        if (n_val < 0) n_val += 11;
        int n_mask = mask | (1 << j);
        res += bitmasking(i + 1, n_val, n_ext, n_mask);
        if (res >= MOD) res -= MOD;
    }

    return res;
}

vector<vector<vector<int> > > g;
int magic_eve(int i = 0, int sum = 0, int cnto = 0)
{
    while (sum >= 11) sum -= 11;
    while (sum <  0 ) sum += 11;
    if (i >= eve.size()) return (sum == 0);

    int cnte = (i + odd.size() + 1) - cnto;
    int &res = g[i][sum][cnto];
    if (res != -1) return res;

    res = 0;
    res += (1LL * cnte * magic_eve(i + 1, sum + eve[i], cnto + 0)) % MOD;
    res += (1LL * cnto * magic_eve(i + 1, sum - eve[i], cnto + 1)) % MOD;
    while (res >= MOD) res -= MOD;

    return res;
}

int magic_odd(int i = 0, int sum = 0, int mask = 0)
{
    if (i >= odd.size())
    {
        return magic_eve(0, sum, (odd.size() + 1) / 2);
    }

    int &res = f[sum][mask];
    if (res != -1) return res;

    res = 0;
    for (int j = 0; j < odd.size(); ++j)
    {
        if (mask >> j & 1) continue;
        int val = (sum - ((i & 1) ? +1 : -1) * odd[j]) % 11;
        if (val < 0) val += 11;
        res += magic_odd(i + 1, val, mask | (1 << j));
        if (res >= MOD) res -= MOD;
    }

    return res;
}

int query()
{
    cin >> n;
    a.resize(n);
    for (int &x : a)
        getUnsign(x);

//    cout << brute() << ' ';

    fixing();
//    cout << brute_2() << ' ';

//    f.assign(11, vector<int>(1 << n, -1));
//    cout << bitmasking() << ' ';

    f.assign(11, vector<int>(1 << odd.size(), -1));
    g.assign(eve.size(), vector<vector<int> >(11, vector<int>(n, -1)));
    cout << magic_odd() << ' ';
    return 0;
}

int main()
{
    file("GIFT11");
    int q;
    cin >> q;

    while (q-->0)
    {
        query();
        cout << '\n';

    }


    return 0;
}

/*

15
3
1 1 1
4
1 1 1 1
3
1 2 1
2
1 1
3
1 31 12
3
12345 67 84
6
12 23 34 45 56 1
6
123456 12345 1234 123 12 1
7
1234567 123456 12345 1234 123 12 1
7
111111 1111 11 9 999 99999 9999999
6
111111 1111 11 9 999 99999
6
1 2 3 4 5 6
7
1 2 3 4 5 6 7
8
1 2 3 4 5 6 7 8
9
1 2 3 4 5 6 7 8 9

*/

/*
0
0
2
8
0
0
576
4608
31680
331200
3643200

*/
