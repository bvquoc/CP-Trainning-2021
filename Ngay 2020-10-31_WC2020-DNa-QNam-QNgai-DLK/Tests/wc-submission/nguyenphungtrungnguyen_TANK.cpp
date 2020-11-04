#include <bits/stdc++.h>
using namespace std;
long n,M;
long long a[100005];
bool check(long l){
    for(long i = l; i <= n; i++){
        if( a[i] - a[i-l] < M ) return false;
    }
    return true;
}
int main(){
    cin >> M >> n;
    for(long i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    long l = 1, r = n, mid = ( l + r ) / 2;
    while( r - l > 1 ){
        if( check(mid) ) r = mid;
        else l = mid;
        mid = ( l + r ) / 2;
    }
    if( check(l) ) cout << l;
    else cout << r;
}
