#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define reset(x) memset(x, 0, sizeof x)
#define MIN(x,y) {if (x > (y)) x = (y);}
#define MAX(x,y) {if (x < (y)) x = (y);}
#define remain(x) while (x >= MOD) x -= MOD
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 1000010
#define maxC INT_MAX
#define MOD 1000000007
#define ll long long
#define pii pair <int, int>
#define task "PAINT"

using namespace std;

int n;
char a[maxn];
bool mark[maxn];

void sub1()
{
    FOR(i, 1, n)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            char x; cin >> x;
            FOR(j, 1, n) if (!mark[j]) {mark[j] = 1; a[j] = x; break;}
        }
        else
        {
            char x, y;
            cin >> x >> y;
            FOR(j, 1, n)
            {
                if (!mark[j]) break;
                if (a[j] == x) a[j] = y;
            }
        }
    }
    FOR(i, 1, n)
        if (mark[i]) cout << a[i];
        else break;
}

struct data {int type; char x, y;} t[maxn];
char ne[maxn], kq[maxn];

void sub2()
{
    int dem = 0;
    FOR(i, 1, n)
    {
        cin >> t[i].type >> t[i].x;
        if (t[i].type == 2) cin >> t[i].y;
    }
    for(char c = 'a'; c <= 'z'; c++) ne[c] = c;
    FORD(i, n, 1)
    {
        if (t[i].type == 2) ne[t[i].x] = ne[t[i].y];
        else kq[++dem] = ne[t[i].x];
    }
    FORD(i, dem, 1) cout << kq[i];
}

int main()
{
    ios_base:: sync_with_stdio(NULL);
    cin. tie(NULL) ; cout. tie(NULL);
    freopen(task".INP" , "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n;
    if (n <= 10000) sub1();
    else sub2();
    return 0;
}
