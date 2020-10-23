#include <bits/stdc++.h>
using namespace std;
long long t1,t2,n,k,h,tong,lay,lay1,l;string a;
const long long  nho=1000000007;
long long mu(long long m,long long n)
{
    long long an=1;
    while (n!=0)
    {
        if (n%2!=0) an=an*m%nho;
        n=n/2;m=m*m%nho;
    }
    return an;
}
int main()
{
    freopen("NGUHANH.inp","r",stdin);
    freopen("NGUHANH.out","w",stdout);
    cin>>a;
    cin>>k;
    tong=0;l=a.length();

    for (long i=0;i<=a.length()-1;i++)
    {
        if (a[i]=='0'||a[i]=='5')
        {

          tong=(tong+mu(2,i))%nho;
        }
    }
    t1=mu((mu(2,l)-1),nho-2);
    t2=(t1*(mu(2,k*l)-1))%nho;
    cout<<(tong*t2)%nho;
    return 0;
}
