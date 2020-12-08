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
#define TASK "MOTION"
const int M = 1e5+8;
const int oo = 1e9+7;
using namespace std;

// mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int t, n, m, xa, ya, xb, yb, xc, yc, xd, yd;

Pii _calc(){
    int Va = (xb - xa)*(xb - xa) + (yb - ya)*(yb - ya);
    int Vb = (xd - xc)*(xd - xc) + (yd - yc)*(yd - yc);
    int Sum = Va + Vb;
    int Mom = -1, Son = -1;
    if(Va == Vb) Mom = 2;
    int Rand = rand() % (m*n);
    Son = Rand;
    return {Son, Mom};
}

int main(int argc, char const *argv[]){
	// freopen("test.txt", "r", stdin);
	freopen(TASK".inp", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ios_base::sync_with_stdio(false);   cin.tie(0);
    srand(time(NULL));

    cin >> t;
    while(t--){
        cin >> n >> m >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        // cout << _calc() << '\n';
        Pii Res = _calc();
        if(Res.st == -1 || Res.nd == -1) cout << "-1\n";
        else 
            cout << Res.st << ' ' << Res.nd << '\n';
    }
	return 0; 
}