#include <bits/stdc++.h>
using namespace std;

#define fi first
#define sc second

typedef pair <int,int> cap;

set < cap > mp;
set < cap > :: iterator it;

int main()
{
    //freopen ("COOLMAC.INP","r",stdin);
    //freopen ("COOLMAC.OUT","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;  cin>>n;
    int a,b,i,dem;

    for (i=0; i<n; i++)
    {
        cin>>a>>b;
        mp.insert(cap(b,a));
    }
    /*cout<<"\n";
    for (it=mp.begin(); it!=mp.end(); it++)
        cout<<it->sc<<" "<<it->fi<<"\n";
        cout<<"\n";*/

    int m;  cin>>m;
    int t,mi=1e6;
    for (i=0; i<m; i++)
    {
        cin>>t;
        mi=min(t,mi);
    }
    cout<<"\n";

    it=mp.end();
    it--;
    if (it->fi!=100000) {cout<<-1;return 0;}
    a=it->sc;
    //cout<<a<<"\n";
    dem=1;
    it--;
    //cout<<it->fi<<" "<<it->sc<<" "<<a<<"\n\n";
    while (a>t)
    {
        mi=a;
        for (it=it; ;it--)
        {
            if (a<=it->fi)
            {
                mi=min(mi,it->sc);
                if (it==mp.begin())
                {
                    if (a!=mi) {dem++; a=mi; break;}
                    else {cout<<-1; return 0;}
                }
            }
            else
            {
                if (a==mi) {cout<<-1; return 0;}
                it++; dem++; a=mi; break;
            }
        }
        if (it==mp.begin() && a>t) {cout<<-1; return 0;}
    }

    cout<<dem;

}
