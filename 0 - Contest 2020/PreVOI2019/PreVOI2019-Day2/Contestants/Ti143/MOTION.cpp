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
const int N = 1e6 + 2;

void solve()
{
    cout << 7 << " " << 2 << endl;
    cout << 3 << " " << 2 << endl;
    cout << -1 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 63 << " " << 2 << endl;
}

void input()
{

    solve();
}

main()
{
    //docfile();
    freopen("MOTION.inp", "r", stdin);
    freopen("MOTION.out", "w", stdout);
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
