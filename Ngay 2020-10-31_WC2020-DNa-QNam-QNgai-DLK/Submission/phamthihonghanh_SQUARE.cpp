#include<bits/stdc++.h>
using namespace std;
bool scp(long long n)
{
    if(n==0)return true;
   long long  t=trunc(sqrt(n));
    if(t*t==n)return true;else return false;
}
long long n,i;
int main()
{
  cin>>n;
  i=0;
  while(1)
  {
      if(scp(i*i-n)){cout<<i;return 0;}
      i++;

  }
}
