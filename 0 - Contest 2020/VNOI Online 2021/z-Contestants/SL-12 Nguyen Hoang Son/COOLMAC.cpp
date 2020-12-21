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
const ll mod = 1000000007;
//-std=gnu++17 -Wall

//COOLMAC
int m, n;
pii suid[100005];
int t;
void process(){
    cin >> m;
    for(int i = 1; i<=m; i++){
        int l, r;
        cin >> l >> r;
        suid[i] = {l, r};
    }
    cin >> n;
    t = 100000;
    for(int i = 1; i<=n; i++){
        int val;
        cin >> val;
        t = min(t, val);
    }
    //Sort
    sort(suid + 1, suid + m + 1, [](pii &ax, pii &bx){
        if(ax.S != bx.S) return ax.S > bx.S;
        return ax.F < bx.F;
    });
    //Process
    int lt = 100000;
    bool ok = true;
    int res = 0;
    int minf = 100001;
    for(int i = 1; i<=m; i++){
        if(suid[i].S>=lt){
            minf = min(minf, suid[i].F);
        } else {
            if(minf == 100001){
                ok = false;
                break;
            } else {
                lt = minf;
                minf = 100001;
                res++;
                if(lt <= t) break;
                i--;
            }
        }
    }
    if(lt > t){
        if(minf == 100001){
            ok = false;
        } else {
            lt = minf;
            res++;
        }
    }
    if(lt > t) ok = false;
    //Print
    if(!ok){
        cout << -1;
    } else cout << res;
}
int online = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(online == 0){
        freopen("in.inp","r", stdin);
        freopen("out.out","w", stdout);
    } else if(online == 1){
        freopen("COOLMAC.inp","r", stdin);
        freopen("COOLMAC.out","w", stdout);
    }
    //times
    process();
    //gettime
    return 0;
}