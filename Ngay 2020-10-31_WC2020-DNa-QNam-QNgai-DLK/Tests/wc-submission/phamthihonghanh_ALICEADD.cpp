#include<bits/stdc++.h>
using namespace std;
string cong(string n,string m)
{
    string h,kq;
    long long i,t,borrow,a[300],sn=n.size(),sm=m.size();
    h="";
  for(i=1;i<=abs(sn-sm);i++)
    {
        h=h+'0';
    }
    borrow=0;
    if(sn>sm)m=h+m;else n=h+n;
    for(i=max(sn,sm)-1;i>=0;i--)
    {
        t=n[i]-48+m[i]-48+borrow;
        if(t>=10)borrow=1;else borrow=0;
        a[i]=t%10;
    }
    if(borrow==1)kq="1";
    for(i=0;i<max(sn,sm);i++)kq+=(a[i]+48);
    while(kq.size()>1&&kq[0]=='0')kq.erase(0,1);
    return kq;
}
string n,m;
int t;
int main()
{
cin>>t;
for(int i=1;i<=t;i++)
{
    cin>>n>>m;
    cout<<cong(n,m)<<endl;
}
}
