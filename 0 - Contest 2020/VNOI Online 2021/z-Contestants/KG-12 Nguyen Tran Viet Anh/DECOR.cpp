#define TASK "DECOR"
#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define ENDL "\n"
using namespace std;

const int MAX = 5e5+6;

int n, d[MAX], cnt, bo[MAX], vs[MAX], m, k;
string s;
int res, l=1;
vector<int> g[MAX];

void DFS(int u){
    vs[u] = cnt;
    for(int i=0; i < g[u].size(); i++){
        int v= g[u][i];
        if (!vs[v]) DFS(v);
    }
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#ifndef ONLINE_JUDGE
	    //freopen("input.txt","r",stdin);
		freopen(TASK".INP","r", stdin);
		freopen(TASK".OUT","w", stdout);
	#endif

    cin >> n >> m >> k;
    cin >> s;
    s=  ' ' + s;
    for(int i =1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if (!vs[i]) {
            cnt++;
            DFS(i);
        }
    }
    for(int i=1; i<=n; i++){
        if (s[i]=='1'){
            d[vs[i]]++;
        }
    }
    int j = 1, rem = k;
    for(int i =1; i<=n; i++){
        if (i > 1){
            if (bo[i-1] == cnt+1) rem++;
            else d[bo[i-1]]++;
        }
        j = max(j, i);
        while (j<=n){
            if (d[vs[j]]){
                d[vs[j]]--;
                bo[j] = vs[j];
                j++;
            }
            else if (rem){
                rem--;
                bo[j] = cnt+1;
                j++;
            }
            else break;
        }
        if (res < j-i){
            res = j-i;
            l = i;
        }
    }
    if (res ==0){
        cout << -1;
        return 0;
    }
    cout << l << " " << l + res -1;
	return 0;
}
