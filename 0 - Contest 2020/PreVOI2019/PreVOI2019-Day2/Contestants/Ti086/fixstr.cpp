#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 1000005

using namespace std;
struct IT
{
    int x,n,val;
} st[4*maxn];
string s;
string a[maxn];
int m,n;
void make_st(int node,int l,int r)
{
    if(l==r)
    {
        if(s[l-1]=='(')
        {
            st[node].x=1;
            st[node].n=0;
            st[node].val=1;
        }
        else
        {
            st[node].n=1;
            st[node].x=0;
            st[node].val=1;
        }
        return ;
    }
    int m=(l+r)/2;
    make_st(2*node,l,m);
    make_st(2*node+1,m+1,r);
    if(st[2*node].x>=st[2*node+1].n)
    {
        st[node].x=st[2*node].x-st[2*node+1].n+st[2*node+1].x;
        st[node].n=st[2*node].n;
    }
    else
    {
        st[node].x=st[2*node+1].x;
        st[node].n=st[2*node].n+st[2*node+1].n-st[2*node].x;
    }
    st[node].val=st[node].x+st[node].n;
}
void update(int node,int l,int r,int vt)
{
    if(vt>r||vt<l)
        return ;
    if(l==r)
    {
        if(st[node].x==1)
        {
            st[node].x=0;
            st[node].n=1;
            st[node].val=1;
        }
        else
        {
            st[node].x=1;
            st[node].n=0;
            st[node].val=1;
        }
        return ;
    }
    int m=(l+r)/2;
    update(2*node,l,m,vt);
    update(2*node+1,m+1,r,vt);
    if(st[2*node].x>=st[2*node+1].n)
    {
        st[node].x=st[2*node].x-st[2*node+1].n+st[2*node+1].x;
        st[node].n=st[2*node].n;
    }
    else
    {
        st[node].x=st[2*node+1].x;
        st[node].n=st[2*node].n+st[2*node+1].n-st[2*node].x;
    }
    st[node].val=st[node].x+st[node].n;
}
pii get(int node,int l,int r,int u,int v)
{
    if(u>r||v<l)
        return make_pair(0,0);
    if(u<=l&&r<=v)
        return mp(st[node].x,st[node].n);
    int m=(l+r)/2;
    pii a=get(2*node,l,m,u,v);
    pii b=get(2*node+1,m+1,r,u,v);
    if(a.x>=b.y)
        return mp(a.x-b.y+b.x,a.y);
    return mp(b.x,a.y+b.y-a.x);
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    cin>>s;
    cin>>m;
    n=s.size();
    make_st(1,1,n);
    for(int i=1; i<=m; i++)
    {
        a[i]=s;
        char x;
        cin>>x;
        if(x=='C')
        {
            int v;
            cin>>v;
            if(s[v-1]=='(')
                s[v-1]=')';
            else s[v-1]='(';
            update(1,1,n,v);
        }
        else if(x=='Q')
        {
            int u,v;
            cin>>u>>v;
            pii va =get(1,1,n,u,v);
            cout<<va.x+va.y<<'\n';
        }
        else
        {
            int t;
            cin>>t;
            s=a[t];
            make_st(1,1,n);
        }
        //cout<<s<<'\n';
    }
}
