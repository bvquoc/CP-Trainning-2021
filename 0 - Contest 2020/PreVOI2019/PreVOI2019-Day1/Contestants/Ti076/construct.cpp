#include<bits/stdc++.h>
#define fi first
#define se second
#define fr(i, x, y) for (int i=x; i<=y; i++)
#define ft(i, x, y) for (int i=y; i>=x; i--)
#define pb push_back
#define ll long long
#define pii pair <int,int>
#define pll pair <ll,ll>
using namespace std ;
int n, m, a[1000010], T, lazy[4000010];
struct building
{
    int l;
    int r;
    ll val;
};
building tree[4000010];
void inp ()
{
    scanf ("%d%d", &n, &m);
    fr (i, 1, n)
    {
        scanf ("%d", &a[i]);
    }
}
void sub1 ()
{
    fr (i, 1, m)
    {
        int num;
        scanf ("%d", &num);
        if (num==1)
        {
            int l, r, k;
            scanf ("%d%d%d", &l, &r, &k);
            fr (i, l, r)
            {
                a[i]+=k;
            }
        }
        else
        {
            int l, r;
            ll res=0;
            scanf ("%d%d", &l, &r);
            if (r>l)
            fr (i, l+1, r)
            {
                if (a[i]>a[i-1]) res+=(a[i]-a[i-1]);
            }
            res+=a[l];
            printf ("%lld\n", res);
        }
    }
}
void build (int s, int l, int r)
{
    if (l==r)
    {
        tree[s].l=a[l];
        tree[s].r=a[r];
        tree[s].val=0;
        return;
    }
    int mid=(l+r)/2;
    build (2*s, l, mid);
    build (2*s+1, mid+1, r);
    tree[s].val=tree[2*s].val+tree[2*s+1].val+max(tree[2*s+1].l-tree[2*s].r, 0);
    tree[s].l=tree[2*s].l;
    tree[s].r=tree[2*s+1].r;
}
void do_lazy (int s, int l, int r)
{
    if (lazy[s]!=0)
    {
        tree[s].r+=lazy[s];
        tree[s].l+=lazy[s];
        if (l!=r)
        {
            lazy[2*s]+=lazy[s];
            lazy[2*s+1]+=lazy[s];
        }
        lazy[s]=0;
    }
}
void update (int s, int l, int r, int u, int v, int w)
{
    do_lazy (s, l, r);
    if (u>r or v<l) return;
    if (u<=l and r<=v)
    {
        tree[s].l+=w;
        tree[s].r+=w;
        if (l!=r)
        {
            lazy[2*s]+=w;
            lazy[2*s+1]+=w;
        }
        return;
    }
    int mid=(l+r)/2;
    update (2*s, l, mid, u, v, w);
    update (2*s+1, mid+1, r, u, v, w);
    tree[s].val=tree[2*s].val+tree[2*s+1].val+max(tree[2*s+1].l-tree[2*s].r, 0);
    tree[s].l=tree[2*s].l;
    tree[s].r=tree[2*s+1].r;
}
building get (int s, int l, int r, int u, int v)
{
    do_lazy (s, l, r);
    building ret;
    ret.l=1e9;
    ret.r=1e9;
    ret.val=0;
    if (u>r or v<l) return ret;
    if (u<=l and r<=v) return tree[s];
    int mid=(l+r)/2;
    building get1=get(2*s, l, mid, u, v);
    building get2=get(2*s+1, mid+1, r, u, v);
    if (get1.r==1e9 or get2.l==1e9) ret.val=get1.val+get2.val;
    else ret.val=get1.val+get2.val+max(get2.l-get1.r, 0);
    if (get1.l!=1e9) ret.l=get1.l;
    else if (get2.l!=1e9) ret.l=get2.l;
    if (get2.r!=1e9) ret.r=get2.r;
    else if (get1.r!=1e9) ret.r=get1.r;
    return ret;
}
void sub2 ()
{
    build (1, 1, n);
    fr (i, 1, m)
    {
        int num;
        scanf ("%d", &num);
        if (num==1)
        {
            int l, r, k;
            scanf ("%d%d%d", &l, &r, &k);
            update (1, 1, n, l, r, k);
        }
        else
        {
            int l, r;
            ll res=0;
            scanf ("%d%d", &l, &r);
            res=get(1, 1, n, l, r).val;
            res+=get(1, 1, n, l, r).l;
            printf ("%lld\n", res);
        }
    }
}
int main ()
{
    freopen ("construct.inp", "r", stdin);
    freopen ("construct.out", "w", stdout);
    scanf ("%d", &T);
    while (T--)
    {
        inp ();
        if (n<=1000 and m<=1000) sub1();
        else sub2 ();
    }
    return 0;
}

