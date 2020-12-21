#include<bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){ return rng()%(r-l+1)+l;}
#define pii pair<int,int>
#define fi first
#define se second
#define getbit(i,x) ((x>>i)&1ll)
#define tatbit(i,x) (x&~(1ll<<i))
#define batbit(i,x) (x|(1ll<<i))

const int maxn=1e5+5;
int n,m,A[maxn];
pii M[maxn];
int ret,ok;
int cur_pos;

bool dk(pii X,pii Y){
    if(X.se==Y.se) return X.fi<Y.fi;
    return X.se<Y.se;
}

main(){
    freopen("COOLMAC.inp","r",stdin);
    freopen("COOLMAC.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>m;
    forinc(i,1,m) cin>>M[i].fi>>M[i].se;
    cin>>n;
    forinc(i,1,n) cin>>A[i];

    sort(M+1,M+m+1,dk);
    sort(A+1,A+n+1);

    int id=m,cur_pos=1e5;
    if(M[id].se!=1e5) return cout<<-1,0;


    while(id>0){
        int j=id;
        int Lf=1e5+6;
        while(M[j].se>=cur_pos&&j>=1){
            Lf=min(Lf,M[j].fi);
            j--;
        }
      //  cout<<j<<" "<<Lf<<"\n";
        if(Lf==1e5+6) return cout<<-1,0;
        ret++;
        cur_pos=Lf;
        if(Lf<=A[1]){
         //   cout<<id<<" "<<Lf<<" "<<A[1]<<"\n";
            ok=1;
            break;
        }
        id=j;
    }
    if(!ok) cout<<-1;
    else cout<<ret;

}
