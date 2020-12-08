// PRZXCT
// loves_my_lover_so_much..
#include <bits/stdc++.h>
#define NaMe "mine"
#define pii pair<int,int>
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define gb(i,j) ((i>>j)&1)
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define ll long long
#define maxn 200003

using namespace std;

int n, m, a[maxn], x[maxn], df[15], T[15];
ll rs = 0;
ll L[403][203], mod = 1000003, F[403][203][403];
void sub2(){
    L[1][0] = 1 ;   L[1][1] = 0;
    fto(i,2,2*n)
      fto(j,0,i/2){
          if (j > 0)   L[i][j] = (L[i][j] + L[i-1][j-1]) % mod;
          L[i][j] = (L[i][j] + L[i-1][j]) % mod;
          //cout << i << " " << j << " " << L[i][j] << '\n';
      }
    cout << L[2*n][n];
}
void check(){
    fto(j,1,n)    {df[j] = 0;   T[j] = 0;}
    fto(j,1,2*n){
        if (df[x[j]] == 2)    return;
        if (df[x[j]] == 0){
            fto(h,1,j-1)   if (x[h] > x[j])    return;
            df[x[j]]++;   T[x[j]] = j;
        }
        else{
            fdto(h,j-1,T[x[j]]+1)    if (df[x[h]] != 2)    return;
            if (a[j] - a[T[x[j]]] > m)   return;
            df[x[j]]++;
        }
    }
    //cout << a[6] - a[T[x[6]]] << " ";
    rs = (rs + 1) % mod;
}
void backtrack(int u){
    fto(i,1,n){
        x[u] = i;
        if (u == 2*n)    check();
        else backtrack(u+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> n >> m ;
    fto(i,1,2*n)    cin >> a[i];
    if (n <= 10)         {backtrack(1);   cout << rs;   return 0;}
    if (m == 1000000)    {sub2();    return 0;}
    return 0;
}
