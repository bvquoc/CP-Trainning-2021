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
int n;
int a[maxN],pos = 0 ;
int dd[105];
struct oo {
    int tp;
    int x,y;
} q[maxN];
int res[maxN];
void UP1(int x) {
    a[++pos] = x;
}
void UP2(int x,int y) {
    FOR(i,1,pos) {
        if(a[i] == x)
            a[i] = y;
    }
}
void trau() {
      FOR(i,1,n) {
        int tp;
        char x,y;
        cin>>tp;
        if(tp == 1) {
            cin>>x;
            UP1(x -'a' + 1);
        }
        else {
            cin>>x>>y;
            UP2(x -'a' + 1 , y -'a' + 1) ;
        }
        //cout<< "tp " <<tp<<' '<<x<<' '<<y<<endl;
    }
    FOR(i,1,pos) cout<<char('a' + a[i] - 1) ;
    //cout<<endl<<" == = " <<endl;
}
void ac() {
    int N = 0;
    FOR(i,0,26)
        dd[i] = i ;
    FOR(i,1,n){
      //  cout<<" I"  <<i<<endl;
        int tp;
        char x, y;
        cin>> tp ;
        q[i].tp =tp ;
       // cout<<"Q Q Q" <<q[i].tp<<endl;
        if(tp == 1) {
            N ++;
            cin>>x;
            q[i].x = (x - 'a' + 1 ) ;
        }
        else {
            cin>>x>>y;
            q[i].x = (x - 'a'  + 1) , q[i].y = (y - 'a' + 1);
        }
    }
    int cnt = N;
    ROF(i,n,1) {
        int tmp = q[i].tp;
        int x,y;
        if(tmp == 1) {
            x = q[i].x;
           // cout<< "XX " <<N<<' '<<x<<' '<<dd[x]<<endl;
            res[N] = dd[x];
            N--;
        }
        else {
            x = q[i].x;
            y = q[i].y;
            if( x == y) continue;
            dd[x] = dd[y];
        }
       // cout<< " III " <<' '<<N<<' '<<tmp<<' '<<x<<' '<<y<<endl;
    }
    FOR(i,1,cnt)
        cout<<char('a' + res[i] -1 );
}
int main () {
    fast_read
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>n;
    if(n <= 10000)
    trau();
    else
        ac();
}
/*
10
1 c
1 b
1 a
1 c
1 d
2 a b
1 c
1 a
1 b
2 b d
*/
