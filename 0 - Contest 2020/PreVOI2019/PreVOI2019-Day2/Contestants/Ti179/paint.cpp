#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b;a<=c;++a)
#define fordec(a,b,c) for(int a=b;a>=c;--a)
#define forv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define task "paint"
const int N=1e6+5;
int n,cnt,id[N];
vector<int> ad[28];
int ans[N],node[N],cur[N];
void sub1(){
    while(n--){
        int type;
        cin>>type;
        if(type==1){
            char u;
            cin>>u;
            ans[++cnt]=u-'a';
        }
        else{
            char u,v;
            cin>>u>>v;
            forinc(i,1,cnt){
                if(ans[i]==(u-'a')) ans[i]=v-'a';
            }
            //ad[u-'a'].clear();
        }
    }
    forinc(i,1,cnt) cout<<(char)(ans[i]+'a');
}
int root(int x){return id[x]<0?x:id[x]=root(id[x]);}
void mer(int u,int v){
    u=root(u),v=root(v);
    if(u==v) return;
    if(id[u]>id[v]) swap(u,v);
    id[u]+=id[v];
    id[v]=u;
}
void sub2(){
    reset(id,-1);
    while(n--){
        int type;
        cin>>type;
        if(type==1){
            char u;
            cin>>u;
            cnt++;
            if(cur[u-'a']) mer(cur[u-'a'],cnt);
            cur[u-'a']=cnt;
            node[root(cnt)]=u-'a';
        }
        else{
            char u,v;
            cin>>u>>v;
            if(!cur[u-'a']||u==v) continue;
            //if(u=='e') cerr<<"a";
            if(!cur[v-'a']){
                node[root(cur[u-'a'])]=v-'a';
                cur[v-'a']=cur[u-'a'];
                cur[u-'a']=0;
            }
            else{
                mer(cur[u-'a'],cur[v-'a']);
                node[root(cur[u-'a'])]=v-'a';
                cur[v-'a']=max(cur[v-'a'],cur[u-'a']);
                cur[u-'a']=0;
            }
        }
    }
    //cerr<<cur['b'-'a']<<' ';
    forinc(i,1,cnt){
        int u=root(i);
        //cerr<<u<<' ';
        cout<<(char)(node[u]+'a');
    }
}
main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    if(n<=10000) sub1();
    else{
        sub2();
    }
}
