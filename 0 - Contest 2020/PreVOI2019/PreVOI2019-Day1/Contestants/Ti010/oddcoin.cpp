// PRZXCT
// loves_my_lover_so_much..
#include <bits/stdc++.h>
#define NaMe "oddcoin"
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

int q;
pair<int, int> Q[maxn];
int a[20];
ll L[maxn], R[maxn];
void sub1(){
    fto(h,1,q){
        int x = Q[h].fi,   t = Q[h].se;
        fto(j,1,t)     R[j] = L[j];
        fto(j,1,t){
             if (x <= j)    R[j] = min(R[j], R[j-x] + 1);
        }
        cout << R[t] << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> q ;
    int T = 1;
    fto(i,1,5){
        a[(i-1)*3+1] = T*1;
        a[(i-1)*3+2] = T*3;
        a[(i-1)*3+3] = T*5;
        T = T*10;
    }
    fto(i,1,1000000)    L[i] = 1e15;
    fto(i,1,1000000)
      fto(j,1,15){
          if (a[j] <= i)   L[i] = min(L[i], L[i-a[j]] + 1);
      }
    int Maxx = -1e9,   Maxt = -1e9;
    fto(i,1,q){
         cin >> Q[i].fi >> Q[i].se;
         Maxx = max(Q[i].fi, Maxx);
         Maxt = max(Q[i].se, Maxt);
    }
    if (max(Maxx, Maxt) <= 100000)     {sub1();    return 0;}
    fto(h,1,q){
        int x = Q[h].fi,  t = Q[h].se;
        int dec = 1;
        while (a[dec] <= t && dec <= 15)   ++dec;
        --dec;    dec = a[dec]; // cout << dec;
        if (dec < x && x <= t)   dec = x;
        int rs = 0;
        if (t > 1000000){
            rs = (t - 1000000)/dec;
            t -= dec*rs;
            if (t > 1000000)    {t -= dec;   ++rs;}
        }
        //cout << dec;
        fto(i,1,t)    R[i] = L[i];
        fto(i,1,t){
            if (x <= i)    R[i] = min(R[i], R[i-x] + 1);
        }
        cout << R[t] + rs << '\n';
    }
    return 0;
}
