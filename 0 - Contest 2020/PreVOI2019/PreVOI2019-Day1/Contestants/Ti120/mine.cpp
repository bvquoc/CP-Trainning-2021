#include <bits/stdc++.h>
#define hqm "mine"
#define maxn 200009
#define ll long long

using namespace std;
const int mod=1e6+3;
int Cin(){
    int x=0;
    char c=getchar();
    while(c<'0' || c>'9')c=getchar();
    while(c>='0' && c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int l[maxn],a[maxn*2];
int n,m;
int s[4009][2009];
void sub1234(){
    s[0][0]=1;
    for(int i=1; i<=n*2; ++i)
    {
        for(int j=0; j<min(n+2,i); ++j){
            s[i][j+1]=(s[i][j+1]+s[i-1][j])%mod;
            if(j>0)s[i][j-1]=(s[i][j-1]+s[i-1][j])%mod;
        }
    }
    l[0]=1;
    for(int i=1; i<=n*2; ++i)
    if(i%2==0){
        l[i/2]=0;
        int j=i-2;
        while(j>=0 && a[i]-a[j+1]<=m){
            j-=2;
        }
        j+=2;
        l[i/2]=(1ll*l[j/2]*s[i-j][0])%mod;
    }
    cout << l[n];
    exit(0);
}
/*int t[maxn];
void add(int x,int y){
    for(;x<=n+1; x+=x&-x)t[x]=(t[x]+y)%mod;
}

int get(int x){
    int res=0;
    for(;x;x-=x&-x)res=(res+t[x])%mod;
    return res;
}*/
int b[maxn],c[maxn];

ll mu(int a, int b){
    if(b==0) return 1;
    ll tg=mu(a,b/2);
    tg=(tg*tg)%mod;
    if(b%2==1)tg=(tg*a)%mod;
    return tg;
}

int s1[maxn];

void sub5(){
    s1[1]=1;
    for(int i=1; i<=n; ++i){
        b[i+1]=a[i*2-1];
        c[i+1]=a[i*2];
        s1[i+1]=(1ll*s1[i]*(4*i+2)*mu(i+2,mod-2))%mod;
        //cout << i+1 <<' '<< s1[i+1] <<endl;
    }
    l[1]=1;
    //add(1,1);
    for(int i=2; i<=n+1; ++i){
        int j=lower_bound(b+2,b+n+2,c[i]-m)-b-1;
        //l[i]=(get(i-1)-get(j-1))%mod;
        l[i]=1ll*l[j]*s1[i-j]%mod;
        //add(i,l[i]);
    }
    cout << (l[n+1]+mod)%mod;
    exit(0);
}

void sinhtest(int n){
    /// sinh test sieu to khong lo
    cout << n <<' '<< 1000000 <<endl;
    for(int i=1; i<=n*2; ++i) cout << 100000+i<< ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(hqm".inp","r", stdin);
    freopen(hqm".out","w", stdout);
    n=Cin();
    m=Cin();
    for(int i=1;i<=n*2; ++i){
        a[i]=Cin();
        if(i%2==0 && a[i]-a[i-1]>m){cout << 0; return 0;}
    }
    //sinhtest(2000);
    if(n<=2000)sub1234();
    sub5();
    /// accept
    return 0;
}
