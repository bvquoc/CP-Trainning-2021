#include<bits/stdc++.h>
using namespace std;
long long tam,a,b,c,i,x[1000000];
long long j=0;
long long d=1;
long long dem=0;
int main()
{
	cin>>a>>b>>c;
    for (long long i=a;i<=b;i++)
    {
        if(b % i == 0)
        {
            j++;
            x[j]=i;
        }
    }
    while (a<=x[j] && d<=j )
    {
        tam=x[d]-a;
        if (tam % 2 != 0)
        {
            dem++;
            dem=dem+(tam-1)/2;
            a=x[d];
            d++;
        }
        else
        {
            dem=dem+tam/2;
            a=x[d];
            d++;
        }
    }
    tam=b-x[j];
    if (tam % 2 ==0)dem=dem+tam/2;
    else dem=dem+1+(tam-1)/2;
    cout<<dem;
}
