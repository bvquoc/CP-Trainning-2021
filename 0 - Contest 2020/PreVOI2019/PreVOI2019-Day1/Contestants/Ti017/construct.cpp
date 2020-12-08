#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+6;
const int oo=1e9+7;
template <typename T> re(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
int t,n,m;
int a[mn];
int it[5*mn],lef[5*mn],rig[5*mn],la[mn];
void built(int x,int l,int r)
{
    lef[x]=l;
    rig[x]=r;
    if(l==r)
    {
        la[l]=x;
        it[x]=a[l];
        return;
    }
    int mid=(l+r)/2;
    built(2*x,l,mid);
    built(2*x+1,mid+1,r);
    it[x]=min(it[2*x],it[2*x+1]);
}
int get(int x,int l,int r)
{
    if(l>r)return 0;
    if(lef[x]>r||rig[x]<l)return oo;
    if(lef[x]>=l&&rig[x]<=r)return it[x];
    return min(get(2*x,l,r),get(2*x+1,l,r));
}
void upd(int x,int val)
{
    x=la[x];
    it[x]=val;
    x/=2;
    while(x)
    {
        it[x]=min(it[2*x],it[2*x+1]);
        x/=2;
    }
}
int tinh(int l,int r,int ss)
{
    if(l>r)return 0;
    int tmp=max(ss,get(1,l,r));
    int x=tmp;
    tmp-=ss;
    int tr=l;
    for(int i=l;i<=r;i++)
    if(x==a[i])
    {
        tmp=tmp+tinh(tr,i-1,x);
        tr=i+1;
    }
    tmp=tmp+tinh(tr,r,x);
    return tmp;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    re(t);
    while(t--)
    {
        re(n);re(m);
        for(int i=1;i<=n;i++)re(a[i]);
        built(1,1,n);
        for(int i=1;i<=m;i++)
        {
            int tv;
            re(tv);
            if(tv==2)
            {
                int l,r;
                re(l);re(r);
                cout<<tinh(l,r,0)<<'\n';
            }
            else
            {
                int l,r,k;
                re(l);re(r);re(k);
                for(int j=l;j<=r;j++)
                {
                    a[j]+=k;
                    upd(j,a[j]);
                }
            }
        }
    }
    return 0;
}
