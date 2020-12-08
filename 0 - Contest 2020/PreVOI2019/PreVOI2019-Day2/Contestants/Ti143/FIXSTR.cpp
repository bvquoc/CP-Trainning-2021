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
string s, b[N];
int n, m, ans;
char t;
int x, y;

void sub1()
{
    for(int i = 1; i <= m; i++)
    {
        b[i] = s;
        cin >> t >> x;
        if(t == 'Q')
        {
            cin >> y;
            stack <int> st;
            ans = 0;
            for(int j = x; j <= y; j++)
            {
                if(s[j] == '(') st.push(j);
                else
                {
                    if(st.empty()) ans++;
                    else st.pop();
                }
            }
            cout << ans + st.size() << endl;
        }
        else if(t == 'C')
        {
            if(s[x] == ')') s[x] = '(';
            else s[x] = ')';
        }
        else s = b[x];
    }
}

/*
void sub2()
{
    for(int i = 1; i <= n; i++)
    {
        cur[i] = cur[i-1];
        cnt[i] = cnt[i-1];
        if(s[i] == '(') cur[i] = max(0, cur[i] + 1);
        else cur[i] = max(cur[i] - 1, -1);
        if(cur[i] < 0) cnt[i]++;
    }
    while(m--)
    {
        cin >> t >> x;
        if(t == 'Q')
        {
            cin >> y;
        }
        else
        {
            if(s[x] == '(') leo[x]++;
            else leo[x]--;
        }
    }
}
*/

void solve()
{
    sub1();
    //else sub2();
}

void input()
{
    cin >> s >> m;
    n = s.size();
    s = '*' + s;
    solve();
}

main()
{
    //docfile();
    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
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
