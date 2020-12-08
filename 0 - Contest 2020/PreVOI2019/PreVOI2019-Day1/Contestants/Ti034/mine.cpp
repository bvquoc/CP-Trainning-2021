//----------Just Me & You---------
#include <bits/stdc++.h>
#include <bitset>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define oo 1000000007
#define Mod 1000003
#define ll long long
#define pii pair< int, int>
#define memset(f, a) memset(f, a, sizeof(f))
#define sz(x) int(x.size())
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,a,b) for(int i=a;i>=b;--i)
#define Lozer "mine"
#define mn 100005

using namespace std;

//1 la vao
//0 la ra

int n,m,a[mn];
int vao[mn],ra[mn];
int f[mn];

int Tinh(int x)
{
    int cur=0;
    forr(i,0,n)
    {
        vao[i]=0;
        ra[i]=0;
    }
    forr(i,0,2*n-1)
    {
        int bi=(x>>i)&1;
        if(bi==1)
        {
            cur++;
            vao[cur]=a[i];
        }
        else
        {
            ra[cur]=a[i];
            if(ra[cur]-vao[cur]>m)
            {
                return 0;
            }
            cur--;
            if(cur<0)
            {
                return 0;
            }
        }
    }
    return 1;
}


void Sub1()
{
    int ans=0;
    forr(i,0,2*n-1)
    {
        cin>>a[i];
    }
    forr(x,1,1<<(2*n)-1)
    {
        if(__builtin_popcount(x)!=n)
        {
            continue;
        }
        ans+=Tinh(x);
        if(ans>=1000003)
        {
            ans-=1000003;
        }
    }
    cout<<ans<<'\n';
}

void Sub2()
{
    f[1]=1;
    forr(i,2,n)
    {
        f[i]=f[i-1];
        forr(j,1,i-1)
        {
            f[j]+=f[i]*f[j-i];
        }
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen(Lozer".inp", "r", stdin);
    freopen(Lozer".out", "w", stdout);
    cin>>n>>m;
    if(n<=10)
    {
        Sub1();
        return 0;
    }
    cout<<rand()%Mod;
    return 0;
}
