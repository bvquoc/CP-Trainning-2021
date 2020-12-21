// Date created: "09:16:25, 18-12-2020"
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

const LL MaxN = 1 + 1e5, MOD = 998244353;

LL t, n, ans, mark[MaxN];
vector<LL> a, used;
pair<LL, LL> b[MaxN];

pair<LL, LL> Calc(LL k){
    LL sum = 0, cnt = 0;
    while(k){
        if(cnt % 2) sum += k % 10;
        else sum -= k % 10;
        cnt++;
        k /= 10;
    }
    if(cnt % 2) sum *= -1;
    return {sum, cnt};
}

namespace Subtask1{
    void Check(){
        LL total = 1, sum = 0;
        for(int i = 0 ; i < n ; ++i){
            if(total % 2) sum += b[used[i]].first;
            else sum -= b[used[i]].first;
            total += b[used[i]].second;
        }
        if(abs(sum) % 11 == 0) ans++;
    }

    void Try(LL id){
        if(id == n){
            Check();
            return;
        }
        for(int i = 0 ; i < n ; ++i)
        if(!mark[i]){
            mark[i] = 1;
            used.push_back(i);
            Try(id + 1);
            mark[i] = 0;
            used.pop_back();
        }
    }

    void Solve(){
        Try(0);
        cout << ans << endl;
    }
}

namespace Subtask2{
    void Solve(){
        LL sum = 0;
        for(int i = 0 ; i < n ; ++i) sum += b[i].first;
        if(abs(sum) % 11 == 0){
            LL ans = 1;
            for(int i = 1 ; i <= n ; ++i) ans = (ans * i) % MOD;
            cout << ans << endl;
        }
        else cout << 0 << endl;
    }
}


void Solve(){
    cin >> n;
    a.resize(n, 0);
    ans = 0;
    LL cnt = 0;
    for(int i = 0 ; i < n ; ++i){ 
        cin >> a[i]; 
        b[i] = Calc(a[i]);
        if(b[i].second % 2 == 0) cnt++;
    }
    // for(int i = 0 ; i < n ; ++i) cout << b[i].first << " " << b[i].second << endl;
    if(cnt == n) Subtask2::Solve();
    else Subtask1::Solve();
}

void InOut(){
    #define TASK "GIFT11"
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
    cin >> t;
    while(t--) Solve();

    return 0;
}