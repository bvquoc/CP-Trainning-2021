#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define lam_tron cout<<fixed <<setprecision(2);
/*----------------------------------------------*/
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
/*----------------------------------------------*/
const int M=1e6+5;
const int mod=1e9+7;
/*----------------------------------------------*/
string s;
int m;
int a[M],sum[M];
struct mido{
   int  minn,tong,lazy=0;
   mido(int x=0,int y=0)
   {
       minn=x;tong=y;
   }
} f[4*M];
void build(int id,int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        f[id].tong=a[l];
        f[id].minn=sum[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    f[id].tong=f[id*2].tong+f[id*2+1].tong;
    f[id].minn=min(f[id*2].minn,f[id*2+1].minn);
}
void down(int id)
{
    int t=f[id].lazy;
    f[id*2].minn+=t;
    f[id*2].lazy+=t;
    f[id*2+1].minn+=t;
    f[id*2+1].lazy+=t;
    f[id].lazy=0;
}
void upd1(int id,int l,int r,int i,int val)
{
    if(l>r) return ;
    if(r<i || i<l) return ;
    if(l==r)
    {
        f[id].tong+=val;
        return ;
    }
    int mid=(l+r)/2;
    upd1(id*2,l,mid,i,val);
    upd1(id*2+1,mid+1,r,i,val);
    f[id].tong=f[id*2].tong+f[id*2+1].tong;
}
void upd2(int id,int l,int r,int u,int v,int val)
{
    if(l>r) return ;
    if(r<u || v<l) return ;
    if(u<=l && r<=v)
    {
        f[id].minn+=val;
        f[id].lazy+=val;
        return ;
    }
    int mid=(l+r)/2;
    down(id);
    upd2(id*2,l,mid,u,v,val);
    upd2(id*2+1,mid+1,r,u,v,val);
    f[id].minn=min(f[id*2].minn,f[id*2+1].minn);
}
mido get(int id,int l,int r,int u,int v)
{
    if(l>r) return mido(mod,0);
    if(r<u || v<l) return mido(mod,0);
    if(u<=l && r<=v)
    {
        return mido(f[id].minn,f[id].tong);
    }
    int mid=(l+r)/2;
    down(id);
    mido k1=get(id*2,l,mid,u,v);
    mido k2=get(id*2+1,mid+1,r,u,v);
    return mido(min(k1.minn,k2.minn),k1.tong+k2.tong);
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>s;
    cin>>m;
    int n=s.size();
    for(int i=1;i<=4*n;i++) f[i].minn=mod;
    s=" "+s;
    for(int i=1;i<=n;i++)
        if(s[i]=='(') a[i]=1;
        else a[i]=-1;
    sum[0]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    build(1,1,n);
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='C')
        {
            int k;
            cin>>k;
            if(a[k]==-1)
            {
                upd1(1,1,n,k,2);
                upd2(1,1,n,k,n,2);
                a[k]=1;
            }
            else
            {
                upd1(1,1,n,k,-2);
                upd2(1,1,n,k,n,-2);
                a[k]=-1;
            }
        }
        else
        if(c=='Q')
        {
            int l,r;
            cin>>l>>r;
            mido k1=get(1,1,n,1,l-1);
            mido k2=get(1,1,n,l,r);
            int val1=k2.minn-k1.tong;
            int val2=k2.tong;
            cout<<abs(val1)+val2-val1<<"\n";
        }
    }
    return 0;
}
