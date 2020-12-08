#include <bits/stdc++.h>
#define x first
#define y second
#define fu(_i,_a,_b) for (int _i=_a; _i<=_b; _i++)
#define fd(_i,_a,_b) for (int _i=_a; _i>=_b; _i--)
#define task "construct"
#define pb push_back
#define ALL(vecS) vecS.begin(),vecS.end()

using namespace std;

const int N=1e5+5;

typedef long long ll;
typedef pair <int,int> ii;
typedef pair <ll,int> li;

const ll oo=1e18;

int T,n,m,a[N];

struct ITree
{
    ll lazy[N*4],val[N*4];//ans;
    int L[N*4],R[N*4],pos=0;

    void build(int id, int l ,int r)
    {
        L[id]=l; R[id]=r; val[id]=0; lazy[id]=0;
        if (l!=r)
        {
            int mid = (l+r) / 2;
            build(id*2,l,mid);
            build(id*2+1,mid+1,r);
            val[id]=min(val[id*2],val[id*2+1]);
        }
        else val[id]=a[l];
    }

    void dolazy(int id)
    {
        if (lazy[id]==0) return;

        val[id]+=lazy[id];
        if (L[id]!=R[id]) lazy[id*2]+=lazy[id],lazy[id*2+1]+=lazy[id];
        lazy[id]=0;
    }

    void upd(int id, int l,int r, ll k)
    {
        dolazy(id);
        if (L[id]>r || R[id]<l) return;
        if (l<=L[id] && R[id]<=r)
        {
            val[id]+=k;
            if (L[id]!=R[id]) lazy[id*2]+=k,lazy[id*2+1]+=k;
            return;
        }
        upd(id*2,l,r,k); upd(id*2+1,l,r,k);
        val[id]=min(val[id*2],val[id*2+1]);
    }

    void Find(int id, int l, int r, ll w)
    {
        dolazy(id);
        if (L[id]>r || R[id]<l || pos!=0) return;
        if (l<=L[id] && R[id]<=r)
        {
            if (L[id]==R[id])
                {
                    if (val[id]==w) {pos=L[id];}
                    return;
                }

            Find(id*2,l,r,w);
            Find(id*2+1,l,r,w);
            return;
        }
        Find(id*2,l,r,w); Find(id*2+1,l,r,w);
    }

    ll getmin(int id, int l,int r)
    {
        dolazy(id);
        if (L[id]>r || R[id]<l) return oo;
        if (l<=L[id] && R[id]<=r) return val[id];
        return min(getmin(id*2,l,r), getmin(id*2+1,l,r));
    }

    ll get(int l, int r, ll vn)
    {
        pos=0;
        if (l>r) return 0;
        ll Minidlr=getmin(1,l,r);
        if (l==r) return Minidlr-vn;
        Find(1,l,r,Minidlr);
        int minpos=pos;
        //ll ans=(Minidlr-vn);
        return (Minidlr-vn)+get(l,minpos-1,Minidlr)+get(minpos+1,r,Minidlr);
    }

    void Get(int l, int r)
    {
        pos=0; //ans=0;
        cout << get(l,r,0)  << '\n';
    }
} ST;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        fu(i,1,n) cin >> a[i];
        ST.build(1,1,n);
        int typ,l,r; ll w;
        /*ST.Get(1,5);
        ST.upd(1,3,4,2);
        ST.Get(2,4);
        ST.Get(1,5);*/
        fu(i,1,m)
        {
            cin >> typ >> l >> r;
            if (typ==1) { cin >> w; ST.upd(1,l,r,w);}
            else
                 ST.Get(l,r);
        }
    }
    return 0;
}
