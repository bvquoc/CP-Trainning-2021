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
int n,m,N;
int sum[oo];
string s;
struct tdz
{
    int fi,se;
    int tong;
}p[4*oo];
void ReadInPut()
{
    getline(cin,s);
    N=s.size();
    s='*'+s;
    cin>>n;
    F(i,1,N)
    {
        int t=-1;
        if(s[i]=='(')t=1;
        sum[i]=sum[i-1]+t;
    }
}
void Build(int k,int l,int r)
{
    if(l==r)
    {
        p[k].se=sum[l];
        p[k].fi=0;
        p[k].tong=sum[l];
        return;
    }
    int mid=(l+r)/2;
    Build(k*2,l,mid);
    Build(k*2+1,mid+1,r);
    p[k].se=min(p[k*2].se,p[k*2+1].se);
    p[k].tong=p[k*2+1].tong;
}
void lazy(int id,int l,int r)
{
    int t=p[id].fi;
    int mid=(l+r)/2;
    p[id*2].fi+=t;
    p[id*2].se+=t;
    p[id*2].tong+=t*(mid-l+1);
    p[id*2+1].fi+=t;
    p[id*2+1].se+=t;
    p[id*2+1].tong+=t*(r-mid);
    p[id].fi=0;
}
void update(int id,int l,int r,int u,int v,int val)
{
    if (v < l || r < u)return;
    if(u<=l&&r<=v)
    {
        p[id].fi+=val;
        p[id].se+=val;
        p[id].tong+=val*(r-l+1);
        return ;
    }
    int m=(l+r)/2;
    lazy(id,l,r);
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    p[id].se=min(p[id*2].se,p[id*2+1].se);
    p[id].tong=p[id*2+1].se;
}
int get(int id,int l,int r,int u,int v)
{
    if (v < l || r < u)return 1e9;
    if(u<=l&&r<=v)return p[id].se;
    int m=(l+r)/2;
    lazy(id,l,r);
    return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int getsum(int id,int l,int r,int u,int v)
{
    if (v < l || r < u)return 0;
    if(u<=l&&r<=v)
    {
        if(r==v)return p[id].tong;
        return 0;
    }
    int m=(l+r)/2;
    lazy(id,l,r);
    return (getsum(id*2,l,m,u,v)+getsum(id*2+1,m+1,r,u,v));
}
void sub2()
{
    Build(1,1,N);
    F(i,1,n)
    {
        char c;
        cin>>c;
        if(c=='C')
        {
            int x;
            cin>>x;
            if(s[x]==')')
            {
                s[x]='(';
                update(1,1,N,x,N,2);
            }
            else{
                s[x]=')';
                update(1,1,N,x,N,-2);
            }
        }
        else{
            int L,R;
            cin>>L>>R;
            int t=get(1,1,N,L,R);
            if(L>1)t-=get(1,1,N,L-1,L-1);
            //if(t>=0){cout<<t<<'\n';continue;}
            int bac=getsum(1,1,N,R,R);
            if(L>1)bac-=getsum(1,1,N,L-1,L-1);
         //   cout<<bac<<" ";
            bac-=t;
            cout<<abs(t)+bac<<'\n';
        }
    }
}
struct query
{
    char c;
    int x,y;
}Q[oo];
//string s1[oo][oo];
void sub1()
{
    F(i,1,n)
    {
        cin>>Q[i].c;
        if(Q[i].c=='C')
        {
            cin>>Q[i].x;
            if(s[Q[i].x]=')')s[Q[i].x]='(';
            else s[Q[i].x]=')';
            continue;
        }
        if(Q[i].c=='Q')
        {
            cin>>Q[i].x>>Q[i].y;
            int L=Q[i].x,R=Q[i].y;
            int bac=0,ans=0;
            for(int i=L;i<=R;i++)
            {
                if(s[i]=='(')bac++;
                else bac--;
                if(bac<0)ans++;
            }
            bac+=ans;
            cout<<bac<<'\n';
            continue;
        }
        cin>>Q[i].x;
        int cuoi=Q[i].x;
        int j=i-1;
        while(1)
        {
            if(j<cuoi)break;
            if(Q[j].c=='C')
            {
                int x=Q[j].x;
                if(s[x]==')')s[x]='(';
                else s[x]=')';
            }
            else{
                if(j>1&&j==cuoi&&Q[j-1].c=='U')cuoi=Q[j].x;
            }
            j--;
        }
    }
}
void Solve()
{
    if(n<=1000&&N<=1000)sub1();
    else sub2();
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    int sotest=1;
    //cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
