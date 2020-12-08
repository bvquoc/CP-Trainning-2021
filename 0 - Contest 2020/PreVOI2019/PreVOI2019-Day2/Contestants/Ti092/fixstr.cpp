#include <bits/stdc++.h>

using namespace std;
struct data
{
    int mo,dong;
};
data it[8000001];
string s,xau[1000001];
int n;
data md(int p,int q)
{
    data ans;
    ans.mo=p;
    ans.dong=q;
    return ans;
}
void tc(int k,int l,int r)
{
    if (l==r)
    {
        if (s[l]==')')
        {
            it[k].dong=1;
            it[k].mo=0;
        }
        else
        {
            it[k].mo=1;
            it[k].dong=0;
        }
        return;
    }
    int mid=(l+r)/2;
    tc(k*2,l,mid);
    tc(k*2+1,mid+1,r);
    int m1,m2,d1,d2;
    m1=it[k*2].mo;
    m2=it[k*2+1].mo;
    d1=it[k*2].dong;
    d2=it[k*2+1].dong;
    int z=min(m1,d2);
    m1-=z;d2-=z;
    it[k].mo=m1+m2;
    it[k].dong=d1+d2;
}
void up(int k,int l,int r,int pos)
{
    if (pos<l || pos>r) return;
    if (l==r)
    {
        if (s[pos]==')')
        {
            it[k].dong=1;
            it[k].mo=0;
        }
        else
        {
            it[k].mo=1;
            it[k].dong=0;
        }
        return;
    }
    int mid=(l+r)/2;
    up(k*2,l,mid,pos);
    up(k*2+1,mid+1,r,pos);
    int m1,m2,d1,d2;
    m1=it[k*2].mo;
    m2=it[k*2+1].mo;
    d1=it[k*2].dong;
    d2=it[k*2+1].dong;
    int z=min(m1,d2);
    m1-=z;d2-=z;
    it[k].mo=m1+m2;
    it[k].dong=d1+d2;
}
data tv(int k,int l,int r,int u,int v)
{
    if (r<u || l>v) return md(0,0);
    if (u<=l && v>=r)
    {
        return it[k];
    }
    int mid=(l+r)/2;
    data c1=tv(k*2,l,mid,u,v);
    data c2=tv(k*2+1,mid+1,r,u,v);
    int m1,m2,d1,d2;
    data kq;
    m1=c1.mo;
    m2=c2.mo;
    d1=c1.dong;
    d2=c2.dong;
    int z=min(m1,d2);
    m1-=z;d2-=z;
    kq.mo=m1+m2;
    kq.dong=d1+d2;
    return kq;
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>s;
    s=' '+s;
    tc(1,1,s.length());
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        xau[i]=s;
        char tt;cin>>tt;
        if (tt=='C')
        {
            int vt;cin>>vt;
            if (s[vt]=='(') s[vt]=')';else s[vt]='(';
            up(1,1,s.length(),vt);
        }
        else if (tt=='Q')
        {
            int u,v;
            cin>>u>>v;
            data truyvan=tv(1,1,s.length(),u,v);
            cout<<truyvan.mo+truyvan.dong<<"\n";
        }
        else
        {
            int vt;
            cin>>vt;
            s=xau[vt];
            tc(1,1,s.length());
        }
    }
}
