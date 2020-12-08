#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000003
#define pii pair <int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 400005

using namespace std;
ll n,m,a[maxn],s[maxn],res;
void solve(int id,int pos, int dem)
{
    if(id==n+1||pos==2*n+1)
    {
        res=(res+dem)%mod;
        return ;
    }
    if(a[pos+1]<=a[pos]+m)
        solve(id+1,pos+2,dem);
    for(int i=pos+3; i<=2*n; i=i+3)
        if(a[pos]+m>=a[i])
            solve(id+1,i+1,dem*s[i-pos-1]%mod);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=2*n; i++)
        cin>>a[i];
    if(m==1000000)
    {
        s[0]=1;
        s[2]=1;
        s[4]=2;
        for(int i=6; i<=2*n; i=i+2)
        {
            s[i]=(s[i]+s[i-2])%mod;
            for(int j=4; j<=i; j=j+2)
                s[i]=(s[i]+s[j-2]*s[i-j])%mod;
        }
        cout<<s[2*n];
    }
    else
    {
        s[0]=1;
        s[2]=1;
        s[4]=2;
        for(int i=6; i<=2*n; i=i+2)
        {
            s[i]=(s[i]+s[i-2])%mod;
            for(int j=4; j<=i; j=j+2)
                s[i]=(s[i]+s[j-2]*s[i-j])%mod;
        }
        solve(1,1,1);
        cout<<res;
    }

}
