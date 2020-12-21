// Date created: "07:57:00, 18-12-2020"
// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long LL;
typedef pair<LL, LL> II;

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

const LL MaxN = 1 + 1e5;

LL n, mi = 1e5, m, ans;
II a[MaxN];
vector<LL> used;

namespace Subtask3{
    void Solve(){
        sort(a, a + n, [&](const II &x, const II &y){return x.first == y.first ? x.second > y.second : x.first < y.first; });
        // for(int i = 0 ; i < n ; ++i) cout << a[i].first << " " << a[i].second << endl;
        LL ma = mi;
        for(int i = 0 ; i < n ; ++i)
        if(a[i].first > ma){
            cout << -1 << endl;
            return;
        }
        else{
            if(a[i].first <= mi){
                ma = max(ma, a[i].second);
                continue;
            }
            else{
                if(ma == 1e5) break;
                ans++;
                mi = ma;
                ma = max(ma, a[i].second);
            }
        }
        if(ma != 1e5) cout << -1 << endl;
        else cout << ans + 1 << endl;
    }
}

namespace Subtask1{
    void Check(){
        if(used.size() == 0) return;
        vector<LL> temp(used.begin(), used.end());
        sort(temp.begin(), temp.end(), [&](const LL &x, const LL &y){return a[x].first == a[y].first ? a[x].second > a[y].second : a[x].first < a[y].first;});
        if(a[temp[0]].first > mi) return;
        LL ma = a[temp[0]].second;
        for(int i = 0 ; i < temp.size() ; ++i)
        if(a[temp[i]].first > ma) return;
        else ma = max(ma, a[temp[i]].second);
        if(ma == 1e5){
            if(!ans) ans = temp.size();
            else ans = min(ans, LL(temp.size()));
        }
    }

    void Try(LL id){
        if(id == n){
            Check();
            return;
        }
        Try(id + 1);
        used.push_back(id);
        Try(id + 1);
        used.pop_back();
    }

    void Solve(){
        Try(0);
        Check();
        if(ans == 0) cout << -1 << endl;
        else cout << ans << endl;
    }
}

void InOut(){
    #define TASK "COOLMAC"
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
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i].first >> a[i].second;
    cin >> m;
    for(int i = 0 ; i < m ; ++i){
        LL x;
        cin >> x;
        mi = min(mi, x);
    }
    if(n <= 10 && m <= 16) Subtask1::Solve();
    else Subtask3::Solve();

    return 0;
}