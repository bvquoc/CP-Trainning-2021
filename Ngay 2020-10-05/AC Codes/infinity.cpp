//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "infinity"
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Pll pair < long long, long long >

using namespace std;

typedef long long ll;

const ll base = 100000000;
const ll base2 = base * base;

ll n;

Pll Pow(ll u, ll v){
        ll x = ((u * v * 2) % base) * base + v * v;
        return mp( u * u + x / base2 + (u * v * 2)/ base, x % base2);
}

ll Calc2(){
    string s;
    cin >> s;
    Pll cur = mp(0,0);
    for (int i = 0; i + 16 < s.length(); i++) cur.F = cur.F*10 + s[i]-48;
    for (int i = max(0,(int)s.length()-16); i < s.length(); i++) cur.S = cur.S*10 + s[i]-48;
    ll u = sqrt(cur.F), le = 0, ri = base;
    while (ri - le > 1){
        ll mid = (le+ri)/2;
        if (Pow(u,mid) < cur) le =mid;
            else ri = mid;
    }
    Pll a = Pow(u, le);
    ll du = (cur.F-a.F) * base2 + cur.S-a.S;
    if (du == 0) return 1;
    ll x = u * base + le + 1;
    if (du > x) return x + x - du;
    return du;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    //freopen("82", "r", stdin);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    int ntest;
    cin >> ntest;
    while (ntest --) cout << Calc2() << "\n";
    return 0;
}

