#include<bits/stdc++.h>
using namespace std;
const int oo = 1e9+7;
int q;
long long x,t;
int dp[100050];
bool check[500005];
int data[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
vector <int> a[700050];
void sub1(long long X,long long T)
{
     check[X] = true;
     fill(dp,dp+2+T,oo);
     for(int i=1;i<=T;i++)
     {
          if(check[i])
          {
               dp[i] = 1;
               continue;
          }
          for(int j=0;j<=i;j++)
          {
               dp[i] = min(dp[i],dp[j]+dp[i-j]);
          }
     }
     cout << dp[T] << endl;
     check[X] = false;
}
void sub2(int X,int T)
{
      queue <int> q;
      vector <int> d(T+50001);
      q.push(0);
      d[0] = 0;
      while(q.size())
      {
           int tmp = q.front();q.pop();
           if(tmp==T) break;
           for(auto x : a[tmp])
               if(x<=T)
           {
                if(d[x]==0)
                {
                     d[x] = d[tmp] + 1;
                     q.push(x);
                }
           }
           if(d[tmp+X]==0)
               {
                     d[tmp+X] = d[tmp] + 1;
                     q.push(tmp+X);
               }

      }
      cout << d[T] << endl;


}
int main()
{
     freopen("oddcoin.inp","r",stdin);
     freopen("oddcoin.out","w",stdout);
     ios_base::sync_with_stdio(false);cin.tie(nullptr);
     for(int i=0;i<15;i++)
     {
          check[data[i]] = true;
       //   cout << data[i] << endl;
          for(int j=0;j<=100001;j++)
          {
              a[j].push_back(j+data[i]);
          }
     }
   //  return 0;
     cin >> q;
     while(q--)
     {

          cin >> x >> t;

           sub2(x,t);
     }
}
