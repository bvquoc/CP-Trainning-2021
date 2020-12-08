#ifdef THEMIS
    #include "testlib_themis.h"
#else
    #include "testlib.h"
#endif // THEMIS

#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

/**
 * The original limit of this problem is |cord| <= 1e8 and number of steps <= 1e8.
 * Hence, if contestant outputs a point with |cord| > 1e9, he will surely get WA.
**/
const int MAX_CORD = (int)1e9;

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    Point(InStream &stream, const string &name) {
        x = stream.readInt(-MAX_CORD, MAX_CORD, name + ".x");
        y = stream.readInt(-MAX_CORD, MAX_CORD, name + ".y");
    }
};

long long dist(const Point &a, const Point &b) {
    long long dx = a.x - b.x, dy = a.y - b.y;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}

#define MAX   500500
int numPoint, limit;
Point input[MAX], output[MAX];

void init(void) {
    numPoint = inf.readInt();
    limit = inf.readInt();
    FOR(i, 1, numPoint) input[i] = Point(inf, format("points[%d]", i));
}

long long sumDiff(vector<int> &v) {
    sort(v.begin(), v.end());
    int n = v.size();
    long long res = 0;
    REP(i, n) {
        int numLess = i;
        int numGreater = n - 1 - i;
        res += 1LL * v[i] * (numLess - numGreater);
    }
    return res;
}

long long checkAnswer(InStream &stream) {
    long long totalDist = stream.readLong(0, LLONG_MAX, "total distance");
    FOR(i, 1, numPoint) output[i] = Point(stream, format("points[%d]", i));

    long long sumChanged = 0;
    FOR(i, 1, numPoint) {
        /** input[i]'s cordinates are between -1e8 and 1e8, while
         *  output[i]'s cordinates are between -1e9 and 1e9,
         *  so tmpDist will be at most 2e9 + 2e8 > 2^31
        **/
        long long tmpDist = dist(input[i], output[i]);
        sumChanged += tmpDist;
        stream.ensuref(sumChanged <= limit, "Contestant uses more than %d steps.", limit);
    }

    vector<int> x, y;
    FOR(i, 1, numPoint) {
        x.push_back(output[i].x);
        y.push_back(output[i].y);
    }
    long long realDist = sumDiff(x) + sumDiff(y);
    stream.ensuref(realDist == totalDist,
                   "The printed total distance differs from actual the solution (%lld vs %lld).",
                   totalDist, realDist);
    return totalDist;
}

void process(void) {
    long long jury = checkAnswer(ans);
    long long cont = checkAnswer(ouf);

    if (jury == cont) quitf(_ok, "Minimum total distance is %lld.", jury);
    else if (jury < cont) {
        quitf(_wa, "Jury has better answer (jury: %lld, contestant: %lld).", jury, cont);
    } else {
        quitf(_fail, "Jury has worse answer (jury: %lld, contestant: %lld).", jury, cont);
    }
}

int main(int argc, char* argv[]) {
    #ifdef THEMIS
        registerTestlibThemis("tigersugar2.inp", "tigersugar2.out");
    #else
        registerTestlibCmd(argc, argv);
    #endif // THEMIS

    init();
    process();
    return 0;
}
