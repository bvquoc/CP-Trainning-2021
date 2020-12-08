///....DH....///
#include <bits/stdc++.h>
#define task                "MINE"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)

#define pii                 pair<int, int>
#define ft                  first
#define sd                  second
#define mp                  make_pair

#define pb                  push_back
#define pf                  push_front
#define popb                pop_back
#define popf                pop_front

#define reset(a, x)         memset(a, x, sizeof(a))

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1000003;
/** size of array **/       const int maxn = 200005;

stack <int> in;
int n, k, F[20005][10005], a[maxn];
bool isok = false;

int digit(int id, int op, int cl) {
    if((2 * n + 1 - id) + cl < op)
        return 0;
    if(id == n * 2 + 1) {
        if(op == cl)
            return 1;
        else
            return 0;
    }
    if(isok == true && F[id][op - cl] > -1)
        return F[id][op - cl];
    in.push(id);
    F[id][op - cl] = digit(id + 1, op + 1, cl);
    in.pop();
    if(op >= (cl + 1)) {
        int ft = in.top();
        if(a[id] - a[ft] <= k) {
            in.pop();
            F[id][op - cl] = (F[id][op - cl] + digit(id + 1, op, cl + 1));
            in.push(ft);
        }
    }
    return F[id][op - cl] % mod;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= 2 * n + 2; i++)
        for(int j = 0; j <= n + 2; j++)
            F[i][j] = -1;
    for(int i = 1; i <= 2 * n; i++)
        scanf("%d", &a[i]);
    if(a[2 * n] - a[1] <= k)
        isok = true;
    else
        isok = false;
    printf("%d", digit(1, 0, 0));
}
