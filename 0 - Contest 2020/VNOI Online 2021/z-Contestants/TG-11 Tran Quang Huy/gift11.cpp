#include <bits/stdc++.h>

using namespace std;
int n,a[1000000],t,BASE=998244353;
struct po
{
    int x,y;
}l[10000000];
int Tong(int a);
{
    int t=0,l=1;
    string s;
    while (a>0)
    {
        s=char(a%10+48)+s;
        a/=10;
    }
    for (int i=0;i<s.length();i++)
    {
        t+=l*(int(s[i])-48);
        l*=-1;
    }
    return t;
}
void Tinh2()
{
    int t=0;
    for (int i=1;i<=n;i++)
        t+=l[i].x;
    if (t%11==0)
    {
        int k=1;
        for (int i=1;i<=n;i++)
            k=(k*i)%BASE;
    }
}
void XuLy()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        l[i]=Tong(a[i]);
    }
    if (n<8) Tinh1();
    else Tinh2();
}
int main()
{
    freppen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++)
        XuLy();
    return 0;
}
