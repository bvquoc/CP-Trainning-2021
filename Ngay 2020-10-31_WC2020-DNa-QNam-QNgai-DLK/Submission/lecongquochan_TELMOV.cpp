#include <bits/stdc++.h>
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i > (b); --i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define bp __builtin_popcount
#define debug(a) cout << a << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef pair <ll, ld> pld;
typedef pair <ll, pll> pllp;
typedef pair <pll, ll> ppll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pll> vpll;
typedef vector <pii> vpii;
typedef map <int, int> mii;
typedef map <ll, ll> mll;
typedef string BigNum;

const ll maxN = 1e18;
const ll minN = -1e18;
const int INF = 2e9;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const int baseHash = 331;
const int bigNumLength = 5000;
const ld PI = acos(-1);

//Remember limit for IT, etc..., and +1 in limit of any array
const ll limit = 2e5 + 5;
const ll limit1 = 1e6 + 5;
const ll limit2 = 1e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

struct Data {
    int dist, pos, num, distRequire;
};

struct CMP {
    bool operator () (Data a, Data b) {
        return a.dist > b.dist;
    }
};

int n, m, teleCost, distLim, numLim;
vpii g[limit];
int dist[10005][15][15];

void dijkstra() {
    pq <Data, vector <Data>, CMP> heap;
    REP(i, 1, n) REP(j, 0, numLim) REP(k, 0, distLim + 2) dist[i][j][k] = INF;
    dist[1][0][distLim + 1] = 0;
    heap.push({0, 1, 0, distLim + 1});

    while (!heap.empty()) {
        int u = heap.top().pos;
        int curDist = heap.top().dist;
        int curNum = heap.top().num;
        int distRequire = heap.top().distRequire;
        heap.pop();

        //Next without requirement
        if (distRequire == distLim + 1) {
            for (auto it : g[u]) {
                int v = it.fi, w = it.se;
                if (dist[v][curNum][distRequire] > dist[u][curNum][distRequire] + w) {
                    dist[v][curNum][distRequire] = dist[u][curNum][distRequire] + w;
                    heap.push({dist[v][curNum][distRequire], v, curNum, distRequire});
                }
            }
        }

        //Next with requirement
        else if (distRequire != distLim + 1) {
            for (auto it : g[u]) {
                int v = it.fi;
                if (distRequire < distLim) {
                    if (dist[v][curNum][distLim + 1] > dist[u][curNum][distRequire] + teleCost) {
                        dist[v][curNum][distLim + 1] = dist[u][curNum][distRequire] + teleCost;
                        heap.push({dist[v][curNum][distLim + 1], v, curNum, distLim + 1});
                    }

                    if (dist[v][curNum][distRequire + 1] > dist[u][curNum][distRequire]) {
                        dist[v][curNum][distRequire + 1] = dist[u][curNum][distRequire];
                        heap.push({dist[v][curNum][distRequire + 1], v, curNum, distRequire + 1});
                    }
                }
            }
        }

        //Give requirement
        if (distRequire == distLim + 1 && curNum < numLim) {
            if (dist[u][curNum + 1][0] > dist[u][curNum][distRequire]) {
                dist[u][curNum + 1][0] = dist[u][curNum][distRequire];
                heap.push({dist[u][curNum + 1][0], u, curNum + 1, 0});
            }
        }
    }
}

void solveProblem() {
    //dist[i][j][k]: pos i, used j teleports, k = distance from recent teleport requirement
    dijkstra();
    int ans = INF;
    //cout << dist[5][1][distLim + 1] << endl;
    REP(i, 0, numLim) ans = min(ans, dist[n][i][distLim + 1]);
    cout << ans << endl;
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void readInput() {
    cin >> n >> m >> teleCost >> distLim >> numLim;
    REP(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
}

int main() {
    fastInput();
    readInput();
    solveProblem();
}

/*
6 7 3 2 1
1 2 2
1 3 5
2 3 4
2 4 23
3 4 6
5 4 7
5 6 9
*/
