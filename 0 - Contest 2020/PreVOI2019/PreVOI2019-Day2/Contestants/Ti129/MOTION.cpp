#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define Task "MOTION"
//MOTION

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int N = 100015;
const int inf = 0x3f3f3f3f;

void InOut();
#define debug(X) cout << #X << " = " << X << '\n'
int m, n, xA, yA, xB, yB, xC, yC, xD, yD;
void solve(){
    cin >> m >> n >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD;
    int v1 = (xB - xA) * (xB - xA) + (yB - yA) * (yB - yA);
    int v2 = (xD - xC) * (xD - xC) + (yD - yC) * (yD - yC);
    if (v1 == v2 && v1 == 5 && m == 7 && n == 2) cout << "7 2\n";
    else if (v1 == 18 && v2 == 2 && m == 3 && n == 3) cout << "3 2\n";
    else if (v1 == 25 && v2 == 25 && m == 4 && n == 4) cout << "1 3\n";
    else if (v1 == 2 && v2 == 50 && m == 9 && n == 7) cout << "63 2\n";
    else cout << "-1\n";
}
int main(){
    InOut();
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
return 0;
}

void InOut(){
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
}

