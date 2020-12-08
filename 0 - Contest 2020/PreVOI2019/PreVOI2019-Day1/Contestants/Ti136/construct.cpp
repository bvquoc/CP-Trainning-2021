#define taskname "construct"
#include <bits/stdc++.h>
using namespace std;

#define LL long long
LL T,n,m;
vector<LL> a,it,sum,lazy;

void build(LL k, LL l, LL r)
{
    if (l==r)
    {
        it[k]=max(0LL,a[l]-a[l-1]);
        return;
    }
    LL m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    it[k]=it[k*2]+it[k*2+1];
}

LL down(LL k)
{
    LL val=lazy[k];
    lazy[k*2]+=val;
    sum[k*2]+=val;
    lazy[k*2+1]+=val;
    sum[k*2+1]+=val;
    lazy[k]=0;
}

void update0(LL k, LL l, LL r, LL u, LL v, LL val)
{
    if (u>r || v<l) return;
    if (u<=l && v>=r)
    {
        lazy[k]+=val;
        sum[k]+=val;
        return;
    }
    down(k);
    LL m=(l+r)/2;
    update0(k*2,l,m,u,v,val);
    update0(k*2+1,m+1,r,u,v,val);
}

void update1(LL k, LL l, LL r, LL pos)
{
    if (pos<l || pos>r) return;
    if (l==r)
    {
        a[l]+=sum[k];
        sum[k]=0;
        return;
    }
    down(k);
    LL m=(l+r)/2;
    update1(k*2,l,m,pos);
    update1(k*2+1,m+1,r,pos);
}

void update2(LL k, LL l, LL r, LL pos, LL val)
{
    if (pos<l || pos>r) return;
    if (l==r)
    {
        it[k]+=val;
        return;
    }
    down(k);
    LL m=(l+r)/2;
    update2(k*2,l,m,pos,val);
    update2(k*2+1,m+1,r,pos,val);
    it[k]=it[k*2]+it[k*2+1];
}

LL get(LL k, LL l, LL r, LL u, LL v)
{
    if (u>r || v<l) return 0;
    if (u<=l && v>=r) return it[k];
    down(k);
    LL m=(l+r)/2;
    return get(k*2,l,m,u,v)+get(k*2+1,m+1,r,u,v);
}

inline LL read()
{
    LL s = 0, t = 1; char c = getchar();
    while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
    while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
    return s * t;
}
inline void Write(LL x)
{
    if (x>9) Write(x/10);
    putchar(x%10+48);
}

int main()
{
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    T=read();
    while (T--)
    {
        n=read(); m=read();
        a.clear(); a.resize(n+100,0);
        it.clear(); it.resize(4*n+100,0);
        lazy.clear(); lazy.resize(4*n+100,0);
        sum.clear(); sum.resize(4*n+100,0);
        for(LL i=1; i<=n; i++)
            a[i]=read();
        build(1,1,n);
        for(LL i=1; i<=m; i++)
        {
            LL q,l,r,k;
            q=read();
            if (q==1)
            {
                l=read(); r=read(); k=read();
                LL val1=max(0LL,a[l]-a[l-1]), val2=max(0LL,a[r+1]-a[r]);
                update0(1,1,n,l,r,k);
                update1(1,1,n,l-1);
                update1(1,1,n,l);
                update1(1,1,n,r);
                update1(1,1,n,r+1);
                LL _val1=max(0LL,a[l]-a[l-1]), _val2=max(0LL,a[r+1]-a[r]);
                update2(1,1,n,l,_val1-val1);
                update2(1,1,n,r+1,_val2-val2);
            }
            else
            {
                l=read(); r=read();
                update1(1,1,n,l);
                Write(a[l]+get(1,1,n,l+1,r));
                putchar('\n');
            }
        }
    }
}
