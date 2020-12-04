#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Trie{//0-indexed
    int ntrie, trie[3][6000000];

    void push(ll key, int val = 1){
        for(int k = 0, i = 60; i--; ){
            int t = key >> i & 1;
            if (!trie[t][k]) trie[t][k] = ++ntrie;
            k = trie[t][k];
            trie[2][k] += val;
        }
    }

    ll n_th_out(ll n){//n_th element that isn't in trie
        ll ans = 0;
        for(int k = 0, i = 60; i--; ){
            ll tmp = (1LL << i) - trie[2][trie[0][k]];
            if (tmp >= n) k = trie[0][k];
            else{
                n -= tmp;
                ans ^= 1LL << i;
                k = trie[1][k];
            }
            //printf("i=%d n=%lld ans=%lld\n", i, n, ans);
            if (!k) return ans + n - 1;
        }
        return ans;
    }

} trie;

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    ll n, m;
    cin >> n >> m;
#ifdef GENTEST
    cerr << n << ' '  << m << endl;
#endif
    while(m--){
        ll i;
        cin >> i;
        i = trie.n_th_out(i+1);//skip 0
        auto index = [&](ll u, ll v){//1-indexed
            return (n - u + n) * (u - 1) / 2 + v - u;
        };
        ll u = 1;
        for (int t = 30; t--; )
            if (u + (1<<t) < n && index(u + (1<<t), u + (1<<t) + 1) <= i) u += 1<<t;
        ll v = u + 1 + i - index(u, u+1);
        assert(index(u, v) == i && u >= 1 && u <= n && v >= 1 && v <= n && u < v);
        cout << u << ' ' << v << '\n';
        trie.push(i);
    }
}
