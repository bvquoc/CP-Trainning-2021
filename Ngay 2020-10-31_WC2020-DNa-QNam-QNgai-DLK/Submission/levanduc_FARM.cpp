#include<bits/stdc++.h>

using namespace std;

//Shortcut

#define ll int
#define lb long double
#define fi first
#define se second
#define debug(a) cout << "This is value of " << #a << ": " << a << "\n";

#define ft(i , a , b) for (ll i = (ll)a ; i <= (ll)b ; i++)
#define fd(i , a , b) for (ll i = (ll)a ; i >= (ll)b ; i--)
#define lt(i , a , b , c) for (ll i = (ll)a ; i <= (ll)b ; i += (ll)c)
#define ld(i , a , b , c) for (ll i = (ll)a ; i >= (ll)b ; i -= (ll)c)
#define at(a , b) for (auto a : b)

#define pll pair <ll , ll>
#define vtl vector <ll>
#define prio priority_queue<pll , vector<pll > , greater<pll> >

//Functions

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll l , ll r) {return (rando() % (r - l + 1) + l);}

ll getbit(ll a , ll b) {return a & (1 << b);}
ll onbit(ll a , ll b) {return a | (1 << b);}
ll offbit(ll a , ll b) {return (!getbit(a , b)) ? a : a ^ (1 << b);}

//Variable

const ll mxN = 1e4 + 5;
const ll oo = 1e18;
const ll MOD = 1e9 + 7;
const ll d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const ll d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

ll TestCase;
ll n , k , q , p;
ll a[mxN] , dp[mxN][mxN];
bool mark[mxN][mxN];

ll cal(ll idx , ll num) {
    ll &ans = dp[idx][num];
    bool &tie = mark[idx][num];

    if (num == 0) return 0;
    if (idx > n) return 0;
    if (tie) return ans;
    tie = true;
    
    ans = max(ans , cal(idx + 1 , num));
    fd(i , min(num , p) , max(min(num , p) - 25 , 1)) {
        ans = max(ans , cal(idx + k , num - i) + i * a[idx]);
    }

    return ans;
}

ll calc(ll idx , ll num) {
    ll &ans = dp[idx][num];
    bool &tie = mark[idx][num];

    if (num == 0) return 0;
    if (idx > n) return 0;
    if (tie) return ans;
    tie = true;
    
    ans = max(ans , calc(idx + 1 , num));
    fd(i , min(num , p) , max(min(num , p) - 1 , 1)) {
        ans = max(ans , calc(idx + k , num - i) + i * a[idx]);
    }

    return ans;
}

void Solve() {
    cin >> n >> k >> q >> p;
    ft(i , 1 , n) cin >> a[i];
    if (n <= 1000 && p <= 1000 && q <= 1000) cout << cal(1 , q);
    else cout << calc(1 , q);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".inp" , "r" , stdin);
    // freopen(".out" , "w" , stdout);
    // read(TestCase);
    TestCase = 1;
    while(TestCase--)
        Solve();
    return 0;
}