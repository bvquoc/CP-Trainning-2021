#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>

using namespace std;

char __;
template<typename T>
void getSigned(T &x)
{
    while (__ = getchar(), __ != '-' && (__ < '0' || __ > '9'));
    bool sign(__ == '-');
    if (sign) __ = getchar();

    x = __ - '0';
    while (__ = getchar(), __ >= '0' && __ <= '9')
        x = (x << 3) + (x << 1) + (__ - '0');

    if (sign) x = -x;
}

void file(const string FILE = "Test")
{
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}

template<typename T> inline void maximize(T &res, const T &val) { if (res < val) res = val; }
template<typename T> inline void minimize(T &res, const T &val) { if (res > val) res = val; }

#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pi;
typedef long long ll;
const int LIM = 5e5 + 55;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
/// ====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====

int n, m, d;
string s;

int sub1()
{
    int st = 0, best = 0, cnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '1')
        {
            ++cnt;
            if (best < cnt)
            {
                best = cnt;
                st = i - best + 1;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    cout << st + 1 << ' ' << st + best;
    return 0;
}

int sub2(int k = d)
{
    deque<int> S;
    int st = 0, best = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0' && k == 0)
        {
            while (s[S.front()] == '1') S.pop_front();
            S.pop_front();
            ++k;
        }

        S.push_back(i);
        if (s[i] == '0') --k;

        if (best < S.size())
        {
            best = S.size();
            st = i - best + 1;
        }
    }

    cout << st + 1 << ' ' << st + best;
    return 0;
}

int f[LIM];
vector<int> G[LIM];
int dfs_0(int u)
{
    if (f[u] != -1) return f[u];
    int &res = f[u];

    if (s[u] == '0') return res = u;

    res = n;
    for (int v : G[u])
        minimize(res, dfs_0(v));

    return res;
}

int dfs_1(int u)
{
    if (f[u] != -1) return f[u];
    int &res = f[u];

    if (s[u] == '1') return res = u;

    res = 0;
    for (int v : G[u])
        maximize(res, dfs_1(v));

    return res;
}

int sub3(int k = d)
{
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        getSigned(u);
        getSigned(v);
        --u; --v;

        if (u < v)
            G[u].push_back(v);
        else
            G[v].push_back(u);
    }

//    for (int i = 0; i < n; ++i)
//    {
//        sort(all(G[i]));
//        reverse(all(G[i]));
//    }

    deque<int> S;
    int st = 0, best = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0') /// Take rightmost '1' | guaranteed not in queue
        {
            memset(f, -1, sizeof(f[0]) * (n + 1));
            int p = dfs_1(i);
            if (p != 0) swap(s[i], s[p]); // if exist
        }

        if (s[i] == '0' && k == 0) /// Empty of special adding, find leftmost '0' to replace
        {
            bool Need = true;
            while (S.size() && s[S.front()] == '1') /// Remove leftmost '1' connected
            {                                       /// By trading with first '0' at right if exist
                memset(f, -1, sizeof(f[0]) * (n + 1));
                int p = dfs_0(S.front());
                if (p != n) swap(s[S.front()], s[p]); // if exist
                S.pop_front();

                if (p <= i)
                {
                    if (p < i) ++k;
                    Need = false;
                    break;
                }
//                cout << "[" << i << "] = " << s << " | " << S.front() << " -> " << p << " / " << n << endl;
            }

            if (Need && S.size() && s[S.front()] == '0') /// Remove leftmost '0'
            {                                    /// By replacing it with current
                S.pop_front();
                ++k;
            }
        }

        if (s[i] == '1' || k > 0) /// If the light is set or possible of using special adding
        {
            S.push_back(i);
            if (s[i] == '0') --k;
        }

//        cout << s << " | ";
//        cout << k << " | ";
//        for (int x : S) cout << x + 1 << ' ';
//        cout << endl;
        if (best < S.size()) /// Update the fucking result
        {
            best = S.size();
            st = i - best + 1;
        }

    }

    cout << st + 1 << ' ' << st + best; /// Output the fucking result
    return 0;
}

int main()
{
    file("DECOR");
    cin >> n >> m >> d;
    cin >> s;

    if (count(all(s), '1') == 0 && d == 0)
    {
        cout << -1;
        return 0;
    }

    if (count(all(s), '0') <= d)
    {
        cout << 1 << ' ' << n;
        return 0;
    }

    if (m == 0 && d == 0)
    {
        sub1();
        return 0;
    }

    if (m == 0)
    {
        sub2();
        return 0;
    }

    if (n <= 2000)
    {
        sub3();
        return 0;
    }

    sub3(); /// Complex Data Structure Required to Upgrade
    return 0;
}

/*
5 3 1
00101
1 2
2 3
3 5

1 3
*/

/*
5 0 3
11010

1 5
*/

/*
15 1 5
101001000100001
10 9

1 9

*/

/*
15 2 5
101001000100001
10 9
15 9

1 10
*/

/*
15 0 10
101001000100001

1 15
*/

/*
15 1 6
101001000100001
1 3

1 10
*/

/*
10 0 5
1010101010
1 3

1 10
*/
