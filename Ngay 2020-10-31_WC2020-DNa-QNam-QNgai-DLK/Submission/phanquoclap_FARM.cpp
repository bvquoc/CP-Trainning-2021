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

int n, k, q, p;
vector<int> a;
vector<vector<int> > f;
int magic(int i = 0, int left = q)
{
    if (left == 0) return 0;
    if (i >= n) return 0;

    int &res = f[i][left];
    if (res != -INF) return res;

    res = magic(i + 1, left);
    int t = min(left, p);
    maximize(res, magic(i + k, left - t) + t * a[i]);
    t = left % p;
    maximize(res, magic(i + k, left - t) + t * a[i]);
    return res;
}

int main()
{
    cin >> n >> k >> q >> p;

    a.resize(n);
    for (int &x : a) cin >> x;

    f.assign(n + 1, vector<int>(q + 1, -INF));
    cout << magic();
    return 0;
}