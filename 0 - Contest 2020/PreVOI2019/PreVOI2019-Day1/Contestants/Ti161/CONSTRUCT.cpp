#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
#define pii pair<int,int>
#define getbit(i,x) ((x>>i)&1)

const int maxn=1e3+5;
int test,n,m,a[maxn];
main()
{
   freopen("CONSTRUCT.inp","r",stdin);
   freopen("CONSTRUCT.out","w",stdout);
   ios_base::sync_with_stdio(false);
   cin>>test;
   while(test--)
   {
       cin>>n>>m;
       forinc(i,1,n) cin>>a[i];
       while(m--)
       {
           int x;
           cin>>x;
           if(x==1)
           {
               int L,R,x;
               cin>>L>>R>>x;
               forinc(i,L,R) a[i]+=x;
           }
           else
           {
               int kq=0;
               int L,R;
               cin>>L>>R;
               //if(L==2&&R==4) {forinc(i,L,R) cout<<a[i]<<" ";return 0;}
               forinc(i,L+1,R) kq+=max(0ll,a[i]-a[i-1]);
               cout<<kq+a[L]<<"\n";
           }
       }
   }
}
