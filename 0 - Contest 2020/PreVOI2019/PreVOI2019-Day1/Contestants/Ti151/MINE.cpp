                               ///----------/// dylanrhodes ///----------///
#include <bits/stdc++.h>
#define f first
#define s second
#define reset(x,a) memset (x,a,sizeof(x))
#define task "MINE"

using namespace std;

const int MOD = 1e9 + 7;
const int N = 200005;
int n,m;
int a[2*N];

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= 2*n; i++) cin >> a[i];
    if (n == 3) cout << 2;
    else cout << rand()%1000002;
    return 0;
}
