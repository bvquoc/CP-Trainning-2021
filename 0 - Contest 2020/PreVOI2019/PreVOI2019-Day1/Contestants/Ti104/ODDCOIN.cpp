// Code by Nguyen Huu Lam
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;

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
#define hash Slient_voice

// #define ordered_set tree<LL, null_type, less<LL>, rb_tree_tag, tree_order_statistics_node_update>
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

LL Rand(LL l, LL h){
	return uniform_int_distribution<LL>(l, h)(rng);
}

template <typename T> void read(T &t){
	t = 0; char ch = getchar(); int f = 1;
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	do { (t *= 10) += ch - '0'; ch = getchar(); } while (isdigit(ch)); t *= f;
}

const LL MaxN = 1 + 2e7;

LL n, b[16] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000}, d[MaxN], x, t, a[16], ma;
pair<LL, LL> c[51];

namespace Subtask1{
    void Solve(){
        cin >> t;
        for(int te = 0 ; te < t ; ++te){
            cin >> x >> n;
            memcpy(a, b, sizeof b);
            a[15] = x;
            sort(a, a + 16);
            memset(d, 0x3f3f, sizeof d);
            d[0] = 0;
            // for(int i = 0 ; i < 16 ; ++i) cout << a[i] << " ";
            for(int i = 1 ; i <= n ; ++i)
            for(int j = 0 ; j < 16 ; ++j)
            if(a[j] > i) break;
            else d[i] = min(d[i], d[i - a[j]] + 1);
            cout << d[n] << endl;
        }
    }
}

void InOut(){
	#define TASK "ODDCOIN"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// Subtask1::Solve();
	cin >> t;
	for(int i = 0 ; i < t ; ++i){
        cin >> c[i].first >> c[i].second;
        ma = max(ma, c[i].second);
	}
	if(ma <= 1e5){
        Subtask1::Solve();
        return 0;
	}
    for(int te = 0 ; te < t ; ++te){
        LL x = c[te].first, n = c[te].second;
        memcpy(a, b, sizeof b);
        a[15] = x;
        sort(a, a + 16);
        memset(d, 0x3f3f, sizeof d);
        d[0] = 0;
        // for(int i = 0 ; i < 16 ; ++i) cout << a[i] << " ";
        for(int i = 1 ; i <= 1e6 ; ++i)
        for(int j = 0 ; j < 16 ; ++j)
        if(a[j] > i) break;
        else d[i] = min(d[i], d[i - a[j]] + 1);
        LL kq = 1e18;
        if(n <= 1e6){
            cout << d[n] << endl;
            continue;
        }
        for(int i = 0 ; i < 16 ; ++i)
        if(a[i] <= n){
            LL k = (n - LL(1e6)) / a[i] + 1;
            LL m = n - a[i] * k;
            if(m < 0){
                k--;
                m += a[i];
            }
            kq = min(kq, d[m] + k);
        }
        cout << kq << endl;
    }

	return 0;
}
