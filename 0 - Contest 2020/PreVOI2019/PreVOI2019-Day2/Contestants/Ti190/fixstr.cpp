// KHAz
#include <bits/stdc++.h>
#define maxn 1000005
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1000000007
#define Task "fixstr"
#define pii pair < int,int >
#define pil pair < int,pii >
using namespace std;
int n , m , d[1005] , T[4*maxn] , G[4*maxn] , t[maxn] , lz[4*maxn] , c[maxn];
string s;
string pr[maxn];
void up(int x, int val)
{
    for(;x<=n;x+=x&-x) t[x]+=val;
}
int ge(int x)
{
    int ss=0;
    for(;x;x-=x&-x) ss+=t[x];
    return ss;
}
void sub1()
{
    pr[0]=s;
    for(int i=1;i<=m;i++)
    {
        char ty ; int u;
        cin>>ty>>u;
        if(ty=='U')
        {
          //  if(u<i) s=pr[u];
            s=pr[u-1];
            pr[i]=s;
        }
        if(ty=='C')
        {
            if(s[u]=='(') s[u]=')';
            else s[u]='(';
            pr[i]=s;
        }
        //if(i==5) cout << s;
        if(ty=='Q')
        {
            pr[i]=s;
            int v;cin>>v;
            int z=0,dem1=0, ma=1e6 , res=0;
            for(int j=u;j<=v;j++)
            {
                //if(i==7) cout << s[j];
                if(s[j]=='(') z++;
                else z--;
                d[j]=z;
                ma=min(ma , z);
            //  if(i==4)  cout << z <<' ';
            }
            if(ma < 0) res-=ma, z-=ma;
            if(z>0) res+=z;
           cout << res << '\n';
        }
         // cout << i<<' '<<s << endl;
    }
}
void init(int id,int l, int r)
{
    if(l==r)
    {
       // T[id]=s[l];
        T[id]=c[l];
        if(s[l]=='(') G[id]=1;
        else G[id]=-1;
        return ;
    }
    int mid=(l+r)/2;
    init(2*id,l,mid), init(2*id+1,mid+1,r);
  //  t[id]=t[2*id+1]+t[2*id];
    T[id]=min(T[2*id],T[2*id+1]);
    G[id]=G[2*id]+G[2*id+1];
}
void ud(int id , int l , int r , int u ,int v,int val)
{
    if(lz[id])
    {
        T[id]+=lz[id];
       // G[id]+=lz[id]*(r-l+1);
        if(l!=r) lz[2*id]+=lz[id], lz[2*id+1]+=lz[id];
        lz[id]=0;
    }
    if(l>v||r<u) return ;
    if(l>=u&&r<=v)
    {
        T[id]+=val;
       // G[id]+=val*(r-l+1);
        if(l!=r) lz[2*id]+=val , lz[2*id+1]+=val;
        return ;
    }
    int mid=(l+r)>>1;
    ud(2*id,l,mid,u,v,val) , ud(2*id+1,mid+1,r,u,v,val);
    T[id]=min(T[2*id], T[2*id+1]);
    G[id]=G[2*id]+G[2*id+1];
}
void ud1(int id , int l ,int r , int u,int v, int val)
{
    if(l>v||r<u) return ;
    if(l>=u&&r<=v)
    {
        G[id]+=val;
        return ;
    }
    int mid=(l+r)>>1;
    ud1(2*id,l,mid,u,v,val) , ud1(2*id+1,mid+1,r,u,v,val);
    G[id]=G[2*id]+G[2*id+1];
}
int getmin(int id, int l, int r, int u, int v )
{
    if(lz[id])
    {
        T[id]+=lz[id];
        if(l!=r) lz[2*id]+=lz[id], lz[2*id+1]+=lz[id];
        lz[id]=0;
    }
    if(l>v||r<u) return 1e9;
    if(l>=u&&r<=v) return T[id];
    int mid=(l+r)>>1;
    int x=getmin(2*id,l,mid,u,v),y=getmin(2*id+1,mid+1,r,u,v);
    return min(x,y);
}
int getsum(int id, int l, int r, int u, int v )
{
    if(l>v||r<u) return 0;
    if(l>=u&&r<=v) return G[id];
    int mid=(l+r)>>1;
    int x=getsum(2*id,l,mid,u,v),y=getsum(2*id+1,mid+1,r,u,v);
    return x+y;
}
void sub2()
{

    for(int i=1;i<=n;i++) if(s[i]=='(') c[i]=c[i-1]+1;
    else c[i]=c[i-1]-1;
    init(1,1,n);
   // for(int i=1;i<=n;i++)cout << c[i]<<' ';
    for(int i=1;i<=m;i++)
    {
        char ty;int u ,v;
        cin>>ty>>u;
        if(ty=='C')
        {
            if(s[u]=='(') s[u]=')' , ud(1,1,n,u,n,-2) , ud1(1,1,n,u,u,-2);
            else s[u]='(',ud(1,1,n,u,n,2),ud1(1,1,n,u,u,2);

        }
        else
        {
            int res=0;
            cin>>v;
            int k=getmin(1,1,n,u,v);
            int k1=getsum(1,1,n,u,v);
            int z=getsum(1,1,n,1,u-1);
        //    cout << z;
          //  int z=ge(u-1);
            k-=z;
            if(k<0) res-=k;
            k1-=k;
            if(k1>0) res+=k1;
            cout << res << '\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>s;
    n=s.length();
    s=' '+s;
    cin>>m;
    if(n<=1000&&m<=1000) sub1();
    else sub2();
  //sub2();
    return 0;
}
