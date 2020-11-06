#include<bits/stdc++.h>
using namespace std;
long long d,c,a,b,c1,s,res,dem;
int main()
{
    cin>>a>>b>>c;
    d=c*(((a-1)/c)+1);
    res=(b/c)-((a-1)/c);
    c1=(b/c)*c;
    if (res==0) cout<<((b+1)-a)/2;
    else cout<<res+((c-1)/2)*(res-1)+(d-a)/2+(b-c1)/2;
}
