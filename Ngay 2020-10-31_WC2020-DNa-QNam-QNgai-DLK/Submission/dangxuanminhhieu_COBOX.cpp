#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

/*
struct Node
{
    int node, len;
    Node() {node = len = 0;}
    Node(int node, int len) {this -> node = node, this -> len = len;}
};
typedef vector<Node> vg;
*/

#define MAX 100001
#define MOD 1000000007

#define fi first
#define se second
#define pf push_front
#define pb push_back

#define FOR(type, i, a, b) for(type i = (a); i <= (b); i++)
#define FORR(type, i, b, a) for(type i = (b); i >= (a); i--)

#define testBit(n, bit) ((n >> bit) & 1)
#define flipBit(n, bit) (n ^ (1ll << bit))
#define cntBit(n) __builtin_popcount(n)
#define cntBitll(n) __builtin_popcountll(n)
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

struct Point {int x, y;};
bool operator < (Point a, Point b){
    return a.x + a.y < b.x + b.y;
}

int n;
int x[MAX];
int y[MAX];
pair<Point, int> p[MAX];
map<int, map<int, set<int>>> bit;
int pre[MAX];
vi save[MAX];

void nen(int *arr){
    mii save; FOR(int, i, 1, n) save[arr[i]] = true;
    
    int tmp = 0;
    for (pii i: save)
        save[i.fi] = ++tmp;
    
    FOR(int, i, 1, n)
        arr[i] = save[arr[i]];
}

void add(int x, int y2, int ind){
    for(; x <= n; x += x & -x)
        for(int y = y2; y <= n; y += y & -y)
            bit[x][y].insert(ind);
}
void del(int x, int y2, int ind){
    for(; x <= n; x += x & -x)
        for(int y = y2; y <= n; y += y & -y)
            bit[x][y].erase(bit[x][y].find(ind));
}

int get(int x, int y2){
    int ans = 0;
    for (; x; x -= x & -x){
        for (int y = y2; y; y -= y & -y)
            if (bit[x][y].size()){
                ans = *bit[x][y].begin();
                break;
            }
        if (ans) break;
    }
    if (ans){
        Point tmp = p[ans].fi;
        del(tmp.x, tmp.y, ans);
    }
    return ans;
}

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //init
    cin >> n; FOR(int, i, 1, n) cin >> x[i] >> y[i];
    nen(x), nen(y);
    FOR(int, i, 1, n)
        p[i] = {{x[i], y[i]}, i};
    sort(p + 1, p + 1 + n);
    //=========================
    //doIt
    int part = 0;
    FOR(int, i, 1, n){
        Point currP = p[i].fi; int ind = p[i].se;

        int child = get(currP.x - 1, currP.y - 1);
        if (!child){
            part += (child == 0);
            pre[ind] = ind;
            save[ind].push_back(ind);
        } else{
            pre[ind] = pre[child]; 
            save[pre[ind]].push_back(ind);
        }
        add(currP.x, currP.y, ind);
    }
    //=========================
    
    cout << part << '\n';
    FOR(int, i, 1, n)
        if (save[i].size()){
            cout << save[i].size() << ' ';
            for (int child: save[i]) cout << child << ' ';
            cout << '\n';
        }
}