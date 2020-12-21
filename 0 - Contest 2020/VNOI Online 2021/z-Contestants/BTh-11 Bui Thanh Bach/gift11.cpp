#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353 ;
ll t;
ll n;
ll a[2005];
ll chan, le;
void inp(){
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    cin>>t;
}

ll sizee( ll val ){
    ll dem = 0;
    while( val > 0){
        dem++;
        val/=10;
    }
    return dem ;
}

void dem_c_l(ll val){
    //ll val = a[i];
    ll dem = 0;

    while( val> 0 ){
        dem++;
        if(dem % 2 == 0) chan += val%10;
        else le+= val%10;
        val/=10;
    }
    return ;
}


void sub1(){
    ll dem  = 0;
    for(ll i=1; i<=n; i++) cin>>a[i];
    do{
        ll res = 0;
        for(ll i=1; i<= n ; i++){
            res *= sizee(a[i]);
            res += a[i];
            res%=11;
        }
        if(res == 0 ) dem++;
    } while( next_permutation(a+1, a+n+1));
    cout<<dem % MOD << "\n";
}

int main()
{
    inp();
    while( t -- ){
        cin>>n;
        le = 0 , chan = 0;
        if( n <= 10 ) sub1();
        else{

            for(ll i=1; i<=n; i++) {
                cin>>a[i];
                dem_c_l(a[i]);
            }
            if( abs(le - chan) % 11 != 0 ) cout<< "0\n";
            else{
                ll res = 1;
                ll tmp =1 ;
                while(tmp <= n ){
                    res *= tmp;
                    res%=MOD;
                    tmp++;
                }
                cout<<res<<"\n";
            }
        }
    }
    return 0;
}
