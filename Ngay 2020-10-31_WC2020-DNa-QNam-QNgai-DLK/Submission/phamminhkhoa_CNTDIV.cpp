#include<bits/stdc++.h>
using namespace std;
int a[1000003],x,q;
int era()
{
    for (int i=1;i<=1e6+3;i++)
    {
        for (int j=i;j<=1e6+3;j+=i)
        {
            a[j]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>q;
    era();
    for (int i=1;i<=q;i++)
    {
        cin>>x;
        if (x%2==0)
        {
            long long n=a[x]+a[x+1]+a[x+2]-5;
            cout<<((n+1)*n)/2<<"\n";
        }
        else
        {
            long long n=a[x]+a[x+1]+a[x+2]-4;
            cout<<((n+1)*n)/2<<"\n";
        }
    }
}
