#include <bits/stdc++.h>
#define getbit(x, i) (x >> (i - 1) & 1)
#define onbit(x, i) (x | (1 << (i - 1)))
#define offbit(x, i) (x ^ (1 << (i - 1)))
#define cntone(x) (__builtin_popcount(x))
#define sum(x, y, u, v) (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1])

using namespace std;

typedef long long ll;
const int oo = 1e9;
const int mod = 1e6 + 3;
const int maxn = 2e5 + 10;

template < typename T > inline void read(T &x)
{
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do x = x * 10 + c - 48; while(isdigit(c = getchar()));
}

int n, m, a[maxn], res;
int b[maxn];
bool dx[maxn], xet[222][222];

bool mid(int a, int b, int c)
{
    return (a <= b && b <= c);
}

bool check()
{
    vector < int > pos[100];
    for(int i = 1; i <= n + n; i++)
    {
        pos[b[i]].push_back(i);
        if(pos[b[i]].size() == 2 && a[pos[b[i]].back()] - a[pos[b[i]].front()] > m)
            return false;
    }
    for(int i = 2; i <= n; i++)
        for(int j = 1; j < i; j++)
        {
            int Li = pos[i].front(), Ri = pos[i].back();
            int Lj = pos[j].front(), Rj = pos[j].back();
            if(!((mid(a[Lj], a[Li], a[Rj]) && mid(a[Lj], a[Ri], a[Rj])) || (a[Li] > a[Rj])))
                return false;
        }
    if(xet[1][pos[1].back()]) return false;
    xet[1][pos[1].back()] = true;
    return true;
}

void Try(int x)
{
    if(x > n + n)
    {
        /*for(int i = 1; i <= n + n; i++)
        {
            if(b[i] > n) b[i] -= n;
            cout << b[i] << ' ';
        }*/
        bool ok = check();
        res += ok;
        //cout << '\n';
        return;
    }
    if(x == 1)
    {
        dx[1] = true;
        b[x] = 1;
        Try(x + 1);
        dx[1] = false;
    }
    else
    {
        for(int i = 1; i <= n + n; i++)
        if(!dx[i])
        {
            dx[i] = true;
            b[x] = i;
            if(i > n) b[x] = i - n;
            if(i != 1 && i != n + 1) Try(x + 1);
            if(((i == 1 || i == n + 1) && !xet[1][x]))
                if((i == 1 || i == n + 1) && a[x] - a[1] <= m)
                    Try(x + 1);
            dx[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("MINE.inp", "r"))
    {
       freopen("MINE.inp", "r", stdin);
       freopen("MINE.out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n + n; i++) cin >> a[i];
    if(a[n] - a[n - 1] > m)
    {
        cout << 0;
        return 0;
    }
    Try(1); cout << res;
}
