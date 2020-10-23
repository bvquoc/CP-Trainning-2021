#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b; i++)

using namespace std;

const int NMAX = 1000005;
const int INF = 1000000005;

int a[NMAX], st[NMAX*2], n;

void init(int id, int l, int r, int i, int v){
    if (i < l || i > r){
        return;
    }
    if (l == r){
        st[id] = v;
    }
    else{
        int mid = (l + r) / 2;
        init(id * 2, l, mid, i, v);
        init(id * 2 + 1, mid + 1, r, i, v);
        /*
        if (a[st[2 * id]] <= a[st[2 * id + 1]]){
            st[id] = st[2 * id];
        }
        else{
            st[id] = st[2 * id + 1];
        }
        */
        st[id] = min(st[id * 2], st[id * 2 + 1]);
    }

}

int get(int id, int l, int r, int u, int v){
    if (v < l || r < u){
        return INF;
    }
    if (u <= l && r <= v){
        return st[id];
    }
    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int isEdge(int l){
    FOR(i, 1, n - l + 1){
        int tmp = get(1, 1, n, i, i + l - 1);
        if (tmp >= l){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    ifstream fi("SHOPSIGN.INP");
    ofstream fo("SHOPSIGN.OUT");
    fi >> n;
    fill(st, st + 2*n, 1000000);
    int hi = 0;
    FOR(i, 1, n){
        fi >> a[i];
        init(1, 1, n, i, a[i]);
        hi = max(hi, a[i]);
    }

    int ans;
    int lo = 1;
    while (lo <= hi){
        int l = (lo + hi) / 2;
        if (isEdge(l)){
            lo = l + 1;
            ans = l;
        }
        else {
            hi = l - 1;
        }
    }
    fo << ans << "\n";
    return 0;
}
