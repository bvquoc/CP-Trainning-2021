// Date created: "15:47:45, 18-12-2020"
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

const LL MaxN = 1 + 2e5, MOD = 1e9 + 7;

LL n, a[MaxN], b[MaxN];

namespace Subtask1{

    ordered_set<LL> s;

    void Solve(){
        LL ans = 0;
        for(int i = 1 ; i <= n ; ++i){
            ans += s.order_of_key(-a[i]);
            s.insert(-a[i]);
        }
        cout << ans << endl;
    }
}

namespace Subtask2{

    LL Pow(LL n, LL k) {
        if (k == 0) return 1;
        LL v = Pow(n, k / 2);
        if (k % 2) return v * v % MOD * n % MOD;
        return v * v % MOD;
    }

    LL gt[MaxN];

    void Solve() {
        gt[0] = 1;
        for (int i = 1; i <= n; ++i) {
            gt[i] = gt[i - 1] * i;
            gt[i] %= MOD;
        }
        LL ans;
        ans = 1LL * n * (n - 1) * gt[n] % MOD * Pow(4, MOD - 2) % MOD;
        cout << ans << endl;
    }

}

void InOut(){
    #define TASK "PERMEOW"
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
    LL cnt = 0;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int i = 1 ; i <= n ; ++i) cin >> b[i], cnt += (a[i] == b[i]);
    if(cnt == n) Subtask1::Solve();
    else Subtask2::Solve();

    return 0;
}