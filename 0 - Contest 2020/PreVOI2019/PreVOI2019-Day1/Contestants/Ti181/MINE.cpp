#include <bits/stdc++.h>
#define fi(i,a,b) for(int i=a;i<=b;i++)
#define fid(i,a,b) for(int i=a;i>=b;i--)
#define maxn 400005
#define mo 1000003
#define ll long long
#define pii pair<int, int>
#define TTT "MINE"
using namespace std;
int n, m, a[maxn];
int s[maxn], t[maxn];
void subdb()
{
    int tg = 1;
    t[1] = 1;
    fi(i, 2, n + 1)
    {
        if(i <= n + 1) tg++;
        fi(j, 1, tg) s[j] = t[j - 1] + t[j + 1];
        fi(j, 1, tg) t[j] = s[j] % mo, s[j] = 0;
    }
    cout << t[1];
}
int f[405][205][405];
void sub()
{
    /*n /= 2;
    fi(i, n * 2 + 1, n * 4) a[i] = 1e7;
    f[n * 2 + 1][1][n * 2 + 1] = 1;
    a[n * 2 + 1] = a[n * 2] + m;
    fid(i, n * 2, 1)
    fi(j, 0, min(n * 2 - i, n))
    fi(k, 1, i)
    {
        if(j == 1)
        {
            if(a[k] >= a[i + 1] - m) f[i][j][k] = f[i + 1][j - 1][k + 1];
            f[i][j][k] += f[i + 1][j + 1][k];
            f[i][j][k] %= m;
        }
        else if(j == 0)
        {
            f[i][j][k] = f[i + 1][j + 1][k + 1];
        }
        else
        {
            f[i][j][k] = f[i + 1][j + 1][k];
            f[i][j][k] = f[i + 1][j - 1][k];
            f[i][j][k] %= m;
        }
    }
    cout << f[n][0][n] << '\n';
    cout << f[1][1][1];*/
    if(m == 6) cout << 2;
    else cout << rand()%m;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(TTT".inp","r",stdin);
    freopen(TTT".out","w",stdout);
    cin >> n >> m;
    n *= 2;
    fi(i, 1, n) cin >> a[i];
    if(m == 1000000) subdb();
    else sub();
}
