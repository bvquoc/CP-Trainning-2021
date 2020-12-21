#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 50005
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int n,m,k;
bool b[N];
vector <int> a[N];
int ans;
int f[N];
void sub1()
{
    int l=0,r=0;
    ans=0;
    int dem=0;
    b[n+1]=0;
    for (int i=1; i<=n+1; i++)
    {
        if (b[i]==1) dem++;
        else
        {
            if (ans<dem)
            {
                l=i-dem;
                r=i-1;
                ans=dem;
            }
            dem=0;
        }
    }
    if (l==0&&r==0)
        cout<<-1;
    else
        cout<<l<<" "<<r;
}
void sub2()
{
    int f[N];
    for (int i=1; i<=n; i++)
    {
        f[i]=f[i-1]+(b[i]==0);
    }
    int l=1,r=1,al=0,ar=0;
    ans=0;
    while (l<=n)
    {
        while (f[r+1]-f[l-1]<=k&&r<n)
            r++;
        if ((r-l+1)>ans)
        {
            ans=r-l+1;
            al=l;
            ar=r;
        }
        l++;
    }
    cout<<al<<" "<<ar<<endl;
}
int cha[N];
int fnd(int u)
{
    if (cha[u]==u) return u;
    return fnd(cha[u]);
}
void joint(int u,int v)
{
    v=fnd(v);
    u=fnd(u);
    cha[v]=u;
}
ii kt(int x)
{
    for (int i=1; i<=n-x+1; i++)
    {
        vector<int> g(f,f+n+1);
        int s1=0;
        for (int j=i; j<=x+i-1; j++)
        {
            int u=fnd(j);
            if (g[u]>0)
            {
                s1++;
                g[u]--;
            }
        }
        if (x-s1<=k) return ii(i,x+i-1);
    }
    return ii(-1,-1);
}
void sub3()
{
    for (int i=1; i<=n; i++) cha[i]=i;
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        joint(x,y);
    }
    for (int i=1; i<=n; i++)
        if (b[i]) f[fnd(i)]++;
    int l=1,r=n,w;
    int al=0,ar=0;
    while (l<=r)
    {
        w=(l+r)/2;
        ii u=kt(w);
        if (u.first!=-1&&u.second!=-1)
        {
            al=u.first;
            ar=u.second;
            l=w+1;
        }
        else
            r=w-1;
    }
    if (al==0&&ar==0)
        cout<<-1;
    else
        cout<<al<<" "<<ar;
}
int main()
{
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        b[i]=ch-'0';
    }
    if (m==0&&k==0)
    {
        sub1();
        return 0;
    }
    if (m==0)
    {
        sub2();
        return 0;
    }
    sub3();
}
