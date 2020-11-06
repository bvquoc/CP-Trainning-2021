#include <bits/stdc++.h>
using namespace std;
long n,m,t,k;
long a[100005],b[100005],c[100005],d[100005];
int main(){
    cin >> n >> m >> t >> k;
    for(long i = 1; i <= n; i++){
        cin >> a[i];
        c[i] += a[i] + k - 1;
    }
    for(long i = 1; i <= m; i++){
        cin >> b[i];
        d[i] += b[i] + k - 1;
    }
    long res1 = a[1] - 0;
    long res2 = 0;
    long l = a[1];
    long type = 2;
    while( l < t ){
        if( type == 2 ){
            long tmp1 = lower_bound(b + 1, b + 1 + m, l) - b;
            tmp1--;
            long tmp2 = upper_bound(d + 1, d + 1 + m, l) - d;
            //cout << tmp1 << " " << tmp2 << " " << l << " ";
            if( tmp1 + 1 == tmp2 ){
                if( b[tmp2] >= t ){
                    res2 += t - l;
                    break;
                }
                else{
                    res2 += b[tmp2] - l;
                    //cout << b[tmp2] << " " << b[tmp2] - l << " " << res2 << endl;
                }
                l = b[tmp2];
            }
            else{
                if( b[tmp2] >= t ){
                    res2 += t - d[ tmp2 - 1 ];
                    break;
                }
                else{
                    res2 += b[tmp2] - d[tmp2 - 1] - 1;
                }
                l = b[tmp2];
            }
            //cout << res2 << endl;
            type = 1;
            continue;
        }
        else{
            long tmp1 = lower_bound(c + 1, c + 1 + n, l) - c;
            tmp1--;
            long tmp2 = upper_bound(a + 1, a + 1 + n, l) - a;
            //cout << tmp1 << " " << tmp2 << " " << l << " " << type << endl;
            if( tmp1 + 1 == tmp2 ){
                if( a[tmp2] >= t ){
                    res1 += t - l;
                    break;
                }
                else{
                    res1 += a[tmp2] - l;
                }
                l = a[tmp2];
            }
            else{
                if( a[tmp2] >= t ){
                    res1 += t - c[ tmp2 - 1 ];
                    break;
                }
                else{
                    res1 += a[tmp2] - c[tmp2 - 1] - 1;
                }
                l = a[tmp2];
            }
            type = 2;
            continue;
        }
    }
    cout << res1 << " " << res2;
}
