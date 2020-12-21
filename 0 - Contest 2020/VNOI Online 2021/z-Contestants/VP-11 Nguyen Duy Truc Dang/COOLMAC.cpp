#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int , int> II;
typedef pair<double , double> DD;
const int N = 1e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 251;
int m , n , t[N] , ans;
II p[N];
bool cmp(II a , II b){
    return a.second > b.second || (a.second == b.second && a.first > b.first);
}
int main(){
    freopen("COOLMAC.inp" , "r" , stdin);
    freopen("COOLMAC.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m;
    for(int i = 1 ; i <= m ; i ++) cin >> p[i].first >> p[i].second;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> t[i];
    sort(p + 1 , p + 1 + m , cmp);
    if(p[1].second < 100000){
        cout << -1 << endl;
        return 0;
    }
    sort(t + 1 , t + 1 + n , greater<int> ());
    priority_queue<int> pq;
    int cur = 100000;
    bool ok = false;
    for(int i = 1 ; i <= m ;){
        bool check = false;
        int tmp = cur;
        while(p[i].second >= tmp && i <= m){
           cur = min(cur , p[i].first);
           i ++;
           check = true;
        }
        ans ++;
        if(!check){
            cout << -1 << endl;
            return 0;
        }
        if(cur <= t[n]){
            ok = true;
            break;
        }
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}
