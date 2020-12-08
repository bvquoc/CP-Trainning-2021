#include <bits/stdc++.h>

using namespace std;

int xu[15];

void query()
{
    int x,t;
    cin>>x>>t;
    int res=INT_MAX;
    int n;
    if (x<=50000)
        n=50000;
    if (x>50000)
        n=t/x;
    for (int i=0; i<=n; ++i)
    {
        int c=t,coin=i;
        if (c>=x*i)
            c-=x*i;
        else
            break;
        for (int j=14; j>=0; --j)
        {
            if (c>=xu[j])
            {
                coin+=c/xu[j];
                c=c%xu[j];
            }
        }
        res=min(res,coin);
    }
    cout<<res<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);

    xu[0]=1; xu[1]=3; xu[2]=5;
    for (int i=3; i<15; ++i)
    {
        xu[i]=xu[i-3]*10;
    }

    int q; cin>>q;
    while (q--)
    {
        query();
    }

    return 0;
}
