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

const string NO_ANSWER = "poor professor";
void noAnswer(void) {
    cout << NO_ANSWER << endl;
    exit(EXIT_SUCCESS);
}

#define MAX   16
int n, m;
long long pos;
bool mustLess[MAX + 3][MAX + 3];
int lessMask[MAX + 3];
int slotMask[MAX + 3];
long long cnt[MASK(MAX) + 3];
vector<int> ones[MASK(MAX) + 3];

void init(void) {
    cin >> n >> pos >> m;
    REP(love, m) {
        int a, b; cin >> a >> b; a--; b--;
        mustLess[a][b] = true;
    }

    REP(i, n) if (mustLess[i][i]) noAnswer();

    REP(i, n) mustLess[i][i] = true;
    REP(k, n) REP(i, n) REP(j, n) mustLess[i][j] |= mustLess[i][k] && mustLess[k][j];

    REP(i, n) REP(j, n) if (i != j && mustLess[i][j] && mustLess[j][i]) noAnswer();
    REP(i, n) REP(j, n) if (mustLess[i][j]) lessMask[j] |= MASK(i);

    REP(i, MASK(n)) REP(j, n) if (BIT(i, j)) ones[i].push_back(j);
}

#define SUBSET(big, small) (((big) & (small)) == (small))

long long cntFill(const vector<int> &prefix) {
    FOR(i, 1, n) slotMask[i] = MASK(n) - 1;
    REP(i, prefix.size()) slotMask[prefix[i]] = MASK(i);

    memset(cnt, 0, sizeof cnt);
    cnt[0] = 1;
    REP(mask, MASK(n)) if (cnt[mask] > 0) {
        int next = __builtin_popcount(mask) + 1;
        int slots = slotMask[next] & ~mask;
        FORE(it, ones[slots]) {
            int newPos = *it;
            int newMask = mask | MASK(newPos);
            if (SUBSET(newMask, lessMask[newPos])) cnt[newMask] += cnt[mask];
        }
    }

    return cnt[MASK(n) - 1];
}

void process(void) {
    if (cntFill(vector<int>()) < pos) noAnswer();

    vector<int> prefix;
    int used = 0;
    REP(love, n) {
        bool ok = false;
        FOR(value, 1, n) if (!BIT(used, value)) {
            vector<int> tmpPrefix = prefix;
            tmpPrefix.push_back(value);
            long long cntWay = cntFill(tmpPrefix);
            if (cntWay >= pos) {
                prefix.push_back(value);
                used |= MASK(value);
                ok = true;
                break;
            } else pos -= cntWay;
        }
        assert(ok);
    }

    FORE(it, prefix) cout << *it << " "; cout << endl;
}

int main(void) {
#if ONLINE_JUDGE || THEMIS
    freopen("chocolate.inp", "r", stdin);
    freopen("chocolate.out", "w", stdout);
#endif // ONLINE_JUDGE
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
