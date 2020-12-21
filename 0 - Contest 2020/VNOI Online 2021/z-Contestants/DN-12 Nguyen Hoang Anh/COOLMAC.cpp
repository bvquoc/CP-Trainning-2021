/* This code is written by 18to_nhanh */
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Tourist "COOLMAC"
#define fi first
#define se second
#define ll long long
#define sz(v) (int)(v.size())
#define get_bit(x,i) (x >>(i-1)&1)
#define countbit_one(n) __builtin_popcountll(n)
#define INC(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int base = 31;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<pi> vpi;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int m,n;
int minn = INF;
//int dp[maxn+5];
int dp_sub_2[maxn+5];
pi G[maxn+5];
struct ii{
    int sum,lazy;
};
ii IT[4*maxn+5];
bool cmp(pi A,pi B){
   return A.se < B.se ||(A.se == B.se && A.fi < B.fi);
}
void build(int id,int left,int right){
    if(left == right){
        IT[id] = {0,0};
        return;
    }
    int mid = (left + right) >> 1;
    build(id*2,left,mid);
    build(id*2+1,mid+1,right);
    IT[id].sum = IT[id*2].sum + IT[id*2+1].sum;
    IT[id].lazy = IT[id*2].lazy + IT[id*2+1].lazy;
}
void push(int id){
    int tmp = IT[id].lazy;
    IT[id*2].lazy += tmp;
    IT[id*2].sum += tmp;
    IT[id*2+1].lazy += tmp;
    IT[id*2+1].sum += tmp;
    IT[id].sum = min(IT[id*2].sum,IT[id*2+1].sum);
    IT[id].lazy = 0;
}
void update(int id,int L,int R,int u,int v,int val){
    if(v < L || R < u) return;
    if(u <= L && R <= v){
        IT[id].lazy += val;
        IT[id].sum += val;
        return;
    }
    push(id);
    int mid = (L + R) >> 1;
    update(id*2,L,mid,u,v,val);
    update(id*2+1,mid+1,R,u,v,val);
    IT[id].sum = min(IT[id*2].sum,IT[id*2+1].sum);
}
int get(int id,int L,int R,int u,int v){
    if(v < L || R < u) return INF;
    if(u <= L && R <= v) return IT[id].sum;
    push(id);
    int mid = (L + R) >> 1;
    int tmp1 = get(id*2,L,mid,u,v);
    int tmp2 = get(id*2+1,mid+1,R,u,v);
    return min(tmp1,tmp2);
}
void sub_1(){
    int res = INF;
    INC(state,1,(1<<m)-1){
        int cnt = countbit_one(state);
        build(1,1,1e5+1);
        INC(i,1,m){
            if(get_bit(state,i)){
               int u = G[i].fi;
               int v = G[i].se;
               update(1,1,1e5+1,u,v,1);
            }
        }
        if(get(1,1,1e5+1,minn,1e5+1)){
            res = min(res,cnt);
        }
    }
    printf("%d",res);
}
void sub_2(){
    INC(i,minn,1e5+1) dp_sub_2[i] = INF;
    INC(i,1,m){
        if(G[i].se < minn) continue;
        if(G[i].fi <= minn){
            dp_sub_2[G[i].se] = 1;
            continue;
        }
        DEC(j,i-1,1){
            if(G[j].se >= G[i].fi-1){
                dp_sub_2[G[i].se] = min(dp_sub_2[G[i].se],dp_sub_2[G[j].se]+1);
            }
        }
    }
    printf("%d",dp_sub_2[100001]);
}
int main(){
    freopen(Tourist".inp","r",stdin);
    freopen(Tourist".out","w",stdout);
    scanf("%d",&m);
    INC(i,1,m){
        int u,v;
        scanf("%d %d",&u,&v);
        u++;
        v++;
        G[i] = {u,v};
        update(1,1,1e5+1,u,v,1);
    }
    scanf("%d",&n);
    INC(i,1,n){
        int u;
        scanf("%d",&u);
        minn = min(minn,u);
    }
    minn++;
    if(get(1,1,1e5+1,minn,1e5+1) == 0){
        printf("-1");
        return 0;
    }
    sort(G+1,G+m+1,cmp);
    if(m <= 16){
        sub_1();
        return 0;
    }
    if(m <= 3000){
        sub_2();
        return 0;
    }
//    INC(i,minn,1e5+1) dp[i] = INF;
//
//    INC(i,1,m){
//        if(G[i].se < minn) continue;
//        dp[G[i].se] = min(dp[G[i].se],dp[G[i].fi-1] + 1);
//    }
//    INC(i,1,m) printf("%d %d\n",G[i].fi,G[i].se);
}
