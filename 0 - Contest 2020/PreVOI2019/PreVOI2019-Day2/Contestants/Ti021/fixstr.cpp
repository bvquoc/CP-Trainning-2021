#include<bits/stdc++.h>
#define ii pair<long,long>
#define x first
#define y second
using namespace std;
const long o=1e6+5;
string s;
long n,m;
char l[o]; long v[o],v1[o],v2[o];
ii info[4*o];
vector<string>p;
bool dd[o];
ii hn(ii a,ii b)
{
    ii c;
    c.x=a.x+b.x-min(a.y,b.x);
    c.y=a.y-min(a.y,b.x)+b.y;
    return c;
}
void update(long x,long l,long r,long vt)
{
    if(vt<l || vt>r)
        return;
    if(l==r)
    {
        if(s[vt]==')')
           info[x].x=1,info[x].y=0;
        else info[x].x=0,info[x].y=1;
        return;
    }
    long mid=(l+r)>>1;
    update(2*x,l,mid,vt);
    update(2*x+1,mid+1,r,vt);
    info[x]=hn(info[2*x],info[2*x+1]);
}
ii get(long x,long l,long r,long u,long v)
{
    if(v<l || u>r)
        return {0,0};
    if(u<=l && r<=v)
        return info[x];
    long mid=(l+r)>>1;
    ii g1=get(2*x,l,mid,u,v);
    ii g2=get(2*x+1,mid+1,r,u,v);
    return hn(g1,g2);
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>m;
    n=s.size()-1;
    for(long i=1;i<=m;i++)
    {
        cin>>l[i];
        if(l[i]=='C' || l[i]=='U')
        {
            cin>>v[i];
            v[i]--;
        }
        if(l[i]=='Q')
        {
            cin>>v1[i]>>v2[i];
            v1[i]--; v2[i]--;
        }
        if(l[i]=='U')
            dd[v[i]]=1;
    }
    p.resize(m);
    for(long i=1;i<=m;i++)
    {
        if(dd[i-1])
            p[i-1]=s;
        if(l[i]=='C')
        {
            if(s[v[i]]=='(')
                s[v[i]]=')';
            else s[v[i]]='(';
            update(1,0,n,v[i]);
        }
        if(l[i]=='Q')
        {
            ii g=get(1,0,n,v1[i],v2[i]);
            cout<<g.x+g.y<<'\n';
        }
        if(l[i]=='U')
        {
            s=p[v[i]];
            for(long i=0;i<=n;i++)
                update(1,0,n,i);
        }
    }
    return 0;
}
