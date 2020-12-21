#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll , int> II;
typedef pair<double , double> DD;
const int N = 5e5 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int base = 251;
int n , m , k , cnt , par[N] , sz[N] , u , v , ans , L , R;
string s;
int get(int a){
   if(a != par[a]) par[a] = get(par[a]);
   return par[a];
}
void unite(int a , int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a , b);
    par[b] = a;
    sz[a] += sz[b];
}
void subtask1(){
   for(int i = 1 ; i <= n ; i ++){
    cnt = 0;
    if(s[i] == '0') continue;
    int pos = i;
    while(s[pos] == '1' && pos <= n) cnt ++ , pos ++;
    pos --;
    if(cnt > ans) L = i , R = pos;
    i = pos;
    ans = max(ans , cnt);
   }
   if(!L) cout << -1 << endl;
   else cout << L << " " << R << endl;
}
void subtask2(){
    int l = 1 , r = n , pos;
    while(l <= r){
        int mid = l + r >> 1 , cnt = 0;
        bool ok = false;
        for(int i = 1 ; i <= mid ; i ++) cnt += (s[i] == '1');
        if(cnt + k >= mid) ok = true , pos = 1;
        else{
            for(int i = 2 ; i <= n - mid + 1 ; i ++){
                cnt -= (s[i - 1] == '1');
                cnt += (s[i + mid - 1] == '1');
                if(cnt + k >= mid){
                    pos = i;
                    ok = true;
                    break;
                }
            }
        }
        if(ok) ans = mid , l = mid + 1;
        else r = mid - 1;
    }
    if(ans == 0){
        cout << -1 << endl;
        return;
    }
    cout << pos << " " << pos + ans - 1 << endl;
}
bool ck(int l , int r){
    int cnt = 0 , d = k;
    vector<int> f(n + 1 , 0);
    for(int i = 1 ; i < l ; i ++) if(s[i] == '1') f[get(i)] ++;
    for(int i = r + 1 ; i <= n ; i ++) if(s[i] == '1') f[get(i)] ++;
    for(int i = l ; i <= r ; i ++){
        if(s[i] == '0'){
            if(f[get(i)]) f[get(i)] --;
            else if(d) d --;
            else return false;
        }
    }
    return true;
}
void subtask3(){
    int l = 1 , r = n , pos = 0 , ans = 0;
    while(l <= r){
        bool ok = false;
        int mid = l + r >> 1;
        for(int i = 1 ; i <= n - mid + 1 ; i ++){
            if(ck(i , i + mid - 1)){
                ok = true;
                pos = i;
                break;
            }
        }
        if(ok) ans = mid , l = mid + 1;
        else r = mid - 1;
    }
    if(!ans){
        cout << -1 << endl;
        return;
    }
    cout << pos << " " << pos + ans - 1 << endl;
}
int main(){
    freopen("DECOR.inp" , "r" , stdin);
    freopen("DECOR.out" , "w" , stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> s;
    for(int i = 1 ; i <= n ; i ++) par[i] = i , sz[i] = 1;
    s = ' ' + s;
    for(int i = 1 ; i <= m ; i ++){
        cin >> u >> v;
        unite(u , v);
    }
    if(m == 0 && k == 0) subtask1();
    else if(m == 0) subtask2();
    else subtask3();
    return 0;
}
