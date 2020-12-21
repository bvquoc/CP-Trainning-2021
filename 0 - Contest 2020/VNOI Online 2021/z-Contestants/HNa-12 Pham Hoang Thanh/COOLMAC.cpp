#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define BIT(mask, i) (((mask) >> (i)) & 1ll)
#define ONBIT(mask, i) (mask^(1ll << i))
#define OFFBIT(mask, i) (mask &~ (1ll << i))
#define countBIT(x) __builtin_popcountll(x)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;

template<class T> inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x *= -1;
    }
    if (x > 9) Write(x / 10);
    putchar(x % 10 + '0');
}

template<class T>inline void Read(T &x)
{
    char c;
    for (c = getchar(); (c > '9' || c < '0') && c != '-'; c = getchar());
    T y;
    if (c == '-')x = 0, y = -1;
    else x = c - '0', y = 1;
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())x = x * 10 + c - '0';
    x *= y;
}


template <class X, class Y> bool minimize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x > y + eps)
    {
        x = y;
        return true;
    }
    else return false;
}

template <class X, class Y> bool maximize(X &x, const Y &y)
{
    X eps = 1e-9;
    if (x + eps < y)
    {
        x = y;
        return true;
    }
    else return false;
}

template <class T> T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
const int oo = 1e9 + 7;
/* ---------- default ---------- */
int numJacket, numDay;
int Max = 1e5 + 2;
int Min = 1e9;
struct jacketType
{
    int l, r;
    void inp()
    {
        cin >> l >> r;
        ++l, ++r;
    }
    bool operator <(const jacketType &x)const
    {
        if (r == x.r)
            return l < x.l;
        return r > x.r;
    }
} jackets[N];
void inp()
{
    cin >> numJacket;
    forr(i, 1, numJacket)
    jackets[i].inp();
    cin >> numDay;
    forr(i, 1, numDay)
    {
        int tmp;
        cin >> tmp, ++tmp;
        Min = min(Min, tmp);
    }
}
class SegmentTree
{
private:
    int t[4 * N], d[4 * N];
    void init(int node, int l, int r)
    {
        d[node] = 1e9;
        t[node] = 1e9;
        if (l == r)
        {
            if (r == Max)
                t[node] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        init(node * 2, l, mid);
        init(node * 2 + 1, mid + 1, r);
        t[node] = min(t[node * 2], t[node * 2 + 1]);
    }
    void lazyUpdate(int node, int l, int r)
    {
        if ((l == r) || (d[node] == 1e9))
            return;
        for (int x = node * 2; x <= node * 2 + 1; ++x)
        {
            t[x] = min(t[x], d[node]);
            d[x] = min(d[x], d[node]);
        }
        d[node] = 1e9;
    }
    int GetMin(int node, int L, int R, int l, int r)
    {
        lazyUpdate(node, L, R);
        if (R < l || r < L)
            return 1e9;
        if (l <= L && R <= r)
            return t[node];
        int mid = (L + R) >> 1;
        int Left = GetMin(node * 2, L, mid, l, r);
        int Right = GetMin(node * 2 + 1, mid + 1, R, l, r);
        return min(Left, Right);
    }
    void Update(int node, int L, int R, int l, int r, int x)
    {
        lazyUpdate(node, L, R);
        if (R < l || r < L)return;
        if (l <= L && R <= r)
        {
            t[node] = min(t[node], x);
            d[node] = min(d[node], x);
            return;
        }
        int mid = (L + R) >> 1;
        Update(node * 2, L, mid, l, r, x);
        Update(node * 2 + 1, mid + 1, R, l, r, x);
        t[node] = min(t[node * 2], t[node * 2 + 1]);
    }
public:
    void init()
    {
        init(1, 1, Max);
    }
    int GetMin(int l, int r)
    {
        return GetMin(1, 1, Max, l, r);
    }
    void Update(int l, int r, int x)
    {
        Update(1, 1, Max, l, r, x);
    }
} IT;
void Process()
{
    IT.init();
    sort(jackets + 1, jackets + numJacket + 1);
    for (int i = 1; i <= numJacket; ++i)
    {
        int l = jackets[i].l, r = jackets[i].r;
        int res = IT.GetMin(l, r + 1);
        IT.Update(l, r, res + 1);
    }
    int ans = IT.GetMin(1, Min);
    cout << ((ans == 1e9) ? (-1) : (ans));
}
int main()
{
#define Task "COOLMAC"
    freopen(Task".inp", "r", stdin);
    freopen(Task".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inp();
    Process();
    return 0;
}
