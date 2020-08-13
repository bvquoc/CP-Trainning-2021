#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define int long long
#define endl putchar('\n');
#define space putchar(' ');
#define id first.first
#define ans first.second
#define L second.first
#define R second.second

using namespace std;

using ii = pair <int, int>;
using ld = long double;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}


using data = pair<ii, ii>;
const int N = 5003, INF = 1000001, zero = 3*INF;
int n, q_sz, a[N];
vector <int> pos[2*INF];
vector <data> q;

struct BIT_SumQuery {
    int bit[2*INF], n = INF*2 - 1;
    int sum(int r) {
        int ret = 0;
        for (; r >= 1; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) { 
        return sum(r) - sum(l - 1); 
    }
    void add(int idx, int delta) {
        for (; idx <= n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} BIT;

int count(int x, int l, int r) {
    if (pos[x].empty()) return 0;

    int left = INF, right = -INF;
    int lf, rt, mi;

    lf = 0; rt = pos[x].size()-1;
    while (lf<=rt) {
        mi = (lf+rt)/2;
        if (pos[x][mi]>=l) {
            left = min(left, mi);
            rt = mi-1;
        } else lf = mi+1;
    }
    if (left == INF || pos[x][left]>r) return 0;
    if (pos[x][left]==r) return 1;

    lf = 0; rt = pos[x].size()-1;
    while (lf<=rt) {
        mi = (lf+rt)/2;
        if (pos[x][mi]<=r) {
            right = max(right, mi);
            lf = mi+1;
        } else rt = mi-1;
    }

    return right-left+1;
}

signed main(void) {
    FastIO;
    freopen("3SUM.INP","r",stdin);
    freopen("3SUM.OUT","w",stdout);
    Read(n); Read(q_sz);
    FOR(i,1,n) {
        Read(a[i]);
        a[i] += INF;
        pos[a[i]].push_back(i);
    }

    FOR(i,1,q_sz) {
        int l, r;
        Read(l); Read(r);
        if (l>r) swap(l,r);
        q.push_back(data({i,0},{l,r}));
    }
    sort(q.begin(),q.end(),[](const data &A, const data &B){
        return A.R < B.R;
    });

    int idx = 0;
    while (q[idx].R<3 && idx+1<q_sz) idx++;
    FOR(r,3,n) {
        FORD(l,r-2,1) {
            int cnt = count(zero-a[l]-a[r],l+1,r-1);
            if (cnt <= 0) continue;
            // cout << zero-a[l]-a[r] << ' ' << l+1 << ' ' << r-1 << ' ' << cnt << '\n';
            BIT.add(l,cnt);
        }
        
        while (q[idx].R == r && idx<q_sz) {
            q[idx].ans = BIT.sum(q[idx].L,q[idx].R);
            idx++;
        }
        if (idx+1>q_sz) break;
    }

    sort(q.begin(),q.end(),[](const data &A, const data &B){
        return A.id < B.id;
    });
    for (data x: q) {
        Write(x.ans);
        endl;
    }
    return 0;
}