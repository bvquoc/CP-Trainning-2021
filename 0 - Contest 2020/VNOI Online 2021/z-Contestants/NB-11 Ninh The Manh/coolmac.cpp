#include<bits/stdc++.h>
using namespace std;
int n,m,vt=1e9,sl=1;
int vt1=1
,f[100005];
int t[100005];
typedef pair<int,int> ii;
 ii a[100005];

int main()
{
  freopen("coolmac.inp","r",stdin);
  freopen("coolmac.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>a[i].first>>a[i].second;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        vt=min(vt,t[i]);
    }
    sort(a+1,a+1+m);
    while(vt1<=m)
    {
        sl++;
        int x=vt1;
        int maxx=0;
        for(int i=x;i<=m;i++)
        {
            if(a[i].first<=vt&&a[i].second>=vt)
                {
                    if(maxx<a[i].second)
                    {
                        maxx=a[i].second;
                        vt1=i;
                    }
                }
            if(a[i].first>vt)
                   break;
            if(a[i].second>=100000)
            {
                cout<<sl;
                return 0;
            }
        }
        if(vt1==x)
        {
            cout<<-1;
            return 0;
        }
        vt=a[vt1].second;
    }
}
