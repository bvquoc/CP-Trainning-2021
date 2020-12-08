#include <bits/stdc++.h>

#define taskname "mine"
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 4e5 + 1;
const int maxS = 1e6 + 1;
const ll mod = 1e6 + 3;

int n, m;

int a[maxN];

ll fact[maxS];
ll ifact[maxS];

ll power(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    ll k = power(a, b >> 1);
    if (b & 1)
    {
        return k * k % mod * a % mod;
    }
    return k * k % mod;
}

void init()
{
    fact[0] = 1;
    for1(i, 1e6)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    ifact[1000000] = power(fact[1000000], mod - 2);
    ford(i, 1e6)
    {
        ifact[i] = ifact[i + 1] * (i + 1) % mod;
    }
}

ll nCk(ll n, ll k)
{
    if (k > n)
    {
        return 0;
    }
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

ll res = 1;

set <vi> vt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    init();
    cin >> n >> m;
    vi tmp;
    tmp.eb(0);
    for1(i, n)
    {
        tmp.eb(i);
        tmp.eb(i);
    }
    for1(i, n * 2)
    {
        cin >> a[i];
    }
    int res = 0;
    for1(x, fact[n * 2])
    {
        vi freq(n + 1);
        stack <int> st;
        bool ext = 1;
        for1(i, n * 2)
        {
            if (!freq[tmp[i]])
            {
                freq[tmp[i]] = i;
                st.push(tmp[i]);
                bool ok = 1;
                for1(j, tmp[i] - 1)
                {
                    if (!freq[j])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                {
                    ext = 0;
                    break;
                }
            }
            else if (a[i] - a[freq[tmp[i]]] > m)
            {
                ext = 0;
                break;
            }
            else if (st.top() != tmp[i])
            {
                ext = 0;
                break;
            }
            else
            {
                st.pop();
            }
        }
        if (ext)
        {
            vt.insert(tmp);
        }
        next_permutation(tmp.begin() + 1, tmp.end());
    }
    cout << vt.size();
    return 0;
}
