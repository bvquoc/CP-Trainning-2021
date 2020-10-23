#include <bits/stdc++.h>

#define ULL unsigned long long
const int N = 16 + 1;
const int K = 3400 + 5;

int n, k;
int a[N];
ULL f[N][66000];

void input()
{
    scanf("%d %d", &n, &k );
    for( int i = 1; i <= n; i++ )
        scanf("%d", a+i);
}

int getBit( int i, int state )
{
    return ( state >> i ) & 1;
}

int offBit( int i, int state )
{
    return state & (~( 1 << i ));
}

int abs( int x )
{
    return ( x >= 0 ) ? x : (-x);
}

void solve()
{
    int first = 1;
    int last = ( 1 << n ) - 1;

    memset( f, 0, sizeof( f ) );
    for( int i = 0; i < n; i++ )
        f[i][1<<i] = 1;

    for( int s = first; s <= last; s++ )
        for( int i = 0; i < n; i++ )
        {
            if ( getBit( i, s ) == 1 )
            {
                int preS = offBit( i, s );
                for( int j = 0; j < n; j++ )
                    if ( getBit( j, preS ) == 1 )
                        if ( abs( a[i+1] - a[j+1] ) > k )
                            f[i][s] += f[j][preS];
            }
        }
}

void output()
{
    ULL res = 0;
    for( int i = 0; i < n; i++ )
        res += f[i][(1<<n)-1];

    printf("%lld", res );
}

int main()
{
    freopen("COWMIX.INP", "r", stdin);
    freopen("COWMIX.OUT", "w", stdout);
    input();
    solve();
    output();
}
