#include <bits/stdc++.h>
using namespace std;
#define fi first
#define sc second
typedef pair<int,int> cap;

int main()
{
    freopen("coolmac.inp","r",stdin);
    freopen("coolmac.out","w",stdout);
    vector< cap > vect;
    int m,a[100005]={0},b[100005]={0},i,j,n,d=1,d1=1,giu=100000,x;
    cin>>m;
    for (i=1;i<=m;++i)
    {
        cin >> a[i] >> b[i];
        vect.push_back(make_pair(a[i],b[i]));
    }
    sort(vect.begin(),vect.end());
    cin>>n;
    for (i=1;i<=n;++i)
    {
        cin>>x;
        if (giu>x)  giu=x;
    }
    if (vect[0].fi>giu)  cout<<-1;
    else
    {
        a[d]=vect[0].fi;
        b[d]=vect[0].sc;
        for (i=1;i<vect.size();++i)
        {
            if (a[d]<vect[i].fi && vect[i].fi-b[d]<2 && b[d]<vect[i].sc)
            {
                ++d;
                a[d]=vect[i].fi;
                b[d]=vect[i].sc;
            }
            else if (a[d]==vect[i].fi && vect[i].fi<b[d] && b[d]<vect[i].sc)  b[d]=vect[i].sc;
        }
        if (b[d]<100000)  cout<<-1;
        else
        {
            for (i=1;i<=d;++i)
                if (a[i]<=giu && giu<=b[i])  break;
            j=i;
            for (i=i;i<d;++i)
                {
                    while (a[j+1]<b[i])
                    {
                        ++j;
                        if (j==d)  break;
                    }
                    --j;
                    i=j;
                    ++d1;

                }
            cout<<d1;
        }
    }
    return 0;
}
