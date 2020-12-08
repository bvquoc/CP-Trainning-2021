#include <bits/stdc++.h>
using namespace std;
int gia[] = { 0 , 1 , 3 , 5 , 10 , 30 , 50 , 100 , 300 , 500 , 1000 , 3000 , 5000 , 10000 , 30000 , 50000 , 0 };
typedef long long ll;
int t,x;
int F[100004][18];
int kq=0,nani;
priority_queue < int , vector < int > , less < int > >q;
void subtask1()
{
   gia[16] = x;
   for(int i=1;i<=t;i++) F[i][1]=i;
   for(int j=2;j<=16;j++)
   {
       for(int i=1;i<=t;i++)
       {
           if( gia[j] > i ) F[i][j] = F[i][j-1];
           else F[i][j] = min( F[i][j-1] , F[i-gia[j]][j]+1 );
       }
   }
   cout<<F[t][16]<<endl;
}
void subtask2()
{
  q.push(x);
  for(int i=1;i<=15;i++) q.push(gia[i]);
  kq=0;
  while( q.empty() == 0 )
  {
     nani = q.top();
     q.pop();
     if( t >= nani )
     {
         kq+= t/nani;
         t = t%nani;
     }
  }
  cout<<kq<<endl;
}
void nhap()
{
   cin>>x>>t;
}
int main()
{
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    int q;
    cin>>q;
    while( q-- )
    {
       nhap();
       if( x <= 1e5 && t <= 1e5 ) subtask1();
       else subtask2();
    }
}
