//Gear4snamekmen
#include <bits/stdc++.h>
#define GEAR4 "FIXSTR"
#define nmax 1000001
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define oo 1000000009
#define mod 1000000009
#define PB push_back
#define foR(i, r, k) for(int i = r; i <= k; i++)
#define foG(i, r, k) for(int i = k; i >= r; i--)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
int n, i[nmax], j[nmax], res, dem;
string s;
char a[nmax];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(GEAR4".inp","r",stdin);
    freopen(GEAR4".out","w",stdout);
    cin >> s;
    s = ' ' + s;
    cin >> n;
    foR(l, 1, n) {
        cin >> a[l];
        if(a[l] == 'C') {
            cin >> i[l];
            if(s[i[l]] == '(') s[i[l]] = ')';
            else s[i[l]] = '(';
        }
        if(a[l] == 'Q') {
            res = 0;
            dem = 0;
            cin >> i[l] >> j[l];
            if(s[i[l]] == ')') {
                res++;
                i[l]++;
            }
            foR(k, i[l], j[l]) {
                if(s[k] == '(') dem++;
                if(s[k] == ')') dem--;
            }
            res += abs(dem);
            cout << res << '\n';
        }
        if(a[l] == 'U') {
            cin >> i[l];
            if(a[i[l]] == 'U') continue;
            if(a[i[l]] == 'Q') continue;
            if(a[i[l]] == 'C') {
                if(s[i[i[l]]] == ')') s[i[i[l]]] = '(';
                else s[i[i[l]]] = ')';
                continue;
            }
        }
    }

}
