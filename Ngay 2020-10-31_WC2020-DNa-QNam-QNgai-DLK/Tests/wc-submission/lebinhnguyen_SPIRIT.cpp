#include <bits/stdc++.h>
using namespace std;
int a,b,c,dem=0,tinh,mm=0;
int main()
{
    cin>>a>>b>>c;
    int d=((a-1)/c+1)*c;
    for(int i=d;i<=b;i+=c)
        dem++,mm=max(mm,i);
        tinh=(c-1)/2;
    if(dem==0)
        cout<<(b+1-a)/2;
    else
        cout<<(d-a)/2+(b-mm)/2+dem+(dem-1)*tinh;


}
