#include <bits/stdc++.h>
using namespace std;
int q,n,op,i,kq[1000001];
char ch,chx,chy;
void sub1()
{
    n=0;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>ch;
            kq[++n]=ch-'a';
        }
        else
        {
            cin>>chx>>chy;
            int x=chx-'a',y=chy-'a';
            for(i=1;i<=n;i++)
                if(kq[i]==x) kq[i]=y;
        }
    }
    for(i=1;i<=n;i++) cout<<char(kq[i]+'a');
}
string s;
int sh[2000001],r[2000001],sl,a[2000001],x,y,c[2000001];
int root(int u)
{
    if(u==r[u]) return u;
    return r[u]=root(r[u]);
}
void sub2()
{
    n=0; sl=25;
    for(i=0;i<=sl;i++) { c[i]=i; r[i]=i; sh[i]=i; }
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cin>>ch; x=ch-'a';
            a[++n]=sh[x];
        }
        else
        {
            cin>>chx>>chy; x=sh[chx-'a']; y=sh[chy-'a'];
            r[x]=y;
            sl++; r[sl]=sl; sh[chx-'a']=sl; c[sl]=chx-'a';
        }
    }
    string s="";
    for(i=1;i<=n;i++)
    {
        x=root(a[i]);
        s+=char(c[x]+'a');
    }
    cout<<s;
}
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>q;
    if(q<=10000) sub1();
    else sub2();
}
