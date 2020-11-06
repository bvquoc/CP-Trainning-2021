#include <bits/stdc++.h>
using namespace std;
string a,b;
int f[25],t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        a='0'+a;
        b='0'+b;
        while(a.size()<b.size()) a='0'+a;
        while(b.size()<a.size()) b='0'+b;
         int cmp=0;
        for(int i=a.size()-1;i>=0;i--)
        {
            f[i]=(int) (a[i]-'0') +(int) (b[i]-'0') + cmp;
            //cout<<f[i]<<" "<<i<<endl;
            cmp=f[i]/10;
            f[i]=f[i]%10;
        }
        if(f[0]!=0) cout<<f[0];
        for(int i=1;i<a.size();i++)
            cout<<f[i];
        cout<<endl;
    }
}
