#include<bits/stdc++.h>
using namespace std;
long long a,b,c,s,Minh,Sang;
int main()
{
    //freopen("input.inp","r",stdin);
   // freopen("output.out","w",stdout);
    cin >> a >> b >> c; s=c;
    c = (a / c) * c + c * (a % c != 0);
    while (a<b)
    {
        Sang=min(b,c-1);
        Minh += (Sang - a) / 2 + (Sang - a) % 2;
        c += s;
        a = Sang;
    }
    cout<<Minh;
}