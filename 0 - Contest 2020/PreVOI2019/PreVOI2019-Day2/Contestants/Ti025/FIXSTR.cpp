#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define ROF(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define maxN 1000005
#define Bit(i,j) ((j>>i)&1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m;
int a[1005][1005];
string s;

int b[maxN];
struct node {
    int val;
    int le ;
    int ri ;
} t[maxN*8];
node add(node a,node b) {
//    cout<<"ADD " <<endl;
//    cout<<" AA " <<a.val<<' '<<a.le<<' ' <<a.ri<<endl;
//    cout<<" BB " <<b.val<<' '<<b.le<<' ' <<b.ri<<endl;
    int res = a.le < b.ri ? a.le : b.ri;
    //cout<<val<<' '<<le<<' '<<ri<<' '<<" RES"  <<res<<endl;
    return {a.val + b.val + res ,a.le + b.le - res,a.ri + b.ri - res};
}
void trau() {
    n = s.size();
    FOR(i,1,n) {
        if(s[i-1] == '(')
            a[0][i] = 1;
        else
            a[0][i] = -1;
    }
    cin>>m;
    FOR(i,1,m) {
      //  cout<< " q" <<i<<endl;
        FOR(j,1,n) {
            a[i][j] = a[i-1][j];
           // cout<<a[i][j];
        }
      //  cout<<endl;
        char tp;
        cin>>tp;
        if(tp == 'C') {
            int x;
            cin>>x;
            a[i][x] = a[i][x] * (-1);
            continue;
        }
        if(tp == 'Q') {
            int x,y;
            cin>>x>>y;
            int le = 0 , ri = 0 ;
            int cur =0  ;
            int res = y - x + 1;
            FOR(k,x,y) {
                if(a[i][k] == -1 && le > 0) {
                    le --;
                    res -= 2;
                    continue;
                }
                if(a[i][k] == 1) {
                    le++;
                    continue;
                }
            }
            cout<<res<<'\n';
            continue;
        }
        if( tp == 'U') {
            int k;
            cin>>k;
            FOR(j,1,n)
            a[i][j] = a[k-1][j];
            continue;
        }
    }
    //cout<<"TRAU "<<endl;
}
void update(int id,int l,int r,int u,int val) {
    //cout<< " UP  " <<id<<' '<<l<<' '<<r<<endl;
    if(l > u || r < u ) return;
    if(l == r) {
        if(val == 1)
        t[id] = {0,1,0};
        else t[id] ={0,0,1};
        return;
    }
    int c = (l + r)/2;
    update(id*2,l,c,u,val);
    update(id*2 +1,c+1,r,u,val);
    t[id] = add(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v) {
   // cout<<"get " <<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
    if(l > v || r < u ) return {0,0,0};
    if(l >= u && r <= v) return t[id];
    int c = (l + r)/2;
    return (add(get(id*2,l,c,u,v),get(id*2 +1,c+1,r,u,v)));
}
void ac() {
   // cout<< "s " <<s<<endl;
    n = s.size();
    FOR(i,1,n) {
        if(s[i-1] == '(')
            b[i] = 1;
        else
            b[i] = -1;
        update(1,1,n,i,b[i]);
    }
     cin>>m;
    // cout<< "m " <<m<<endl;
    FOR(i,1,m) {
       // cout<< " I " <<i<<endl;
        char tp;
        cin>>tp;
       // cout<< " TP " <<tp<<endl;
        if(tp == 'C') {
            int x;
            cin>>x;
            b[x] *=(-1);
           // cout<< " XX"  <<x<<' '<<b[x]<<endl;
            update(1,1,n,x,b[x]);
            continue;
        }
        if(tp == 'Q') {
            int x,y;
            cin>>x>>y;
//            int sl = get(1,1,n,x,y).val;
//            int le = get(1,1,n,x,y).le;
//            int ri = get(1,1,n,x,y).ri;
           // cout<<"SL " <<sl<<' '<<le<<' '<<ri<<endl;
            int res = (y - x + 1 - 2*get(1,1,n,x,y).val);
            cout<<res<<'\n';
            continue;
        }
    }
    //cerr<<(double)clock()/1000<<endl;
}
int main () {
    fast_read
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s;
    if(n <= 1000)
        trau();
    else
        ac();
}
/*
4 6 1 2 6
*/
