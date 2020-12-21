#include<bits/stdc++.h>
using namespace std;
const int maxN = 100005+7;
int n, m, k, l, city, s[maxN];
int waterlemon[1005][1005];
vector< vector< pair<int,int> > > adj(100005+7);
// Store with n <= 10
int a[1005][1005], L[1005];
int D, C, cnt = 0;
char Flag[1005];
void Input(){
    freopen("DHAKA.INP", "r", stdin);
    freopen("DHAKA.OUT", "w+", stdout);
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++i){
        cin >> s[i];
        if(s[i] == 1) city = i;
        for(int j = 1; j <= s[i]; ++j) cin >> waterlemon[i][j];
    }
    for(int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        if(n <= 25){
            a[u-1][v-1] = w;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}
int Path(int start, int finish){
    vector<int> cnt(100005+7, 0);
    typedef pair<int,int> T;
    priority_queue<T, vector<T>, greater<T> > q;
    q.push({0, start});
    while(!q.empty()){
        long long distance = q.top().first;
        long long top = q.top().second;
        q.pop();
        if(cnt[top] == 1)
            continue;
        ++cnt[top];
        if(top == finish){
            return distance;
        }
        for(int i = 0; i < adj[top].size(); ++i){
            q.push({distance+adj[top][i].second, adj[top][i].first});
        }
    }
    return -1;
}
void Init() {
    D = 0, C = n-1;
    for (int i = 0; i < n; i++) {
        Flag[i] = 0;
        L[i] = 0;
    }
    Flag[D] = 1;
    L[0] = D;
}
int min_cost = maxN;
void Show(int Vext) {
    cnt++;
    int cost = 0;
    for (int i = 0; i < Vext-1; i++){
        cost += a[L[i]][L[i+1]];
    }
    set<int> counting;
    for (int i = 0; i < Vext; i++){
        for(int j = 1; j <= s[L[i]+1]; j++)
            counting.insert(waterlemon[L[i]+1][j]);
    }
    if(counting.size() >= l){
        min_cost = min(cost, min_cost);
    }
}
void Find(int Vext){
    if(L[Vext-1] == C)
        Show(Vext);
    else{
        for(int i = 0; i < n; i++){
            if(a[L[Vext-1]][i] > 0 && Flag[i] == 0 ){
                L[Vext] = i;
                Flag[i] = 1;
                Find(Vext+1);
                L[Vext] = 0;
                Flag[i] = 0;
            }
        }
    }
}
void Sub1(){
    Init();
    Find(1);
    if(cnt == 0 || min_cost == maxN){
        cout << -1;
        exit(0);
    }
    cout << min_cost;
}
void Sub2(){
    int Path1 = Path(1, n);
    cout << Path1;
}
void Sub3(){
    int Path1 = Path(1, city);
    int Path2 = Path(city, n);
    if(Path1 * Path2 < 0){
        cout << -1;
        exit(0);
    }
    cout << Path1 + Path2;
}
main(){
    Input();
    if(l > k){
        cout<< -1;
        return 0;
    }
    if(l == 0){
        Sub2();
    }
    else if(k == 1 && l == 1){
        Sub3();
    }
    else{
        Sub1();
    }
}
