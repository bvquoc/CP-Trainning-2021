#include<bits/stdc++.h>
using namespace std;
const long long N=200010,MOD=1e9+7;
long long n,a[N],b[N];
void sub1()
{
   long long ans=0;
   while(true)
   {
      bool check=true;
      for(int i=1;i<n;i++)
      {
         if(a[i]>a[i+1])
         {
            check=false;
            swap(a[i],a[i+1]);
            ans++;
         }
      }
      if(check) break;
   }
   cout<<ans%MOD<<endl;
}
int main()
{
   freopen("PERMEOW.inp","r",stdin);
   freopen("PERMEOW.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n;
   bool checksub2=true;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      if(a[i]!=i) checksub2=false;
   }
   for(int i=1;i<=n;i++)
   {
      cin>>b[i];
      if(b[i]!=a[n-i+1]) checksub2=false;
   }
   bool check=true;
   for(int i=1;i<=n;i++)
   {
      if(a[i]!=b[i]) check=false;
   }
   if(check)
   {
      sub1();
      return 0;
   }
   return 0;
}
