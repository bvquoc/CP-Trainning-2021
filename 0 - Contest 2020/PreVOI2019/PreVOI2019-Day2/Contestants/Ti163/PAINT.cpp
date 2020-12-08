#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EL putchar('\n');
#define mod 1000000007
#define oo 1000006
#define INF 0x3f3f3f3f
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll base=1e9+7;
int n;
char s[oo];
vector<int>a[30];
struct query
{
    int t;
    char x,y;
}p[oo];
void ReadInPut()
{
    cin>>n;
    F(i,1,n)
    {
        cin>>p[i].t>>p[i].x;
        if(p[i].t==2)cin>>p[i].y;
    }
}
void sub1()
{
    int cur=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i].t==1){
            s[++cur]=p[i].x;
            a[p[i].x-'a'+1].pb(cur);
        }
        else{
            int X=p[i].x-'a'+1,Y=p[i].y-'a'+1;
            for(int j=a[X].size()-1;j>=0;j--)
            {
                int v=a[X][j];
                s[v]=p[i].y;
                a[Y].pb(v);
            }
            a[X].clear();
        }
    }
    F(i,1,cur)cout<<s[i];
}
int pa[30];
int Find_Set(int u)
{
    if(pa[u]<0)return u;
    pa[u]=Find_Set(pa[u]);
    return pa[u];
}
char C[30];
void sub2()
{
    for(char c='a';c<='z';c++)
    {
        C[c-'a'+1]=c;
    }
    reset(pa,-1);
    int cur=0,L;
    F(i,1,n)cur+=(p[i].t==1);
    if(cur==0)return;
    L=cur;
    FD(i,n,1)
    {
        if(p[i].t==2)
        {
            int x=p[i].x-'a'+1;
            int y=p[i].y-'a'+1;
            if(pa[y]==x)continue;
            if(x==y)continue;
            pa[x]=y;
        }
        else{
            int x=p[i].x-'a'+1;
            int t=Find_Set(x);
            s[cur--]=C[t];
        }
    }
    F(i,1,L)cout<<s[i];
}
void Solve()
{
    if(n<=1e4)sub1();
    else sub2();
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    int sotest=1;
    //cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
/*10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/
/*
4
1 a
1 b
2 a b
2 b a
2 a b
*/
