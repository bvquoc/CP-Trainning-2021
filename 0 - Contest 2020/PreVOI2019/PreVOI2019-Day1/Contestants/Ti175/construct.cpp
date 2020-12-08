#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define pb push_back
#define maxn 100005
#define ll long long
#define Ntu "construct"
#define st first
#define nd second
#define int long long

using namespace std;

int n,m;
int a[maxn];
int t[maxn*4], t2[maxn*4];
int f[maxn];


void cn(int i,int w)
{
    for(;i<=n;i+=i&-i) f[i]+=w;
}

int gt(int i)
{
    int s=0;
    for(;i>0;i-=i&-i) s+=f[i];
    return s;
}

void build(int u,int l,int r)
{
    if (l==r) {t[u]=max(1ll*0,a[l]-a[l-1]);return;}
    int mid=(l+r)/2;
    build(u*2,l,mid);build(u*2+1,mid+1,r);
    t[u]=t[u*2]+t[u*2+1];
}

void ud(int u,int l,int r,int vt)
{
    if (l>vt || r<vt) return;
    if (l==r)
    {
        t[u]=max(1ll*0,(a[l]+gt(l)-gt(l-1))-(a[l-1]+gt(l-1)-gt(l-2)));
        return;
    }
    int mid=(l+r)/2;
    ud(u*2,l,mid,vt);ud(u*2+1,mid+1,r,vt);
    t[u]=t[u*2]+t[u*2+1];
}

int get(int u,int l,int r,int d,int c)
{
    if (l>c || r<d) return 0;
    if (l>=d && r<=c) return t[u];
    int mid=(l+r)/2;
    return get(u*2,l,mid,d,c)+get(u*2+1,mid+1,r,d,c);
}

main()
{
    ios_base::sync_with_stdio(0);
    freopen (Ntu".inp","r",stdin);
    freopen (Ntu".out","w",stdout);
    cin.tie(NULL);cout.tie(NULL);
    int tes;
    cin >> tes;
    int l,r,k,id;
    while (tes--)
    {
        cin >> n >> m;
        fto(i,1,n) f[i]=0;
        fto(i,1,n) cin >> a[i];
        build(1,1,n);
        while (m--)
        {
            cin >> id;
            if (id==1)
            {
                cin >> l >> r >> k;
                cn(l,k);cn(r+1,-k);
                ud(1,1,n,l);ud(1,1,n,r+1);
            }
            else
            {
                cin >> l >> r;
                cout << a[l]+gt(l)-gt(l-1)+get(1,1,n,l+1,r) << '\n';
            }
        }
    }
    return 0;
}
