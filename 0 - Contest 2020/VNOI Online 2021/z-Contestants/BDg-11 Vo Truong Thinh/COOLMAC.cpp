#include <bits/stdc++.h>
#define oo 1000000000
#define M 100005

using namespace std;

int n, m;

int l[M], r[M];
int mini;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void enter(){
    reup();
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        l[i] = a;
        r[i] = b;
    }
    cin >> m;
    mini = oo;
    for(int i = 1; i <= m; ++i){
        int ta;
        cin >> ta;
        mini = min(mini, ta);
    }
}

struct edge{
    pair<int, int> seg[4 * M];

    pair<int, int> init(int i, int l, int r){
        if(l > r)
            return {oo, oo};
        if(l == r)
            return seg[i] = {oo, oo};
        int mid = (l + r) / 2;
        pair<int, int> ta = init(2 * i, l, mid);
        pair<int, int> tb = init(2 * i + 1, mid + 1, r);
        if(ta.first < tb.first)
            return seg[i] = ta;
        else
            return seg[i] = tb;
    }

    pair<int, int> update(int i, int l, int r, int x, int v){
        if(l > r)
            return {oo, oo};
        if(x < l || x > r)
            return seg[i];
        if(l == r){
            if(v < seg[i].first){
                seg[i].first = v;
                seg[i].second = x;
            }
            return seg[i];
        }
        int mid = (l + r) / 2;
        pair<int, int> ta = update(2 * i, l, mid, x, v);
        pair<int, int> tb = update(2 * i + 1, mid + 1, r, x, v);
        if(ta.first < tb.first)
            return seg[i] = ta;
        else
            return seg[i] = tb;
    }

    pair<int, int> getset(int i, int l, int r, int ll, int rr){
        if(l > r)
            return {oo, oo};
        if(r < ll || rr < l)
            return {oo, oo};
        if(ll <= l && r <= rr)
            return seg[i];
        int mid = (l + r) / 2;
        pair<int, int> ta = getset(2 * i, l, mid, ll, rr);
        pair<int, int> tb = getset(2 * i + 1, mid + 1, r, ll, rr);
        if(ta.first < tb.first)
            return seg[i] = ta;
        else
            return seg[i] = tb;
    }

    void update(int x, int v){
        update(1, 1, 100000, x, v);
    }

    pair<int, int> getset(int l, int r){
        return getset(1, 1, 100000, l, r);
    }

    void build(){
        init(1, 1, 100000);
    }

}st;

void solve(){
    st.build();
    for(int i = 1; i <= n; ++i)
        st.update(r[i], l[i]);
    int maxx = 100000;
    int cur = maxx;
    int res = 0;
    while(cur > mini){
        pair<int, int> ta = st.getset(cur, maxx);
        cout << ta.first << " " << ta.second << "\n";
        if(ta.first > cur){
            cout << -1;
            return;
        }
        ++res;
        cur = ta.first - 1;
    }
    cout << res;
}

int main()
{
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.out", "w", stdout);
    enter();
    solve();
    return 0;
}
