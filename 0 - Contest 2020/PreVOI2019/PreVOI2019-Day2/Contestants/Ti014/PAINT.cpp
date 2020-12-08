#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "PAINT"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))

const int N=1000010;

int n;
int id[N],co[N],has[N];

int root(int x){
    return !id[x]?x:id[x]=root(id[x]);
}
void join(int x,int y){
    if((x=root(x))==(y=root(y))) return;
    id[y]=x;
}

main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    fasty;
    int T; cin>>T; while(T--){
        int type; cin>>type;
        if(type==1){
            char ch; cin>>ch;
            co[++n]=ch-'a';
            if(has[ch-'a']){
                join(n,has[ch-'a']);
            } else{
                has[ch-'a']=n;
            }
        } else{
            char x,y; cin>>x>>y;
            if(!has[x-'a']) continue;
            if(!has[y-'a']){
                has[y-'a']=has[x-'a'];
                co[root(has[x-'a'])]=y-'a';
                if(x!=y) has[x-'a']=0;
            } else{
                join(has[y-'a'],has[x-'a']);
                if(x!=y) has[x-'a']=0;
            }
        }
    }
    forinc(i,1,n) cout<<(char)(co[root(i)]+'a');
}

