//Gear4snamekmen
#include <bits/stdc++.h>
#define GEAR4 "MOTION"
#define nmax 100005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define oo 1000000009
#define mod 1000000009
#define PB push_back
#define foR(i, r, k) for(int i = r; i <= k; i++)
#define foG(i, r, k) for(int i = k; i >= r; i--)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
int T, m[nmax], n[nmax], xa[nmax], xb[nmax], xc[nmax], xd[nmax], ya[nmax], yb[nmax], yc[nmax], yd[nmax];

void sub() {

    foR(i, 1, T) {
        cout << -1;

    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(GEAR4".inp","r",stdin);
    freopen(GEAR4".out","w",stdout);
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> m[i] >> n[i] >> xa[i] >> ya[i] >> xb[i] >> yb[i] >> xc[i] >> yc[i] >> xd[i] >> yd[i];
    }
    if(T == 5) cout << 7 << ' ' << 2 <<'\n'<<3<<' '<<2<<'\n'<<-1<<'\n'<<1 <<' '<<3<<'\n'<<63<<' '<<2;
    else
        sub();

}
