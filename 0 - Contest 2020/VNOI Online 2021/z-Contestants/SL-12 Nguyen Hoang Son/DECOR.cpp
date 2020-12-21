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

//DECOR
int n, m, k;
int bitt1[500005];
//DSU
int pa[500005], cntbit1[500005];
int root(int u){
    if(pa[u] < 0) return u;
    return pa[u] = root(pa[u]);
}
bool unco(int u, int v){
    int pu = root(u), pv = root(v);
    if(pu == pv) return false;
    if(pa[pu] > pa[pv]) swap(pu, pv);
    pa[pu] += pa[pv];
    pa[pv] = pu;
    return true;
}
//Check ok mid
bool avail[500005], nousef[500005];
vector<int> vt[500005];
pii res = {0, 0};
bool check(int mid){
    for(int i = 1; i<=n; i++){
        avail[i] = false;
        vt[i].clear();
        cntbit1[root(i)] = 0;
        nousef[i] = false;
    }
    for(int i = 1; i<=n; i++) cntbit1[root(i)] += bitt1[i];
    int cntbi = 0;
    for(int i = 1; i<=n; i++){
        if(cntbit1[root(i)] > 0){
            cntbit1[root(i)]--;
            avail[i] = true;
            cntbi++;
        } else {
            avail[i] = false;
            vt[root(i)].push_back(i);
        }
        if(i >= mid){
            if(mid - cntbi <= k){
                res = {i - mid + 1, i};
                return true;
            }
        }
        if(i > mid){
            int v = i - mid;
            if(avail[v]){
                cntbi--;
                avail[v] = false;
                cntbit1[root(v)]++;
                while(vt[root(v)].size() > 0){
                    if(nousef[vt[root(v)].back()]){
                        vt[root(v)].pop_back();
                        continue;
                    }
                    cntbit1[root(v)]--;
                    cntbi++;
                    avail[vt[root(v)].back()] = true;
                    vt[root(v)].pop_back();
                    break;
                }
            } else {
                nousef[v] = true;
            }
        }
    }
    return false;
}
//Main process
string s;
void process(){
    cin >> n >> m >> k;
    cin >> s;
    for(int i = 1; i<=n; i++) bitt1[i] = (s[i - 1] - '0');
    for(int i = 1; i<=n; i++) pa[i] = -1;
    for(int i = 1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        unco(u, v);
    }
    int l = 1, r = n, ans = 0;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }
    if(ans == 0){
        cout << -1;
    } else {
        cout << res.F << " " << res.S;
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
        freopen("DECOR.inp","r", stdin);
        freopen("DECOR.out","w", stdout);
    }
    //times
    process();
    //gettime
    return 0;
}