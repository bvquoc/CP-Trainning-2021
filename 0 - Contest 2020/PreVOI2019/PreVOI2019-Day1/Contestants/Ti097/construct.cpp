#include <bits/stdc++.h>
using namespace std;
int t,m,n,l,r,k,form;
long long a[1000001];
long long h[4000001];
long long b[1000001];
long long tr[4000001];
long long x, y;
void build(int id , int l ,int r)
{
    if (l>r) return ;
    if (l==r)
    {
        tr[id] = b[l];
        return ;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    tr[id] = tr[id*2]+tr[id*2+1];
}
void down(int id)
{
    h[id*2] += h[id];
    h[id*2+1] += h[id];
    h[id]=0;
    return ;
}
long long get_h(int id,int l ,int r , int vt )
{
    if (l==r) return h[id];
    down(id);
    int m = (l+r)/2;
    if (vt<=m) return get_h(id*2,l,m,vt);
    return get_h(id*2+1,m+1,r,vt);
}
void update_cl(int id,int l ,int r, int u ,int v)
{
    if (u<l|| u>r) return ;
    if (l==r)
    {
        tr[id] = v;
        return ;
    }
    int m=(l+r)/2;
    update_cl(id*2,l,m,u,v);
    update_cl(id*2+1,m+1,r,u,v);
    tr[id] = tr[id*2]+tr[id*2+1];
}

long long get_cl(int id, int l ,int r , int u ,int v)
{
    if (v<l || r<u ) return 0;
    if (u<=l && r<=v) return tr[id];
    int m = (l+r)/2;
    return get_cl(id*2,l,m,u,v)+get_cl(id*2+1,m+1,r,u,v);
}
void update_h(int id, int l , int r , int u , int v, int k )
{
    if (v<l || r<u) return ;
    if (u<=l && r<=v )
    {
        h[id]=k;
        return ;
    }
    down(id);
    int m=(l+r)/2;
    update_h(id*2,l,m,u,v,k);
    update_h(id*2+1,m+1,r,u,v,k);

}
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        a[0] = 0;
        b[0] = 0;
        memset(h,0,sizeof(h));
        for (int i=1;i<=n;i++) b[i] = max( 0LL , a[i] - a[i-1] );
        build(1,0,n);
        for (int i=1;i<=m;i++)
        {
            cin>>form ;
            if ( form == 1 )
            {
                cin>>l>>r>>k;
                update_h(1,0,n,l,r,k);
               x = a[l] + get_h(1,0,n,l) ;
                y = x - ( a[l-1]+get_h(1,0,n,l-1) ) ;
                update_cl( 1 , 0 , n , l , max( 0ll , y ) );
                x = a[r+1] + get_h(1,0,n,r+1) ;
                y = x - ( a[r] + get_h(1,0,n,r) ) ;
                if (r+1<=n) update_cl( 1, 0 , n , r+1 , max( 0ll , y) );
            }
            if (form == 2 )
            {
                cin>>l>>r;
                x = get_cl(1,0,n,0,l);
                y = get_cl(1,0,n,0,r);
                long long z = a[l] + get_h(1,0,n,l);
                cout<<y-x+z<<"\n";
            }
        }
    }
    return 0;
}
