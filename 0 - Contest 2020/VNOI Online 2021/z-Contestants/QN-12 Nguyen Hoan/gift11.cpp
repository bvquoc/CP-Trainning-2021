#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
typedef struct pair<int, int> ii;
void io () {
    freopen ("gift11.inp", "r", stdin);
    freopen ("gift11.out", "w", stdout);
}
int d[15];
int n, t;
string a[2010];
ll res[3];
ll mod = 998244353;
ll ans = 0;

void inp () {
    cin >> t;
}

void solve1()
{
    ans = 0;
    do
    {
        res[0] = 0;
        res[1] = 0;
        int now = 0;
        for(int i = 1; i <= n; i++)
        {
            string S = a[d[i]];
            for(int j = 0; j < S.size(); j++)
            {
                res[now] += (int)(S[j] - '0');
                now = 1 - now;
            }
        }
        if((res[0] - res[1]) % 11 == 0) ans = (ans + 1) % mod;
    } while(next_permutation(d + 1, d + n + 1));
}

ll GT(ll n)
{
    ll kq = 1;
    for(int i = 1; i <= n; i++)
    {
        kq = (kq * i) % mod;
    }
    return kq % mod;
}

void solvechan()
{
    res[0] = 0;
    res[1] = 0;
    int now = 0;
    for(int i = 1; i <= n; i++)
    {
        string S = a[i];
        for(int j = 0; j < S.size(); j++)
        {
            res[now] += (int)(S[j] - '0');
            now = 1 - now;
        }
    }
    if((res[0] - res[1]) % 11 == 0) ans = (ans + GT(n)) % mod;
}

void sub1 () {
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            d[i] = i;
//            cout << a[i] << "\n";
        }
        if(n <= 10)
        {
            solve1();
        }
        else
        {
            if(a[1].size() % 2 == 0)
            {
                solvechan();
            }
//            else solvele();
        }
        cout << ans << "\n";
    }
}
int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    io ();
    inp ();
    sub1 ();
    return 0;
}
