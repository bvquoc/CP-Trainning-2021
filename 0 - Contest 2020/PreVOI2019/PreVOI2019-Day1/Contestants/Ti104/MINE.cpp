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

const LL MaxN = 1 + 1e6, MOD = 3 + 1e6;

LL n, a[MaxN], d[MaxN], m, gt[MaxN];

LL Mu(LL a, LL n){
    if(n == 0) return 1;
    LL tg = Mu(a, n / 2);
    if(n % 2) return (((tg * tg) % MOD) * a) % MOD;
    return (tg * tg) % MOD;
}

LL Calc(LL n){
    LL k = n / 2;
    LL x = (((gt[k] * gt[n - k]) % MOD) * (k + 1)) % MOD;
    return (gt[n] * Mu(x, MOD - 2)) % MOD;
}

void InOut(){
	#define TASK "MINE"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	n *= 2;
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	gt[0] = 1;
	for(int i = 1 ; i <= n ; ++i) gt[i] = (gt[i - 1] * i) % MOD;
	if(m == 1000000){
	    cout << Calc(n) << endl;
        return 0;
	}
	d[0] = 1;
	// cout << Calc(4) << endl;
	for(int i = 1 ; i <= n ; ++i){
        LL j = i - 1;
        if(a[i] - a[j] > m) continue;
        while(j > 0 && a[i] - a[j] <= m) j -= 2;
        j += 2;
        d[i] = d[j - 1] * Calc(i - j + 1);
	}
	cout << d[n] << endl;

	return 0;
}
