#include <bits/stdc++.h>
using namespace std;
const long mod = 1e9 + 7;
long n,a[200005],b[200005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    cin >> n;
    bool ok1 = true, ok2 = true;
    for(long i = 1; i <= n; i++) cin >> a[i];
    for(long i = 1; i <= n; i++) cin >> b[i];
    for(long i = 1; i <= n; i++) if( a[i] != b[i] ) ok1 = false;
    if( ok1 ){
        long cnt = 0;
        for(long i = 1; i <= n; i++){
            for(long j = i; j <= n; j++){
                if( a[j] == i ){
                    for(long k = j; k > i; k--){
                        swap(a[k],a[k-1]);
                        cnt++;
                    }
                    break;
                }
            }
        }
        cout << cnt;
        return 0;
    }
}
