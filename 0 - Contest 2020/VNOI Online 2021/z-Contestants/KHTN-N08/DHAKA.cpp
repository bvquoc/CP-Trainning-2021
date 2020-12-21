#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int inf=1e18;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int maxn=1e5+5;
vii AdjList[maxn];
bool ck[maxn][6];
int dist[maxn][35];
priority_queue<iii,vector<iii>,greater<iii>> pq;
int n,m,k,l;
void dijkstra() {
    while(!pq.empty()) {
        iii bruh=pq.top();
        int cur_bit=bruh.second.second;
        int cur_v=bruh.second.first;
        int cur_dist=bruh.first;
        pq.pop();
        if(dist[cur_v][cur_bit]<cur_dist) continue;
        for(ii tmp: AdjList[cur_v]) {
            int nxt_v=tmp.first;
            int w=tmp.second;
            int nxt_bit=0;
            for(int i=0 ; i<k ; i++) {
                if(ck[nxt_v][i]) nxt_bit+=(1<<i);
                else if(cur_bit&(1<<i)) nxt_bit+=(1<<i);
                if(dist[nxt_v][nxt_bit]>cur_dist+w) {
                    dist[nxt_v][nxt_bit]=cur_dist+w;
                    pq.push(iii(cur_dist+w,ii(nxt_v,nxt_bit)));
                }
            }
        }
    }
}
signed main() {
    freopen("DHAKA.inp","r",stdin);
    freopen("DHAKA.out","w",stdout);
    cin>>n>>m>>k>>l;
    int cnt,tmp,u,v,w;
    for(int i=1 ; i<=n ; i++) {
        cin>>cnt;
        for(int j=1 ; j<=cnt ; j++) {
            cin>>tmp;
            tmp--;
            ck[i][tmp]=true;
        }
    }
    for(int i=1 ; i<=m ; i++) {
        cin>>u>>v>>w;
        AdjList[u].push_back(ii(v,w));
        AdjList[v].push_back(ii(u,w));
    }
    for(int i=1 ; i<=n ; i++) {
        for(int j=0 ; j<(1<<k) ; j++) {
            dist[i][j]=inf;
        }
    } 
    int st_bit=0;
    for(int i=0 ; i<k ; i++) {
        if(ck[1][i]) st_bit+=(1<<i);
    }
    dist[1][st_bit]=0;
    pq.push(iii(0,ii(1,st_bit)));
    dijkstra();
    int ans=inf;
    for(int bit=0 ; bit<(1<<k) ; bit++) {
        if(__builtin_popcount(bit)<l) continue;
        ans=min(ans,dist[n][bit]);
    }
    if(ans==inf) cout<<-1;
    else cout<<ans;
}