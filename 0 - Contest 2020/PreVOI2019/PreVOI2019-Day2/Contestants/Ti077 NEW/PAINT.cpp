#include <bits/stdc++.h>
#define FOR(i,x,y) for (int i=x; i<=y; i++)
#define ROF(i,x,y) for (int i=x; i>=y; i--)
#define ll long long
#define fi first
#define se second
#define FORR(i,x) for(int i=0; i<x.size(); i++)
#define yct "PAINT"
using namespace std;
int q;
char a[2000010];

void sub1()
{
    char x,y;
    int ms, dem=0;
    FOR(i,1,q)
    {
        cin >>ms;
        if (ms==1)
        {
            dem++;
            cin >>x;
            a[dem]=x;
        }
        else
        {
            cin >>x >>y;
            FOR(i,1,dem)
            {
                if (a[i]==x) a[i]=y;
            }
        }
    }
    FOR(i,1,dem) cout <<a[i];
    exit(0);

}
int dem;
int cur[100];
int l[1000010], h[1000010];
char x,y;
int Find(int x)
{
    if (x==l[x]) return x;
    l[x]=Find(l[x]);
    return l[x];
}

void Union(int u, int v, char ms)
{
    int x=Find(u);
    int y=Find(v);
    if (h[x]>h[y])
    {
        l[y]=x;
        h[x]+=h[y];
        a[x]=ms;
    }
    else
    {
        l[x]=y;
        h[y]+=h[x];
        a[y]=ms;
    }
}

int main()
{
    freopen(yct".INP","r",stdin);
    freopen(yct".OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >>q;
    if (q<=1000) sub1();
    FOR(i,1,q)
    {
        int ms;
        cin>>ms;
        if (ms==1)
        {
            cin >>x;
            dem++;
            l[dem]=dem; h[dem]=1;
            int tg=x-'a'+1;
            if (cur[tg]==0)
            {
                cur[tg]=dem;
                a[dem]=x;
            }
            else Union(dem,cur[tg],x);
        }
        else
        {
            cin >>x >>y;
            if (x==y) continue;
            int tg1=x-'a'+1;
            int tg2=y-'a'+1;
            if (cur[tg1]==0) continue;

            if (cur[tg2]!=0) Union(cur[tg1],cur[tg2],y);
            else
            {
                a[Find(cur[tg1])]=y;
                cur[tg2]=cur[tg1];
            }
            cur[tg1]=0;
        }
    }

    FOR(i,1,dem) cout <<a[Find(i)];
    return 0;
}
