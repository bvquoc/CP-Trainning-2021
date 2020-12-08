#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define db "MINE"
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
const int N = 5 * 1e5 + 2;
const int MOD = 1e6 + 3;
int n, m, ans;
int a[N];
int cnt[N], cntt[N];
int l, r, val;

void solve()
{
    cntt[2] = 0;
    cnt[2] = 1;
    for(int i = 4; i <= 2 * n; i += 2)
    {
        for(int j = 2; j <= i - 2; j += 2)
        {
            cnt[i] = cnt[i] + (max(1, cntt[j]) * cnt[i-j] % MOD);
            cnt[i] %= MOD;
        }
        cnt[i] += cnt[i-2];
        cnt[i] %= MOD;
        cntt[i] = cnt[i-2];
        cntt[i] %= MOD;
    }
    deque <PII2> dq;
    for(int i = 2; i <= 2 * n; i += 2)
        if(a[i] - a[1] <= m) dq.push_back({{1, i}, max(1, cntt[i])});
    while(!dq.empty())
    {
        l = dq.front().fi.fi;
        r = dq.front().fi.se;
        val = dq.front().se;
        dq.pop_front();
        if(r == 2 * n)
        {
            ans = ans + (val * cnt[r-l+1] % MOD);
            ans %= MOD;
            continue;
        }
        r++;
        for(int i = r + 1; i <= 2 * n; i += 2)
            if(a[i] - a[r] <= m) dq.push_back({{r, i}, (val + cntt[i-r+1]) % MOD});
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n * 2; i++) cin >> a[i];
    solve();
}

main()
{
    //docfile();
    freopen("MINE.inp", "r", stdin);
    freopen("MINE.out", "w", stdout);
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
