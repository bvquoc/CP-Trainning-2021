#include<bits/stdc++.h>
using namespace std;

int n ,m;
int x ,y;
int mi ,dem;

struct ii
{
    int x ,y;
};
ii a[100005];

bool ss ( ii a ,ii b )
{
    return a.y > b.y;
}

main()
{
    freopen("COOLMAC.inp" ,"r" ,stdin);
    freopen("COOLMAC.out" ,"w" ,stdout);
    cin >> n;
    for( int i = 1 ; i <= n ;i++ )
    {
        cin >> a[i].x >> a[i].y;
    }
    cin >> m;
    for( int i = 1 ; i <= m ;i++ )
    {
        cin >> x;
        if( i == 1 ) mi = x;
        mi = min( mi ,x );
    }
    sort(a+1 ,a+n+1 ,ss);
    int vt = 0;
    int te = 100001;
    int cu = 100001;
    int j = 1;
    for( int i = 100000 ; i >= mi ;i-- )
    {
        while( j <= n && i == a[j].y )
        {
            cu = min(cu ,a[j].x);
            j++;
        }
        if( i < te )
        {
            if( cu > i )
            {
                cout<<-1<<'\n';
                return 0;
            }
            te = cu;
            dem++;
        }
    }
    cout<<dem<<'\n';
}
