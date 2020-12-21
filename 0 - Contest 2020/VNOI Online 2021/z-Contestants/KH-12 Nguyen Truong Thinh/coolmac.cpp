#include<bits/stdc++.h>
using namespace std;
int n,m,mi;
typedef pair<int, int> ii;
ii a[100009];
bool cmp(ii x, ii y)
{
    if (x.first==y.first)
    {
        return x.second<y.second;
    }
    else
    {
        return x.first<y.first;
    }
}
int main()
{
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[i].first=u;
        a[i].second=v;
    }
    cin>>n;
    mi=100001;
    for (int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        mi=min(mi,t);
    }
    //cout<<mi<<endl;
    sort(a+1,a+m+1,cmp);
    if (a[1].first>mi)
    {
       // cout<<0<<endl;
        cout<<-1<<endl;
        return 0;
    }
    a[0].second=mi;
    int j=0;
    int res=0;
    while (j<m)
    {
        int i=j+1;
        int ma=0;
        while (i<=m)
        {
            if (a[j].second+1>=a[i].first && j>0)
            {
                ma=max(ma,a[i].second);
                i++;
            }
            else
            {
                if (a[j].second>=a[i].first && j==0)
                {
                    ma=max(ma,a[i].second);
                    i++;
                }
                break;
            }
        }
        if (i<=m) {
        if (i==j+1)
        {
        //    cout<<0<<endl;
            cout<<-1<<endl;
            return 0;
        }
        }
       // else
        //{
          //  break;
        //}
        int o=j;
        if (a[j].second<ma) {
        res++;
     //   cout<<i-1<<endl;
        }
        j=i-1;
        a[j].second=max(a[o].second,ma);
    }
    if (a[j].second<100000)
    {
       // cout<<0<<endl;
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        cout<<res<<endl;
        return 0;
    }
}
