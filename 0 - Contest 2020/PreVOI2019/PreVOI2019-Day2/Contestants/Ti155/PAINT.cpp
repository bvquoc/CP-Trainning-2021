#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Task "PAINT"

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

int lab[maxn + 26];
char col[maxn];
int last[26];
int finds(int u)
{
    if (lab[u] == u) return u;
    return lab[u] = finds(lab[u]);
}

void merges(int u, int v)
{
    u = finds(u); v = finds(v);
    if (u == v) return;
    lab[v] = u;
    col[v] = col[u];
}

int Q;

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> Q;
    fill(begin(last), end(last), -1);
    int nowpos = 0;
    for (int i=1; i<=Q; ++i){
        int type;
        char x, y;
        cin >> type >> x;
        if (type == 1){
            ++nowpos;
            if (last[x - 'a'] == -1){
                col[nowpos] = x;
                last[x - 'a'] = nowpos;
                lab[nowpos] = nowpos;
            }
            else{
                lab[nowpos] = nowpos;
                col[nowpos] = x;
                merges(last[x - 'a'], nowpos);
                last[x - 'a'] = nowpos;
            }
        }
        else{
            char y;
            cin >> y;
            if (last[x-'a'] == -1) continue;
            if (last[y-'a'] != -1){
                merges(last[y-'a'], last[x-'a']);
                last[x - 'a'] = -1;
            }
            else{
                col[finds(last[x - 'a'])] = y;
                last[y - 'a'] = last[x - 'a'];
                last[x - 'a'] = -1;
            }
        }
    }
    for (int i=1; i<=nowpos; ++i){
        cout << col[finds(i)];
    }
}
