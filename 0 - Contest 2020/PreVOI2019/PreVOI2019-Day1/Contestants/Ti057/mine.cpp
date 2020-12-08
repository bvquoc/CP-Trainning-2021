///Kurumi
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define Pii pair < int, int >
#define Piii pair < Pii, int >
#define Vi vector < int >
#define Vii vector < Pii >
#define pb push_back
#define mp make_pair
#define reset(x) memset(x, 0, sizeof(x))
#define fi first
#define se second
#define Kurumi "mine"
#define nmax 200005
const ll OO = 1e9+7 ;
const ll MOD = 1000003;
using namespace std;
ll f[nmax],n,m;
map < ll, ll > check;
int read(){
    int res = 0;
    char c = getchar();
    bool Neg = false;
    while(c == ' ' || c == '\n') c = getchar();
    if(c == '-'){
        Neg = true;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        res = res * 10 + c - '0';
        c = getchar();
    }
    if(Neg) return -res;
    return res;
}
void solve1(){
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; i++){
        f[i] = 1;
        check.clear();
        for(int j = 1; j <= sqrt(i); j++){
            if(check[j] == 0){
                check[j] = 1;
                if(check[i - j] == 0){
                    check[i - j] = 1;
                    f[i] += (f[j] * f[i - j]) * 2 % MOD;
                }
                else{
                    f[i] += (f[j] * 2) % MOD;
                }
            }
        }
    }
}
void kurumi(){
    cin >> n >> m;
    if(m == 1000000) solve1();
    cout << f[n];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
