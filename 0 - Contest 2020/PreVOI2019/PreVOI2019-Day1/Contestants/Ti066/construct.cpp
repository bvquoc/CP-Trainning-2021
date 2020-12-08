#include <bits/stdc++.h>
//#define int long long
#define task "construct"
#define inpt freopen(task".inp","r",stdin);
#define outpt freopen(task".out","w",stdout);
#define for(a,b,c) for (int a=b;a<=c;a++)
#define maxn 100005

using namespace std;

const long long oo=1e9+7;
int T,n,m,a[maxn],tree[maxn*4],b[maxn],lazy[maxn*4];

void build(int k,int l,int r)
{
    if (l>r) return;
    if (l==r) {tree[k]=b[l];return;}
    int g=(l+r)/2;
    build(k*2,l,g);
    build(k*2+1,g+1,r);
    tree[k]=max(0,tree[2*k])+max(0,tree[2*k+1]);
}

int get ( int id , int l , int r , int L , int R  )
{
    if( r < L || l > R ) return 0;
    if( L <= l && r <= R ) return tree[id];
    int mid=(l+r)/2;
    return max(get( 2 * id , l , mid , L , R ),0)+max(0,get( 2 * id + 1 , mid + 1 , r , L , R ));
}

void nhap()
{
	ios_base::sync_with_stdio(0);cin.tie();cout.tie();
	inpt;
	outpt;
	cin>>T;
}
void update(int id,int l, int r, int tg, int x)
{
    if (l>r) return;
    if (tg<l||tg>r) return;
    if (l==r&&l==tg) {tree[id]=b[l]+x;b[l]=b[l]+x;return;}
    int g=(l+r)/2;
    update(id*2,l,g,tg,x);
    update(id*2+1,g+1,r,tg,x);
    tree[id]=max(0,tree[2*id])+max(0,tree[2*id+1]);
}
void uplazy(int id, int x,int y,int l,int r,int val)
{
    if (l>r) return;
    if (y<l||x>r) return;
    if (l<=x&&y<=r) {lazy[id]+=val;return;}
    int g=(l+r)/2;
    uplazy(id*2,x,y,l,g,val);
    uplazy(id*2+1,x,y,g+1,r,val);
}
int getlazy(int id,int l,int r,int tg)
{
    if (l>r) return 0;
    if (tg<l||tg>r) return 0;
    if (l==r&&l==tg) {return lazy[id];}
    int g=(l+r)/2;
    if (tg<=g) return lazy[id]+getlazy(id*2,l,g,tg);
    if (tg>g) return lazy[id]+getlazy(id*2+1,g+1,r,tg);
}
void xuly()
{
    cin>>n>>m;
    for(i,1,n) cin>>a[i];
    for(i,1,n) b[i]=a[i]-a[i-1];
    build(1,1,n);
    for (i,1,m)
    {
        int x,l,r;
        cin>>x;
        if (x==2)
        {
            cin>>l>>r;
            int kq=get(1,1,n,l,r)-b[l]+max(a[l-1]+getlazy(1,1,n,l-1)+b[l],0);
            cout<<kq<<endl;
        }
        else
        {
            int k;
            cin>>l>>r>>k;
            update(1,1,n,l,k);
            update(1,1,n,r+1,-k);
            uplazy(1,l,r,1,n,k);
        }
    }

}
int main()
{
    nhap();
    for (i,1,T) xuly();
    return 0;
}
