#include <bits/stdc++.h>
#define FILE "decor"
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 5e5+9;
int n,m,k;
bool a[N];
pii e[N];
void sub1()
{
    int d=0,kq=0,r;
    a[n+1]=0;
    for(int i=1;i<=n+1;i++)
        if(a[i]) d++;
        else
        {
            if(d > kq)
            {
                r=i;
                kq=d;
            }
            d=0;
        }
    cout<<r-kq+1<<' '<<r;
}
int dd[N],vt[N];
void sub2()
{
    int d=0;
    a[n+1]=0;
    for(int i=1;i<=n+1;i++)
        if(a[i])
        {
            d++;
            dd[i]=d;
        }
        else d=0;
    int kq=0,s0=0,kql,kqr;
    vt[0]=0;/*
    for(int i=0;i<=n;i++) cout<<a[i]<<' ';cout<<'\n';
    for(int i=0;i<=n;i++) cout<<dd[i]<<' ';cout<<'\n';*/
    for(int i=1;i<=n;i++)
        {
            s0=s0+(a[i]==0);
            vt[s0]=i;
            int l=vt[max(s0-k,0)],r=i;
            if(a[l]) l=max(l-dd[l]+1,1);
            else l++;
            if(r-l+1 > kq || (r-l+1 == kq && l < kql))
            {
                kq=r-l+1;
                kql=l;kqr=r;
            }
        }
    cout<<kql<<' '<<kqr;
}
int main()
{
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;
    char c;
    for(int i=1;i<=n;i++) cin>>c,a[i]=(c=='1');
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        e[i]={x,y};
    }
    if(m==0 && k==0) {sub1();return 0;}
    //if(m==0) {sub2();return 0;}
    sub2();
}
