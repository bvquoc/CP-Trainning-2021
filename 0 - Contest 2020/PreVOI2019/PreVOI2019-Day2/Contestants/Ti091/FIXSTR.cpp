#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define st first
#define nd second
#define int long long
using namespace std;
const int N=1e3+4;
string s;
int n,m,dem,x0,x1;
int a[N];
int t[4*N];
int b[N][N];
vector<pii> g;
struct ss
{
    char ch;
    int c,x;
};
ss p[N];
void built(int s,int l,int r)
{
    if (l==r)
    {
        t[s]=a[l];
        return;
    }
    int mid=(l+r)/2;
    built(2*s,l,mid);
    built(2*s+1,mid+1,r);
    t[s]=t[2*s]+t[2*s+1];
}
int get(int s,int l,int r,int u,int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[s];
    int mid=(l+r)/2;
    return get(2*s,l,mid,u,v)+get(2*s+1,mid+1,r,u,v);
}
int sol(int x,int y)
{
    int l=x;
    int r=y,kq=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (get(1,1,n,x,mid)==mid)
        {
            kq=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return kq;
}
main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin >> s;
    m=s.size();
    s=' '+s;
    forinc(i,1,s.size())
    {
        if (s[i]=='(') a[i]=0;
        else a[i]=1;
    }
    built(1,1,m);
    cin >> n;
    forinc(i,1,n)
    {
        char ch;
        int c,x,res=0,cnt=0;
        cin >> ch >> c;
        if (ch=='C')
        {
            p[i]={ch,c,0};
        }
        else if (ch=='Q')
        {
            cin >> x;
            p[i]={ch,c,x};
        }
        else
        {
            p[i]={ch,c,0};
            dem++;
        }
    }
    if (dem!=0)
    {
        forinc(i,1,n)
        {
            char ch=p[i].ch;
            int c=p[i].c;
            int x=p[i].x;
            if (ch=='C')
            {
                a[c]=1-a[c];
            }
            else if (ch=='Q')
            {
                int res=0,cnt=0;
                forinc(j,c,x)
                {
                    if (a[j]==1 && cnt==0) res++;
                    else if (a[j]==1) cnt--;
                    else if (a[j]==0) cnt++;
                }
                cout << res+cnt <<"\n";
            }
            else
            {
                dem++;
                forinc(j,1,m) a[j]=b[c-1][j];
            }
            forinc(j,1,m) b[i][j]=a[j];
        }
    }
}
