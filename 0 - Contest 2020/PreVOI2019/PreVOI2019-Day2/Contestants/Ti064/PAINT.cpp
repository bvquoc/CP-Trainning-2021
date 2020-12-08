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
    for (c = getchar();'a'>c||c>'z';c=getchar())
    {
        dem++;if(dem==1000) return;
    }
    for (;'a'<=c&&c<='z';c=getchar())
    {
        son = c;
    }
}

const int MaxN = 1e6+1e5;

const ll mod = 1e6+3;

template<typename so> void get_min(so &a,so b)
{
    if (a>b) a = b;
}

int a[MaxN];

int cha[MaxN];

int n;

int dem =0 ;

int tim(int u)
{
    if (cha[u]!=u)
    {
        return cha[u] = tim(cha[u]);
    }
    return cha[u];
}

void noi(int x,int y)
{
    if (x==y) return;
    cha[x] = y;
}
int come[28];

struct Query
{
    int type;
    int x;
    int y;
};

Query q[MaxN];

int vt = 0;

multimap<int,int> mp;

multimap<int,int>::iterator it;

void input()
{
    //cin>>n;
    read(n);
    fill(come,come+28,-1);
    for (int i=0;i<n;i++)
    {
        char c;
        //cin>>q[i].type>>c;q[i].y = -1;
        read(q[i].type);
        rec(c);
        q[i].x = c - 'a';
        if (q[i].type==1)
        {
            dem++;
        }
        else
        {
            //cin>>c;
            rec(c);
            q[i].y = c - 'a';
        }
    }
    for (int i=1;i<=dem;i++)
    {
        cha[i] = i;
    }
    for (int i=0;i<n;i++)
    {
        if (q[i].type==1)
        {
            ++vt;
            int color  = q[i].x;
            if (come[color]==-1)
            {
                come[color] = vt;
            }
            else
            {
                int pre = come[color];
                cha[pre] = vt;
                come[color] = vt;
            }
        }
        else
        {
            int mau_now = q[i].x, mau_become = q[i].y;
            if (come[mau_now]==-1) continue;
            int vt1 = come[mau_now],vt2 = come[mau_become];
            cha[vt1] = vt2;
            come[mau_now] = -1;
        }
    }
    for (int i=0;i<28;i++)
    {
        mp.insert({come[i],i});
    }
    for (int i=1;i<=dem;i++)
    {
        int gg = tim(i);
        it = mp.find(gg);
        cout<<char((it->second)+'a');
    }
}

//name PAINT

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ll test = 1;
    //cin>>test;
    while(test--)
    input();
}
