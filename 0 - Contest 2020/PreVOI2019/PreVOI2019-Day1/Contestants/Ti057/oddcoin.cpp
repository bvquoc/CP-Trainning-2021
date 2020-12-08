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
#define Kurumi "oddcoin"
#define nmax 105
const ll OO = 1e9+7 ;

using namespace std;
int q;
int a[16] = {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
ll b[nmax],h[nmax];
ll res = OO;
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
void solve(ll t){
    res = OO;
    for(int i = 16; i >= 1; i--){
        if(t >= b[i]){
            ll cnt = 0;
            ll xx = t;
            ll temp = xx / b[i];
            cnt += temp;
            xx -= temp * b[i];
            for(int j = 16; j >= 1; j--){
                if(xx >= b[j]){
                    ll temp = xx / b[j];
                    cnt += temp;
                    xx -= temp * b[j];
                }
            }
            if(cnt != 0){
                res = min(res,cnt);
            }
        }
    }
    cout << res << '\n';
}

void kurumi(){
    cin >> q;
    while(q--){
        ll x,t;
        cin >> x >> t;
        for(int i = 1; i <= 15; i++)
            b[i] = a[i];
        b[16] = x;
        sort(b + 1, b + 16 + 1);
            solve(t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen(Kurumi".inp","r",stdin);
    freopen(Kurumi".out","w",stdout);
    kurumi();
    return 0;
}
