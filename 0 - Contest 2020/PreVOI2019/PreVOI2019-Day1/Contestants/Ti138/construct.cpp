#include <bits/stdc++.h>
#define int long long
#define pli pair<int,int>
#define fi first
#define se second
using namespace std;
const int maxn=1e5+5;
int n,m,i,j,k;
typedef int arr[4*maxn];
arr leg,rig,lazy,leep;
pli it[4*maxn];
int a[maxn];
void build(int x,int l,int r)
{
    leg[x]=l,rig[x]=r;
    if(l==r) {it[x]={a[l],l};return;}
    int z=(l+r)/2;
    build(2*x,l,z);
    build(2*x+1,z+1,r);
    it[x]=min(it[2*x],it[2*x+1]);
}
void dolazy(int x)
{
    int val=lazy[x];
    lazy[2*x]+=val;
    it[2*x].fi+=val;
    lazy[2*x+1]+=val;
    it[2*x+1].fi+=val;
    lazy[x]=0;
}
void upd(int x,int l,int r,int val)
{
    dolazy(x);
    if(leg[x]>r || rig[x]<l) return;
    if(l<=leg[x] && rig[x]<=r)
    {
        lazy[x]+=val;
        it[x].fi+=val;
        dolazy(x);
        return;
    }

    upd(2*x,l,r,val);
    upd(2*x+1,l,r,val);
    it[x]=min(it[2*x],it[2*x+1]);
}
pli get(int x,int l,int r)
{
    dolazy(x);
    if(leg[x]>r || rig[x]<l) return it[0];
    if(l<=leg[x] && rig[x]<=r) return it[x];
    pli kq1=get(2*x,l,r);
    pli kq2=get(2*x+1,l,r);
    return min(kq1,kq2);
}
int calc(int l,int r,int s)
{
    if(l>r) return 0;
    pli z=get(1,l,r);
    if(l==r) return z.fi-s;
    int k=z.fi-s;
    return k+calc(l,z.se-1,z.fi)+calc(z.se+1,r,z.fi);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    int t;
    cin >> t;
    a[0]=1e15;
    it[0]={a[0],0};
    while(t--)
    {
        cin >> n >> m;
        for(int i=1;i<=n;i++) cin >> a[i];
        build(1,1,n);
        while(m--)
        {
            int c;
            cin >> c;
            if(c==1)
            {
                int l,r,k;
                cin >> l >> r >> k;
                upd(1,l,r,k);
            }
            else
            {
                int l,r;
                cin >> l >> r;
                cout << calc(l,r,0) << '\n';
            }
        }
        for(int i=1;i<=4*n;i++) lazy[i]=0;
    }
}
