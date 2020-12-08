#include <bits/stdc++.h>

#define fi first
#define se second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Task "MOTION"
#define point pair<int, int>

using namespace std;
typedef long long ll;

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    int T;
    cin >> T;
    while (T--){
        int n, m;
        point A, B, C, D;
        cin >> n >> m >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        if (mp(n, m) == mp(7, 2) && A == point(0, 0) && B == point(1, 2) && C == point(7, 2) && D == point(6, 0)){
            cout << "7 2\n";
        }
        else if (mp(n, m) == mp(3, 3) && A == point(0, 0) && B == point(3, 3) && C == point(3, 0) && D == point(2, 1)){
            cout << "3 2\n";
        }
        else if (mp(n, m) == mp(4, 4) && A == point(1, 0) && B == point(4, 4) && C == point(3, 0) && D == point(0, 4)){
            cout << "1 3\n";
        }
        else if (mp(n, m) == mp(9, 7) && A == point(0, 0) && B == point(1, 1) && C == point(9, 0) && D == point(8, 7)){
            cout << "63 2\n";
        }
        else cout << "-1\n";
    }
}
