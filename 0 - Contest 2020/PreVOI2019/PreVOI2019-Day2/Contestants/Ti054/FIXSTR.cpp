#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=1e6;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,nq,f[4*N+5],now[4*N+5],lz[4*N+5],t[N+5];
string s,Pre[1005];
void sol1()
{
    char type;
    int u,v,tmp,Min,res;
    for (int j=1;j<=nq;j++)
    {
        cin>>type;
        Pre[j]=s;
        if (type=='C')
        {
            cin>>u;
            if (s[u]=='(') s[u]=')'; else s[u]='(';
        } else if (type=='Q')
        {
            tmp=Min=res=0;
            cin>>u>>v;
            for (int i=u;i<=v;i++)
            {
                if (s[i]=='(') tmp++; else tmp--;
                Min=min(Min,tmp);
            }
            res=0;
            if (Min<0) {tmp+=-Min; res+=-Min;}
            if (tmp>0) res+=tmp;
            cout<<res<<'\n';
        } else
        {
            cin>>u;
            s=Pre[u];
        }
    }
    return;
}
void build(int id, int l, int r)
{
    if (l>r) return;
    if (l==r)
    {
        now[id]=t[l];
        f[id]=t[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    f[id]=min(f[id*2],f[id*2+1]);
    return;
}
void down(int id)
{
    if (lz[id]==0) return;
    int val=lz[id]; lz[id]=0;
    now[id*2]+=val; now[id*2+1]+=val;
    lz[id*2]+=val; lz[id*2+1]+=val;
    f[id*2]+=val; f[id*2+1]+=val;
    return;
}
void update(int id, int l, int r, int u, int v, int val)
{
    if (l>r || l>v || r<u) return;
    if (u<=l && r<=v)
    {
        now[id]+=val;
        f[id]+=val;
        lz[id]+=val;
        return;
    }
    down(id);
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    f[id]=min(f[id*2],f[id*2+1]);
    return;
}
int getmin(int id, int l, int r, int u, int v)
{
    if (l>r || u>v || l>v || r<u) return oo;
    if (u<=l && r<=v) return f[id];
    int mid=(l+r)/2;
    down(id);
    return min(getmin(id*2,l,mid,u,v),getmin(id*2+1,mid+1,r,u,v));
}
int getval(int id, int l, int r, int u)
{
    if (l>r || l>u || r<u) return 0;
    if (l==r) return now[id];
    int mid=(l+r)/2;
    down(id);
    return getval(id*2,l,mid,u)+getval(id*2+1,mid+1,r,u);
}
int main()
{
	freopen("FIXSTR.inp","r",stdin);
	freopen("FIXSTR.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin>>s;
    n=s.length(); s=" "+s;
    cin>>nq;
    if (n<=1000 && nq<=1000) {sol1(); return 0;}
    for (int i=1;i<=n;i++)
    {
        t[i]=t[i-1];
        if (s[i]=='(') t[i]++; else t[i]--;
    }
    build(1,1,n);
    char type;
    int u,v,Min,tmp1,tmp2,res;
    for (int i=1;i<=nq;i++)
    {
        cin>>type;
        if (type=='C')
        {
            cin>>u;
            if (s[u]=='(')
            {
                s[u]=')';
                update(1,1,n,u,n,-2);
            } else
            {
                s[u]='(';
                update(1,1,n,u,n,2);
            }
        } else if (type=='Q')
        {
            cin>>u>>v;
            res=0;
            Min=getmin(1,1,n,u,v);
            tmp1=getval(1,1,n,u-1);
            tmp2=getval(1,1,n,v);
            Min-=tmp1; tmp2-=tmp1;
            if (Min<0)
            {
                res+=-Min;
                tmp2+=-Min;
            }
            if (tmp2>0) res+=tmp2;
            cout<<res<<'\n';
        }
    }
	return 0;
}
