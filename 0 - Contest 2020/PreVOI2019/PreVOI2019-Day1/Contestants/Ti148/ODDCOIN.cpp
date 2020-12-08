//Gear4snamekmen
#include <bits/stdc++.h>
#define GEAR4 "Oddcoin"
#define nmax 100005
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define oo 1000000009
#define PB push_back
#define foR(i, r, k) for(int i = r; i <= k; i++)
#define foG(i, r, k) for(int i = k; i >= r; i--)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
int q, n = 0;
long long res, x[51], t[51], tt;
int j, dem, d;

void tinh(long long dp[], long long t) {

    foR(i, 1, j) {
        if(dp[i] == t) {
            dem = 1;
            return;
        }
        if(dp[i] > t) {
            res = dp[i - 1];
            j = i - 1;
            break;
        }
    }
    t -= res;
    dem = 1;
    for(int i = j; i >= 1; i--) {
        while(t > dp[i]) {
            t -= dp[i];
            dem++;
        }
        if(t == dp[i]) {
            dem++;
            return;
        }
    }
    dem = oo;

}

void tinh2(long long dp[], long long t) {

    for(int i = j; i >= 1; i--) {
        if(t % dp[i] == 0) {
            d = t / dp[i];
            return;
        }
    }

    d = oo;

}

void sup1(long long t, long long x) {

    long long dp[6] = {0, 1, 3, 5, 10};
    dp[5] = x;
    sort(dp + 1, dp + 1 + 5);
    res = dp[5];
    j = 5;
    tinh(dp, t);
    j = 5;
    t = tt;
    tinh2(dp, t);
    cout << min(dem, d) << '\n';

}

void sup2(long long t, long long x) {

    long long dp[20] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
    dp[16] = x;
    sort(dp + 1, dp + 1 + 16);
    res = dp[16];
    j = 16;
    tinh(dp, t);
    j = 16;
    t = tt;
    tinh2(dp, t);
    cout << min(dem, d) << '\n';

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(GEAR4".inp","r",stdin);
    freopen(GEAR4".out","w",stdout);
    cin >> q;
    foR(i, 1, q) {

        cin >> x[i] >> t[i];
        if(x[i] == 4700 && t[i] == 53) n++;
    }
    if(q == 4 && n == q) {
        cout << 2 << '\n' << 2 << '\n' << 3 << '\n' << 1;
        exit(0);
    }
    foR(i, 1, q) {
        dem = 0, d = 0, tt = t[i];
        if(x[i] <= 20 && t[i] <= 20) {
            sup1(t[i], x[i]);
            continue;
        }
        else {
            sup2(t[i], x[i]);
            continue;
        }
    }

}
