#ifndef LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

#define taskname "DHAKA"

const int64_t inf=1e15;

int main()
{
        if (fopen(taskname".inp", "r")) {
                freopen(taskname".inp", "r", stdin);
                freopen(taskname".out", "w", stdout);
        }

        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        int n, m, k, l; std::cin>>n>>m>>k>>l;

        std::vector<int> a[n+1];
        int s[n+1];
        for (int i=1; i<=n; ++i) {
                std::cin>>s[i];
                a[i].resize(s[i]);
                for (auto& j: a[i]) std::cin>>j, --j;
        }

        std::vector< std::pair<int, int> > adjList[n+1];
        for (int i=0; i<m; ++i) {
                int v1, v2, w; std::cin>>v1>>v2>>w;
                adjList[v1].push_back({v2, w});
                adjList[v2].push_back({v1, w});
        }

        /*for (int i=1; i<=n; ++i) {
                std::cout<<"#"<<i<<":  ";
                for (auto& j: a[i]) std::cout<<j<<" ";
                std::cout<<"\n";
        }*/

        int64_t dist[n+1][1<<k];
        for (int i=0; i<=n; ++i) {
                for (int j=0; j<(1<<k); ++j) dist[i][j]=inf;
        }
        adjList[0].push_back({1, 0});

        std::priority_queue< std::pair<int64_t, std::pair<int, int> > > pq;
        pq.push({-(dist[0][0]=0), {0, 0}});
        while (!pq.empty()) {
                int cdist=-pq.top().first;
                int cvertex=pq.top().second.first;
                int cmask=pq.top().second.second;

                //std::cout<<cdist<<" "<<cvertex<<" "<<cmask<<"\n";
                pq.pop();

                if (cdist>dist[cvertex][cmask]) continue;

                int n_gift=__builtin_popcount(cmask);
                for (auto& i: adjList[cvertex]) {
                        for (int mask=0; mask<(1<<s[i.first]); ++mask) {
                                int new_mask=cmask;
                                for (int j=0; j<s[i.first]; ++j) {
                                        if ((mask>>j)&1) new_mask|=(1<<a[i.first][j]);
                                }

                                if (cdist+i.second<dist[i.first][new_mask]) {
                                        pq.push({-(dist[i.first][new_mask]=cdist+i.second), {i.first, new_mask}});
                                }
                        }
                }
        }

        int64_t result=inf;
        for (int mask=0; mask<(1<<k); ++mask) {
                int n_gift=__builtin_popcount(mask);
                if (n_gift==l) {
                        result=std::min(result, dist[n][mask]);
                }
        }

        std::cout<<(result==inf ? -1: result);

        return 0;
}
