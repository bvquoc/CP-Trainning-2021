#include <bits/stdc++.h>
#define Killian "COOLMAC"
#define endl "\n"
#define pii pair <int,int>
#define long long long
#define bit(mask,u) (((mask)>>(u))&1)
#define bitcount(mask) __builtin_popcount((mask))
using namespace std;
mt19937_64 random_num(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MOD=1000000007;
const int base=26;
const int arsz=100005;

int n,m;
struct suit
{
    int l,r;
} a[100005];
int d[100005];
int mintmp=1e9;
struct IT
{
    int val,pos;
} st[400005];
int res;

IT Merge (const IT &A,const IT &B)
{
    if (A.val<B.val)
        return A;
    return B;
}
void make_st (int node,int l,int r)
{
    if (l==r)
    {
        st[node]= {d[l],l};
        return;
    }
    make_st(node*2,l,(l+r)/2);
    make_st(node*2+1,(l+r)/2+1,r);
    st[node]=Merge(st[node*2],st[node*2+1]);
}
IT get (int node,int l,int r,int u,int v)
{
    if (v<l || u>r || u>v)
        return {MOD,-1};
    if (u<=l && r<=v)
        return st[node];
    return Merge(get(node*2,l,(l+r)/2,u,v),get(node*2+1,(l+r)/2+1,r,u,v));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>m;
    for (int i=0; i<=100000; i++)
        d[i]=MOD;
    for (int i=1; i<=m; i++)
    {
        cin>>a[i].l>>a[i].r;
        if (d[a[i].r]==MOD || d[a[i].r]>a[i].l)
            d[a[i].r]=a[i].l;
    }
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int t;
        cin>>t;
        mintmp=min(mintmp,t);
    }
    if (d[100000]==MOD)
    {
        cout<<-1;
        return 0;
    }
    res=1;
    make_st(1,0,100000);
    int it=100000;
    while (d[it]>mintmp)
    {
        IT t=get(1,0,100000,d[it],it-1);
        if (t.val==MOD)
        {
            cout<<-1;
            return 0;
        }
        res++;
        it=t.pos;
    }
    cout<<res;
}
