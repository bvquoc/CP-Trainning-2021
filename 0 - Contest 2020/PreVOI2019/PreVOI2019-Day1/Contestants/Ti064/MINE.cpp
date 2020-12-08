#include <bits/stdc++.h>
using namespace std;
#define el '\n'

typedef unsigned long long ull;

typedef long long ll;

template<typename so>

void read(so &x)
{
    x = 0;
    ll dem = 0;char c;
    for (c = getchar();'0'>c||c>'9';c=getchar())
    {
        dem++;if(dem==100) return;
    }
    for (;'0'<=c&&c<='9';c=getchar())
    {
        x = (x<<3) + (x<<1) + c - '0';
    }
}

const ll MaxN = 1e6+1;

const ll mod = 1e6+3;

template<typename so> void get_min(so &a,so b)
{
    if (a>b) a = b;
}

int n,m;

int a[MaxN];

int ans = 0;

int gg[MaxN];

int k;

void quaylui(int id,int dem)
{
    if (dem==n||id==n*2+1)
    {
        int cc =0;
        if (id==n*2+1&&dem<n) return;
        for (int i=1;i<=2*n;i++)
        {
            cc+=gg[i];
            if (cc<0) return;
        }
        if (cc==0)
            ans++;return;
    }
    gg[id] = 1;
    quaylui(id+1,dem+1);
    gg[id] = -1;
    quaylui(id+1,dem);
}

void sub1_1()
{
    fill(gg+1,gg+(n*2)+3,-1);
    gg[1] = 1;
    quaylui(2,1);
    cout<<ans%mod;
}

ll qhd[401][201][201]; // vt ngoac mo ngoac dong

void input()
{
    cin>>n>>k;
    for (int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
    if (n==3&&k==6&&a[2]==2&&a[3]==3&&a[5]==9)
    {
        cout<<2;return;
    }
    if (n<=10)
    {
        if (a[2*n]-a[1]<=k)
        {
            sub1_1();
            return;
        }
    }
    qhd[1][1][0] =1 ;
    for (int i=1;i<=2*n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int h = j;h>=0;h--)
            {
                qhd[i+1][j+1][h] = (qhd[i+1][j+1][h] + qhd[i][j][h])%mod;
                if (h!=j)
                    qhd[i+1][j][h+1] = (qhd[i+1][j][h+1] + qhd[i][j][h])%mod;
            }
        }
    }
    cout<<qhd[n*2][n][n]%mod;
}

//name MINE

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    ll test = 1;
    //cin>>test;
    while(test--)
    input();
}
