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

const ll mxN = 2e6 + 100;
// const ll oo = 1e18;
const ll MOD = 1e9 + 7;
const ll d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const ll d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase;
int n , t , ans , cnt1 , cnt2 , len;
int prime[mxN] , cnt[mxN] , path[mxN];
bool mark[mxN];

void era() {
    ft(i , 2 , 2e6) {
        if (!prime[i]) {
            prime[i] = i;
            for(int j = 1 ; j * i <= 2e6 ; j++) prime[j * i] = i;
        }
    }
}

void factor(int n) {
    while (n > 1) {
        if (!mark[prime[n]]) {
            path[++len] = prime[n];
            mark[prime[n]] = 1;
        }
        cnt[prime[n]]++;
        n /= prime[n];
    }
}

void Solve() {
    cin >> n;
    len = 0;
    factor(n);
    factor(n + 1);
    factor(n + 2);
    cnt1 = cnt2 = 1;
    ft(j , 1 , len) {
        int i = path[j];
        cnt1 *= (cnt[i] + 1);
        cnt2 *= (cnt[i] * 2 + 1);
    }
    cout << (cnt2 + 1) / 2 - cnt1 << "\n";
    ft(j , 1 , len) {
        int i = path[j];
        cnt[i] = 0 , mark[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".inp" , "r" , stdin);
    // freopen(".out" , "w" , stdout);
    era();
    cin >> TestCase;
    while(TestCase--)
        Solve();
    return 0;
}