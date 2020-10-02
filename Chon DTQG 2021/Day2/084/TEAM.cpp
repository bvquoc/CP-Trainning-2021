#include <bits/stdc++.h>

using namespace std;
long long n,i,v,t,s,k;
map <int, int> a;
int main()
{
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        s=s+a[i];
    }
    t=k/s;
    v=k-s*t;
    if (v==0)
        cout<<0;
    else {
        for (i=1;i<=n;i++)
            if (v>=a[i])
                v=v-a[i];
            else break;
        cout<<v;
    }
    return 0;
}
