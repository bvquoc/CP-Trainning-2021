#include<bits/stdc++.h>
using namespace std;
#define fr(i,x,y) for (int i=x;i<=y;i++)
#define _fr(i,x,y) for (int i=x;i<y;i++)
#define frb(i,x,y) for (int i=x;i>=y;i--)
#define _frb(i,x,y) for (int i=x;i>y;i--)
#define add push_back
#define ll long long
#define ad push
#define fi first
#define se second
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
}
string s;
int u[1000000],v[1000000],tree[4000000],a[1000000],dem,o,n,m,ck,dem1,dem2;
int res1,res2,res;
typedef pair<int,int> ii;
ii lt[1000000];
vector<ii> vcs[1000000];
vector<int>bo[1000000];
char x[100000];
void inp()
{
    cin>>s;
    fr(i,0,s.size()-1)
    {
        if(s[i]=='(')
        {
            a[i+1]=-1;
        }
        else
        {
            a[i+1]=1;
        }
    }
    n=s.size();
    cin>>m;
    fr(i,1,m)
    {
        cin>>x[i];
        if(x[i]=='C') cin>>u[i];
        if(x[i]=='Q') cin>>u[i]>>v[i];
        if(x[i]=='U') {cin>>u[i]; ck++;}
    }
}
void build(int s,int l,int r)
{
    if(l==r)
    {
        tree[s]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
    tree[s]=tree[2*s]+tree[2*s+1];
}
void upd(int s,int l,int r,int u,int v)
{
    if(u<l||r<u) return ;
    if(l==r)
    {
        tree[s]*=v;
        return ;
    }
    int mid=(l+r)/2;
    upd(2*s,l,mid,u,v);
    upd(2*s+1,mid+1,r,u,v);
    tree[s]=tree[2*s]+tree[2*s+1];
}
int get(int s,int l,int r,int u,int v)
{
    if(v<l||r<u) return 0;
    if(u<=l and r<=v) return tree[s];
    int mid=(l+r)/2;
    return get(2*s,l,mid,u,v)+get(2*s+1,mid+1,r,u,v);
}
void sub()
{
    build(1,1,n);
    fr(i,1,m)
    {
        if(x[i]=='C')
        {
            a[u[i]]*=-1;
            upd(1,1,n,u[i],-1);
        }
        else{
            res=res1=res2=dem1=dem2=0;
            while(a[u[i]]==1)
            {
                res1++;
                u[i]++;
            }
            while(a[v[i]]==-1)
            {
                res2++;
                v[i]--;
            }
            res=get(1,1,n,u[i],v[i]);
            cout<<abs(res)+res1+res2<<"\n";
        }
    }

}
void trau()
{

    fr(i,1,n)
    {
        bo[0].add(a[i]);
    }
    fr(i,1,m)
    {
        if(x[i]=='C')
        {
            a[u[i]]*=-1;
            fr(j,1,n)
            {
                bo[i].add(a[j]);
            }
        }
        if(x[i]=='Q')
        {
            res=res1=res2=dem1=dem2=0;
            fr(j,1,n)
            {
                bo[i].add(a[j]);
            }
            while(a[u[i]]==1)
            {
                res1++;
                u[i]++;
            }
            while(a[v[i]]==-1)
            {
                res2++;
                v[i]--;
            }
            fr(j,u[i],v[i])
            {
                if(a[j]==-1)
                {
                    dem1++;
                }
                else{dem2++;}
            }
            res=dem1-dem2;
            cout<<abs(res)+res1+res2<<"\n";
        }
        if(x[i]=='U')
        {
            fr(j,0,bo[u[i]-1].size()-1)
            {
                a[j+1]=bo[u[i]-1][j];
            }
            fr(j,1,n)
            {
                bo[i].add(a[j]);
            }
        }
    }
}
int main()
{
    io();
    inp();
    if(n<=1000 and m<=1000) trau();
    else{
        if(ck==0)
        {
            sub();
            return 0;
        }
    }
    return 0;
}
/**
((()))
8
C 1
Q 2 5
C 5
Q 1 6
C 4
Q 3 6
C 1
Q 1 5
**/
