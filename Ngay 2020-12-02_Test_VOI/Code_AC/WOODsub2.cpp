#include <bits/stdc++.h>
using namespace std;

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    int n, m, k;
    cin >> n >> m >> k;
    assert(n == 1);
    vector<int> xs(k);
    for (auto &x : xs){
        cin >> n >> x >> n >> n;
    }
    map<int, int> posOf;
    for (int i = 0; i < k; ++i) posOf[xs[i]] = i;
    xs.push_back(0);
    xs.push_back(m);
    sort(xs.begin(), xs.end());
    vector<int> nxt(xs.size()), pre(xs.size());
    for (int i = 0; i < xs.size(); ++i){
        nxt[i] = i+1;
        pre[i] = i-1;
    }
    priority_queue<pair<int,int>> heap;
    #define insert(i)\
        if (pre[i] >= 0 && nxt[i] < xs.size())\
            heap.push({xs[pre[i]] - xs[nxt[i]], i});
    for (int i = 1; i <= k; ++i) insert(i);
    long long ans = 0;
    vector<int> bestXs;
    while(heap.size()){
        auto tmp = heap.top();
        heap.pop();
        int i = tmp.second;
        if (xs[pre[i]] - xs[nxt[i]] != tmp.first) continue;
        bestXs.push_back(xs[i]);
        ans -= tmp.first;
        int pi = pre[i], ni = nxt[i];
        nxt[i] = pre[i] = 0;
        pre[ni] = pi;
        nxt[pi] = ni;
        insert(pi);
        insert(ni);
    }
    reverse(bestXs.begin(), bestXs.end());
    cout << ans << '\n';
    for (auto &x : bestXs) cout << posOf[x]+1 << ' ';
}
