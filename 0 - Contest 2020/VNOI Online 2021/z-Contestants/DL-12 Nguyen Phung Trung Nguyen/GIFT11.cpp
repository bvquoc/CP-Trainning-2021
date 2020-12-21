#include <bits/stdc++.h>
using namespace std;
const long mod = 998244353;
long test,n,a[2005],d[20],f[20],res;
string s;
bool get(long x){
    long cnt = 0;
    while( x > 0 ){
        cnt++;
        x /= 10;
    }
    return ( ( cnt % 2 ) == 0 );
}
void BAG(long i){
    long x = a[i];
    while( x > 0){
        s += char( x%10 + 48 );
        x /= 10;
    }
}
void tinh(){
    s = "";
    for(long i = 1; i <= n; i++) BAG(d[i]);
    long cnt1 = 0, cnt2 = 0;
    reverse(s.begin(),s.end());
    for(long i = s.size() - 1; i >= 0; i -= 2 ) cnt1 += ( s[i] - '0' );
    for(long i = s.size() - 2; i >= 0; i -= 2 ) cnt2 += ( s[i] - '0' );
    if( abs(cnt1 - cnt2) % 11 == 0 ){
        res++;
    }
}
void dq( long i ){
    for(long j = 1; j <= n; j++){
        if( f[j] ) continue;
        d[i] = j;
        f[j] = 1;
        if( i == n ) tinh();
        else dq(i + 1);
        f[j] = 0;
    }
}
long cl[5];
void ge(long i){
    long pos = 1;
    long x = a[i];
    while( x > 0 ){
        cl[pos] += x%10;
        x /= 10;
        pos++;
        pos %= 2;
    }
}
void sub2(){
    cl[0] = cl[1] = 0;
    for(long i = 1; i <= n; i++) ge(i);
    if( abs( cl[1] - cl[0] ) % 11 == 0 ){
        long long res = 1;
        for(long i = 1; i <= n; i++) res = ( res * i ) % mod;
        cout << res << '\n';
    }
    else cout << 0 << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    cin >> test;
    bool ok1,ok2;
    while( test-- ){
        ok1 = true;
        ok2 = true;
        cin >> n;
        if( n > 9 ) ok1 = false;
        for(long i = 1; i <= n; i++){
            cin >> a[i];
            if( !get(a[i]) ) ok2 = false;
        }
        res = 0;
        if( ok1 ){
            dq(1);
            cout << res << '\n';
            continue;
        }
        if( ok2 ){
            sub2();
            continue;
        }
        cout << 0 << '\n';
    }
}
/*
1
4
7 1 7 2
*/
