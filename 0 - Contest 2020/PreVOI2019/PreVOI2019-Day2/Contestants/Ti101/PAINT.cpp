#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

const int N = int(1e6) + 7;
const int oo = int(1e9) + 9;
const int nAlpha = 'z' - 'a' + 1;
typedef pair<int, int> pii;
typedef tuple<int, int, int> TQuery;

TQuery q[N];
int n, lab[N], cmd, top[nAlpha];
char c, x, y;
vector<int> ans;

int Find(int x) {return lab[x] < 0? x: lab[x] = Find(lab[x]);}
void Union(int r, int s) {
    if(r == s) return;
    if(lab[r] > lab[s]) swap(r, s);
    lab[r] += lab[s], lab[s] = r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "paint"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n; memset(&lab, -1, sizeof lab);
    memset(&top, -1, sizeof top);
    for(int i = 1; i <= n; ++i) {
        cin >> cmd >> x; x -= 'a';
        if(cmd == 2) {
            cin >> y; y -= 'a';
            if(top[x] == -1) continue;
            if(x == y) continue;
            if(top[y] == -1) top[y] = top[x];
            else {
                int r = Find(top[y]), s = Find(top[x]);
                Union(r, s);
            }
            top[x] = -1;
        } else {
            if(top[x] == -1) top[x] = i;
            else {
                int r = Find(top[x]), s = Find(i);
                Union(r, s);
            }
            ans.pb(i);
        }
    }
    for(int pos: ans) {
        for(int i = 0; i < nAlpha; ++i) {
            if(top[i] != -1 && Find(top[i]) == Find(pos)) {
                cout << char(i + 'a'); break;
            }
        }
    }
}
