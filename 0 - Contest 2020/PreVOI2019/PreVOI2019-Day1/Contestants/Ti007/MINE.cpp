// @___justkiddin
#include <bits/stdc++.h>
#define ll long long
#define Pii pair<int, int>
#define Piii pair<int, Pii>
#define _mp make_pair
#define _pb push_back
#define st first
#define nd second
#define whole(x) x.begin(), x.end()
#define Reset(x) memset(x, 0, sizeof(x))
#define PI acos(-1)
#define TASK "MINE"
const int M = 2e5+8;
const int oo = 1e9+7;
const int MOD = 1000003;
using namespace std;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int n, m, a[M];

int _calc(int l, int r){
    if(l >= r) return 0; 

    if(a[r] - a[l] > m){
        int Mid = upper_bound(a+l, a+r+1, a[l] + m) - a - 1;
        if(Mid == l)    return 0;

        int Between = Mid - l - 1;
        if(Between >= 1 && Between % 2) Mid--;

        int tmp = 0;
        for(int i = l+1; i <= Mid; i += 2) tmp = (tmp + (1LL * _calc(l, i) * _calc(i+1, r)) % MOD) % MOD;
        return tmp;

        // return (1LL * _calc(l, Mid) * _calc(Mid+1, r)) % MOD;
    }

    if((r - l - 1) % 2) return 0;
    if(l == r-1) return 1;
    if(l == r-3) 
        if(l == 1 || r == n*2) return 1;
        else return 2;

    int tmp = 0;
    for(int i = l+1; i <= r-1; i += 2) tmp = (tmp + (1LL * _calc(l, i) * _calc(i+1, r)) % MOD) % MOD;
    tmp = (tmp + _calc(l+1, r-1)) % MOD;
    return tmp;
}

// int _getRes(int l, int r){
//     if(l >= r) return 0;
//     if(l + 1 == r && a[l] + m <= a[r]) return 1;
//     if(l + 3 == r && a[l] + m <= a[r]) return 1;
//     int Res = 0;
//     for(int i = l+1; i <= r-1; i+=2)
//         Res = (Res + (1LL * _calc(l, i) * _calc(i+1, r)) % MOD) % MOD;
//     return Res;
// }

int main(int argc, char const *argv[]){
	// freopen("test.txt", "r", stdin);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n*2; i++) cin >> a[i];
    // int Res = _getRes(1, n*2);
    int Res = _calc(1, n*2);
    if(Res > 1) Res ++;
    cout << Res;
	return 0; 
}