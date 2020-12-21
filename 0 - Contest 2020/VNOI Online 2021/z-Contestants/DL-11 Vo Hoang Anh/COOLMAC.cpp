#include <algorithm>
#include <iostream>
#include <cstdio>
#include <deque>
#include <queue>
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

typedef pair<int, int> pi;
const int MAXN = 1e5 + 15;
const int INF = 0x3f3f3f3f;

/// ====*====*====*====*====*====*====*====*====*====*====

int n;
pi a[MAXN];

int lowest, highest;
int f[MAXN];
int magic(int i = 0, int cover = lowest)
{
    if (cover >= highest) return 0;
    if (i >= n) return +INF;

    int &res = f[cover];
    if (res != -1) return res;

    res = magic(i + 1, cover);
    if (a[i].first <= cover)
        minimize(res, magic(i + 1, a[i].second) + 1);

    return res;
}

int main()
{
    file("COOLMAC");
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        getUnsign(a[i].first);
        getUnsign(a[i].second);
    }

    sort(a, a + n, [](const pi &a, const pi &b) {
        return (a.second != b.second)
             ? a.second < b.second
             : a.first < b.first;
    });




    int m;
    cin >> m;

    lowest = +INF;
    highest = 1e5;
    for (int i = 1; i <= m; ++i)
    {
        int temp;
        getUnsign(temp);
        minimize(lowest, temp);
    }

    memset(f, -1, sizeof(f));
    int res = magic();
    if (res >= +INF)
        cout << -1;
    else
        cout << res;

    return 0;
}
