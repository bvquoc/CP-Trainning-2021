#include <bits/stdc++.h>
#define maxn 500005
#define maxc 1000000007
#define MOD 1000000007
#define task "DECOR"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
using namespace std;

int n, m, k;
string s;
int p[maxn], root[maxn], cnt[maxn], ans = 0;
pii pos;

int get_root(int u){
    return (!root[u]) ? u : root[u] = get_root(root[u]);
}

void add(int u, int v){
    u = get_root(u);
    v = get_root(v);
    if(u != v){
        root[u] = v;
        p[v] += p[u];
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n >> m >> k >> s;
    s = ' ' + s;
    for(int i = 1; i <= n; ++ i){
        char x = s[i];
        p[i] = x - '0';
    }
    for(int i = 1; i <= m; ++ i){
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    int run = 1, sl = 0;
    for(int i = 1; i <= n; ++ i){
        int x = get_root(i);
        cnt[x] ++;
        if(cnt[x] > p[x]){
            ++ sl;
        }
        while(p[x] < cnt[x] && run <= i && sl > k){
            int u = get_root(run);
            if(cnt[u] > p[u]) -- sl;
            cnt[u] --;
            ++ run;
        }
        if(run <= i){
            int res = i - run + 1;
            if(res > ans){
                pos = {run, i};
                ans = res;
            }
        }
    }
    if(ans == 0) {
        cout << -1;
        return 0;
    }
    cout << pos.F << " " << pos.S;
    return 0;
}
