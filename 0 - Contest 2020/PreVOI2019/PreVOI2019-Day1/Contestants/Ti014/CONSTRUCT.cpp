#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "construct"
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

const int N=50010;

int n,m;
int bit[N],lf[N],rt[N],a[N];

void upd(int i,int x){
    for(;i<=n;i+=i&-i) bit[i]+=x;
}
int que(int i){
    int ret=0;
    for(;i;i-=i&-i) ret+=bit[i];
    return ret;
}

main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    fasty;
    int T; cin>>T; while(T--){
        cin>>n>>m;
        forinc(i,1,n) cin>>a[i];
        forinc(i,1,m){
            int type; cin>>type;
            if(type==1){
                int l,r,k; cin>>l>>r>>k;
                forinc(j,l,r) a[j]+=k;
            } else{
                int l,r; cin>>l>>r;
                stack<int> st; st.push(0); a[0]=a[n+1]=-1;
                forinc(j,l,r){
                    while(a[st.top()]>=a[j]) st.pop();
                    lf[j]=st.top()+1;
                    st.push(j);
                }
                while(st.size()) st.pop(); st.push(n+1);
                fordec(j,r,l){
                    while(a[st.top()]>=a[j]) st.pop();
                    rt[j]=st.top()-1;
                    st.push(j);
                }
                vector<int> pos;
                forinc(j,l,r) pos.pb(j);
                sort(all(pos),[](int x,int y){
                     return a[x]<a[y];
                });
                int ret=0;
                forv(j,pos){
                    int has=que(j);
                    int sub=a[j]-has;
                    upd(lf[j],sub);
                    upd(rt[j]+1,-sub);
                    ret+=sub;
                }
                cout<<ret<<"\n";
                reset(bit,0);
            }
        }
    }
}

