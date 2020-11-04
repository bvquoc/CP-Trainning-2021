#include<bits/stdc++.h>

using namespace std;

//Shortcut

#define ll long long
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

const ll mxN = 1e6 + 5;
const ll oo = 1e18;
const ll MOD = 1e9 + 7;
const ll d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const ll d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

ll TestCase;
ll n , k , ans , x;
ll dp[mxN];
pair<pll , ll> a[mxN];

void Solve() {
    cin >> n >> k;
    ft(i , 1 , n) {
        cin >> a[i].fi.fi >> x >> a[i].se;
        a[i].fi.se = a[i].fi.fi + x - 1;
        ans = max(ans , a[i].se);
    }
    sort(a + 1 , a + n + 1);
    dp[1] = a[1].se;
    ft(i , 2 , n) {
        dp[i] = a[i].se;
        ft(j , 1 , i - 1) {
            if (a[j].fi.se + k < a[i].fi.fi) {
                dp[i] = max(dp[i] , dp[j] + a[i].se);
            }
        }
        ans = max(ans , dp[i]);
    }
    cout << ans;
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