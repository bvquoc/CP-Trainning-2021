///....DH....///
#include <bits/stdc++.h>
#define task                "PAINT"
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
#define For(i, s, n, m)     for(int i = s; i <= n; i += m)
#define Ford(i, s, n, m)    for(int i = s; i >= n; i -= m)

using namespace std;

template <typename R, typename D> inline void Min(R &a, D b) {
    if(a>b)
        a=b;
}
template <typename D, typename R> inline void Max(D &a, R b) {
    if(a<b)
        a=b;
}

/** MOD **/                 const long long mod = 1e9 + 7;
/** size of array **/       const int maxn = 2000005;

map <int, int> mpp;
int n, id, color[maxn], cnt = 0, last, dem, p[maxn], vi[maxn], co[maxn];
char c, d;

int Find(int u) {
    if(u == p[u])
        return u;
    return p[u] = Find(p[u]);
}

void dsu(int u, int v) {
    int x = Find(u);
    int y = Find(v);
    p[y] = x;
    return ;
}

void change(int u, int v, int co) {
    int x = Find(u);
    int y = Find(v);
    p[y] = x;
    color[co] = ++last;
}

void sub1() {
    for(int i = 1; i <= n; i++) {
        cin >> id;
        if(id == 1) {
            cin >> c;
            cnt++;
            for(int i = 1; i <= n; i++)
                if(co[i] == 0) {
                    co[i] = int(c - 'a' + 1);
                    break;
                }
        } else {
            cin >> c >> d;
            for(int i = 1; i <= n; i++)
                if(co[i] == int(c - 'a' + 1))
                    co[i] = int(d - 'a' + 1);
        }
    }
    for(int i = 1; i <= cnt; i++)
        cout << char(co[i] - 1 + 'a');
}

void sub2() {
    for(int i = 1; i <= 2 * n + 26; i++)
        p[i] = i;
    for(int i = n + 1; i <= n + 26; i++)
        color[i - n] = i;
    last = n + 26;
    for(int i = 1; i <= n; i++) {
        cin >> id;
        if(id == 1) {
            while(cnt == 0 || vi[cnt] == 1)
                cnt++;
            cin >> c;
            vi[cnt] = 1;
            dsu(color[int(c - 'a' + 1)], cnt);
        } else {
            cin >> c >> d;
            if(c == d)
                continue;
            change(color[int(d - 'a' + 1)], color[int(c - 'a' + 1)], int(c - 'a' + 1));
        }
    }
    for(int i = 1; i <= 26; i++)
        mpp[color[i]] = i;
    for(int i = 1; i <= cnt; i++)
        cout << char(mpp[Find(i)] - 1 + 'a');
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    fi(task".inp");
    fo(task".out");
    cin >> n;
    if(n <= 1000)
        sub1();
    else
        sub2();
}
