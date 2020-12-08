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

const LL MaxN = 1 + 1e6;

LL n, a[MaxN], query, nxt[27];
vector<pair<LL, LL> > change;
char ch, ch1, ch2;
string s;

inline LL getNext(LL u){
    if(u == nxt[u]) return u;
    return nxt[u] = getNext(nxt[u]);
}

void InOut(){
	#define TASK "PAINT"
	freopen(TASK".inp","r",stdin);
	freopen(TASK".out","w",stdout);
}

void Subtask1(){
    for(int i = 0 ; i < n ; ++i){
        cin >> query;
        if(query == 1){
            cin >> ch;
            s += ch;
            continue;
        }
        LL m = s.length();
        cin >> ch1 >> ch2;
        for(int i = 0 ; i < m ; ++i)
        if(s[i] == ch1) s[i] = ch2;
	}
	cout << s << endl;
}

void Subtask2(){
    for(int i = 0 ; i < n ; ++i){
        cin >> query;
        if(query == 1){
            cin >> ch;
            change.push_back({-1, ch - 'a'});
            continue;
        }
        cin >> ch1 >> ch2;
        change.push_back({ch1 - 'a', ch2 - 'a'});
	}
	for(int i = 0 ; i < 26 ; ++i) nxt[i] = i;
	for(int i = change.size() - 1 ; i >= 0 ; --i)
    if(change[i].first == -1){
        LL temp = getNext(change[i].second);
        s = char(temp + 'a') + s;
    } else{
        nxt[change[i].first] = change[i].second;
    }
    cout << s << endl;
}

int main(){
	InOut();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if(n <= 1e4) Subtask1();
	else Subtask2();

	return 0;
}
