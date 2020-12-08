//Gear4snamekmen
#include <bits/stdc++.h>
#define GEAR4 "PAINT"
#define nmax 100005
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
int n, i, l = 0;
char a, b, s[1000001];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(GEAR4".inp","r",stdin);
    freopen(GEAR4".out","w",stdout);
    cin >> n;
    while(n--) {
        cin >> i;
        if(i == 1)
            cin >> s[++l];
        else {
            cin >> a >> b;
            if(l == 0) continue;
            foR(j, 1, (l)) {
                if(s[j] == a)
                    s[j] = b;
            }
        }
    }
    foR(j, 1, l) {
        cout << s[j];
    }

}
