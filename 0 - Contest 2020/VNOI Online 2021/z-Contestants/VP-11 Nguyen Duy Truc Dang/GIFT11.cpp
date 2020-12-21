#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll , int> II;
typedef pair<double , double> DD;
const int N = 2e3 + 3;
const ll MOD = 998244353;
const ll INF = 1e18;
const int base = 251;
int n , a[N];
ll f[N][11];
II b[N];
ll fact[N];
II in4(int a){
  vector<int> vt;
  while(a > 0){
    vt.push_back(a % 10);
    a /= 10;
  }
  int ans = 0;
  reverse(vt.begin() , vt.end());
  for(int i = 0 ; i < vt.size() ; i ++){
    if(i % 2 == 0) ans += vt[i];
    else ans -= vt[i];
  }
  ans %= 11;
  return II(ans , vt.size());
}
void subtask1(){
    int ans = 0;
    int per[10];
    for(int i = 1 ; i <= n ; i ++) per[i] = i;
   do{
    vector<int> vt;
    for(int i = 1 ; i <= n ; i ++){
       vector<int> add;
       int x = a[per[i]];
       while(x > 0){
        add.push_back(x % 10);
        x /= 10;
       }
       reverse(add.begin() , add.end());
       for(int it : add) vt.push_back(it);
    }
    int val = 0;
    for(int i = 0 ; i < vt.size() ; i ++){
        if(i % 2 == 0) val += vt[i];
        else val -= vt[i];
    }
    ans += (val % 11 == 0);
   }while(next_permutation(per + 1 , per + 1 + n));
   cout << ans << "\n";
}
void subtask2(){
    int val = 0;
    for(int i = 1 ; i <= n ; i ++) val += b[i].first;
    if(val % 11 == 0) cout << fact[n] << endl;
    else cout << 0 << endl;
}
void subtask3(){
    f[0][0] = 1;
    for(int i = 1 ; i <= n ; i ++){
        for(int k = 0 ; k < 11 ; k ++){
            int nmod1 = (k - b[i].first + 11) % 11;
            int nmod0 = (k + b[i].first + 11) % 11;
            int mid = i / 2 + i % 2;
            f[i][k] += f[i - 1][nmod1] * mid;
            f[i][k] %= MOD;
            f[i][k] += f[i - 1][nmod0] * (i - mid);
            f[i][k] %= MOD;
        }
    }
    cout << f[n][0] << endl;
}
int main(){
    freopen("GIFT11.inp" , "r" , stdin);
    freopen("GIFT11.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1 ; i < N ; i ++) fact[i] = fact[i - 1] * i % MOD;
    int t;
    cin >> t;
    while(t --){
    cin >> n;
    bool check = true;
    for(int i = 1 ; i <= n ; i ++){
       cin >> a[i];
       b[i] = in4(a[i]);
       if(b[i].second % 2 == 1) check = false;
    }
    if(n <= 9) subtask1();
    else if(check) subtask2();
    else subtask3();
    }
    return 0;
}
