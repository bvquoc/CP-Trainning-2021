//Hoang Son WIBU lolicon codeforces rate 1439 khong cay
#include <bits/stdc++.h>
#define F first
#define S second
#define times double stime = clock();
#define gettime cerr << "\nTime executed: " << (clock() - stime) / CLOCKS_PER_SEC * 1000 << "ms.\n";
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll mod = 998244353;
//-std=gnu++17 -Wall

//SOCKS
int n, q, cnt = 0;
bool stas[500005];
vector<int> ed[500005];
void sub1(){
    cout << (cnt > 1 ? 1 : 0) << "\n";
    while(q--){
        int u;
        cin >> u;
        if(!stas[u]){
            cnt++;
            stas[u] = true;
        } else {
            cnt--;
            stas[u] = false;
        }
        cout << (cnt > 1 ? 1 : 0) << "\n";
    }
}
int ans = 1;
bool dfs(int u, int p){
    bool ok = stas[u];
    int cnted = 0;
    for(int v: ed[u]){
        if(v != p){
            if(dfs(v, u)){
                ok = true;
                cnted++;
            }
        }
    }
    if(stas[u] && cnted == 0){
        ans++;
    }
    return ok;
}
int countLeaf(){
    if(cnt < 2) return 0;
    ans = 1;
    for(int i = 1; i<=n; i++){
        if(stas[i]){
            dfs(i, i);
            break;
        }
    }
    return (ans/2 + ans%2);
}
void sub3(){
    cout << countLeaf() << "\n";
    while(q--){
        int u;
        cin >> u;
        if(!stas[u]){
            cnt++;
            stas[u] = true;
        } else {
            cnt--;
            stas[u] = false;
        }
        cout << countLeaf() << "\n";
    }
}
void process(){
    cin >> n >> q;
    for(int i = 1, val; i<=n; i++){
        cin >> val;
        if(val == 1){
            stas[i] = true;
            cnt++;
        }
    }
    bool oksub1 = true;
    for(int i = 1; i<n; i++){
        int u, v;
        cin >> u >> v;
        ed[u].push_back(v);
        ed[v].push_back(u);
        if(ed[u].size() > 2 || ed[v].size() > 2){
            oksub1 = false;
        }
    }
    if(oksub1){
        sub1();
    } else {
        sub3();
    }
}
int online = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(online == 0){
        freopen("in.inp","r", stdin);
        freopen("out.out","w", stdout);
    } else if(online == 1){
        freopen("SOCKS.inp","r", stdin);
        freopen("SOCKS.out","w", stdout);
    }
    //times
    process();
    //gettime
    return 0;
}