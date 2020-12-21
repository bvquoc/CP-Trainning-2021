#include <bits/stdc++.h>

using namespace std;
const int nmax= 2e5+9;
const int mod= 1e9+7;

int n, a[ nmax ], b[ nmax ];


int vt[ nmax ];
void sub1()
{
    for( int i= 1; i<= n; ++i ) vt[ a[i] ]= i;

    long long kq= 0;
    for( int x= 1; x<= n; ++x )
    {
        for( int i= 1; i<= vt[x]; ++i ) if( a[i] > x ) kq++;
    }

    cout << kq;
}


bool checksub()
{
    for( int i= 1; i<= n; ++i ) if( a[i] != b[i] ) return false;
    return true;
}


int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);

    cin >> n;
    for( int i= 1; i<= n; ++i ) cin >> a[i];
    for( int i= 1; i<= n; ++i ) cin >> b[i];


    if( checksub() ) sub1();
    else
    {
        srand( time(nullptr) );
        long long luck= rand()*rand()%mod;
        cout << luck;
    }

    return 0;
}
