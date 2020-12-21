#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#define N 100005
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
int m,n,tm;
ii a[N];
int main()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[i]=ii(x,y);
    }
    cin>>n;
    tm=1e5;
    for (int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        tm=min(x,tm);
    }
    sort(a+1,a+m+1);
    a[m+1]=ii(1e7,0);
    //for (int i=1;i<=m;i++) cout<<a[i].first<<" "<<a[i].second<<"\n";
    int ans=0;
    int j=1;
    while (tm<1e5)
    {
        if (tm<a[j].first)
        {
            cout<<-1;
            return 0;
        }
        int tmp=0;
        while (a[j].first<=tm)
        {
            tmp=max(tmp,a[j].second);
            j++;
        }
        tm=tmp;
        ans++;
    }
    cout<<ans;
    return 0;
}
