#include <bits/stdc++.h>
#define X first
#define Y second
#define nmax 100007
using namespace std;
typedef pair <int,int> ii;
int n,m,minn=1e9,maxx,ans=0;
ii coat[nmax];
bool comp(ii &a, ii &b)
{
    return (a.X<b.X || (a.X==b.X && a.Y>b.Y));
}
int main()
{
    freopen("COOLMAC.INP","r",stdin);
    freopen("COOLMAC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> coat[i].X >> coat[i].Y;
        maxx=max(maxx,coat[i].Y);
    }
    cin >> m;
    for (int i=1; i<=m; i++)
    {
        int x;
        cin >> x;
        minn=min(x,minn);
    }
    if (maxx<100000)
    {
        cout << -1;
        return 0;
    }
    sort(coat+1,coat+n+1,comp);
    int i=1;
    int tmp=minn;
    while (i<n+1)
    {
        int ck=0;
        while (coat[i].X<=minn && i<=n)
        {
            tmp=max(tmp,coat[i].Y);
            ck++;
            i++;
        }
        ans++;
        if (ck<=0)
        {
            cout << -1;
            exit(0);
        }
        if (tmp>=100000)
        {
            cout << ans;
            exit(0);
        }
        minn=tmp;
    }
    return 0;
}
