#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define x first
#define y second
typedef pair<int,int> pii;
typedef pair<pii,pii> Rectangle;
typedef Rectangle Line;

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> U(k+2), V(k+2), X(k+2), Y(k+2);
    for (int i = 1; i <= k; ++i) cin >> U[i] >> V[i] >> X[i] >> Y[i];

    map<int, set<int>> byTop, byLeft;
    map<pii, set<pii>> byTopLeft;
    #define let(dosmt,u,v,x,y) byTop[u].dosmt(v),byLeft[v].dosmt(u),byTopLeft[{u,v}].dosmt({x,y})
    auto which = [&](int i){//return the top left rectangles by line i-th
        int top, left;
        if (U[i] == X[i]){
            left = V[i];
            if (byLeft[left].empty() || *byLeft[left].begin() >= U[i])
                return Rectangle(pii(-1,-1), pii(-1, -1));
            top = *--byLeft[left].lower_bound(U[i]);
        } else {
            top = U[i];
            if (byTop[top].empty() || *byTop[top].begin() >= V[i])
                return Rectangle(pii(-1,-1), pii(-1, -1));
            left = *--byTop[top].lower_bound(V[i]);
        }
        pii A(top, left), B = *byTopLeft[A].begin();
        // cerr << i << ": " << top << " " << left << " " << B.x << " " << B.y << endl;
        return Rectangle(A, B);
    };
    let(insert,0,0,n,m);
    long long ans = 0;
    for (int i = 1; i <= k; ++i){
        Rectangle tmp = which(i);
        assert(tmp.x.x != -1);
        pii A = tmp.first, B = tmp.second;
        let(erase, A.x, A.y, B.x, B.y);
        let(insert, A.x, A.y, X[i], Y[i]);
        let(insert, U[i], V[i], B.x, B.y);
        ans += 1LL*(B.x-A.x)*(B.y-A.y);
        // cerr << ans << endl;
    }
    cout << ans << '\n';
    for (int i = 1; i <= k; ++i) cout << i << ' ';
}
