#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,k;
string s;
vector<int>a[N];

void sub1()
{
    int dem=0,kq=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='1') dem++;
        else {kq=max(kq,dem);dem=0;}
    }
    cout<<kq;
}


int f[N];
void sub2()
{
    int x=0,kq=0,le=0,ri=0;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='0') x++;
        f[i]=x;
        int dau=0,cuoi=i-1,r=0;
        while (dau<=cuoi)
        {
            int giua=(dau+cuoi)/2;
            if (f[i]-f[giua]<=k) {r=giua;cuoi=giua-1;}
            else dau=giua+1;
        }
        if (kq<f[i]-r)
        {
            kq=f[i]-r;
            le=r+1;
            ri=i;
        }
    }
    cout<<le<<" "<<ri;
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    s=" "+s;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    if (m==0&&k==0) sub1();
    else if (m==0) sub2();
    //else if (n<=2000) sub3();
    //else sub4();
}
