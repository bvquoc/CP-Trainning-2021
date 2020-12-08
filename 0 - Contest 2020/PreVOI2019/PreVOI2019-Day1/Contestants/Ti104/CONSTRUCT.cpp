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

const LL MaxN = 1 + 1e3;

LL n, a[MaxN], b[MaxN], x, y, z, q, query, t;

LL Solve(LL x, LL y){
    LL kq = 0;
    memcpy(b, a, sizeof a);
    while(1){
        LL mi = 1e18;
        LL pos = x, start = -1;
        while(pos <= y){
            if(b[pos] == 0 && mi != 1e18) break;
            if(b[pos] == 0){
                pos++;
                continue;
            }
            if(start == -1) start = pos;
            mi = min(mi, b[pos]);
            pos++;
        }
        if(start == -1) break;
        kq += mi;
        for(int i = start ; i < pos ; ++i) b[i] -= mi;
        /*for(int i = 0 ; i < n ; ++i) cout << b[i] << " ";
        cout << endl;*/
    }
    return kq;
}

void InOut(){
	#define TASK "CONSTRUCT"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int te = 0 ; te < t ; ++te){
        cin >> n >> q;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int quest = 0 ; quest < q ; ++quest){
            cin >> query;
            if(query == 1){
                cin >> x >> y >> z;
                x--;
                y--;
                for(int i = x ; i <= y ; ++i) a[i] += z;
                continue;
            }
            cin >> x >> y;
            x--;
            y--;
            cout << Solve(x, y) << endl;
        }
	}
	// cout << Solve(1, 5) << endl;

	return 0;
}
