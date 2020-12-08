//    _____                   _                       _
//   / ____|                 | |                     (_)
//  | (___   ___  _ __     __| | ___ _ __    ______ _ _
//   \___ \ / _ \| '_ \   / _` |/ _ \ '_ \  |_  / _` | |
//   ____) | (_) | | | | | (_| |  __/ |_) |  / / (_| | |
//  |_____/ \___/|_| |_|  \__,_|\___| .__/  /___\__,_|_|
//                                  | |
//                                  |_|

#include <bits/stdc++.h>
#define nmax 1000005
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
#define filename "PAINT"
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

lli n, type, nopaint;
char a, b;
string paint;
map<char, pii> mp;
lli trace[nmax];

void sub1(){
    nopaint = 0;
    while(n--){
        sonin >> type >> a;
        if(type == 1){
            paint += a;
            nopaint++;
        } else{
            sonin >> b;
            FOU(i,0,nopaint-1){
                if(paint[i] == a)
                    paint[i] = b;
            }
        }
    }
    sonout << paint;
}
void sub2(){
    nopaint = 1;
    while(n--){
        sonin >> type >> a;
        if(type == 1){
            paint += a;
            pii beta = mp[a];
            lli old = 0;
            if(beta.F!=0) {
                trace[nopaint] = beta.F;
                old = beta.S;
            } else
                old = nopaint;
            mp[a] = {nopaint, old};
            nopaint++;
        } else{
            sonin >> b;
            pii beta = mp[a];
            pii beta2 = mp[b];
            if(beta.F!=0 && beta2.F!=0){
                mp[a] = {0,0};
                trace[beta2.S] = beta.F;
                mp[b] = {beta2.F, beta.S};
            } else if(beta.F!=0){
                mp[b] = {beta.F, beta.S};
                mp[a] = {0,0};
            }
        }
    }
    for(char i = 'a'; i <= 'z'; i++){
        lli x = mp[i].F;
        while(x!=0){
            paint[x - 1] = i;
            x = trace[x];
        }
    }
    sonout << paint;
//    EL
//    sub1();
}

int main(){
    fileNX
    toiuuhoa
    sonin >> n;

    if(n<=10000)
        sub1();
    else
        sub2();

    return 0;
}
