// link:
#include <bits/stdc++.h>

#define task "GIFT11"
#define ll long long
#define f0(i, a, b) for(int i = (a); i <= (b); i++)
#define f1(i, a, b) for(int i = (a); i >= (b); i--)
#define pii pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define MASK(i) (1ll << (i))
#define BIT(i, x) (((x) >> (i)) & 1ll)
#define turn_on(i, x) ((1ll << (i)) | (x))
#define turn_off(i, x) ((x) & ~(1ll << (i)))
#define __builtin_popcount __builtin_popcountll

//---------------DO NOT TRY---------------//
using namespace std;

const ll mod = 998244353;
const int mxN = 2007;
int n;
string a[mxN];
bool checkSubTwo = true, checkSubThree = true;
void input(void){
    cin >> n;
    f0(i, 1, n){
        cin >> a[i];
        if(a[i].size() % 2 == 0) checkSubThree = false;
        if(a[i].size() % 2 == 1) checkSubTwo = false;
    }
}
ll fact[mxN];
void prepare(void){
    fact[0] = 1;
    f0(i, 1, 2000){
        fact[i] = (fact[i - 1] * 1ll * i) % mod;
    }
}
// subOne
bool used[mxN];
string fin;
int ABS(int a){
    if(a < 0) return -a;
    return a;
}
bool check(string s){
    reverse(s.begin(), s.end());
    s = " " + s;
    int sumOdd = 0;
    for(int i = 1; i <= s.size() - 1; i += 2){
        int tmp = s[i] - '0';
        sumOdd += tmp;
    }
    int sumEven = 0;
    for(int i = 2; i <= s.size() - 1; i += 2){
        int tmp = s[i] - '0';
        sumEven += tmp;
    }
    if(ABS(sumOdd - sumEven) % 11 == 0) return true;
    return false;
}
ll res = 0ll;
void backTrack(int pos, string s){
    if(pos > n){
        if(check(s) == true) (res += 1) % mod;
    }
    f0(i, 1, n) if(used[i] == false){
        used[i] = true;
        backTrack(pos + 1, s + a[i]);
        used[i] = false;
    }
}
void subOne(void){
    res = 0ll;
    fin = "";
    backTrack(1, fin);
    cout << res << endl;
}
//
void subTwo(void){
    string tmp = "";
    f0(i, 1, n) tmp += a[i];
    ll res = 0ll;
    if(check(tmp) == true) res = fact[n];
    cout << res << endl;
}
void subThree(void){
}
void solve(void){
    if(n <= 9){
        subOne();
        return;
    }
    if(checkSubTwo == true){
        subTwo();
        return;
    }
}
int main(){
    //
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
    //
    prepare();
    int testcase;
    cin >> testcase;
    while(testcase--){
        input();
        solve();
    }
}
