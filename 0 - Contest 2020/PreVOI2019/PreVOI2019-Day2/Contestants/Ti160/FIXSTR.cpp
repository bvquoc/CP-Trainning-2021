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
#define filename "FIXSTR"
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

string a;
lli m, n;
char type;
lli i, j;

struct xy{
    int x,y;
};

struct IT {
    lli n;
    vector<xy> it;
    IT(lli n) : n(n){
        it = vector<xy>(4*n);
        buldtree(1, 1, n);
    }
    void buldtree(lli i, lli l, lli r){
        if(l == r){
            if(a[l] == '('){
                it[i].x = 1;
                it[i].y = 0;
            }else{
                it[i].x = 0;
                it[i].y = 1;
            }
            return;
        }
        lli mid = (l + r)/2, li = i*2;
        buldtree(li, l, mid);
        buldtree(li + 1, mid + 1, r);
        it[i].x = max(0, it[li].x - it[li + 1].y) + it[li + 1].x;
        it[i].y = max(0, it[li + 1].y - it[li].x) + it[li].y;

    }
    void update(lli i, lli l, lli r, lli u){
        if(l == r){
            if(it[i].x == 1){
                it[i].x = 0;
                it[i].y = 1;
            }else{
                it[i].x = 1;
                it[i].y = 0;
            }
            return;
        }
        lli mid = (l+r)/2, li = i*2;
        if(u>= l && u <= mid){
            update(li, l, mid, u);
        }
        if(u >= mid + 1 && u <= r){
            update(li + 1, mid + 1, r, u);
        }
        it[i].x = max(0, it[li].x - it[li + 1].y) + it[li + 1].x;
        it[i].y = max(0, it[li + 1].y - it[li].x) + it[li].y;
    }
    xy query(lli i, lli l, lli r, lli u, lli v){
        if(l > v || r < u) return {0, 0};
        if(l>=u && r <= v) return it[i];
        lli mid = (l+r)/2, li = i*2;
        xy q1 = query(li, l, mid, u, v);
        xy q2 = query(li + 1, mid + 1, r, u, v);
        xy gg;
        gg.x = max(0, q1.x - q2.y) + q2.x;
        gg.y = max(0, q2.y - q1.x) + q1.y;
        return gg;
    }
};

vector<string> history;
lli locs[nmax];
lli num;

void sub12(){
    num = 0;
    n = a.size()-1;
    IT gg(n);
    history.push_back(a);
    while(m--){
        sonin >> type >> i;
        num++;
        locs[num] = history.size()-1;
        if(type == 'C'){
            gg.update(1,1,n,i);
            if(a[i] == ')')
                a[i] = '(';
            else
                a[i] = ')';
            history.push_back(a);
        } else if(type == 'Q'){
            sonin >> j;
            xy res = gg.query(1, 1, n, i, j);
            sonout << (res.x + res.y) << "\n";
        } else if(type == 'U'){
            if(a != history[locs[i]]){
                a = history[locs[i]];
                gg.buldtree(1,1,n);
            }
        }
    }
}

int main(){
    fileNX
    toiuuhoa
    sonin >> a >> m;
    a = ' ' + a;

    sub12();

    return 0;
}
