#ifndef LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

#define taskname "COOLMAC"

struct Temper {
        int l, r;
};

int main()
{
        if (fopen(taskname".inp", "r")) {
                freopen(taskname".inp", "r", stdin);
                freopen(taskname".out", "w", stdout);
        }

        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        int n; std::cin>>n;
        Temper tempers[n+1];
        for (int i=0; i<n; ++i) {
                std::cin>>tempers[i].l>>tempers[i].r;
        }

        int m; std::cin>>m;
        int bound=100000;
        for (int i=0; i<m; ++i) {
                int x; std::cin>>x;
                bound=std::min(bound, x);
        }

        std::sort(tempers, tempers+n, [&](Temper const& a, Temper const& b) {
                if (a.r==b.r) return a.l>b.r;
                return a.r<b.r;
        });

        if (tempers[n-1].r<100000) {
                std::cout<<"-1"; return 0;
        }
        int idx=0;
        while (idx<n and tempers[idx].r<bound) ++idx;
        while (idx<n and tempers[idx].l>bound) ++idx;
        if (idx==n) {
                std::cout<<"-1"; return 0;
        }

        std::multiset< std::pair<int, int> > q;
        std::multiset<int> q2;
        q.insert({tempers[idx].l, tempers[idx].r});
        q2.insert(tempers[idx].r);
        for (int i=idx+1; i<n; ++i) {
                if (tempers[i].l<=bound) {
                        q.clear(), q2.clear();
                }
                while (!q.empty() and (q.rbegin()->first)>=tempers[i].l) {
                        q2.erase(q.rbegin()->second);
                        q.erase(--q.end());
                }

                if (tempers[i].l>bound and (!q2.empty() and *q2.rbegin()+1<tempers[i].l)) {
                        std::cout<<"-1"; return 0;
                }
                q.insert({tempers[i].l, tempers[i].r});
                q2.insert(tempers[i].r);
        }

        std::cout<<q.size();

        return 0;
}
