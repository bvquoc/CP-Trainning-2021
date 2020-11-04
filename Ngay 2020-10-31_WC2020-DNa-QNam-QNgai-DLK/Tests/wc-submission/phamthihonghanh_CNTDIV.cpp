#include<bits/stdc++.h>
using namespace std;
long long cntdiv(long long x)
{
    long long ans=0,i;
 for( i=2;i<=x*x;i++)
     if((x*x)%i==0&&i<x&&x%i!=0)ans++;
 return ans;
}
long long n,i,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        x=x*(x+1)*(x+2);
        cout<<cntdiv(x)<<'\n';
    }
}
