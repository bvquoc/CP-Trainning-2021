#include <bits/stdc++.h>
#define task "COOLMAC"
#define REP(i,a,b) for(int i = a; i<=b;++i)
#define X first
#define Y second
#define N 100005
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
set<int> S;
ii Gear[N];
iii P[2*N];
int minT;
int Lines = 0;
int PreEnd;
int n,m;
int main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m;
    REP(i,1,m){
        cin>>Gear[i].X>>Gear[i].Y;
    }
    cin>>n;
    minT = N;
    REP(i,1,n){
        int t;
        cin>>t;
        minT = min(minT,t);
    }
    REP(i,1,m){
        if (Gear[i].Y >= minT){
            P[i] = iii(Gear[i].X, ii(i,1));
            P[i+m] = iii(Gear[i].Y, ii(i,2));
        }
    }
    sort(P+1, P+1+2*m);
    PreEnd = P[1].X;
    int ans = 0;
    if (P[m*2].X <100000){
        cout<<"-1";
        return 0;
    }
    REP(i,1,m*2){
        if (P[i].Y.Y == 1){
            if (Lines == 0 && P[i].X > PreEnd){
                cout<<"-1";
                return 0;
            }
            Lines++;
            S.insert(P[i].Y.X);
        }
        if (P[i].Y.Y == 2){
            if (Lines == 1) ans++;
            int id = *S.begin();
            if (Lines >1 && P[i].Y.X == id) ans++;
            Lines --;
            S.erase(P[i].Y.X);
        }
    }
    cout<<ans;
    return 0;
}
