#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int maxn=5e5+5;
vi AdjList[maxn];
int comp[maxn];
int cnt_light[maxn]; // count the number of lights in one component
int cnt_comp[maxn]; // count the number of bulbs in one component in the current segment
bool light[maxn];
bool vis[maxn];
int n,m,k;
pair<int,int> ans;
int cur_comp=0;
void dfs(int s) {
    vis[s]=true;
    if(light[s]) cnt_light[comp[s]]++;
    for(int u: AdjList[s]) {
        if(vis[u]) continue;
        comp[u]=comp[s];
        dfs(u);
    }
}
int total_light=0;
signed main() {
    freopen("DECOR.inp","r",stdin);
    freopen("DECOR.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1 ; i<=n ; i++) {
        char c;
        cin>>c;
        if(c=='0') light[i]=0;
        else {
            light[i]=1;
            total_light++;
        }
    }
    int u,v;
    for(int i=1 ; i<=m ; i++) {
        cin>>u>>v;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
    if(total_light+k==0) {
        cout<<-1;
        return 0;
    }
    if(total_light+k>=n) {
        cout<<1<<' '<<n;
        return 0;
    }
    for(int i=1 ; i<=n ; i++) {
        if(!vis[i]) {
            comp[i]=++cur_comp;
            dfs(i);
        }
    }
    int l=1;
    int r=total_light+k;
    while(l<r) {
        int mid=(l+r+1)/2;
        for(int i=1 ; i<=cur_comp ; i++) cnt_comp[i]=0;
        for(int i=1 ; i<=mid ; i++) {
            cnt_comp[comp[i]]++;
        }
        int cur_off=0;
        for(int i=1 ; i<=cur_comp ; i++) {
            if(cnt_comp[i]>cnt_light[i]) {
                cur_off+=(cnt_comp[i]-cnt_light[i]);
            }
        }
        if(cur_off<=k) {
            ans.first=1;
            ans.second=mid;
            l=mid;
            continue;
        }
        bool ok=false;
        for(int i=mid+1 ; i<=r ; i++) {
            if(cnt_comp[comp[i]]>cnt_light[comp[i]]) {
                cur_off++;
            }
            cnt_comp[comp[i]]++;
            if(cnt_comp[comp[i-mid]]>cnt_light[comp[i-mid]]) {
                cur_off--;
            }
            cnt_comp[comp[i-mid]]--;
            if(cur_off<=k) {
                ans.first=i-mid+1;
                ans.second=i;
                ok=true;
                break;
            }
        }
        if(ok) l=mid;
        else r=mid-1;
    }
    cout<<ans.first<<' '<<ans.second;
}