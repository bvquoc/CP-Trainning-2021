#include <bits/stdc++.h>
#define maxn 1000005
#define NTLiinhh "mine"
#define fto(i,a,b) for (int i=a;i<=b;i++)
#define fdto(i,a,b) for (int i=a;i>=b;i--)
#define endl '\n'
using namespace std;
const int base=1e6+3;
int n, m, a[maxn];
void input()
{
    ios_base::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen (NTLiinhh".inp","r",stdin);
    freopen (NTLiinhh".out","w",stdout);
#endif // ONLINE_JUDGE
    cin >> n >> m;
    n*=2;
    fto (i,1 , n) cin >> a[i];
}

int res, x[maxn], q[maxn], in[maxn];

void check ()
{
    int cnt=0, j=0;
    fto (i, 1, n)
        if (!x[i]) q[++cnt]=++j, in[j]=a[i]; else {
                if (a[i]-in[q[cnt]]>m) return;
                --cnt;
                if (cnt<0) return ;
        }
    if (x[n]==0 || cnt) return;
    ++res;
}

void tohop (int i)
{
    if (i==n+1) {check(); return;}
    fto (j, 0, 1) x[i]=j, tohop(i+1);
}

int f[201][201][201];
int calc (int c, int vt, int last)
{
    if (f[c][vt][last]!=-1) return f[c][vt][last];
    if (vt==n+1) {
        if (c==0) f[c][vt][last]=1; else f[c][vt][last]=0;
        return f[c][vt][last];
    }
    f[c][vt][last]=0;
    if (c>0 && a[vt]-a[last]<=m) f[c][vt][last]=calc(c-1, vt+1, last);
    if (c==0) f[c][vt][last] = (f[c][vt][last] + calc(c+1, vt+1, vt))%base;
    if (c>0) f[c][vt][last] = (f[c][vt][last] + calc(c+1, vt+1, last))%base;
    return f[c][vt][last];
}

void solve3()
{
    fto (i, 0, n+1) fto (j, 0, n+1) fto (t, 0, n+1) f[i][j][t]=-1;
    cout << calc(0, 1, 0);
}

void solve1()
{
    tohop(1);
    cout << res << endl;
}

int main()
{
    input();
    if (n<=20) solve1();
    else solve3();
}
