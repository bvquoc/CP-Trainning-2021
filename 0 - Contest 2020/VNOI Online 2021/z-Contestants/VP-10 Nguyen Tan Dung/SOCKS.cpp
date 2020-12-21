#ifndef LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

#define taskname "SOCKS"

const int maxn=500000;

int n_red;
int n_node, n_query;
bool red[maxn+5];
std::vector<int> adjList[maxn+5];

void up1();
void up2();
int check02_;
void up();

int main()
{
        if (fopen(taskname".inp", "r")) {
                freopen(taskname".inp", "r", stdin);
                freopen(taskname".out", "w", stdout);
        }

        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        std::cin>>n_node>>n_query;
        n_red=0;
        for (int i=1; i<=n_node; ++i) std::cin>>red[i];
        for (int i=1; i<n_node; ++i) {
                int v1, v2; std::cin>>v1>>v2;
                adjList[v1].push_back(v2);
                adjList[v2].push_back(v1);
        }

        bool check01=true;
        for (int i=1; i<=n_node; ++i) {
                if (adjList[i].size()>2) {
                        check01=false; break;
                }
        }

        bool check02=true;
        check02_=-1;
        for (int i=1; i<=n_node; ++i) {
                if (adjList[i].size()>3) {
                        check02=false; break;
                }
                if (check02_>-1 and adjList[i].size()>2) {
                        check02=false; break;
                }
                if (adjList[i].size()==3) check02_=i;
        }

        if (check01) up1();
        else if (check02) up2();
        else up();

        return 0;
}

void up1() {
        n_red=0;
        for (int i=1; i<=n_node; ++i) n_red+=red[i];

        std::cout<<(n_red>0)<<"\n";
        while (n_query--) {
                int x; std::cin>>x;
                if (red[x]) red[x]=false, --n_red;
                else red[x]=true, ++n_red;

                std::cout<<(n_red>0)<<"\n";
        }
}

int region[maxn+5];
void travel2(int node, int parent=-1, int reg=0) {
        region[node]=reg;
        for (auto& i: adjList[node]) {
                if (parent==-1) travel2(i, node, ++reg);
                else if (i!=parent) travel2(i, node, reg);
        }
}

void up2() {
        travel2(check02_);
        int cur[4];
        for (int i=1; i<=n_node; ++i) cur[region[i]]+=red[i];

        int ret=0;
        for (int i=1; i<4; ++i) ret+=(cur[i]>0);

        if (ret==0) std::cout<<"0";
        else if (ret<3) std::cout<<"1";
        else std::cout<<"2";
        std::cout<<"\n";

        while (n_query--) {
                int x; std::cin>>x;;
                if (red[x]) red[x]=false, --cur[region[x]];
                else red[x]=true, ++cur[region[x]];

                int ret=0;
                for (int i=1; i<4; ++i) ret+=(cur[i]>0);

                if (ret==0) std::cout<<"0";
                else if (ret<3) std::cout<<"1";
                else std::cout<<"2";
                std::cout<<"\n";
        }
}

int chainHead[maxn+5], chainIdx[maxn+5];//, posInBase[maxn+5];
int parent[maxn+5];
int n_child[maxn+5];
int n_chain, n_base;
int cnt[maxn+5];

void travel(int node)
{
        n_child[node]=1;
        for (int i: adjList[node]) {
                if (i!=parent[node]) {
                        parent[i]=node;
                        travel(i);

                        n_child[node]+=n_child[i];
                }
        }
}

void hld(int node) {
        if (chainHead[n_chain]==0) {
                chainHead[n_chain]=node;
        }

        chainIdx[node]=n_chain;
        //posInBase[node]=++n_base;

        int maxVrtx=-1;
        for (int i: adjList[node]) {
                if (i!=parent[node] and (maxVrtx==-1 or n_child[i]>n_child[maxVrtx])) {
                        maxVrtx=i;
                }
        }

        if (maxVrtx>-1) {
                hld(maxVrtx);
        }

        for (int i: adjList[node]) {
                if (i!=parent[node] and i!=maxVrtx) {
                        ++n_chain;
                        hld(i);
                }
        }
}

void up() {
        parent[1]=0;  travel(1);
        n_chain=1; n_base=0;
        hld(1);

        int ret=0;
        for (int i=1; i<=n_node; ++i) {
                if (red[i] and !(cnt[chainIdx[i]]++)) {
                        ++ret;
                }
        }
        std::cout<<ret-1<<"\n";

        while (n_query--) {
                int x; std::cin>>x;
                if (red[x]) {
                        red[x]=false;
                        if (!(--cnt[chainIdx[x]])) --ret;
                }
                else {
                        red[x]=true;
                        if (!(cnt[chainIdx[x]]++)) ++ret;
                }

                std::cout<<ret-1<<"\n";
        }
}
