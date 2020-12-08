#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define lam_tron cout<<fixed <<setprecision(2);
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
/*----------------------------------------------*/
int doc() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
const int M=1e5+5;
const int mod=1e9+7;
const double esp=1e-1;
const long double pi=4*atan((long double)1);
/*----------------------------------------------*/
int t;
int n,m;
int a[M],b[M],c[M],d[M];
ll chiphi(int l,int r,int b[])
{
    if(l>r) return 0;
    if(l==r)
    {
        return b[l];
    }
    int mi=mod;
    for(int i=l;i<=r;i++) if(mi>b[i]) mi=b[i];
    int dem=0;
    for(int i=l;i<=r;i++)
    {
        if(b[i]==mi) c[++dem]=i;
        b[i]-=mi;
    }
    ll ans=mi;
    c[dem+1]=r+1;
    c[0]=l-1;
    for(int i=0;i<=dem;i++) ans+=chiphi(c[i]+1,c[i+1]-1,b);
    return ans;
}
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        while(m--)
        {
            int x,l,r;
            cin>>x>>l>>r;
            if(x==1)
            {
                int k;
                cin>>k;
                for(int i=l;i<=r;i++) a[i]+=k;
            }
            else
            {
                memset(b,0,sizeof b);
                for(int i=l;i<=r;i++) b[i]=a[i];
                cout<<chiphi(l,r,b)<<"\n";
            }
        }
    }
    return 0;
}
