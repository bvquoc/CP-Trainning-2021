#include <bits/stdc++.h>
using namespace std;
#define el '\n'

typedef unsigned long long ull;

typedef long long ll;

template<typename so>

void read(so &x)
{
    x = 0;
    int dem = 0;char c;
    for (c = getchar();'0'>c||c>'9';c=getchar())
    {
        dem++;if(dem==1000) return;
    }
    for (;'0'<=c&&c<='9';c=getchar())
    {
        x = (x<<3) + (x<<1) + c - '0';
    }
}

void rec(char &son)
{
    char c;int dem = 0;
    for (c = getchar();'A'>c||c>'Z';c=getchar())
    {
        dem++;if(dem==1000) return;
    }
    for (;'A'<=c&&c<='Z';c=getchar())
    {
        son = c;
        return;
    }
}

const int MaxN = 1e6+1e5;

const ll mod = 1e6+3;

template<typename so> void get_min(so &a,so b)
{
    if (a>b) a = b;
}

int n,m;

string s;

struct SG
{
    int mo;
    int dong;
};

SG st[MaxN*4];

int u;

int v;

void noi(int id)
{
    int gg = min(st[(id<<1)].mo,st[(id<<1)+1].dong);
    st[id].dong = st[(id<<1)].dong + st[(id<<1)+1].dong - gg;
    st[id].mo = st[(id<<1)].mo + st[(id<<1)+1].mo - gg;
}

void build(int id,int left,int right)
{
    //cout<<id<<el;
    if (left==right)
    {
        if (s[left]=='(')
        {
            st[id].mo=1;st[id].dong = 0;
        }
        else
        {
            st[id].dong=1;st[id].mo = 0;
        }
        return;
    }
    int mid = (left+right)>>1;
    build((id<<1),left,mid);
    build((id<<1)+1,mid+1,right);
    noi(id);
}

void update(int id,int left,int right)
{
    if (left>v||right<u) return;
    if (left==right)
    {
        st[id].dong = 1 - st[id].dong;
        st[id].mo = 1 - st[id].mo;
        return;
    }
    int mid = (left+right)>>1;
    update((id<<1),left,mid);
    update((id<<1)+1,mid+1,right);
    noi(id);
}

SG lay(SG A,SG B)
{
    int gg = min(A.mo,B.dong);
    return {A.mo+B.mo-gg,A.dong+B.dong-gg};
}

int ngdong,ngmo;

SG get(int id,int left,int right)
{
    if (left>v||right<u) return {0,0};
    if (u<=left&&right<=v)
    {
        return st[id];
    }
    int mid = (left+right)>>1;
    return lay(get((id<<1),left,mid),get((id<<1)+1,mid+1,right));
}

struct Query
{
    char type;
    int x;
    int y;
};

Query q[MaxN];

void sub1()
{
    build(1,0,n-1);
    for (int i=0;i<m;i++)
    {
        if (q[i].type=='C')
        {
            u = q[i].x,v = q[i].x;
            if (s[u]=='(')
                s[u] = ')';
            else s[u] = '(';
            update(1,0,n-1);
            //for (int j=1;j<n*4;j++)cout<<j<<" "<<st[j].mo<<" "<<st[j].dong<<el;
        }
        if (q[i].type=='Q')
        {
            u = q[i].x,v = q[i].y;
            SG ahihi = get(1,0,n-1);
            cout<<ahihi.dong+ahihi.mo<<el;
        }
    }
}

vector<string> s1;

void sub2()
{
    s1.resize(m);
    build(1,0,n-1);
    for (int i=0;i<m;i++)
    {
        s1[i] = s;
        if (q[i].type=='C')
        {
            u = q[i].x,v = q[i].x;
            if (s[u]=='(')
                s[u] = ')';
            else s[u] = '(';
            update(1,0,n-1);
        }
        if (q[i].type=='Q')
        {
            u = q[i].x,v = q[i].y;
            SG ahihi = get(1,0,n-1);
            cout<<ahihi.dong+ahihi.mo<<el;
        }
        if (q[i].type=='U')
        {
            s = s1[q[i].x];
            build(1,0,n-1);
        }
    }

}

void reads(string &akoko)
{
    char c;akoko.clear();
    for (c=getchar();c!='('&&c!=')';c=getchar());
    for (;c=='('||c==')';c=getchar())
    {
        akoko.push_back(c);
    }
}

void input()
{
    bool ktkt = false;
    //cin>>s;
    reads(s);
    n = s.size();
    //cin>>m;
    read(m);
    for (int i =0 ; i<m;i++)
    {
        //cin>>q[i].type>>q[i].x;
        rec(q[i].type);read(q[i].x);
        if (q[i].type=='U')
        {
            ktkt = true;
        }
        q[i].x--;
        if (q[i].type=='Q')
        {
            //cin>>q[i].y;
            read(q[i].y);
            q[i].y--;
        }
    }
    if (ktkt==false)
    {
        sub1();
        return;
    }
    else
    {
        sub2();
        return;
    }
}

//name FIXSTR

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    ll test = 1;
    //cin>>test;
    while(test--)
    input();
}
