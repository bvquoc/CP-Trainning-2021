#include <iostream>
#include <bits/stdc++.h>
#define ft first
#define sc second
using namespace std;

const long long maxn = 100002;
typedef pair<long long,long long> pii ;

vector<pii> ke[maxn];
bool dua[maxn][7];
long long m, n, l, k;
long long x, y, z;
long long uwu , owo;

bool mark[1100];
bool marr[7];
long long  res = 1e15 +3;

void Inp(){
    freopen("dhaka.inp","r",stdin); freopen("dhaka.out","w",stdout);
    cin>>n>>m>>k>>l;
    for(long long i=1; i<=n; i++){
        cin>>uwu;
        while(uwu -- ){
            cin>>owo;
            dua[i][owo] = 1;
        }
    }
    for(long long i=1; i<=m; i++){
        cin>>x>>y>>z;
        ke[x].push_back(pii(y,z));
        ke[y].push_back(pii(x,z));
        //cout<<ke[x][0].ft<<" ";
    }
}

void dfs(long long node, bool  marr[7] , bool mark[11], long long  sizee ){
    if(node == n){
        long long ll = 0;
        for(long long i=1; i<=k; i++){
            if(marr[i] == 1 ) ll ++;
        }
        if( ll >= l ) res = min( res , sizee);
        return ;
    }
    mark[node] = 1;
    //cout<<node<<" ";
    bool tmp[7];
    for(long long i=1; i<= k; i++ ) tmp[i] = marr[i];
    for(long long i=1; i<=k; i++) if(dua[node][i] == 1) tmp[i]=1;
    for(long long i = 0; i< ke[node].size(); i++){
            //cout<<ke[node].size();
        long long  u = ke[node][i].ft;
        //cout<<u<<"  ";
        long long mu = ke[node][i].sc;
        if( mark[u] == 0 ) dfs( u, tmp , mark , sizee +  mu );
    }
    mark[node] = 0;
    return;
}

void sub1(){
    //for(long long i=1; i<=n; i++)
    memset( mark , 0, sizeof mark );
    memset(marr , 0 , sizeof marr );
    dfs(1, marr, mark, 0);
    if( res ==  1e15 + 3) cout<<"-1";
    else cout<<res;
}

vector< long long > dijstra(long long id){
    long long d[100002];
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(long long i=1; i<=n; i++) d[i] = 1e15+3;
    d[id]=0;
    pq.push( pii( d[id], id ) );
    while( !pq.empty()){
        long long u = pq.top().sc;
        long long du = pq.top().ft;
        pq.pop();
        if( du != d[u] ) continue;
        for(auto i : ke[u]){
            long long v = i.ft;
            long long dv = i.sc;
            if( d[v] > du+ dv ) {
                d[v] = du + dv;
                pq.push( pii( d[v], v ) );
            }
        }
    }
    vector<long long> res;
    for(long long i=1; i<=n; i++) res.push_back(d[i]);
    return res;
}

void sub2(){
    vector<long long> dd = dijstra( 1);
    if(dd[n-1]!= 1e15+3 )cout<<dd[n-1];
    else cout<<"-1";
}

void sub3(){
    vector<long long > d1 = dijstra(1);
    vector<long long> dn = dijstra(n);
    for(int i=1; i<=n; i++){
            bool ok = 0;
        for(int j= 1; j<= k; j++) if(dua[i][j]!= 0) ok = 1;
            if( ok ==1 ) res = min( res, d1[i-1] + dn[i-1]);
    }
    if( res!= 1e15+3 ) cout<<res;
    else cout<<"-1";
}

void panik(){
   // cout<<"1";
    if( n <= 10 ) sub1();
    else
    if( l == 0) sub2();
    else
        if( k==1 ) sub3();
    else cout<<"-1";
}

int main()
{
    Inp();
    panik();
    return 0;
}
