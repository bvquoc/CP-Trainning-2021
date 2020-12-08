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
#define debugAry(x, a, b, y) for(int y = a; y<=b; y++) cout << #x << "[" << y << "]" << " -> " << x[y] << "\n";
#define filename "oddcoin"
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

lli q, x, t, res;
vector<lli> piceO = {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
vector<lli> pice;
vector<lli> piceNO = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
vector<lli> piceN = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

void sub1(){
    queue<pii> q;
    q.push({t, 0});
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        if(u.F == 0){
            res = u.S;
            break;
        }
        FOU(i,0,15){
            if(pice[i] > u.F)
                break;
            q.push({u.F - pice[i], u.S + 1});
        }
    }
    sonout << res << "\n";
}
lli check(lli tb){
    lli sum = 0, resB = 0;
    lli i = piceN.size() - 1;
    while(tb > 0){
        while(piceN[i] > tb){
            //piceN.pop_back();
            i--;
        }
        sum += (tb - (tb%piceN[i]));
        resB += (tb - (tb%piceN[i]))/piceN[i];
        tb = tb%piceN[i];
    }
    return resB;
}
void sub2(){
    lli l = 0, r = t/x;
    res = oo;
    piceN = piceNO;
    sort(piceN.begin(), piceN.end());
    FOU(i, 0, r){
        lli kk = check(t - i*x);
        res = min(res, kk + i);
    }
    sonout << res << "\n";
    //sub1();
}

int main(){
    fileNX
    toiuuhoa
    sonin >> q;
    while(q--){
        sonin >> x >> t;
        pice = piceO;
        pice[0] = x;
        //piceN = piceNO;
        sort(pice.begin(), pice.end());
        //sort(piceN.begin(), piceN.end());
        if(t <= 20)
            sub1();
        else
            sub2();
    }

    return 0;
}
