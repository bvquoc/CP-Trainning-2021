#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define forinc(a,b,c) for(int a=b;a<=c;++a)
#define fordec(a,b,c) for(int a=b;a>=c;--a)
#define forv(a,b) for(auto &a:b)
#define fi first
#define se second
#define ii pair<int,int>
#define i3 pair<int,ii>
#define vt vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define task "fixstr"
const int N=1e6+5;
int n,m,cnt=0;
string s[N];
void sub1(){
    s[0]=' '+s[0];
    while(m--){
        char u;int v;
        cin>>u>>v;
        cnt++;
        s[cnt]=s[cnt-1];
        //cerr<<s[cnt]<<' ';
        if(u=='C'){
            if(s[cnt][v]=='(') s[cnt][v]=')';
            else s[cnt][v]='(';
            //cerr<<s[cnt]<<' ';
        }
        else if(u=='Q'){
            int g;
            cin>>g;
            //cerr<<s[cnt]<<'\n';
            int l=v,r=g;
            int ans=0,dem=0;
            forinc(i,l,r){
                //cerr<<i<<' '<<' '<<s[cnt][i]<<' ';
                if(((s[cnt][i])=='(')) dem++;
                else{
                    if(dem>0) dem--;
                    else if(dem==0) ans++;
                }
                //cerr<<cnt<<' ';
            }
            //cerr<<s[cnt]<<'\n';
            ///cerr<<'\n';
            //cerr<<t.size()<<' ';
            ans+=dem;
            cout<<ans<<'\n';
        }
        else s[cnt]=s[v-1];
        //cerr<<s[cnt]<<'\n';
    }
}
main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>s[0]>>m;
    n=s[0].size();
    if(n<=1000&&m<=1000) sub1();
}
