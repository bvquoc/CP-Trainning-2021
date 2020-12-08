// PRZXCT
// loves_my_lover_so_much..
#include <bits/stdc++.h>
#define NaMe "construct"
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

int T, n, m, a[maxn], b[maxn];
ll L[maxn], F[4*maxn], lz[4*maxn];
void bd(int k, int l, int r){
    F[k] = 0;   lz[k] = 0;
    if (l == r)    return;
    int mid = (l+r)/2;
    bd(k*2, l, mid);
    bd(k*2+1, mid+1, r);
}
void dolazy(int k, int l, int r){
    if (lz[k] == 0)   return;
    F[k] += lz[k];
    int mid = (l+r)/2;
    if (l != r){
        lz[k*2] += (lz[k]/(r-l+1))*(mid-l+1);
        lz[k*2+1] += (lz[k]/(r-l+1))*(r-mid);
    }
    lz[k] = 0;
    return;
}
void update(int k, int L, int R, int l, int r, int val){
    dolazy(k, l, r);
    if (L > r || R < l)     return;
    int mid = (l+r)/2;
    if (L <= l && R >= r){
        F[k] += (ll)(r-l+1)*val;
        if (l != r){
            lz[k*2] += (ll)(mid-l+1)*val;
            lz[k*2+1] += (ll)(r-mid)*val;
        }
        return;
    }
    update(k*2, L, R, l, mid, val);
    update(k*2+1, L, R, mid+1, r, val);
}
ll Get(int k, int id, int l, int r){
    dolazy(k, l, r);
    if (id < l || id > r)   return 0;
    if (l == r)             return F[k];
    int mid = (l+r)/2;
    return Get(k*2, id, l, mid) + Get(k*2+1, id, mid+1, r);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(NaMe".inp","r", stdin);
    freopen(NaMe".out","w", stdout);
    cin >> T;
    while (T > 0){
        --T;
        cin >> n >> m;
        bd(1, 1, n);
        fto(i,1,n)      cin >> a[i];
        fto(i,1,n)      L[i] = 0;
        fto(h,1,m){
           int l, u, v, k;
           cin >> l >> u >> v ;
           if (l == 1){
               cin >> k;
               update(1, u, v, 1, n, k);
           }
           else{
                 L[u] = a[u] + Get(1, u, 1, n);
                 fto(i,u+1,v){
                    ll t1 = a[i] + Get(1, i, 1, n), t2 = a[i-1] + Get(1, i-1, 1, n);
                    if (t1 > t2)    L[i] = L[i-1] + t1 - t2;
                    else L[i] = L[i-1];
                 }
                 cout << L[v] << '\n';
           }
        }
    }
    return 0;
}
