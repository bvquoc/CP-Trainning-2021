#define TASK "PERMEOW"
#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ENDL "\n"
using namespace std;

const int MAX = 1e5+6;
const long long MOD = 1e9+7;

int n;
long long res, BIT[MAX];
vector<int> a;
vector<int> b;

bool Check(){
    for(int i=0; i < n; i++){
        if (a[i]!=b[i]) return false;
    }
    return true;
}

void Update(int x){
    for(; x > 0; x-=x&-x) BIT[x]++, BIT[x]%= MOD;
}

long long getBit(int x){
    long long res = 0;
    for(; x <=n; x+=x&-x) res+= BIT[x], res%= MOD;
    return res;
}

void Calc(){
    for(int i=0; i <= n; i++){
        BIT[i] = 0;
    }
    for(int i=0; i < n; i++){
        res+= getBit(a[i]);
        res%= MOD;
        Update(a[i]);
    }
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#ifndef ONLINE_JUDGE
	    //freopen("input.txt","r",stdin);
		freopen(TASK".INP","r", stdin);
		freopen(TASK".OUT","w", stdout);
	#endif

    cin >> n;
    a.resize(n); b.resize(n);
    for(int i=0; i < n; i++) cin >> a[i];
    for(int j=0; j<n; j++) cin >> b[j];

    int bad = false;
    while (1){
        if (Check()) bad = true;
        Calc();
        next_permutation(a.begin(), a.end());
        if (bad) break;
    }
    cout << res;
	return 0;
}
