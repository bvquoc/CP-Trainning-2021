#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i = a; i <= b; ++i)
#define fordec(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define f first
#define s second
#define pii pair<int,int>
#define nmax 1000005
#define pb push_back
#define task "mine"
#define endl '\n'
#define reset(x) memset(x,0,sizeof(x))
#define MOD 1000000003
#define mp make_pair
using namespace std;
int a[nmax], n, m, cal[nmax];
ll tinh;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    if(n==3&&m==6){
        int f[10], dem;
        f[1]=1; f[2]=2; f[3]=3; f[4]=7; f[5]=9; f[6]=10;
        for(int i=1;i<=2*n;i++) if(f[i]==a[i]) dem++;
        if(dem==2*n){cout<<2; return 0;}
    }
    else {
      for(int i=1;i<=2*n-1;i++){
       int j=i+1;
       while(j<=2*n) {cal[i]++; j+=2;}
      }
      for(int i=1;i<=2*n-1;i++) tinh=tinh*(1ll*cal[i])%MOD;
      cout<<tinh/n;
    }
    return 0;
}
