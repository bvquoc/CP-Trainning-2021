#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
const int N=1e5+5;
int m,n,res,b[N];
pair <int,int> a[N];
int cnp(int t,int pre)
{
    int l=1, r=m;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (a[mid].l>t) r=mid-1;
        else l=mid+1;
    }
    --l;
    if (l==pre) return -1;
    if (a[l].r==100000) return b[l];
    int k=cnp(a[l].r,l);
    int kq=k+b[l];
    b[l]=0;
    return kq;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++) cin>>a[i].l>>a[i].r,b[i]=1;
    sort(a+1,a+n+1);
    for (int i=2;i<=m;i++)
    {
        if (a[i-1].r>a[i].r) a[i].r=a[i-1].r;
    }
    a[0].l=100000;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        int k=cnp(t,0);
        if (k==-1) {cout<<-1;exit(0);}
        res+=k;

    }
    cout<<res;
}
