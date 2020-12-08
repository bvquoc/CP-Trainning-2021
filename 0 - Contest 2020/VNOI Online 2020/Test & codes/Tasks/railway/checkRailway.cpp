#ifdef THEMIS
    #include "testlib_themis.h"
#else
    #include "testlib.h"
#endif // THEMIS

#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Edge {
    int from, to, cost;
    Edge(int _from = 0, int _to = 0, int _cost = 0) {
        from = _from;
        to = _to;
        cost = _cost;
    }

    Edge(InStream &stream) {
        from = stream.readInt();
        to = stream.readInt();
        cost = stream.readInt();
    }
};

struct State {
    long long cost;
    int node;
    bool bought;

    State(long long _cost = 0, int _node = 0, bool _bought = false) {
        cost = _cost; node = _node; bought = _bought;
    }

    bool operator < (const State &s) const {
        return cost > s.cost;
    }
};

#define MAX   500500
const int DELTA = (int)1e9 + 7; // add to all node's weight to avoid negative weight
const long long INF = (long long)1e18 + 7LL;

int numNode, numEdge, start, finish;
Edge edges[MAX];
int weight[MAX];
vector<int> adj[MAX];
long long minCost[MAX][2];

void loadGraph(void) {
    numNode = inf.readInt();
    numEdge = inf.readInt();
    start = inf.readInt();
    FOR(i, 1, numNode) weight[i] = inf.readInt();
    FOR(i, 1, numEdge) edges[i] = Edge(inf);
    FOR(i, 1, numEdge) adj[edges[i].from].push_back(i);
}

// calculate the minimum cost from start to all other nodes.
void dijkstra(void) {
    // increase all nodes' weight by DELTA to avoid negative values.
    FOR(i, 1, numNode) weight[i] += DELTA;

    memset(minCost, 0x3f, sizeof minCost);
    priority_queue<State> q;

    #define ADD_STATE(node, bought) q.push(State(minCost[node][bought], node, bought))
    minCost[start][0] = 0; ADD_STATE(start, 0);

    while (!q.empty()) {
        long long c = q.top().cost;
        int u = q.top().node;
        bool b = q.top().bought;
        q.pop();

        if (c != minCost[u][b]) continue;

        if (!b) {
            if (minimize(minCost[u][1], minCost[u][0] + weight[u])) ADD_STATE(u, 1);
        }
        FORE(it, adj[u]) {
            int v = edges[*it].to;
            if (minimize(minCost[v][b], minCost[u][b] + edges[*it].cost)) ADD_STATE(v, b);
        }
    }

    // decrease all nodes' weight and travelling cost by DELTA to get the actual value
    FOR(i, 1, numNode) weight[i] -= DELTA;
    FOR(i, 1, numNode) minCost[i][1] -= DELTA;
}

/**
 * What to check:
 * - The given path is valid:
 *   + If the path contains 0 edges, the starting and ending points must be the same.
 *     In this case, the cost of the path is the weight of the starting node
 *   + Otherwise, verify that the starting point of the first edge equals to the starting node,
 *     the ending point of the last edge equals to the ending node, and
 *     the ending point of an edge equals to the starting point of the next one.
 * - The cost of the path equals to the printed one.
 * - The cost of the path equals the pre-calculated minimum cost.
 * - The ending node is the one with highest minimum cost.
**/
void checkAnswer(void) {
    long long printedCost = ouf.readLong(LLONG_MIN, LLONG_MAX, "path's cost");
    int finish = ouf.readInt(1, numNode, "destination");
    int length = ouf.readInt(0, INT_MAX, "path's number of edges");

    long long pathCost;
    if (length == 0) {
        ouf.ensuref(start == finish,
                    "The path contains 0 edges, but origin %d and destination %d are different.", start, finish);
        pathCost = weight[start];
    } else {
        pathCost = 0;
        int minWeight = min(weight[start], weight[finish]);
        int lastID = -1;

        FOR(i, 1, length) {
            int id = ouf.readInt(1, numEdge, format("edge #%d", i));
            if (lastID < 0) {
                ouf.ensuref(edges[id].from == start,
                            "The given path does not depart at %d.", start);
            } else {
                ouf.ensuref(edges[id].from == edges[lastID].to,
                            "The origin of some edge is different from the destination of the previous one.");
            }
            lastID = id;

            pathCost += edges[id].cost;
            minimize(minWeight, weight[edges[id].to]);
        }

        ouf.ensuref(edges[lastID].to == finish, "The given path path does not arrive at %d.", finish);
        pathCost += minWeight;
    }

    ouf.ensuref(printedCost == pathCost, "Contestant says that the path's cost is %lld, but it's actually %lld.",
                printedCost, pathCost);

    // The path is not a cheapest path from start to finish.
    if (pathCost > minCost[finish][1]) {
        quitf(_wa, "Contestant gives a path from %d to %d with cost %lld, but the minimum cost is %lld.",
              start, finish, pathCost, minCost[finish][1]);
    }
    // Contestant found a path which is cheaper than the calculated minimum cost.
    // In this case, the minimum cost is calculated incorrectly.
    if (pathCost < minCost[finish][1]) {
        quitf(_fail, "The calculated minimum cost (%lld) from %d to %d is not correct.",
              minCost[finish][1], start, finish);
    }

    int mostExpensive = start;
    FOR(i, 1, numNode) if (minCost[i][1] < INF && minCost[mostExpensive][1] < minCost[i][1]) mostExpensive = i;
    long long maxCost = minCost[mostExpensive][1];

    if (maxCost > pathCost) {
        quitf(_wa, "Contestant thinks that the most expensive destination is %d with cost %lld, \
              but destination %d has cost %lld.", finish, pathCost, mostExpensive, maxCost);
    }

    // since pathCost == minCost[finish][1] <= maxCost, now we are sure that pathCost == maxCost
    quitf(_ok, "The most expensive destination is %d with cost %lld.", mostExpensive, maxCost);
}

int main(int argc, char* argv[]) {
    #ifdef THEMIS
    registerTestlibThemis("railway.inp", "railway.out");
    #else
    registerTestlibCmd(argc, argv);
    #endif // THEMIS

    loadGraph();
    dijkstra();
    checkAnswer();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
