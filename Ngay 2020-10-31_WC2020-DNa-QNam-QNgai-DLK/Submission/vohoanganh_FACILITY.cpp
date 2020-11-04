#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, int> pli;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

struct facility {
    int s, d, r;
    facility (int s = 0, int d = 0, int r = 0)
    : s(s), d(d), r(r) {}

    friend istream &operator >> (istream &cin, facility &a) {
        cin >> a.s >> a.d >> a.r;
    }

    bool operator < (const facility &o) const {
        return (s != o.s) ? (s < o.s)
             : (d != o.d) ? (d < o.d) 
                          : (r < o.r);
    }
};

int n, k;
vector<facility> a;
vector<int> jump;
vector<ll> f;
ll magic(int i = 0)
{
    if (i == n) return 0;

    ll &res = f[i];
    if (res != -LINF) return res;
    return res = max(magic(i + 1), magic(jump[i]) + a[i].r);
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(all(a));
    jump.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int pos = n;
        int timer = a[i].s + a[i].d + k;
        for (int l = i + 1, r = n - 1; l <= r; )
        {
            int m = (l + r) >> 1;
            if (a[m].s >= timer)
            {
                pos = m;
                r = m - 1;
            }
            else 
                l = m + 1;
        }
        jump[i] = pos;
    }

    f.assign(n + 1, -LINF);
    cout << magic();
    return 0;
}