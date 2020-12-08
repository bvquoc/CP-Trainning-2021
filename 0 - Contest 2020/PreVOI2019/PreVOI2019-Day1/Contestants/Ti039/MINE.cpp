#include <bits/stdc++.h>
using namespace std;
#define tag "MINE"
#define maxn 200007
#define oo 1000000007LL
#define mid ((l+r)>>1)
#define meset(a,x) memset(a,x,sizeof(a))
#define loop(x) for(int LoOpEr=1;LoOpEr<=x;LoOpEr++)
#define debug(x) cerr<<#x<<" = "<<x<<"\n"
#define runtime(stime) ((clock() - stime) / CLOCKS_PER_SEC * 1000)
#define checkfile(FiLeNaMe) { if(fopen(FiLeNaMe".inp","r")) freopen(FiLeNaMe".inp","r",stdin),freopen(FiLeNaMe".out","w",stdout); }
//// my data:
#define somod 1000003LL
long long fct[maxn<<1],inv[maxn<<1],ivf[maxn<<1];

void add(int &x,const int &y){
    x+=y;
    if(x<0) x+=somod;
    if(x>=somod) x-=somod;
}

void bornfact()
{
    fct[0] = ivf[0] = 1;
    fct[1] = ivf[1] = inv[1] = 1;

    for (int i=2;i<(maxn<<1); i++)
    {
        fct[i] = fct[i-1]*i%somod;
        inv[i] = somod - somod/i*inv[somod%i] % somod;
        ivf[i] = ivf[i-1]*inv[i] % somod;
    }
}

int C(const int &n,const int &k)
{
    return (k<0 || k>n) ? 0 : fct[n]*ivf[k]%somod * ivf[n-k]%somod;
}

int catalan(const int &n){
    return (C(n<<1,n)-C(n<<1,n+1)+somod)%somod;
}
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int n,m;
int a[maxn<<1];
int f[4007][4007];
int g[4007][4007];
int lst[4007];
void toxic(){
    cout<<catalan(n>>1)<<"\n";
}

void dm(){
    for(int i=1;i<=n;i++){
        lst[i]=upper_bound(a+1,a+n+1,a[i]+m)-a-1;
        ///cerr<<i<<" "<<a[i]<<" "<<lst[i]<<"\n";
    }

    for(int i=1;i<=n;i++) g[i+1][i]=f[i+1][i]=1;

    for(int len=2;len<=n;len+=2)
        for(int i=1,j=len;j<=n;i++,j++)
        {
            f[i][j] = j<=lst[i] ? g[i+1][j-1] : 0;
            g[i][j] = 0;
            for (int med=i+1;med<=j;med+=2)
            {
                add(g[i][j],(1LL*f[i][med]*g[med+1][j])%somod);
            }
        }

    cout<<g[1][n]<<"\n";

}

void enter(){
    cin>>n>>m;

    n<<=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    bornfact();
}

void solve(){
    if(m>=*max_element(a+1,a+n+1)) toxic(); else dm();
}

int main()
{
    checkfile(tag);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    enter();
    solve();

    return 0;
}
