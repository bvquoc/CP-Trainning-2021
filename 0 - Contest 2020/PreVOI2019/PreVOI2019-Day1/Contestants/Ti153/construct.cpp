///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "construct"
#define maxn 100005
#define MOD 100000000000000007
#define pii pair<int, int>
#define endl "\n"
int T,n,m;
long long f[4*maxn],a[maxn];
struct ct
{
    long long val,L,R;
} t[4*maxn];
void down(int id)
{
    t[id*2].val+=f[id];
    t[id*2].L+=f[id];
    t[id*2].R+=f[id];
    t[id*2+1].val+=f[id];
    t[id*2+1].L+=f[id];
    t[id*2+1].R+=f[id];
    f[id*2]+=f[id];
    f[id*2+1]+=f[id];
    f[id]=0;
}
void init(int id,int l,int r)
{
    if(l==r)
    {
        t[id].val=t[id].L=t[id].R=a[l];
        return;
    }
    int mid=(l+r ) >> 1;
    init(id*2,l,mid);
    init(id*2+1,mid+1,r);
    t[id].val=t[id*2].val+t[id*2+1].val-min(t[id*2].R,t[id*2+1].L);
    t[id].L=t[id*2].L;
    t[id].R=t[id*2+1].R;
}
void update(int id,int l,int r,int u,int v,long long k)
{
    if(l > v || r < u)
        return;
    if(l >= u && r<= v)
    {
        t[id].val+=k;
        t[id].L+=k;
        t[id].R+=k;
        f[id]+=k;
        return;
    }
    down(id);
    int mid=(l+r) >> 1;
    update(id*2,l,mid,u,v,k);
    update(id*2+1,mid+1,r,u,v,k);
    t[id].val=t[id*2].val+t[id*2+1].val-min(t[id*2].R,t[id*2+1].L);
    t[id].L=t[id*2].L;
    t[id].R=t[id*2+1].R;
}
ct get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u)
        return {0ll,MOD,MOD};
    if(l >= u && r<=v)
        return t[id];
    down(id);
    int mid=(l+r) >> 1;
    ct trai=get(id*2,l,mid,u,v);
    ct phai=get(id*2+1,mid+1,r,u,v);
    return {trai.val+phai.val-((trai.val && phai.val) ? min(trai.R,phai.L) : 0),trai.L,phai.R};
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        for(int i=1; i<=n; ++i)
            cin >> a[i];
        init(1,1,n);
        for(int i=1; i<=m; ++i)
        {
            int type,l,r;
            long long k;
            cin >> type;
            if(type==1)
            {
                cin >> l >> r >> k;
                update(1,1,n,l,r,k);
            }
            else
            {
                cin >> l >> r;
                ct x=get(1,1,n,l,r);
                cout<<x.val<<endl;
            }
        }
        for(int i=1; i<=4*n; ++i)
            {
                t[i].val=f[i]=0;
                t[i].L=t[i].R=MOD;
            }
    }
}
