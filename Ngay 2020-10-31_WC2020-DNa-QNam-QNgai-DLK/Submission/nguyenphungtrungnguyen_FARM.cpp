#include <bits/stdc++.h>
using namespace std;
int n,k,Q,P;
int a[10005],f[10005][10005];
int readInt()
{
    char c;
    while (!isdigit(c = getchar()));
    int x = c - 48;
    while (isdigit(c = getchar())) x = x * 10 + c - 48;
    return x;
}
int get(int i = 1, int r = Q){
    if( r <= 0 ) return 0;
    if( i > n ) return 0;
    int &res = f[i][r];
    if( res != -1e9 ) return res;
    res = get( i + 1, r );
    int t = min( P, r );
    res = max( res, get( i + k, r - t ) + t * a[i] );
    t = r % P;
    res = max( res, get( i + k, r - t ) + t * a[i] );
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    n = readInt();
    k = readInt();
    Q = readInt();
    P = readInt();
    for(int i = 1; i <= n; ++i) a[i] = readInt();
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= Q; ++j) f[i][j] = -1e9;
    cout << get();
}
