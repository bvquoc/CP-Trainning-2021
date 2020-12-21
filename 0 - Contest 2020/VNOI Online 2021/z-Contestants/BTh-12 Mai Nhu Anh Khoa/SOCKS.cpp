#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int maxN=5e5+5;
int n, q, cnt, dem[10], a[maxN], f[maxN];
vector<int> tmp;
vector<int> h[maxN];
bool check_Sub1(){
    for (int i=1; i<=n; ++i) if (h[i].size()>2) return false;
    return true;
}
int Find(){
    for (int i=1; i<=n; ++i) if (h[i].size()==3) return i;
    return 1;
}
void flip(int X){
    if (a[X]==0){
        a[X]=1;
        ++cnt;
    }
    else{
        a[X]=0;
        --cnt;
    }
}
void dfs(int u, int par, int cl){
    f[u]=cl;
    for (int i=0; i<h[u].size(); ++i){
        int v=h[u][i];
        if (v==par) continue;

        dfs(v, u, cl);
    }
}
int check_dem(){
    int ans=0;
    for (int i=1; i<=3; ++i){
        ans+=(dem[i]>0);
    }
    if (ans==0) return (dem[0]!=0);
    else return (ans+1)/2;
}
int main()
{
    ifstream cin("SOCKS.INP");
    ofstream cout("SOCKS.OUT");
    cin >> n >> q;
    for (int i=1; i<=n; ++i) {
        int x;
        cin >> x;
        if (x==1) tmp.pb(i);
    }
    for (int i=1; i<n; ++i){
        int u, v;
        cin >> u >> v;
        h[u].pb(v);
        h[v].pb(u);
    }
    if (check_Sub1()){
        for (int i=0; i<tmp.size(); ++i){
            flip(tmp[i]);
        }
        if (cnt) cout << 1 << endl;
        else cout << 0 << endl;
        while (q--){
            int x;
            cin >> x;
            flip(x);
            if (cnt) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    else{
        int u=Find();
        int ti=0;
        for (int i=0; i<h[u].size(); ++i){
            dfs(h[u][i], u, ++ti);
        }
        for (int i=0; i<tmp.size(); ++i){
            ++dem[f[tmp[i]]];
            a[tmp[i]]=1;
        }
        cout << check_dem() << endl;
        while (q--){
            int x;
            cin >> x;
            if (a[x]==0){
                a[x]=1;
                ++dem[f[x]];
            }
            else{
                a[x]=0;
                --dem[f[x]];
            }
            cout << check_dem() << endl;
        }
    }
    return 0;
}
