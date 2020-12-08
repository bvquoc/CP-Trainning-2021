#include <bits/stdc++.h>

using namespace std;
int x,y,z,t,kq,l,q,u,v,vt;
pair<int,int> st[4000005];
string s,S[1005];
char tt;
void down(int id)
{
    long long k=st[id].second;

    st[id*2].first+=k;

    st[id*2].second+=k;

    st[id*2+1].first+=k;

    st[id*2+1].second+=k;

    st[id].second=0;
}
void update(int id,int l,int r,int u,int v,int gt)
{
    if (l>r || l>v || r<u) return;
    if (l>=u && r<=v)
    {
        st[id].first+=gt;
        st[id].second+=gt;
        return;
    }
    int mid=(l+r)/2;down(id);
    update(id*2,l,mid,u,v,gt);
    update(id*2+1,mid+1,r,u,v,gt);
    st[id].first=min(st[id*2].first,st[id*2+1].first);
}
int get(int id,int l,int r,int u,int v)
{


    if (l>r || l>v || r<u) return 1e9;
    if (l>=u && r<=v) return st[id].first;
    int mid=(l+r)/2;down(id);
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    cin>>s;l=s.length();s='.'+s;
    cin>>q;
    if (l<=1000 && q<=1000)
    {
        S[0]=s;
        for (int tv=1;tv<=q;++tv)
        {
            cin>>tt;
            if (tt=='C')
            {
                cin>>vt;
                if (s[vt]=='(') s[vt]=')';else s[vt]='(';
            }
            if (tt=='Q')
            {
                t=0;
                x=0;
                cin>>u>>v;
                for (int i=u;i<=v;++i)
                {
                    if (s[i]=='(') t++;
                    else t--;
                    x=min(x,t);
                }
                cout<<-x+t-x<<'\n';
            }
            if (tt=='U')
            {
                cin>>vt;
                s=S[vt-1];
            }
            S[tv]=s;
        }
        return 0;
    }
    for (int i=1;i<=l;++i)
    {
        if (s[i]=='(') t++;
        else t--;
        update(1,1,l,i,i,t);
    }

    for (int tv=1;tv<=q;++tv)
    {
        cin>>tt;
        if (tt=='C')
        {
           cin>>vt;
           if (s[vt]=='(') {t=-2;s[vt]=')';}else {t=2;s[vt]='(';}
           update(1,1,l,vt,l,t);
        }
        if (tt=='Q')
        {
            cin>>u>>v;
            x=get(1,1,l,u,v);
            if (u==1) y=0;else y=get(1,1,l,u-1,u-1);
            z=get(1,1,l,v,v);

            x=x-y;t=z-y;
            if (x>=0) kq=t;
            else kq=-x+t-x;
            cout<<kq<<'\n';
        }
    }
    return 0;
}
