#include <iostream>
#include <cstdio>
using namespace std;
#define int long long
///trau

const int mod = 1000003;
int n;
int m;
int a[400005];
int st[15];
int x[15];
int t;
int ans = 0;
int gt[400005];
int nd[400005];

void tryyy(int i,int t)
{
    if (t < 0) return;
    for (int j = 0; j < 2; j++)
    {
        x[i] = j;
        int z=t;
        if (j == 0) z--;
        else z++;
        if (i == n)
        {
            if (z==0)
            {
                t = 0;
                for (int z = 1; z <= n; z++)
                {
                    if (x[z] == 1)
                    {
                        st[++t] = a[z];
                    }
                    else
                    {
                        int tmp = a[z] - st[t];
                        t--;
                        if (tmp > m) return;
                    }
                }
                ans ++;
                ans%=mod;
            }
        }
        else tryyy(i+1,z);
    }
}


void inp()
{
    scanf("%lld%lld",&n,&m);
    n*=2;
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
}


int powr(int x,int y)
{
    if (y==0) return 1;
    int t = powr(x,y/2);
    t = t*t%mod;
    if (y%2==0)
    return t;
    return t*x%mod;
}


int cc(int n,int k)
{
    if (n==k || k == 0) return 1;
    return gt[n]*nd[k]%mod*nd[n-k]%mod;
}


void proc()
{
    int k = n/2;
    gt[0] = 1;
    gt[1] = 1;
    nd[0] = 1;
    nd[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        gt[i] = gt[i-1]*i%mod;
        //nd[i] = powr(i,mod-2)*nd[i-1]%mod;
    }
    nd[k+1] = powr(gt[k+1],mod-2);
    for (int i = k; i > 0; i--)
    {
        nd[i] = nd[i+1]*(i+1);
        nd[i] %= mod;
    }
    int cx;
    int cy;
    cx = cc(n,k);
    cy = cc(n,k-1);
    printf("%lld",(cx-cy + mod*mod)%mod);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    inp();
    x[1] = 1;
    if (m == 1000000)
    proc();
    else
    {
        tryyy(2,1);
        printf("%lld",ans);
    }
    return 0;
}
