#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,m;
long long a[100050];
long long dp[100050];

void sub1()
{
     cin >> t;
     while(t--)
     {
          cin >> n >> m;
          for(int i=1;i<=n;i++) cin >> a[i];
          dp[n] = n+1;
          dp[n+1]= n+1;
          a[n+1] = a[n];
          for(int i=n-1;i>=1;i--)
          {
               if(a[i]<=a[i+1]) dp[i] = dp[i+1];
               else dp[i] = i;
          }
         // for(int i=1;i<=n;i++) cout << dp[i] << ' ' ;
        //  cout << endl;
          for(int i=1;i<=m;i++)
          {
               long long type,l,r,k;
               cin >> type ;
               if(type==1)
               {
                    cin >> l >> r >> k;
                    if(r==n) a[n+1] += k;
                    for(int j=r;j>=l;j--)
                    {
                         a[j] += k ;
                         if(j==n) continue;
                         if(a[j]>a[j+1]) dp[j] = j;
                         else dp[j] = dp[j+1];
                    }
               }
               else
               {
                   cin >>l >> r;
                 long long ans = a[l],vt = l;
                   while(vt<=r)
                   {
                        int R = min(r+1,dp[vt]);
                        ans+= (a[R] - a[vt]);
                        vt = R+1;
                   }
                   cout <<ans << endl;
               }
          }
     }
}
int main()
{
freopen("construct.inp","r",stdin);
     freopen("construct.out","w",stdout);
     ios_base::sync_with_stdio(false);cin.tie(nullptr);
     sub1();
}
