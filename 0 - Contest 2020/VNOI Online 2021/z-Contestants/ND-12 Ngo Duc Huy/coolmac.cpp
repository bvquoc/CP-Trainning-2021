#include <bits/stdc++.h>
#define FILE "coolmac"
#define ll long long
using namespace std;

const int N = 100009;
int m,n,t;
struct tp
{
    int l,r;
}a[N];
bool cmp(tp &a,tp &b)
{
    return a.r > b.r || (a.r == b.r && a.l < b.l);
}
int main()
{
    freopen(FILE".inp","r",stdin);
    freopen(FILE".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].l>>a[i].r;
    cin>>n;
    int x;
    t=1e5;
    for(int i=1;i<=n;i++)
        cin>>x,
        t=min(t,x);
    sort(a+1,a+1+m,cmp);
    int h=1e5,kq=0;
    for(int i=1;i<=m;i++)
        if(a[i].l <= h && h <= a[i].r)
        {
            h=a[i].l;
            kq++;
        }
    if(h > t) cout<<-1;
    else cout<<kq;
}
