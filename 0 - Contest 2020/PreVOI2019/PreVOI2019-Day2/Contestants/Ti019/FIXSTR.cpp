#include<bits/stdc++.h>

#define maxn 100005

using namespace std;
typedef long long ll;

char s[maxn];
int n, m;

struct Data{
    int Min, sum;

    Data (int _Min = 0, int _sum = 0) : Min(_Min), sum(_sum) {};

    Data operator + (const Data& op) const{
        return Data(min(Min, sum + op.Min), sum + op.sum);
    }
};

struct Segment{
    vector < int > l, r, lazy, cs;

    vector < vector < pair < int, Data > > > val;

    Segment(int n = 0){
        l.resize(4 * n);
        r.resize(4 * n);
        lazy.resize(4 * n);
        cs.resize(4 * n);

        val.resize(4 * n);
    }

    void Build(int id, int i, int j){

        l[id] = i; r[id] = j;
        cs[id] = 0;

        if (i == j) {
            int ret = 0;
            if (s[i] == '(') ret = 1;
                else ret = -1;
            val[id].push_back(make_pair(0, Data(ret, ret)));
            return;
        }

        int mid = (l[id] + r[id]) / 2;

        Build(id * 2, i, mid);
        Build(id * 2 + 1, mid + 1, j);

        val[id].push_back(make_pair(0, val[id * 2][0].second + val[id * 2 + 1][0].second));
    }

    void Up(int id, int x){
        int lo = 0, hi = val[id].size() - 1;

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (val[id][mid].first < x) lo = mid;
            else hi = mid - 1;
        }

        cs[id] = lo;
    }

    void Dolazy(int id){
        if (lazy[id] == 0 || (l[id] == r[id])) return;

        lazy[id * 2] = lazy[id];
        lazy[id * 2 + 1] = lazy[id];

        Up(id * 2, lazy[id]);
        Up(id * 2 + 1, lazy[id]);

        lazy[id] = 0;
    }

    void Update(int id, int i, int _cs){
        if (l[id] > i || r[id] < i) return;

        Dolazy(id);

        if (l[id] == r[id]) {
            val[id].push_back(make_pair(_cs, Data(-val[id][cs[id]].second.Min, -val[id][cs[id]].second.sum)));
            cs[id] = val[id].size() - 1;
            return;
        }

        Update(id * 2, i, _cs);
        Update(id * 2 + 1, i, _cs);

        val[id].push_back(make_pair(_cs, val[id * 2][cs[id * 2]].second + val[id * 2 + 1][cs[id * 2 + 1]].second));
        cs[id] = val[id].size() - 1;
    }

    Data Get(int id, int i, int j){
        if (l[id] > j || r[id] < i) return Data(0, 0);

        Dolazy(id);

        if (l[id] >= i && r[id] <= j) return val[id][cs[id]].second;

        return Get(id * 2, i, j) + Get(id * 2 + 1, i, j);
    }
} it;

void solve2(){

    int n = strlen(s + 1);
    it = Segment(n);

    it.Build(1, 1, n);
    char type;

    for (int is = 1; is <= m; ++is) {

        int i, j;
        cin >> type >> i;

        if (type == 'Q') cin >> j;

        if (type == 'C')
            it.Update(1, i, is);
        else
        if (type == 'U'){
            it.lazy[1] = i;
            it.Up(1, i);
        }
        else {
            Data ret = it.Get(1, i, j);
            printf("%d\n", ret.sum - 2 * min(ret.Min, 0));
        }
    }

}

int main(){
    #define TASK "FIXSTR"

    freopen(TASK".inp", "r", stdin); freopen(TASK".out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> s + 1;
    cin >> m;

    solve2();
    return 0;
}
