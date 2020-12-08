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
#define TASK "ODDCOIN"
const int M = 1e5+8;
const int oo = 1e9+7;
using namespace std;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int testCase, n;
long long x, t;
map <ll, int> Optm;

void _init(){
    Optm[1] = Optm[10] = Optm[100] = Optm[1000] = Optm[10000] = 1;
    Optm[2] = Optm[20] = Optm[200] = Optm[2000] = Optm[20000] = 2;
    Optm[3] = Optm[30] = Optm[300] = Optm[3000] = Optm[30000] = 1;
    Optm[4] = Optm[40] = Optm[400] = Optm[4000] = Optm[40000] = 2;
    Optm[5] = Optm[50] = Optm[500] = Optm[5000] = Optm[50000] = 1;
    Optm[6] = Optm[60] = Optm[600] = Optm[6000] = Optm[60000] = 2;
    Optm[7] = Optm[70] = Optm[700] = Optm[7000] = Optm[70000] = 3;
    Optm[8] = Optm[80] = Optm[800] = Optm[8000] = Optm[80000] = 2;
    Optm[9] = Optm[90] = Optm[900] = Optm[9000] = Optm[90000] = 3;
}

int _calc(long long a){
    if(a == 0)  return 0;
    if(Optm[a] != 0)    return Optm[a];
    int Dif = 0;  ll tmp = 1, Rest = 0;
    while(a > 0){
        int t = a % 10; a /= 10;
        if(t != 0){
            Rest += _calc(1LL * t * tmp);
            Dif++;
        }
        tmp *= 10;
    }
    if(Dif == 1) return Optm[a] = (a / 50000);
    return Optm[a] = Rest;
}

int main(int argc, char const *argv[]){
	// freopen("test.txt", "r", stdin);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios_base::sync_with_stdio(false);   cin.tie(0);
    _init();
    cin >> testCase;
    while(testCase--){
        cin >> x >> t;
        if(t < x){
            cout <<  _calc(t) << '\n';
            continue;
        }
        int Res = oo, Old = 0; bool New = false;
        if(Optm[x] != 1){
            if(Optm[x] != 0) Old = Optm[x];
            Optm[x] = 1;
            New = true;
        }
        for(int i = 0; x * i <= t; i++){
            ll Left = x * i, Right = t - Left;
            Res = min(Res, i + _calc(Right));
        }
        if(New) Optm[x] = Old;
        cout << Res << '\n';
    }
	return 0; 
}