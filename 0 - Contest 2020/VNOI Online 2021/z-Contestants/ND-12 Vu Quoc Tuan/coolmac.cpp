#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<int> a[100005];
int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m;
    for (int i=1;i<=m;++i)
    {
        int l,r;
        cin>>l>>r;
        a[r].push_back(l);
    }
    int mn,gh,ct;
    mn=gh=ct=100001;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        gh=min(gh,x);
    }
    for (int i=0;i<a[100000].size();++i) mn=min(mn,a[100000][i]);
    int kq=1;
    while (1)
    {
        if (mn<=gh)
        {
            cout<<kq;return 0;
        }
        ++kq;
        int pp=mn;
        for (int i=ct-1;i>=mn;--i)
         for (int j=0;j<a[i].size();++j) pp=min(pp,a[i][j]);



        if (mn==pp) {cout<<-1;return 0;}

        ct=mn;

        mn=pp;
    }

    return 0;
}
