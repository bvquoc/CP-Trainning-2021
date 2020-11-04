#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int main()
{
    cin >> a >> b >> c;
    int add = -( a / c ); add += b / c;
    if( add == 0 )
    {
        int ans = b - a;
        cout << ( ans / 2 ) + ( ans % 2 == 1 );
        return 0;
    }
    if( c % 2 == 0 )
    {
        int ans = 0;
        if( a % 2 == 0 )
        {
            ++a;
            ++ans;
        }
        int tmp = b - a;
        cout << ( tmp / 2 ) + ( tmp % 2 == 1 ) + ans;
        return 0;
    }
    int fi = c - 1 - ( a % c );
    int se = ( b % c ) - 1;
    int step = c - 2;
    if( fi & 1 ) fi = ( fi + 1 ) / 2; else fi /= 2;
    if( se & 1 ) se = ( se + 1 ) / 2; else se /= 2;
    if( step & 1 ) step = ( step + 1 ) / 2; else step /= 2;
    cout << fi + se + add + step * ( add - 1 );
}
