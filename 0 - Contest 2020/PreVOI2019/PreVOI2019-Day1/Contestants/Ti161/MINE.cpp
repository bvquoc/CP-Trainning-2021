#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
#define pii pair<int,int>
#define getbit(i,x) ((x>>i)&1)

const int maxn=5e5+5,mod=1000003;
int n,m;
int a[maxn],F[maxn];

main()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    forinc(i,1,2*n) cin>>a[i];
    if(a[2*n]-a[2*n-1]>m) return cout<<0,0;
    F[2*n]=0,F[2*n-1]=1;
    fordec(i,2*n-2,1)
    {
       if(i%2==0) continue;
       else
       {
           int pos=-1;
           if(a[i+1]-a[i]<=m)
           {
               if(i+2<=2*n&&F[i+2]!=0) F[i]+=F[i+2];
               else F[i]+=1;
           }
           for(int j=i+3;j<=2*n;j+=2) if(a[j]-a[i]<=m)
           {
               pos=j;
               F[i]++;
           }
//           if(pos!=-1) F[i]+=F[pos+1];
       }
    }
    //cout<<F[3]<<" ";
    cout<<F[1];
}
