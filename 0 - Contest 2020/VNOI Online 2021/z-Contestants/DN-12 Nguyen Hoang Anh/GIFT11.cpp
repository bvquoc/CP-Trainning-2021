/* This code is written by 18to_nhanh */
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Tourist "GIFT11"
#define fi first
#define se second
#define ll long long
#define sz(v) (int)(v.size())
#define get_bit(x,i) (x >>(i-1)&1)
#define countbit_one(n) __builtin_popcountll(n)
#define INC(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 2000;
const int MOD = 998244353;
const int INF = 1e9;
const int base = 31;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
typedef pair<pi,pi> pii;
typedef vector<pi> vpi;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n,s,tc;
int b[maxn+5];
vi Adj[maxn+5];
int check_sub_1(){
   int cnt = 0;
   int cnt_odd = 0,cnt_even = 0;
   vi G;
   INC(i,1,n){
       int tmp = b[i];
       vi T;
       while(tmp > 0){
           T.push_back(tmp%10);
           tmp = tmp / 10;
       }
       reverse(T.begin(),T.end());
       for(int u : T) G.push_back(u);
   }
   for(int u : G){
      cnt++;
      if(cnt & 1) cnt_odd += u;
      else cnt_even += u;
   }
   if((cnt_odd-cnt_even) % 11 == 0) return 1;
   return 0;
}
void sub_1(){
    INC(z,1,tc){
       n = Adj[z].size();
       INC(i,0,n-1){
           b[i+1] = Adj[z][i];
       }
       int res = 0;
       int v = 1;
       INC(i,1,n) v = v * i;
       INC(i,1,v){
            next_permutation(b+1,b+n+1);
          res = res + check_sub_1();
       }
       printf("%d\n",res);
    }
}
int main(){
    freopen(Tourist".inp","r",stdin);
    freopen(Tourist".out","w",stdout);
    s = 0;
    scanf("%d",&tc);
    INC(z,1,tc){
        scanf("%d",&n);
        s += n;
        INC(i,1,n){
            int u;
            scanf("%d",&u);
            Adj[z].push_back(u);
        }
    }
    if(s <= 8){
        sub_1();
        return 0;
    }
}
