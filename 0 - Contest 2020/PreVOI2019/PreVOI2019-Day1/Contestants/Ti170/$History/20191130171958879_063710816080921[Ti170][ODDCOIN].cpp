#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "ODDCOIN"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int maxn = 1e5 + 5;
const int logn = log2(maxn) + 1;
const int mod = 1e6 + 3;

int n , m;
int f[maxn];
vector<int> can = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int x , t;
int Cal(int x){
    if(x >= 50000)return x / 50000 + Cal(x % 50000);
    return f[x];
}

void Solve(){
    cin >> t >> x;
    int res = 1e9;
    for(int i = 0 ; i <= 40000 ; ++i){
        if(i >= res)break;
        if(x - (ll)i * t >= 0)res = min(res , i + Cal(x - (ll)i * t));
        else break;
    }
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    int q;cin >> q;
    for(int i = 1 ; i <= 1e5 ; ++i){
        f[i] = 1e9;
        for(int c : can){
            if(i - c >= 0)f[i] = min(f[i] , f[i - c] + 1);
        }
    }
    while(q--){
        Solve();
    }
}

