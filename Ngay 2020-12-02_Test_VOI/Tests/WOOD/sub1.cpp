#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(),a.end()
#define u first.first
#define v first.second
#define x second.first
#define y second.second
typedef pair<int,int> pii;
typedef pair<pii,pii> Rectangle;
typedef Rectangle Line;

long long cost(int n, int m, vector<Line> lines){
    long long ans = 0;
    vector<Rectangle> recs;
    recs.push_back(Rectangle(pii(0,0), pii(n,m)));
    for (auto &D : lines){
        bool found = false;
        for (auto &R : recs) if
        (((R.u==D.u && R.x==D.x) || (R.v==D.v && R.y==D.y))
        && R.first < D.first && R.second > D.second){
            Rectangle A(R.first, D.second), B(D.first, R.second);
            ans += 1LL * (R.x-R.u) * (R.y-R.v);
            R = A;
            recs.push_back(B);
            found = true;
            break;
        }
        if (!found) return 2e18;
    }
    return ans;
}

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    int n, m, k;
    cin >> n >> m >> k;
    vector<Line> lines(k);
    for (auto &D : lines) cin >> D.u >> D.v >> D.x >> D.y;
    auto saveLines = lines;
    sort(all(lines));
    long long ans = 2e18;
    auto bestLines = lines;
    do{
        long long tmp = cost(n, m, lines);
        if (tmp < ans){
            ans = tmp;
            bestLines = lines;
        }
    } while (next_permutation(all(lines)));

    if (ans > 1e18){
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    for (auto &D : bestLines){
        bool found = false;
        for (auto &E : saveLines)
        if (D == E){
            cout << int(&E - &saveLines[0] + 1) << ' ';
            found = true;
            E.u = -1;
            break;
        }
        assert(found);        
    }
}
