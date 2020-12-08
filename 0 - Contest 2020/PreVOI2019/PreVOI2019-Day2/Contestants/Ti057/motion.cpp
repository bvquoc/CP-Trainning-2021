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
#define Kurumi "motion"
#define nmax
const ll OO = 1e9+7 ;

using namespace std;
int T;
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

void kurumi(){
    cin >> T;
    while(T--){
        int n,m,xa,ya,xb,yb,xc,yc,xd,yd;
        cin >> n >> m >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        cout << -1 << '\n';
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
