#include <bits/stdc++.h>
using namespace std;
struct data{
    long x,y,t;
}a[1000005];
long n,K;
long f[1000005],b[1000005];
bool xet(data u, data v){
    if( u.y == v.y ) return u.x < v.x;
    return u.y < v.y;
}
int main(){
    cin >> n >> K;
    for(long i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y >> a[i].t;
        a[i].y += a[i].x - 1 + K;
    }
    sort( a + 1,a + 1 + n, xet);
    for(long i = 1; i <= n; i++) b[i] = a[i].y;
    /*cout << endl;
    for(long i = 1; i <= n; i++) cout << a[i].x << " " << a[i].y << " "  << a[i].t << endl;*/
    long ma = 0;
    f[1] = a[1].t;
    for(long i = 2; i <= n; i++){
        f[i] = f[i-1];
        long t = lower_bound( b + 1, b + i, a[i].x ) - b;
        f[i] = max( f[i], f[t-1] + a[i].t);
        ma = max( ma, f[i] );
    }
    cout << ma;
}
