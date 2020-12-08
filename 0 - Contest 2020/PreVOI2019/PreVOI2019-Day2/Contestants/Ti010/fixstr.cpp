// PRZXCT
// loves_my_lover_so_much..
#include <bits/stdc++.h>
#define NaMe "fixstr"
#define pii pair<int,int>
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define gb(i,j) ((i>>j)&1)
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define ll long long
#define maxn 1000003

using namespace std;

string s;
int q, n, a[maxn];
string L[maxn];
int F[4*maxn], T[4*maxn], ss[maxn];
void sub1(){
    fto(i,1,q){
         char l;
         int x, y;
         cin >> l >> x;
         L[i] = L[i-1];
         if (l == 'C'){
                a[x] = 0 - a[x];
                if (L[i][x] == '(')    L[i][x] = ')';
                else L[i][x] = '(';
                continue;
         }
         if (l == 'Q'){
              cin >> y;
             // fto(j,x,y)    cout << a[j] << " ";
             // cout << '\n';
              int s = 0, rs = 0;
              fto(j,x,y){
                  s += a[j];
                  if (s < 0)   {rs += abs(s);    s = 0;}
              }
              rs += s;
              cout << rs << '\n';
              continue;
         }
         L[i] = L[x-1];
         fto(j,1,n){
             if (L[i][j] == ')')   a[j] = -1;
             else a[j] = 1;
         }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> s;
    n = s.length();
    s = " " + s;
    L[0] = s;
    fto(i,1,n){
        if (s[i] == ')')     a[i] = -1;
        else a[i] = 1;
        ss[i] = ss[i-1] + a[i];
        //cout << ss[i] << " ";
    }
    cin >> q;
    sub1();
    return 0;
}
