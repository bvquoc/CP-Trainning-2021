#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()

pair<long long, vector<int>> solve(vector<long long> a){
    // for(auto x: a) cerr << x << " ";
    vector<int> nxt(a.size()), pre(a.size());
    for (int i = 0; i < a.size(); ++i) nxt[i] = i+1, pre[i] = i-1;
    priority_queue<pair<long long, int>> heap;
    for (int i = 0; i+1 < a.size(); ++i) heap.push({-a[i]-a[nxt[i]], i});
    long long ans = 0;
    vector<int> orders;
    while(heap.size()){
        auto tmp = heap.top();
        heap.pop();
        int i = tmp.second, j = nxt[i];
        if (j >= a.size() || -a[i]-a[j] != tmp.first) continue;
        orders.push_back(i);
        ans -= tmp.first;
        a[j] += a[i];
        pre[j] = pre[i];
        pre[i] = -1;
        if (pre[j] >= 0){
            nxt[pre[j]] = j;
            heap.push({-a[pre[j]]-a[j], pre[j]});
        }
        if (nxt[j] < a.size()){
            heap.push({-a[j]-a[nxt[j]], j});
        }
    }
    // cerr << ans << " xxxx" << endl;
    reverse(all(orders));
    // for(int i : orders) cerr << i << " ";cerr<<endl;
    return make_pair(ans, orders);
}

#define u first.first
#define v first.second
#define x second.first
#define y second.second
typedef pair<int,int> pii;
typedef pair<pii,pii> Rectangle;
typedef Rectangle Line;

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    int n, m, k;
    cin >> n >> m >> k;
    map<Line, int> lineId;
    map<pii, vector<int>> Xs, Ys;
    for (int i = 0; i < k; ++i){
        Line D;
        cin >> D.u >> D.v >> D.x >> D.y;
        lineId[D] = i+1;
        if (D.u == D.x) Xs[pii(D.v, D.y)].push_back(D.x);
        else Ys[pii(D.u, D.x)].push_back(D.y);
    }
    for (auto &e : Xs) sort(all(e.second));
    for (auto &e : Ys) sort(all(e.second));
    vector<Rectangle> recs;
    recs.push_back(Rectangle(pii(0,0), pii(n,m)));
    long long ans = 0;
    vector<int> orders;
    while (recs.size()){
        Rectangle R = recs.back();
        recs.pop_back();
        vector<Line> lines;
        {//by X
            auto s = lower_bound(all(Xs[pii(R.v, R.y)]), R.u+1);
            auto t = upper_bound(all(Xs[pii(R.v, R.y)]), R.x-1);
            for ( ; s < t; ++s) lines.push_back(Line(pii(*s, R.v), pii(*s, R.y)));
        }
        {//by Y
            auto s = lower_bound(all(Ys[pii(R.u, R.x)]), R.v+1);
            auto t = upper_bound(all(Ys[pii(R.u, R.x)]), R.y-1);
            for ( ; s < t; ++s) lines.push_back(Line(pii(R.u, *s), pii(R.x, *s)));
        }
        sort(all(lines));
        //cerr << R.u << " " << R.v << " " << R.x << " " << R.y << ":" << endl;
        //for (auto line : lines) cerr << line.u << " " << line.v << " " << line.x << " " << line.y << endl;
        vector<long long> a;
        if (lines.size()){//insert rectangles
            #define area(R) (1LL*(R.x-R.u)*(R.y-R.v))
            pii P = R.first;
            for (auto &D : lines){
                recs.push_back({P, D.second});
                a.push_back(area(recs.back()));
                P = D.first;
            }
            assert(P != R.first);
            recs.push_back({P, R.second});
            a.push_back(area(recs.back()));
        }
        auto tmp = solve(a);
        ans += tmp.first;
        for (int i : tmp.second) orders.push_back(lineId[lines[i]]);
    }
    cout << ans << endl;
    for (int i : orders) cout << i << " ";
}
