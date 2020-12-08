#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define db "Oddcoin"
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
const int N = 20;
int m[50] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int x, y, ans;
int a, b;

void solve()
{
    priority_queue <PII, vector<PII>, greater<PII> > pq;
    ans = LONG_MAX;
    m[16] = x;
    for(int i = 1; i <= 16; i++)
        if(y >= m[i]) pq.push({y / m[i], y % m[i]});
    while(!pq.empty())
    {
        a = pq.top().fi;
        b = pq.top().se;
        pq.pop();
        if(a > ans || b == 0)
        {
            ans = min(ans, a);
            continue;
        }
        for(int i = 1; i <= 16; i++)
            if(b >= m[i]) pq.push({a + b / m[i], b % m[i]});
    }
    cout << ans << endl;
}

void input()
{
    cin >> x >> y;
    solve();
}

main()
{
    //docfile();
    freopen("ODDCOIN.inp", "r", stdin);
    freopen("ODDCOIN.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
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

/*
12
101 150
4700 9701
6 158
2000 1300000
4 27
4700 53
4700 9400
4700 9401
4700 30000
1999999999 2000000000
1243 31231
1 2000000000
*/

/*
2
3
4
26
4
2
2
3
1
2
6
40000
*/

