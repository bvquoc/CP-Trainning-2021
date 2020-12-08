#include<bits/stdc++.h>

#define maxn 1000005

using namespace std;
typedef long long ll;

int a[maxn];

struct Data{
    ll ans, Left, Rigt;

    Data(ll _ans = 0, ll _Left = 0, ll _Rigt = 0) : ans(_ans), Left(_Left), Rigt(_Rigt) {};

    Data operator + (const Data& op) const{
        return Data(ans + op.ans - ll(min(Rigt, op.Left)), Left, op.Rigt);
    }

    void operator += (int x){
        ans += x;Left += x;Rigt += x;
    }
};

struct Segment{
    Data val[maxn * 4];
    ll lazy[maxn * 4];
    int l[maxn * 4], r[maxn * 4];

    void Build(int id, int i, int j){
        l[id] = i; r[id] = j;
        lazy[id] = 0;

        if (i == j) {
            val[id] = Data(a[i], a[i], a[i]);
            return;
        }

        int mid = (i + j) / 2;

        Build(id * 2, i, mid);
        Build(id * 2 + 1, mid + 1, j);

        val[id] = val[id * 2] + val[id * 2 + 1];
    }

    void Dolazy(int id){
        if (l[id] == r[id]) return;

        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];

        val[id * 2] += lazy[id];

        val[id * 2 + 1] += lazy[id];

        lazy[id] = 0;
    }

    void Update(int id, int i, int j, int k){
        if (l[id] > j || r[id] < i) return;

        if (l[id] >= i && r[id] <= j) {
            lazy[id] += k;

            val[id] += k;
            return;
        }

        Dolazy(id);

        Update(id * 2, i, j, k);
        Update(id * 2 + 1, i, j, k);

        val[id] = val[id * 2] + val[id * 2 + 1];
    }

    Data Get(int id, int i, int j){
        if (l[id] > j || r[id] < i) return Data(0, 0, 0);

        Dolazy(id);

        if (l[id] >= i && r[id] <= j) return val[id];

        return Get(id * 2, i, j) + Get(id * 2 + 1, i, j);
    }
} it;

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    it.Build(1, 1, n);

    while (m--){

        int type, l, r, k;

        scanf("%d%d%d", &type, &l, &r);

        if (type == 1) {
            scanf("%d", &k);
            it.Update(1, l, r, k);
        }

        else printf("%lld\n", it.Get(1, l, r).ans);

    }
}

int main(){
    #define TASK "CONSTRUCT"
    freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    int t;
    scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}
