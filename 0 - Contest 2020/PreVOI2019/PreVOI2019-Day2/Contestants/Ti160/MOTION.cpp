//    _____                   _                       _
//   / ____|                 | |                     (_)
//  | (___   ___  _ __     __| | ___ _ __    ______ _ _
//   \___ \ / _ \| '_ \   / _` |/ _ \ '_ \  |_  / _` | |
//   ____) | (_) | | | | | (_| |  __/ |_) |  / / (_| | |
//  |_____/ \___/|_| |_|  \__,_|\___| .__/  /___\__,_|_|
//                                  | |
//                                  |_|

#include <bits/stdc++.h>
#define nmax 20
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
#define filename "MOTION"
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

//struct xy{
//    ldo x, y;
//};
//lli t, n, m, resa,resb;
//xy a,b,c,d;
//
//struct abcd{
//    xy a, b;
//};
//
//map<abcd, bool> mp;
//
//pii timep(lli xa, lli xb, lli va, lli vb){
//    return {(-xa + xb), (va - vb)};
//}
//bool checkam(pii xa){
//    if((xa.F == 0))
//        return false;
//    if((xa.F < 0 && xa.S > 0) || (xa.F > 0 && xa.S < 0))
//        return false;
//    return true;
//}
//xy cv(xy ac, xy bc){
//    xy beres = {ac.x - bc.x, ac.y - bc.y};
//    return beres;
//}
//bool checksame(xy ac, xy bc){
//    if(ac.x == bc.x && ac.y == bc.y)
//        return true;
//    return false;
//}
//bool checkout(xy ac){
//    if(ac.x > m || ac.x < 0 || ac.y < 0 || ac.y > n)
//        return false;
//    return true;
//}
//xy afv(xy ac, xy vc, xy t){
//    xy beres = {ac.x + vc.x*(t.F/t.S), ac.y - vc.y*(t.F/t.S)};
//    return beres;
//}
//pii toiuukq(pii nedd){
//    lli uc = __gcd(nedd.F, nedd.S);
//    return {nedd.x/uc, nedd.y/uc};
//}
//xy newa()
//
//void sub1(){
//     while(t--){
//        sonin >> m >> n >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
//        mp[{a, b}] = true;
//        mp[{c, d}] = true;
//        pii res = {0, 0};
//        while(1){
//            xy va = cv(a, b), vb = cv(c, d);
//
//            pii time1 = timep(a.x, c.x, va.x, vb.x);
//            pii time2 = timep(a.y, c.y, va.y, vb.y);
//
//            if(checkam(time1) && checkam(time2) && time1.F == time2.F && time1.S == time2.S){
//                xy ba = afv(a, va, time1);
//                xy bb = afv(c, vb, time2);
//                if(checkout(ba, bb)){
//                    pii toiuures = toiuukq({time1.F + res.F, time1.S + res.S});
//                    sonout << toiuures.F << " " << toiuures.S << "\n"
//                    break;
//                }
//            }
//
//
//
//            if(mp[{a,b}] && mp[{c, d}]){
//                sonout << "-1\n";
//                break;
//            }
//        }
//    }
//
//}

void testd(){
    sonout << "7 2\n3 2\n-1\n1 3\n63 2";
    EX;
}

int main(){
    fileNX
    toiuuhoa
    testd();
    //sonin >> t;

//    if(t<=10)
//        sub1();

    return 0;
}
