#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int oo = 1e7;
int m;
string s;
char h[1000006];
int a[1000006];
int sum[1000005];
int und[1005][1005];
int n;
int st[4000005];
int lazy[4000005];


void inp(){
    scanf("%s",h);
    s = h;
    n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(') a[i+1] = 1;
        else a[i+1] = -1;
    }
    for (int i = 1; i <= n; i++)
    und[0][i] = a[i];
    scanf("%d",&m);
}


void sub1(){
    char c;
    int x,y;
    for (int z = 1; z <= m; z++)
    {
        scanf(" %c",&c);
        if (c=='C')
        {
            scanf("%d",&x);
            if (a[x] == -1) a[x] = 1;
            else a[x] = -1;
        }
        else
        if (c == 'Q')
        {
            int mm = oo;
            scanf("%d%d",&x,&y);
            sum[x-1] = 0;
            for (int i = x; i <= y; i++)
            {
                sum[i] = sum[i-1] + a[i];
                mm = min(mm,sum[i]);
            }
            if (mm >= 0) printf("%d\n",sum[y]);
            else
            {
                printf("%d\n",-mm + s[y] - mm);
            }
        }
        else
        {
            scanf("%d",&x);
            for (int i = 1; i <= n; i++)
            a[i] = und[x-1][i];
        }
        for (int i = 1; i <= n; i++)
        und[z][i] = a[i];
    }
}



void build(int id,int l,int r)
{
    if (l == r)
    {
        st[id] = sum[l];
        return;
    }
    int mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = min(st[id*2],st[id*2+1]);
}


void down(int id)
{
    if (lazy[id] == 0) return;
    st[id*2] += lazy[id];
    st[id*2+1] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
}


void update(int id,int l,int r,int u,int v,int val)
{
    if (v < l || r < u) return;
    if (u <= l && r <= v)
    {
        lazy[id] += val;
        st[id] += val;
        return;
    }
    down(id);
    int mid = (l+r)>>1;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = min(st[id*2],st[id*2+1]);
}


int gett(int id,int l,int r,int u,int v)
{
    if (r < u || v < l) return oo;
    if (u <= l && r <= v)
    {
        return st[id];
    }
    down(id);
    int mid = (l+r)>>1;
    return min(gett(id*2,l,mid,u,v),gett(id*2+1,mid+1,r,u,v));
}


void sub2()
{
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    sum[i] = sum[i-1] + a[i];
    build(1,1,n);

    for (int z = 1; z <= m; z++)
    {
        char c;
        int x,y;
        scanf(" %c",&c);
        if (c == 'C')
        {
            scanf("%d",&x);
            if (a[x] == -1)
            {
                a[x] = 1;
                update(1,1,n,x,n,2);
            }
            else
            {
                a[x] = -1;
                update(1,1,n,x,n,-2);
            }
        }
        else
        if (c == 'Q')
        {
            scanf("%d%d",&x,&y);
            int mm = gett(1,1,n,x,y);
            int base;
            if (x-1 == 0)
            {
                base = 0;
            }
            else base = gett(1,1,n,x-1,x-1);
            mm = mm - base;
            int ss = gett(1,1,n,y,y);
            ss -= base;
            if (mm >= 0) printf("%d\n",ss);
            else
            {
                printf("%d\n",ss - 2*mm);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    inp();
    if (m <= 1000)
    sub1();
    else
    sub2();
    return 0;
}
