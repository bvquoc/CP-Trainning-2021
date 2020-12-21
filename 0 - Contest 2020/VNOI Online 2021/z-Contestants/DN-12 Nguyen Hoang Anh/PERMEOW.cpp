/* This code is written by 18to_nhanh */
#include<bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#define Tourist "PERMEOW"
#define fi first
#define se second
#define ll long long
#define sz(v) (int)(v.size())
#define get_bit(x,i) (x >>(i-1)&1)
#define countbit_one(n) __builtin_popcountll(n)
#define INC(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 2e5;
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
int n;
int a[maxn+5],b[maxn+5];
void sub_1(){
    int res = 0;
    INC(i,1,n){
        int pos = 0;
        INC(j,1,n){
            if(a[j] == i){
                pos = j;
                break;
            }
        }
        if(pos == i) continue;
        DEC(j,pos,i+1){
            res++;
            swap(a[j],a[j-1]);
        }
    }
    printf("%d",res);
    exit(0);
}
int Process(){
    int res = 0;
    INC(i,1,n){
        int pos = 0;
        INC(j,1,n){
            if(a[j] == i){
                pos = j;
                break;
            }
        }
        if(pos == i) continue;
        DEC(j,pos,i+1){
            res++;
            swap(a[j],a[j-1]);
        }
    }
    return res;
}
void sub_2(){
    int res = 0;
    INC(i,1,n) b[i] = i;
    res += Process();
    while(next_permutation(b+1,b+n+1)){
        INC(i,1,n) a[i] = b[i];
        res += Process();
    }
    printf("%d",res);
    exit(0);
}
int main(){
    freopen(Tourist".inp","r",stdin);
    freopen(Tourist".out","w",stdout);
    scanf("%d",&n);
    INC(i,1,n) scanf("%d",&a[i]);
    INC(i,1,n) scanf("%d",&b[i]);
    int cnt_equal = 0;
    INC(i,1,n) cnt_equal += (a[i] == b[i]);
    if(cnt_equal == n) sub_1();
    cnt_equal = 0;
    INC(i,1,n){
        if(a[i] == i && b[i] == (n - i + 1)) cnt_equal++;
    }
    if(cnt_equal == n) sub_2();
}

