#include<bits/stdc++.h>
using namespace std;
const long oo=2000000000;
long q,x[100],t[100],s[20];
vector<long>f;
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    s[1]=1; s[2]=3; s[3]=5;
    s[4]=10; s[5]=30; s[6]=50;
    s[7]=100; s[8]=300; s[9]=500;
    s[10]=1000; s[11]=3000; s[12]=5000;
    s[13]=10000; s[14]=30000; s[15]=50000;
    cin>>q;
    long ln=0;
    for(long i=1;i<=q;++i)
    {
        cin>>x[i]>>t[i];
        ln=max(ln,t[i]);
    }
    f.resize(ln+1); f[0]=0;
    for(long i=1;i<=ln;++i)
    {
        f[i]=oo;
        for(long j=1;j<=15;++j)
        if(i>=s[j])
           f[i]=min(f[i],f[i-s[j]]+1);
    }
    for(long i=1;i<=q;++i)
    {
        long sl=oo;
        for(long j=0;j<=t[i]/x[i];++j)
            sl=min(sl,j+f[t[i]-j*x[i]]);
        cout<<sl<<'\n';
    }
    return 0;
}
