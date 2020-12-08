//    _____                   _                       _
//   / ____|                 | |                     (_)
//  | (___   ___  _ __     __| | ___ _ __    ______ _ _
//   \___ \ / _ \| '_ \   / _` |/ _ \ '_ \  |_  / _` | |
//   ____) | (_) | | | | | (_| |  __/ |_) |  / / (_| | |
//  |_____/ \___/|_| |_|  \__,_|\___| .__/  /___\__,_|_|
//                                  | |
//                                  |_|

#include <bits/stdc++.h>
#define nmax 100005
#define oo 10000000007
#define mod 1000000007
#define reset(x) memset(x, 0, sizeof x)
#define F first
#define S second
#define sonin cin
#define sonout cout
#define PB(x) push_back(x)
#define debug(x) cout << "Loli -> " << #x << " : " << x << "\n"
#define debugAry(x, a, b, y) for(int y = a; y<=b; y++) cout << #x << "[" << y << "]" << " -> " << x[y] << "\n"
#define filename ""
#define fileNX freopen(filename".inp", "r", stdin); freopen(filename".out", "w", stdout);
#define fileN freopen(filename".inp", "r", stdin);
#define fileX freopen(filename".out", "w", stdout);
#define toiuuhoa ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(a) (int) a.size()
#define FOU(x,a,b) for (lli x=a;x<=b;x++)
#define FOD(x,a,b) for (lli x=a;x>=b;x--)
#define FOA(a,b) for(auto &a:b)
#define ALLvec(a) a.begin(),a.end()
#define REU(x,a,b) for (lli x=a;x<b;x++)
#define RED(x,a,b) for (lli x=a;x>b;x--)
#define AutoCinAry(a,b,x) for(int a = 1; a<=b; a++) cin >> x[i];
#define dembit1(x) __builtin_popcount(x)
#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define EL cout << "\n";
#define EX exit(0);
#define Ary(x, i, j, a) x[(i - 1) * a + j]
#define epsinon 1e-8
using namespace std;
typedef long long lli;
typedef long double ldo;
typedef double dou;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pii;
typedef vector<pii> vpi;

lli t, n, m, res;
lli a[nmax], b[nmax];
lli type, l, r, k;
void sub1(){
    while(m--){
        sonin >> type >> l >> r;
        if(type == 1){
            sonin >> k;
            FOU(i, l, r){
                b[i] += k;
                b[i+1] -= k;
            }
        } else {
            res = a[l];
            FOU(i, l+1, r){
                if(b[i] > 0)
                    res += b[i];
            }
            sonout << res << "\n";
        }
    }
}

int main(){
    fileNX
    toiuuhoa
    sonin >> t;
    while(t--){
        sonin >> n >> m;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        FOU(i, 1, n){
            sonin >> a[i];
            b[i] = a[i] - a[i-1];
        }
        //if(m<=50000)
            sub1();
    }

    return 0;
}
