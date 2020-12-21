#include <bits/stdc++.h>
#include <vector>
using namespace std;
int i,j,n,x,y,snho,kt,m;
vector< pair<int,int> >a;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        a.push_back( make_pair(x,y));
    }
    cin>>m;
    cin>>snho;
    for(i=1;i<=m-1;i++)
    {
        cin>>x;
        if(snho>x) snho=x;
    }
    sort(a.begin(),a.end());
    int slon=0,tk=0,vt,dem=0;
    a.push_back(make_pair(0,0));
    for(i=0;i<=n;i++)
    {
        if(kt==0 && a[i].first<=snho && a[i].second>snho)
        {
            if(slon<a[i].second)
            {
                slon=a[i].second;
            }
        }
        if(slon==100000 && kt==0)
        {
            dem++;
            kt=-1;
            continue;
        }
        if(a[i].first>snho && kt==0)
        {
            if(slon>snho)
            {
                snho=slon;
                dem++;
                if(slon<100000) slon=0;
                if(slon==100000) continue;
                tk=0;
                vt=i;
                i--;
            } else
            {
                kt=1;
            }
        }
    }

    if(slon==100000)
    {
        if(kt!=1) cout<<dem;
        else cout<<-1;
    } else cout<<-1;
    return 0;
}
