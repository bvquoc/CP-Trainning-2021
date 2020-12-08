///Phß║ím Nguyß╗àn Tuß║Ñn Ho├áng///
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a);i <= (b);i++)
#define repd(i,a,b) for(int i = (a);i >= (b);i--)
#define F first
#define S second
#define PB push_back
#define Task "mine"
using namespace std;
//template <class T> inline read(T &a){a = 0;char c;bool nega = 0;while(!isdigit(c = getchar()) && c != '-');if(c == '-') nega = 1,c = getchar();a = c - 48;while(isdigit(c = getchar()))a = a * 10 + c - 48;if(nega) a = -a;}
//template <class T> inline writep(T a){if(a > 9) writep(a / 10);putchar(a % 10 + 48);}
//template <class T> inline write(T a){if(a < 0) putchar('-'),a = -a;writep(a);putchar(' ');}
//template <class T> inline writeln(T a){write(a);putchar('\n');}
const int N = 400012,mod = 1000003;
long long f[N],nf[N],dp[N];
int n,m,a[N];

int c(int k,int n)
{
    return (f[n] * nf[k] % mod) * nf[n - k] % mod;
}

int catalan(int l)
{
    if(l & 1) return 0;
    if(l == 0) return 1;
    return (c(l/2,l) -
            c(l/2-1,l) + mod) % mod;
}

int POW(long long a,int b)
{
    long long c = 1;
    for(;b;b /= 2,a = a * a % mod)
        if(b & 1) c = c * a % mod;
    return c;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin >> n >> m;
    f[0] = 1;
    rep(i,1,2*n+1)
    {
        f[i] = f[i-1] * i % mod;
        cin >> a[i];
    }
    nf[2*n + 1] = POW(f[2*n + 1],mod - 2);
    repd(i,2*n,0) nf[i] = nf[i + 1] * (i + 1) % mod;
    if(m == 1000000)
        cout << catalan(2*n) << '\n';
    else
    {
        dp[0] = 1;
        for(int i = 1;i <= 2 * n;i += 2)
            for(int j = i + 1;j <= 2 * n && a[j] - a[i] <= m;j += 2)
                dp[j] += (dp[i - 1] * catalan(j - i - 1)) % mod;
        cout << dp[2*n] << '\n';
    }
    return 0;
}
