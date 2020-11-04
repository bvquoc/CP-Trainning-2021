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

const ll mxN = 1e5 + 5;
const ll oo = 1e18;
const ll MOD = 1e9 + 7;
const ll d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const ll d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

ll TestCase;
ll m , n , ans , l , r , mid;
ll a[mxN] , s[mxN];

bool check(ll x) {
    ft(i , 1 , n - x + 1) {
        if (s[i + x - 1] - s[i - 1] < m) return false;
    }
    return true;
}

void Solve() {
    cin >> m >> n;
    ft(i , 1 , n) cin >> a[i];
    ft(i , 1 , n) s[i] = s[i - 1] + a[i];
    l = 1;
    r = n;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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