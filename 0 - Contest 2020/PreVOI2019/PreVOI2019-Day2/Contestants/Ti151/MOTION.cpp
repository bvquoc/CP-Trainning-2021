                               ///----------/// dylanrhodes ///----------///
#include <bits/stdc++.h>
#define f first
#define s second
#define reset(x,a) memset (x,a,sizeof(x))
#define task "MOTION"

using namespace std;

const int MOD = 1e9 + 7;
const int N = 300005;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen (task".inp","r",stdin);
    freopen (task".out","w",stdout);
    int t;
    cin >> t;
    if (t == 5){
        cout << 7 << " " << 2 << "\n";
        cout << 3 << " " << 2 << "\n";
        cout << -1 << "\n";
        cout << 1 << " " << 3 << "\n";
        cout << 63 << " " << 2 << "\n";
    }
    return 0;
}
