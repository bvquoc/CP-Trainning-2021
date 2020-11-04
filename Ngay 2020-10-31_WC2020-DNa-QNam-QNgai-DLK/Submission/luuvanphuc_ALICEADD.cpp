#include<bits/stdc++.h>
using namespace std;
int T;
string A, B;
string Sum( string a, string b )
{
    while( a.size() < b.size() ) a = '0' + a;
    while( a.size() > b.size() ) b = '0' + b;
    string c;
    int mem = 0;
    for( int i = a.size() - 1; i >= 0; --i )
    {
        int sum = ( a[i] - '0' ) + ( b[i] - '0' ) + mem;
        mem = sum / 10;
        sum %= 10;
        c = char( sum + 48 ) + c;
    }
    if( mem == 1 ) c = '1' + c;
    while( c[0] == '0' && c.size() > 1 ) c.erase( 0, 1 );
    return c;
}
int main()
{
    cin >> T;
    while( T-- )
    {
        cin >> A >> B;
        cout << Sum( A, B ) << endl;
    }
}
