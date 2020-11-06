#include<bits/stdc++.h>
using namespace std;
int n;
int visit[2005];
int T;
int a[1005][1005];
int Hus[2005];
bool DFS( int u, int x )
{
    if( visit[u] != T ) visit[u] = T; else return false;
    for( int v = n + 1; v <= 2 * n; ++v ) if( a[u][v-n] >= x ) if( !Hus[v] || DFS( Hus[v], x ) )
    {
        Hus[v] = u;
        return true;
    }
    return false;
}
bool check( int x )
{
    int cnt = 0;
    for( int i = 1; i <= n; ++i ) Hus[i+n] = 0;
    for( int i = 1; i <= n; ++i )
    {
        ++T;
        cnt += DFS( i, x );
    }
    if( cnt == n ) return true;
    return false;
}
int main()
{
    cin >> n;
    for( int i = 1; i <= n; ++i )
        for( int j = 1; j <= n; ++j ) cin >> a[i][j];
    int L = 1, R = 1e9;
    while( R - L > 5 )
    {
        int mid = ( L + R ) / 2;
        if( check( mid ) ) L = mid; else R = mid;
    }
    for( int i = R; i >= L; --i ) if( check(i) )
    {
        cout << i;
        return 0;
    }
}
