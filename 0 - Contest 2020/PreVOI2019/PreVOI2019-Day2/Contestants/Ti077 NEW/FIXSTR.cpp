#include <bits/stdc++.h>
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ROF(i,x,y) for (int i=x; i>=y; i--)
#define ll long long
#define fi first
#define se second
#define FORR(i,x) for(int i=0; i<x.size(); i++)
#define yct "FIXSTR"
using namespace std;
const int Nmax=2000010;

string s;
char a[Nmax];
int n;
struct node
{
    int d;
    int m;

} st[4*Nmax];

node combine(node x, node y)
{
    int lose=min(x.m,y.d);
    node tmp;
    tmp.m=x.m+y.m-lose;
    tmp.d=x.d+y.d-lose;
    return tmp;
}

void build(int id, int l, int r)
{
    if (l==r)
    {
        if (a[l]==')')
        {
            st[id].d=1;
            st[id].m=0;
        }
        else
        {
            st[id].d=0;
            st[id].m=1;
        }
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=combine(st[id*2],st[id*2+1]);
    return;
}

void update(int id, int l, int r, int i)
{
    if (i>r or i<l) return;
    if (l==r)
    {
        if (a[l]==')')
        {
            st[id].d--;
            st[id].m++;
            a[i]='(';
        }
        else
        {
            st[id].d++;
            st[id].m--;
            a[i]=')';
        }
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,i);
    update(id*2+1,mid+1,r,i);
    st[id]=combine(st[id*2],st[id*2+1]);
    return;
}

node get(int id, int l, int r, int u, int v)
{
    if (u>r or v<l)
    {
        node tmp;
        tmp.d=0;
        tmp.m=0;
        return tmp;
    }
    if (u<=l and r<=v) return st[id];
    int mid=(l+r)/2;
    return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

int q;
char aa[1010][1010];
void sub1()
{
    FOR(i,0,s.length()-1)
    {
        aa[0][i+1]=s[i];
    }
    FOR(t,1,q)
    {
        char ms;
        cin >>ms;
        if (ms=='U')
        {
            int k;
            cin >>k;
            FOR(i,1,n) aa[t][i]=aa[k-1][i];
            continue;
        }
        FOR(i,1,n) aa[t][i]=aa[t-1][i];

        if (ms=='C')
        {
            int val;
            cin >>val;
            if (aa[t][val]=='(') aa[t][val]=')';
            else aa[t][val]='(';
        }
        else
        {
            int u,v;
            cin >>u >>v;
            int d=0, m=0;
            FOR(i,u,v)
            {
                if (aa[t][i]=='(') m++;
                else
                {
                    d++;
                    if (m>0)
                    {
                        m--;
                        d--;
                    }
                }
            }
            cout <<d+m <<endl;
        }
    }
    exit(0);
}


void sub2()
{
    FOR(i,0,s.length()-1) a[i+1]=s[i];
    build(1,1,n);
    while(q--)
    {
        char ms;
        cin >>ms;
        if (ms=='C')
        {
            int k;
            cin >>k;
            update(1,1,n,k);
        }
        if (ms=='Q')
        {
            int u,v;
            cin >>u >>v;
            cout <<get(1,1,n,u,v).d+get(1,1,n,u,v).m <<endl;
        }
        if (ms=='U')
        {
            int val;
            cin >>val;
        }
    }
    exit(0);
}
int main()
{
    freopen(yct".INP","r",stdin);
    freopen(yct".OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >>s;
    cin >>q;
    n=s.length();
    if (n<=1000 and q<=1000) sub1();
    else sub2();
    return 0;
}
