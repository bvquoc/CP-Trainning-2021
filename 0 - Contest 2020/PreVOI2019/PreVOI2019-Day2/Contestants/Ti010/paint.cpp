// PRZXCT
// loves_my_lover_so_much..
#include <bits/stdc++.h>
#define NaMe "paint"
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

int n;
struct DATA{
    char c1, c2;
    int sl;
} q[maxn];
char rs[maxn];
char df[30];
vector<int> a[30];
void sub1(){
    int cnt = 0;
    fto(i,1,n){
         int l;
         char X, Y;
         cin >> l >> X;
         if (l == 1)    rs[++cnt] = X;
         else{
            cin >> Y;
            int t = X - 'a';
            //cout << cnt << " ";
            fto(j,1,cnt){
                int tt = rs[j] - 'a';   //cout << tt << " " << t << '\n';
                if (tt == t)     rs[j] = Y;
            }
         }
    }
    fto(i,1,cnt)    cout << rs[i] ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> n;
    if (n <= 5000)   {sub1();    return 0;}
    int cnt = 0;
    int s = 0;
    fto(i,1,n){
        int l;
        char X, Y;
        cin >> l >> X;
        if (l == 2)    {cin >> Y;    q[++cnt].c1 = X;    q[cnt].c2 = Y;   q[cnt].sl = s;}
        else rs[++s] =  X;
    }
    fto(i,0,25)      df[i] = i;
    fdto(i,cnt,1){
        char X = q[i].c1,    Y = q[i].c2;
        int pos = q[i].sl;
        int pos2 = q[i-1].sl + 1;
        int t = Y - 'a', t2 = X - 'a';
        df[t2] = df[t];       a[df[t]].push_back(t2);
        fdto(j,pos,pos2+1){
            fto(k,0,26){
              for (int h = 0; h < a[k].size(); h++){
                int u = a[k][h];
                int v = rs[j] - 'a';
                if (v == u)    rs[j] = (char)(k + 'a');
              }
            }
        }
    }
    fto(i,1,s)     cout << rs[i] ;
    return 0;
}
