#include<bits/stdc++.h>
#define mod 998244353
using namespace std;

int n ,m ,t ,x ;
long long f[2001][11];
long long kq ;
int dd[2005];

struct ii
{
    int x ,y;
};
vector<int> ch ,le ;
vector<ii> so;
int s;

void di( int x ,int s ,int le)
{
    if( s == 0 && x == n+1 )
    {
        kq++;
    }
    int pr = s;
    for( int i = 0 ; i < so.size() ;i++ )
    {
        if( dd[i] == 0 )
        {
            dd[i] = 1;
            if( le%2 ) di( x+1 ,(s-so[i].x+11)%11 ,le+so[i].y );
            else di(x+1 ,(s+so[i].x)%11 ,le+so[i].y );
            dd[i] = 0;
        }
    }
}

void xl()
{
    cin >> n;
    le.clear();
    ch.clear();
    so.clear();
    kq = 0;
    for( int i = 1 ; i <= n ;i++ )
    {
        cin >> x;
        int te = 0 ,dem = 0;
        while( x )
        {
            dem++;
            if( dem%2 ) te += x%10;
            else te -= x%10;
            x/=10;
        }
        te += 11;
        te %= 11;
        //cout<<te<<' '<<dem<<'\n';
        if( dem%2 ) le.push_back(te);
        else ch.push_back(te);
        so.push_back({te ,dem%2});
    }
    if( le.size() == 0 )
    {
        for( int j = 1 ; j <= ch.size() ;j++ )
        {
            for( int t = 0 ; t <= 10 ;t++ )
            {
                f[j][t] = 0;
            }
        }
        f[0][0] = 1;
        for( int i = 0 ; i < ch.size() ;i++ )
        {
            int te = ch[i];
            //cout<<te<<'\n';
            for( int j = i+1 ; j >= 1 ;j-- )
            {
                for( int t = 0 ; t <= 10 ;t++ )
                {
                    int du =(t+te+11)%11;
                    f[j][du] += (f[j-1][t]*j)%mod;
                    f[j][du] %= mod;
                    //cout<<j<<' '<<du<<' '<<t<<' '<<f[j][du][0]<<'\n';
                }
            }
        }
        kq += f[n][0];
        cout<<f[n][0];
        return;
    }
    di(1 ,0 ,0);
    cout<<kq<<'\n';
    /*
    for( int i = 0 ; i < le.size() ;i++ )
    {
        int te = ch[i];
        for( int j = 1 ; j <= i+1 ;j++ )
        {
            for( int )
            for( int t = 0 ; t <= 10 ;t++ )
            {
                int du =(t+te+11)%11;
                f[j][0][du][0] += (f[j-1][0][t][0]*j)%mod;
                f[j][0][du][0] %= mod;
            }
        }
    }*/
}

main()
{
    freopen("GIFT11.inp" ,"r" ,stdin);
    freopen("GIFT11.out" ,"w" ,stdout);
    cin >> t;
    while( t-- )
    {
        xl();
    }
}
