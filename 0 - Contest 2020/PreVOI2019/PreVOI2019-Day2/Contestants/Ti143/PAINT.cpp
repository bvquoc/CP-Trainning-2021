#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define db "ABS"
#define fi first
#define se second
#define endl '\n'
//#define int long long
const int INF = 1e9 + 1;
const int mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;
typedef pair<int, PII> PII3;

void docfile()
{
    if (ifstream("FORM.inp"))
    {
        freopen("FORM.inp", "r", stdin);
        freopen("FORM.out", "w", stdout);
    }
    else if (ifstream(db".inp"))
    {
        freopen(db".inp", "r", stdin);
        freopen(db".out", "w", stdout);
    }
}

//---------------------------------------------------------------------------
const int N = 1e5 + 2;
int n, t, j; char x, y;
vector <int> pos[30];
string ans;

void solve()
{
    cin >> t >> x;
    if(t == 2)
    {
        cin >> y;
        if(!pos[(x - 'a')].empty() || x == y)
        {
            int val = (x - 'a');
            int len = pos[val].size();
            for(int i = 0; i < len; i++)
            {
                int it = pos[val][i];
                ans[it] = y;
                pos[(y - 'a')].push_back(it);
            }
            pos[(x - 'a')].clear();
        }
    }
    else
    {
        j++;
        ans += x;
        pos[(x - 'a')].push_back(j);
    }
}

void input()
{
    j = -1;
    cin >> n;
    while(n--)
    solve();
    cout << ans;
}

main()
{
    //docfile();
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;
    while(test--)
    input();
}


//-----------------------------------------------------------------------------

/*
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
*/
