#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
typedef vector<int> vi;
vi AdjList[maxn];
int deg[maxn];
int cnt3=0;
int n,q;
int col[maxn];
int qr[maxn];
void solve1() {
    //cout<<"solve 1\n";
    int cnt1=0;
    for(int i=1 ; i<=n ; i++) {
        if(col[i]==1) cnt1++;
    }
    cout<<(cnt1>=2)<<'\n';
    for(int i=1 ; i<=q ; i++) {
        int u=qr[i];
        //cout<<"u = "<<u<<endl;
        //cout<<"col = "<<col[u]<<endl;
        if(col[u]==1) {
            cnt1--;
        }
        else {
            cnt1++;
        }
        //cout<<"cnt1 = "<<cnt1<<endl;
        col[u]=1-col[u];
        cout<<(cnt1>=2)<<'\n';
    }
}
int comp[maxn];
void dfs2(int s, int p) {
    //cout<<"comp "<<s<<" = "<<comp[s]<<endl;
    for(int u: AdjList[s]) {
        if(u==p) continue;
        comp[u]=comp[s];
        dfs2(u,s);
    }
}
void solve2() {
    int root;
    for(int i=1 ; i<=n ; i++) {
        if(deg[i]==3) root=i;
    }
    int c1[3];
    int cnt1=0;
    for(int i=0 ; i<AdjList[root].size() ; i++) {
        int u=AdjList[root][i];
        //cout<<"u = "<<u<<endl;
        comp[u]=i;
        c1[i]=0;
        dfs2(u,root);
    }
    for(int i=1 ; i<=n ; i++) {
        if(col[i]==1&&i!=root) {
            c1[comp[i]]++;
            cnt1++;
        }
    }
    if(cnt1<=2) {
        cout<<0<<'\n';
    }
    else if(c1[0]&&c1[1]&&c1[2]) {
        cout<<2<<'\n';
    }
    else cout<<1<<'\n';
    for(int i=1 ; i<=q ; i++) {
        int u=qr[i];
        if(col[u]==1) {
            cnt1--;
            c1[comp[u]]--;
        }
        if(col[u]==0) {
            cnt1++;
            c1[comp[u]]++;
        }
        col[u]=1-col[u];
        //cout<<cnt1<<" "<<c1[0]<<" "<<c1[1]<<" "<<c1[2]<<endl;
        if(cnt1<=2) {
            cout<<0<<'\n';
        }
        else if(c1[0]&&c1[1]&&c1[2]) {
            cout<<2<<'\n';
        }
        else cout<<1<<'\n';
    }
}
int ans;
int cnt[maxn];
void dfs(int s, int p=-1) {
    if(col[s]==1&&deg[s]==1&&p!=-1) {
        cnt[s]=1;
        return;
    }
    cnt[s]=0;
    for(int u: AdjList[s]) {
        if(u==p) continue;
        dfs(u,s);
        cnt[s]+=(cnt[u]%2);
        ans+=cnt[s]/2;
    }
}
void solve() {
    ans=0;
    dfs(1);
    cout<<ans+1<<'\n';
    for(int i=1 ; i<=q ; i++) {
        int u=qr[i];
        col[u]=1-col[u];
        ans=0;
        dfs(1);
        cout<<ans+1<<'\n';
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    cin>>n>>q;
    for(int i=1 ; i<=n ; i++) {
        cin>>col[i];
    }
    for(int i=1 ; i<n ; i++) {
        int u,v;
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    for(int i=1 ; i<=q ; i++) cin>>qr[i];
    for(int i=1 ; i<=n ; i++) {
        if(deg[i]>3) cnt3+=2;
        if(deg[i]==3) cnt3++;
    }
    //cout<<"cnt3 = "<<cnt3<<endl;
    if(cnt3==0) {
        solve1();
        return 0;
    }
    if(cnt3==1) {
        solve2();
        return 0;
    }
    solve();
    //if(cnt3==1) solve2();
    //if(n<=1000&&q<=1000) solve3();
}
/*
subtask 1
7 10
1 0 0 0 0 0 0 0
3 2
2 4
4 7
7 6
6 5
5 1
3
1
2
2
4
6
6
7
5
1
*/
