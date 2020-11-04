#include <bits/stdc++.h>
using namespace std;
long t,n,k;
long long f[1005],d[100005][85];
vector<long> c;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    f[1] = 1;
    f[2] = 1;
    c.push_back(1);
    for(long i = 3; ; i++){
        f[i] = f[i-1] + f[i-2];
        if( f[i] > 1e5 ) break;
        c.push_back( f[i] );
    }
    for(long i = 0; i <= 1e5; i++) d[i][0] = 1e9;
    d[0][0] = 0;
    for(long i = 1; i <= 1e5; i++){
        for(long j = 0; j < c.size(); j++){
            if( c[j] > i ) break;
            d[i][0] = min( d[i][0],d[i-c[j]][0] + 1);
        }
    }
   for(long j = 1; j <= 80; j++) for(long i = 1; i <= 1e5; i++)  d[i][j] = d[i][0];
    for(long j = 1; j <= 80; j++){
        for(long i = 1; i <= 1e5; i++){
            if( d[i][j] >= j ) d[i][j] += d[i-1][j];
            else d[i][j] = d[i-1][j];
        }
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        if( k > 80 ){
            cout << 0 << '\n';
            continue;
        }
        cout << d[n][k] << '\n';
    }
}
