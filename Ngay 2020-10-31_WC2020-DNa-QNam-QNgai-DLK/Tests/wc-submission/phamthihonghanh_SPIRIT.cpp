#include<bits/stdc++.h>
using namespace std;
long long a,b,c,dem,d,minx,maxx;
int main()
{
    cin>>a>>b>>c;
    minx=(((a-1)/c)+1)*c;
    dem=(b/c)-((a-1)/c);
    maxx=(b/c)*c;
   if(dem==0)cout<<((b+1)-a)/2;
   else cout<<dem+((c-1)/2)*(dem-1)+(minx-a)/2+(b-maxx)/2;

}
