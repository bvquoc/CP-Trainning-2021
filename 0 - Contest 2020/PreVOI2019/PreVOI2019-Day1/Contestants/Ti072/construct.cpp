#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6+7;
int T;
int m,n;
int a[MAXN];
int Left[MAXN],Right[MAXN];
long long val[4*MAXN],t_Left[4*MAXN],t_Right[4*MAXN],lazy[4*MAXN];
void Fix(int k,int l,int r)
{
    if(lazy[k]==0)
        return ;
    val[k]+=lazy[k];
    if(l!=r)
    {
        lazy[k*2+1]+=lazy[k];
        lazy[k*2]+=lazy[k];
    }
    lazy[k]=0;
}
void Build_val(int k,int l,int r)
{
    if(l==r)
    {
        val[k]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    Build_val(k*2,l,mid);
    Build_val(k*2+1,mid+1,r);
    val[k]=max(val[k*2],val[k*2+1]);
}
void Build_Left(int k,int l,int r)
{
    if(l==r)
    {
        t_Left[k]=Left[l];
        return ;
    }
    int mid=(l+r)>>1;
    Build_Left(k*2,l,mid);
    Build_Left(k*2+1,mid+1,r);
    t_Left[k]=t_Left[k*2]+t_Left[k*2+1];
}
void Build_Right(int k,int l,int r)
{
    if(l==r)
    {
        t_Right[k]=Right[l];
        return ;
    }
    int mid=(l+r)>>1;
    Build_Right(k*2,l,mid);
    Build_Right(k*2+1,mid+1,r);
    t_Right[k]=t_Right[k*2]+t_Right[k*2+1];
}
void Update_val(int k,int l,int r,int i,int j,int vau)
{
    if(l>r||r<i||l>j)
        return ;
    Fix(k,l,r);
    if(i<=l&&r<=j)
    {
        lazy[k]+=vau;
        Fix(k,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    Update_val(k*2,l,mid,i,j,vau);
    Update_val(k*2+1,mid+1,r,i,j,vau);
    val[k]=max(val[k*2],val[k*2+1]);
}
void Update_Left(int k,int l,int r,int pos,long long vau)
{
    if(l>r||r<pos||l>pos)
        return ;
    if(l==r&&r==pos)
    {
        t_Left[k]=vau;
        return ;
    }
    int mid=(l+r)>>1;
    Update_Left(k*2,l,mid,pos,vau);
    Update_Left(k*2+1,mid+1,r,pos,vau);
    t_Left[k]=t_Left[k*2+1]+t_Left[k*2];
}
void Update_Right(int k,int l,int r,int pos,long long vau)
{
    if(l>r||r<pos||l>pos)
        return ;
    if(l==r&&r==pos)
    {
        t_Right[k]=vau;
        return ;
    }
    int mid=(l+r)>>1;
    Update_Right(k*2,l,mid,pos,vau);
    Update_Right(k*2+1,mid+1,r,pos,vau);
    t_Right[k]=t_Right[k*2+1]+t_Right[k*2];
}
long long Get_val(int k,int l,int r,int pos)
{
    if(l>r||r<pos||l>pos)
        return 0;
    Fix(k,l,r);
    if(l==r&&r==pos)
        return val[k];
    int mid=(l+r)>>1;
    return max(Get_val(k*2,l,mid,pos),Get_val(k*2+1,mid+1,r,pos));
}
long long Get_sum_Left(int k,int l,int r,int i,int j)
{
    if(l>r||r<i||l>j)
        return 0;
    if(i<=l&&r<=j)
        return t_Left[k];
    int mid=(l+r)>>1;
    return (Get_sum_Left(k*2,l,mid,i,j)+Get_sum_Left(k*2+1,mid+1,r,i,j));
}
long long Get_sum_Right(int k,int l,int r,int i,int j)
{
    if(l>r||r<i||l>j)
        return 0;
    if(i<=l&&r<=j)
        return t_Right[k];
    int mid=(l+r)>>1;
    return (Get_sum_Right(k*2,l,mid,i,j)+Get_sum_Right(k*2+1,mid+1,r,i,j));
}
void Init()
{
    memset(t_Left,0,sizeof(t_Left));
    memset(t_Right,0,sizeof(t_Right));
    Build_val(1,1,n);
    for(int i=1; i<=n; i++)
        Left[i]=max(a[i]-a[i-1],0);
    for(int i=n; i>=1; --i)
        Right[i]=max(a[i]-a[i+1],0);
    Build_Left(1,1,n);
    Build_Right(1,1,n);
}
void Input()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
}
void Output()
{
    long long d1,d2,d3,d4;
    int l,r,k;
    while(m--)
    {
        int te;
        cin>>te;
        if(te==1)
        {
            cin>>l>>r>>k;
            Update_val(1,1,n,l,r,k);
            d1=Get_val(1,1,n,l);
            if(l==1)
                Update_Left(1,1,n,l,d1);
            else
            {
                d3=Get_val(1,1,n,l-1);
                Update_Left(1,1,n,l,max(d1-d3,0LL));
            }
            d2=Get_val(1,1,n,r);
            if(r<n)
            {
                d4=Get_val(1,1,n,r+1);
                Update_Left(1,1,n,r+1,max(d4-d2,0LL));
            }
            if(l>1)
            {
                d3=Get_val(1,1,n,l-1);
                Update_Right(1,1,n,l-1,max(d3-d1,0LL));
            }
            if(r==n)
                Update_Right(1,1,n,r,d2);
            else
            {
                d4=Get_val(1,1,n,r+1);
                Update_Right(1,1,n,r,max(d2-d4,0LL));
            }
        }
        else
        {
            cin>>l>>r;
            //cerr<<Get_sum_Left(1,1,n,l+1,r)<<
            cout<<min(Get_sum_Left(1,1,n,l+1,r)+Get_val(1,1,n,l),(Get_sum_Right(1,1,n,l,r-1)+Get_val(1,1,n,r)))<<'\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>T;
    while(T--)
    {
        Input();
        Init();
        Output();
    }
    return 0;
}
