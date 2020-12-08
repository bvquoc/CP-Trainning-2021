#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define Task "FIXSTR"
//FIXSTR

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 1000015;
const int inf = 0x3f3f3f3f;

void InOut();
#define debug(X) cout << #X << " = " << X << '\n'
string s;
string w[1111];
int n, m;

char o[N];
int pre[N];
struct ABC{
    int mi, lazy;
    ABC(int _mi = 0, int _lazy = 0){
        mi = _mi;
        lazy = _lazy;
    }
};
ABC sg[N * 4];

void down(int id){
    int d = sg[id].lazy;
    if (d == 0) return;
    sg[id * 2].mi += d;
    sg[id * 2].lazy += d;

    sg[id * 2 + 1].mi += d;
    sg[id * 2 + 1].lazy += d;

    sg[id].lazy = 0;
}
void update(int l, int r, int id, int u, int v, int d){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        sg[id].mi += d;
        sg[id].lazy += d;
        return;
    }
    down(id);
    int mid = (l + r) / 2;
    update(l, mid, id * 2, u, v, d);
    update(mid + 1, r, id * 2 + 1, u, v, d);
    sg[id].mi = min(sg[id * 2].mi, sg[id * 2 + 1].mi);
}
int getmin(int l, int r, int id, int u, int v){
    if (l > v || r < u) return inf;
    if (u <= l && r <= v) return sg[id].mi;
    down(id);
    int mid = (l + r) / 2;
    return min(getmin(l, mid, id * 2, u, v), getmin(mid + 1, r, id * 2 + 1, u, v) );
}

void subtask1(){
    w[0] = s;
    for(int i = 1; i <= m; ++i){
        char c;
        cin >> c;
        int l, r;
        w[i] = w[i-1];
        if (c == 'C') {
            cin >> l;
            l--;
            if (w[i][l] == '(') w[i][l] = ')';
            else w[i][l] = '(';
        } else if (c == 'Q'){
            int cur = 0;
            cin >> l >> r;
            l--; r--;
            int mi = inf;
            for(int id = l; id <= r; ++id){
                if (w[i][id] == '(') cur++;
                else cur--;
                mi = min(mi, cur);
            }
            int ans = 0;
            if (mi < 0){
                int d = 0 - mi; ans = ans + d; cur = cur + d;
            }
            if (cur > 0){
                int d = cur; ans = ans + d;
            }
            cout << ans << '\n';
        } else {
            cin >> l;
            w[i] = w[l-1];
        }
    }
}
void subtask2(){
    for(int i = 1; i <= n; ++i){
        o[i] = s[i - 1];
        if (o[i] == '(') pre[i] = pre[i-1] + 1;
        else pre[i] = pre[i-1] - 1;
        update(1, n, 1, i, i, pre[i]);
    }

    for(int i = 1; i <= m; ++i){
        char c;
        cin >> c;
        int l, r;
        if (c == 'C') {
            cin >> l;
            if (o[l] == '(') {
                o[l] = ')';
                update(1, n, 1, l, n, -2);
            } else {
                o[l] = '(';
                update(1, n, 1, l, n, 2);
            }
        } else if (c == 'Q'){
            int cur = 0, bf = 0, ans = 0;
            cin >> l >> r;
            int mi = getmin(1, n, 1, l, r);
            cur = getmin(1, n, 1, r, r);
            if (l > 1) bf = getmin(1, n, 1, l - 1, l - 1);
            else bf = 0;
            mi -= bf; cur -= bf;
            if (mi < 0){
                int d = 0 - mi; ans = ans + d; cur = cur + d;
            }
            if (cur > 0){
                int d = cur; ans = ans + d;
            }
            cout << ans << '\n';
        }
    }
}

int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    n = sz(s);
    cin >> m;
    if (n <= 1000 && m <= 1000)
        subtask1();
    else
        subtask2();

return 0;
}

void InOut(){
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}


