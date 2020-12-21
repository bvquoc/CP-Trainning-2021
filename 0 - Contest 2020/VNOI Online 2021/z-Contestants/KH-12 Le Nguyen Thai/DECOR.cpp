#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum[500010];
string s;
typedef pair <long long,long long > ii;
ii a[500010];
void sub1()
{
      long long dem=0,ans=0,l=0;
      long long ansl=0,ansr=0;
      bool check=false;
      for(int i=0;i<s.length();i++)
      {
         if(s[i]=='1')
         {
            if(check==false) l=i+1,check=true;
         //cout<<l<<endl;
            dem++;
         }
         if(s[i]=='0')
         {
            if(dem>ans)
            {
               ans=dem;
               ansr=i;
               ansl=l;
            }
            dem=0;
            check=false;
         }
      }
      //ans=max(ans,dem);
      if(ans<dem)
      {
         ansr=n;
         ansl=l;
      }
      if(ans==0) cout<<"-1"<<endl;
      else cout<<ansl<<" "<<ansr<<endl;
}
void sub2()
{
   s=' '+s;
   for(int i=1;i<=n;i++)
   {
      if(s[i]=='0') sum[i]=sum[i-1]+1;
      else sum[i]=sum[i-1];
   }
   long long ans=0,ansl=0,ansr=0;
   for(int i=1;i<=n;i++)
   {
      long long vt=upper_bound(sum+i+1,sum+n+1,sum[i-1]+k)-sum;
      if(vt-i>ans)
      {
         ans=vt-i;
         ansl=i;
         ansr=vt-1;
      }
   }
   if(ans==0) cout<<"-1"<<endl;
   else cout<<ansl<<" "<<ansr<<endl;
}
int main()
{
   freopen("DECOR.inp","r",stdin);
   freopen("DECOR.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m>>k;
   cin>>s;

   if(m==0&&k==0)
   {
      sub1();
      return 0;
   }
   if(m==0&&k!=0)
   {
      sub2();
      return 0;
   }

   return 0;
}
