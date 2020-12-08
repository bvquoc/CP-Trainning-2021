#include <bits/stdc++.h>

#define taskname "PAINT"
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

const int maxN = 1e6 + 1;

int n;

int idx = 0;
char color[maxN];

int last[256];

int parent[256];
pair <char, char> out[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    cin >> n;
        vi adj[256];
        for1(i, n)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                char c;
                cin >> c;
                adj[c].eb(++idx);
            }
            else
            {
                char a, b;
                cin >> a >> b;
                while (!adj[a].empty())
                {
                    adj[b].eb(adj[a].back());
                    adj[a].pop_back();
                }
            }
        }
        vector <char> rs(idx + 1);
        fore(i, 'a', 'z')
        {
            for (auto &c: adj[i])
            {
                rs[c] = i;
            }
        }
        for1(i, idx)
        {
            cout << rs[i];
        }

    return 0;
}
