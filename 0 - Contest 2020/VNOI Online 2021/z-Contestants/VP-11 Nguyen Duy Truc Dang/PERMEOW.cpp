#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll , int> II;
typedef pair<double , double> DD;
const int N = 2e5 + 3;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 251;
int n;
vector<int> a , b;
ll fact[N] , f[N];
ll ans = 0;
void subtask1(){
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j < i ; j ++){
            ans += (a[i] < a[j]);
        }
    }
    cout << ans << endl;
}
void subtask2() {
    fact[0] = fact[1] = fact[2] = 1;
    for (int i = 3 ; i <= n ; ++i) fact[i] = fact[i - 1] * i % MOD;
    f[5] = 5;
    int cur = 2;
    for (int i = 6 ; i <= n ; ++i){
        cur ++ ;
        f[i] = (i + f[i - 1] - i + 1 + cur);
    }
    for (int i = 1 ; i <= n ; ++i) f[i] += i ;
    cout << (f[n] % MOD) * fact[n] % MOD << endl;
}
int main(){
    freopen("PERMEOW.inp" , "r" , stdin);
    freopen("PERMEOW.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    a = b = vector<int> (n + 1);
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    for(int j = 1 ; j <= n ; j ++) cin >> b[j];
    if(a == b) subtask1();
    else if(n <= 8){
        do{
           for(int i = 1 ; i <= n ; i ++){
              for(int j = 1 ; j < i ; j ++){
                 ans += (a[i] < a[j]);
                 ans %= MOD;
              }
          }
          if(a == b) break;
        }while(next_permutation(a.begin() + 1 , a.end()));
        cout << ans << endl;
    }
    else subtask2();
    return 0;
}
