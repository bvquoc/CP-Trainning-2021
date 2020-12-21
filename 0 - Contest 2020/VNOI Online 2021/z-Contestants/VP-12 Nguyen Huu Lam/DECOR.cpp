// Date created: "15:04:38, 18-12-2020"
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

#define y0 Sword_Art_Online
#define y1 Your_lie_in_April
#define yn Darling_in_the_Franxx
#define tm Plastic_Memories
#define lr Charlotte
#define norm Weathering_with_you
#define left Violet_Evergarden
#define have Date_a_live
#define ends Your_name
#define prev Five_centimeters_per_second
#define hash Silent_voice
#define endl "\n"

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
    return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
    t = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 5e5;

LL n, m, k;
string s;

namespace Subtask1{
    void Solve(){
        LL ans = 0, cnt = 0;
        pair<LL, LL> pos;
        for(int i = 0 ; i < n ; ++i)
        if(s[i] == '1') cnt++;
        else{
            if(cnt > ans){
                ans = cnt;
                pos = {i - cnt + 1, i};
            }
            cnt = 0;
        }
        if(!ans) cout << -1 << endl;
        else cout << pos.first + 1 << " " << pos.second + 1 << endl;
    }
}

namespace Subtask2{

    LL d[MaxN];
    pair<LL, LL> pos;

    bool Check(LL val){
        for(int i = 1 ; i <= n - val + 1 ; ++i)
        if(d[i + val - 1] - d[i - 1] <= k) return 1;
        return 0;
    }

    void Solve(){
        s = " " + s;
        for(int i = 1 ; i <= n ; ++i) d[i] = d[i - 1] + (s[i] == '0');
        LL l = 1, r = n;
        while(l < r){
            LL tg = (l + r + 1) / 2;
            if(Check(tg)) l = tg;
            else r = tg - 1; 
        }
        for(int i = 1 ; i <= n - l + 1 ; ++i)
        if(d[i + l - 1] - d[i - 1] <= k){
            cout << i << " " << i + l - 1 << endl;
            break;
        }
    }
}

namespace Subtask3{

    LL root[MaxN], sz[MaxN], mark[MaxN], cnt[MaxN], ans;
    vector<LL> roots;
    pair<LL, LL> pos;
    map<LL, LL> d[MaxN];

    inline LL getRoot(LL u){
        return root[u] == u ? u : root[u] = getRoot(root[u]);
    }
    
    void Solve(){
        iota(root + 1, root + n + 1, 1);
        s = " " + s;
        for(int i = 1 ; i <= n ; ++i) sz[i] = (s[i] == '1'), cnt[i] = cnt[i - 1] + (s[i] == '1');
        for(int i = 0 ; i < m ; ++i){
            LL x, y;
            cin >> x >> y;
            LL ru = getRoot(x), rv = getRoot(y);
            if(ru == rv) continue;
            if(ru < rv) swap(ru, rv);
            sz[rv] += sz[ru];
            sz[ru] = 0;
            root[ru] = rv;
        }
        for(int i = 1 ; i <= n ; ++i){
            LL ru = getRoot(i);
            if(!mark[ru]){
                mark[ru] = 1;
                roots.push_back(ru);
            }
        }
        for(int i = 1 ; i <= n ; ++i){
            for(int j : roots) d[i][j] = d[i - 1][j];
            d[i][getRoot(i)]++;
        }
        LL i = 1, j = 1;
        for(; i <= n ; ++i)
        for(; j <= n ; ++j){
            LL total = 0;
            for(int r : roots) total += min(d[j][r] - d[i - 1][r], sz[r]);
            if(total + k >= j - i + 1){
                if(j - i + 1 > ans){
                    ans = j - i + 1;
                    pos = {i, j};
                }
            }
            else break;
        }
        if(ans == 0) cout << -1 << endl;
        else cout << pos.first << " " << pos.second << endl;
    }
}

void InOut(){
    #define TASK "DECOR"
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    cin >> s;
    if(k == 0 && m == 0) Subtask1::Solve();
    else if(m == 0) Subtask2::Solve();
    else Subtask3::Solve();

    return 0;
}