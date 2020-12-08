#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
const int maxn=1000010;

char a[maxn];
int n,q;
string b;
char tv[maxn];
int f1[maxn],f2[maxn];
char A[1500][1500];
int _s;

void _cal(int l,int r,int st)
{
    int kq=0;
    int sum=0;
    _for(i,l,r+1)
    {
        if(A[st][i]=='(') kq++;
        else kq--;
        if (kq<0)
        {
            ++sum;
            kq=0;
        }
    }
    kq=0;
    for(int i=r;i>=l;--i)
    {
        if (A[st][i]==')') ++kq;
        else --kq;
        if (kq<0)
        {
            ++sum;
            kq=0;
        }
    }
    cout<<sum<<"\n";
}
void solve1()
{
    _s=int(b.size());
    for(int i=0;i<int(b.size());++i)
        A[0][i]=b[i];
    _for(i,1,q+1)
    {
        _for(j,0,_s) A[i][j]=A[i-1][j];
        if (tv[i-1]=='C')
        {
            if (A[i-1][f1[i-1]-1]==')') A[i][f1[i-1]-1]='(';
            else A[i][f1[i-1]-1]=')';
        }
        else if (tv[i-1]=='U')
        {
            _for(j,0,_s) A[i][j]=A[f1[i-1]-1][j];
        }
        else
        {
            _cal(f1[i-1]-1,f2[i-1]-1,i);
        }
    }
}
struct node
{
    int c=0,o=0;
    node(){}
    node(int aa,int bb)
    {
        c=aa; o=bb;
    }
};
node seg[4*maxn];
void cal(int st)
{
    int O=seg[st*2].o;
    int C=seg[st*2+1].c;
    if (O>=C)
        seg[st]=node(seg[st*2].c, seg[st*2+1].o + O-C);
    else seg[st]=node(seg[st*2].c + C-O, seg[st*2+1].o);
}

void update(int l,int r,int st,int q)
{
    if (l==r) swap(seg[st].o,seg[st].c);
    else
    {
        int mid=(l+r)/2;
        if (mid>=q) update(l,mid,st*2,q);
        else update(mid+1,r,st*2+1,q);
        cal(st);
    }
}
void build(int l,int r,int st)
{
    if (l==r)
    {
        if (a[l]=='(') seg[st]=node(0,1);
        else seg[st]=node(1,0);
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,st*2);
        build(mid+1,r,st*2+1);
        cal(st);
    }
}
node _get(int l,int r,int u,int v,int st)
{
    if (u<=l && r<=v) return seg[st];
    else if (l>v || r<u) return node(0,0);
    else
    {
        int mid=(l+r)/2;
        node kq1=_get(l,mid,u,v,st*2);
        node kq2=_get(mid+1,r,u,v,st*2+1);
        if (kq1.o>=kq2.c)
            return node(kq1.c, kq2.o + kq1.o-kq2.c);
        else return node(kq1.c + kq2.c-kq1.o, kq2.o);
    }
}


void solve()
{
    n=int(b.size());
    for(int i=0;i<int(b.size());++i)
        a[i+1]=b[i];
    build(1,n,1);
    _for(i,0,q)
    {
        if (tv[i]=='C')
        {
            update(1,n,1,f1[i]);
        }
        else if (tv[i]=='Q')
        {
            node kq=_get(1,n,f1[i],f2[i],1);
            cout<<kq.c+kq.o<<"\n";
        }
    }
}



void choose()
{
    bool ch=true;
    cin>>b;
    cin>>q;
    _for(i,0,q)
    {
        cin>>tv[i];
        if (tv[i]=='C' || tv[i]=='U')
        {
            cin>>f1[i];
        }
        else cin>>f1[i]>>f2[i];
        if (tv[i]=='U')  ch=false;
    }
    if (ch==false) solve1();
    else solve();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    choose();
}
