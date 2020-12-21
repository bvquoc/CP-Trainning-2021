#include <bits/stdc++.h>

#define elif else if
#define ii pair<int,int>
#define pb push_back
#define int long long
#define FOR(i , a , b , c) for(int i = (a) ; i <= (b) ; i += (c))
#define FORD(i , a , b , c) for(int i = (a) ; i >= (b) ; i -= (c))
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const int N = 1e5 + 1;
const int mod = 1e9 + 7;

int n , a[N] , b[N];

void sub1() {
    int res = 0;
    FOR(i , 1 , n , 1) 
        FOR(j , 1 , n , 1) 
            if(a[i] < a[j]) {
                ++res;
                swap(a[i] , a[j]);
                if(res >= mod) res -= mod;
            }

    cout << res;
    
}

main() {
    freopen("PERMEOW.inp" , "r" , stdin);
    freopen("PERMEOW.out" , "w" , stdout);
    FASTIO;

    cin >> n ;

    FOR(i , 1 , n , 1) 
        cin >> a[i];
    
    int check = 0;

    FOR(i , 1 , n , 1) {
        cin >> b[i];
        if(a[i] != b[i]) check = 1;
    }

    if(check == 0) sub1();
    

    return 0;
}