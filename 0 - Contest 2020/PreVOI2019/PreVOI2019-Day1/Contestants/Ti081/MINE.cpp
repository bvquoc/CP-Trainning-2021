#include<bits/stdc++.h>
#define fi first
#define se second
#define pairs pair<int,int>
#define uppair pair<int,pairs>
#define downpair pair<pairs,int>
#define add push_back
#define upfor(i,x,y) for(int i=x; i<=y; i++)
#define downfor(i,x,y) for(int i=x; i>=y; i--)
#define sz(s) (int)s.size()
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define maxm 200001
#define maxn 400000
using namespace std;
const int M = 1000003;
int n, m;
int a[maxn];
long long f[5000][5000];
long long gt[maxn], dgt[maxn];

long long lt( long long x, long long y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;
    long long c = lt(x,y/2);
    if(y%2==0)
        return (c*c)%M;
    if(y%2!=0)
        return ((c*c)%M * x)%M;
}

void online_judge()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
}

void solvem(int n, int m)
{
    gt[0] = 1;
    upfor(i,1,2*n) gt[i] = (gt[i-1]*i)%M;
    dgt[2*n] = lt(2*n,M-2);
    downfor(i,2*n-1,0) dgt[i] = (dgt[i+1]*(i+1))%M;
    long long res = ((gt[2*n]*dgt[n])%M * dgt[n+1])%M;
    cout<<res;
}

void solve()
{
    cin>>n>>m;
    upfor(i,1,2*n) cin>>a[i];
    if(n<=5000)
    {
        upfor(i,2,2*n) f[i-1][i] = (a[i] - a[i-1] <=m);
        long long step;
        for(int w=3; w<=2*n; w+=2)
        {
            for(int i=1; i+w<=2*n; i++)
            {
                int j = i+w;
                if(a[j] - a[i] <= m)
                    f[i][j] = f[i+1][j-1];
                step = -1e18;
                for(int k=1; i+k+1<=j; k++)
                    step = max(step,f[i][i+k]*f[i+k+1][j]);
                f[i][j] = (f[i][j]+step)%M;
            }
        }
        cout<<f[1][2*n];
    }
    else
    {
        if(m>= a[2*n] - a[1])
        {
            solvem(n,m);
            return;
        }
    }
}

int main()
{
    fastread
    online_judge();
    solve();
    return 0;
}
