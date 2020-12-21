#include <bits/stdc++.h>
#define task "SOCKS"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define N 500005
using namespace std;
typedef pair<int, int> ii;

vector<int> Cnt[N];
bool Status[N];
int Line[N];
int n,Q;
int Sub1(){
    int Lighting = 0;
    REP(i,1,n) Lighting += Status[i];
    if (Lighting >1) cout<<"1"<<"\n";
    while(Q--){
        int id;
        cin>>id;
        if (Status[id] == 0) Lighting++;
        else Lighting--;
        Status[id] = !Status[id];
        if (Lighting >1) cout<<"1"<<"\n";else cout<<"0"<<"\n";
    }
    return 0;
}
int Build2(int Node,int L, int Par){
    if (Cnt[Node].size() == 3){
        Line[Node] = 0;
        REP(i,0,2){
            Build2(Cnt[Node][i], i+1, Node);
        }
    }
    else{
        Line[Node] = L;
        if (Cnt[Node][0] != Par) Build2(Cnt[Node][0], L, Node);
        else if (Cnt[Node].size() == 2 && Cnt[Node][1] != Par) Build2(Cnt[Node][1], L, Node);
    }
    return 0;
}
int Sub2(){
    int T; int Apping = 0 ;
    REP(i,1,n){
        if (Cnt[i].size() ==3){
            T = i;
            break;
        }
    }
    REP(i,1,n) Apping += Status[i];
    int App[4];
    memset(App, 0, sizeof(App));
    if (Apping <=1) cout<<"0"<<"\n";
        else
            if (Apping == 2) cout<<"1"<<"\n";
        else{
            int ans = 0;
            REP(i,1,3) ans += (App[i] >0);
            cout<<ans<<"\n";
        }
    Build2(T,0,0);
    while(Q--){
        int id;
        cin>>id;
        if (Status[id] == 0){
            App[Line[id]]++;
            Apping++;
        }
        else{
            App[Line[id]]--;
            Apping--;
        }
        Status[id] = !Status[id];
        if (Apping <=1) cout<<"0"<<"\n";
        else
            if (Apping == 2) cout<<"1"<<"\n";
        else{
            int ans = 0;
            REP(i,1,3) ans += (App[i] >0);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>Q;
    bool IsLine = true;
    int TSidded = 0;
    REP(i,1,n) cin>>Status[i];
    REP(i,1,n-1){
        int u,v;
        cin>>u>>v;
        Cnt[u].push_back(v);
        Cnt[v].push_back(u);
    }
    REP(i,1,n){
        if (Cnt[i].size() > 2) IsLine = false;
        if (Cnt[i].size() ==3) TSidded++;
    }
    if (IsLine){
        Sub1();
        return 0;
    }
    if (TSidded == 1){
        Sub2();
        return 0;
    }
    else{
        cout<<"0";
        return 0;
    }
}
