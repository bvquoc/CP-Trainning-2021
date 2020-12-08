#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define db "CONSTRUCT"
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
int n, m, ans, cur;
int a[N], h[N], b[N];
int t, l, r, x, flag;
int ok[N];

void solve()
{
    memset(ok, 0, sizeof(ok));
    while(m--)
    {
        ans = 0;
        cin >> t >> l >> r;
        if(t == 1)
        {
            cin >> x;
            for(int i = l; i <= r; i++) h[i] += x;
            for(int i = l; i <= r; i++) if(h[i] >= a[i]) ok[i] = 1;
        }
        else
        {
            for(int i = 1; i <= n; i++)
            {
                if(i < l || i > r) b[i] = 0;
                else b[i] = h[i];
            }
            flag = ans = 0;
            while(!flag)
            {
                flag = 1;
                for(int i = 1; i <= n; i++)
                {
                    if(b[i] < a[i]) {flag = 0; break;}
                }
                int j = 1;
                while(b[j] >= a[j]) j++;
                for(int i = j; i <= n; i++)
                {
                    if(b[i] >= a[i] && !ok[i]) break;
                    b[i]++;
                }
                ans++;
            }
            cout << ans - 1<< endl;
        }
    }
}

void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], h[i] = 0;
    solve();
}

main()
{
    //docfile();
    freopen("CONSTRUCT.inp", "r", stdin);
    freopen("CONSTRUCT.out", "w", stdout);
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
