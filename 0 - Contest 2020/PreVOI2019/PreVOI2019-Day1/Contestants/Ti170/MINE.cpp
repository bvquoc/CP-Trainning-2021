#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "MINE"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int maxn = 4e5 + 5;
const int logn = log2(maxn) + 1;
const int mod = 1e6 + 3;

int n , m;
int a[maxn];
int Pow(int x , int y){
    if(y == 0)return 1;
    int r = Pow(x,y/2);
    if(y&1)return (ll)r * r % mod * x % mod;
    return (ll)r * r % mod;
}
int fac[maxn];
int nCk(int x , int y){
    return (ll)fac[x] * Pow((ll)fac[y] * fac[x - y] % mod , mod - 2) % mod;
}
int f[maxn];
int dp[2005][2005];
void testing(){
    dp[0][0] = 1;
    for(int i = 1 ; i <= 1000 ; ++i){
        for(int j = 1 ; j <= i ; ++j){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]);
            if(dp[i][j] >= mod)dp[i][j] -= mod;
        }
        dp[i][0] = dp[i - 1][1];
    }
    for(int i = 1 ; i <= 1000 ; ++i){
        cout << (ll)nCk(2 * i , i + 1) * Pow(i,mod-2) % mod << " " << dp[2 * i][0] << endl;
    }
}
int Catalan(int i){
    return (ll)nCk(2 * i , i + 1) * Pow(i,mod-2) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n >> m;
    fac[0] = 1;
    for(int i = 1 ; i <= 2 * n ; ++i)fac[i] = (ll)fac[i - 1] * i % mod;
    for(int i = 1 ; i <= 2 * n ; ++i){
        cin >> a[i];
    }
    if(m >= a[n * 2] - a[1])return cout << Catalan(n) , 0;
//    testing();
    int j = 1;int t = 1;
    f[0] = 1;
    for(int i = 2 ; i <= 2 * n ; i += 2){
        while(j < i && a[j] + m < a[i])j += 2;
        f[i] = (ll)f[j - 1] * Catalan((i - j + 1) / 2) % mod;
    }
    cout << f[2 * n];
}

