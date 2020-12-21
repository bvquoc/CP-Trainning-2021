#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+7;
int n, q, light[maxN];
int level3 = 0;
vector<int> adj[maxN];
void DFS(int &u, vector<int> &subset){
    bool ok[maxN] = {false};
    int cnt = 0;
    stack<int> s;
    s.push(u);
    ok[level3] = true;
    ok[u] = true;
    while(!s.empty()){
        int u = s.top(); s.pop();
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i];
            if(!ok[v]){
                subset.push_back(v);
                s.push(v);
                ok[v] = true;
            }
        }
    }
}
int main(){
    freopen("SOCKS.INP", "r", stdin);
    freopen("SOCKS.OUT", "w+", stdout);
    cin >> n >> q;
    int cntred = 0;
    for(int i = 1; i <= n; ++i){
        cin >> light[i];
        cntred += light[i];
    }
    for(int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Setup for subtask 1:
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 1; i <= n; ++i){
        if(adj[i].size() == 1) ++cnt1;
        if(adj[i].size() == 2) ++cnt2;
        if(adj[i].size() == 3){
            ++cnt3;
            level3 = i;
        }
    }
    int cntlevel = 0;
        if(light[level3] == 1)
            cntlevel = 1;
    bool checksub1 = false, checksub2 = false;
    if(cnt2 + cnt1 == n)
        checksub1 = true;
    else if(cnt1+cnt2+cnt3 == n && cnt3 == 1)
        checksub2 = true;

    int top1, top2, top3;
    vector<int> subset1, subset2, subset3;

    if(checksub1){
        if(cntred <= 1)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    else if(checksub2){
        top1 = adj[level3][0];   subset1.push_back(top1);
        top2 = adj[level3][1];   subset2.push_back(top2);
        top3 = adj[level3][2];   subset3.push_back(top3);

        DFS(top1, subset1);
        DFS(top2, subset2);
        DFS(top3, subset3);
        int cntsub1 = 0, cntsub2 = 0, cntsub3 = 0;
            for(int i = 0; i < subset1.size(); i++)
                if(light[subset1[i]] == 1)
                    ++cntsub1;
            for(int i = 0; i < subset2.size(); i++)
                if(light[subset2[i]] == 1)
                    ++cntsub2;
            for(int i = 0; i < subset3.size(); i++)
                if(light[subset3[i]] == 1)
                    ++cntsub3;
            if(cntsub2 + cntsub2 + cntsub3 + cntlevel <= 1){
                cout << 0 << "\n";
            }
            else if(cntsub1 >= 1 && cntsub2 >= 1 && cntsub3 >= 1){
                cout << 2 << "\n";
            }
            else cout << 1;
    }
    else{
        return 0;
    }
    while(q--){
        int top;
        cin >> top;
        if(light[top] == 0){
            light[top] = 1;
            cntred += 1;
        }
        else{
            light[top] = 0;
            cntred -= 1;
        }
        if(checksub1){
            if(cntred <= 1)
                cout << 0 << "\n";
            else
                cout << 1 << "\n";
        }
        else if(checksub2){
            int cntsub1 = 0, cntsub2 = 0, cntsub3 = 0;
                for(int i = 0; i < subset1.size(); i++)
                    if(light[subset1[i]] == 1)
                        ++cntsub1;
                for(int i = 0; i < subset2.size(); i++)
                    if(light[subset2[i]] == 1)
                        ++cntsub2;
                for(int i = 0; i < subset3.size(); i++)
                   if(light[subset3[i]] == 1)
                        ++cntsub3;
                if(cntsub2 + cntsub2 + cntsub3 + cntlevel <= 1){
                    cout << 0 << "\n";
                }
                else if(cntsub1 >= 1 && cntsub2 >= 1 && cntsub3 >= 1){
                    cout << 2 << "\n";
                }
                else cout << 1;
        }
    }
}
