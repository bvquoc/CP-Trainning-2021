#ifndef LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

#define taskname "DECOR"

void up1();
void up2();
void up();

const int maxn=500000;

int n, m, k;
std::string str;
std::vector<int> adjList[maxn+5];

int main()
{
        if (fopen(taskname".inp", "r")) {
                freopen(taskname".inp", "r", stdin);
                freopen(taskname".out", "w", stdout);
        }

        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        std::cin>>n>>m>>k;
        std::cin>>str;
        for (int i=0; i<m; ++i) {
                int v1, v2; std::cin>>v1>>v2;
                adjList[v1].push_back(v2);
                adjList[v2].push_back(v1);
        }

        if (m==0) {
                if (k==0) up1();
                else up2();
        }
        else up();

        return 0;
}

void up1() {
        int cur=0;
        int ret=0, pos=0;
        str+="0";
        for (int i=0; str[i]; ++i) {
                if (str[i]=='1') ++cur;
                else {
                        if (ret<cur) ret=cur, pos=i-ret+1;
                        cur=0;
                }
        }

        std::cout<<pos<<" "<<pos+ret-1;
}

int ret[maxn+5];

void up2() {
        int pref[n+1];
        pref[0]=0;
        for (int i=0; str[i]; ++i) {
                pref[i+1]=pref[i]+str[i]-'0';
        }

        int low=0, high=n, x;
        while (low<=high) {
                x=low+high>>1;

                bool check=false;
                for (int i=0; i<=n-x; ++i) {
                        if (pref[i+x]-pref[i]+k>=x) {
                                ret[x]=i;
                                check=true; break;
                        }
                }

                if (check) low=x+1;
                else high=x-1;
        }

        if (low==0) {
                std::cout<<"-1"; return ;
        }
        std::cout<<ret[low-1]+1<<" "<<ret[low-1]+low-1;
}

int ncc;
//std::vector<int> ccList[maxn+5];
bool counted[maxn+5];
int ccIdx[maxn+5];
int n_egg[maxn+5];

void travel(int vertex) {
        counted[vertex]=true;
        //ccList[ncc].push_back(vertex);
        ccIdx[vertex]=ncc;

        for (auto& i: adjList[vertex]) {
                if (!counted[i]) travel(i);
        }
}

int cnt[maxn+5];

void up() {
        ncc=0;
        for (int i=1; i<=n; ++i) counted[i]=false;
        for (int i=1; i<=n; ++i) {
                if (!counted[i]) {
                        ++ncc; travel(i);
                }
        }

        /*for (int i=1; i<=ncc; ++i) {
                std::sort(ccList[i].begin(), ccList[i].end());
                for (auto& j: ccList[i]) n_egg[i]+=(str[j-1]=='1');
        }*/
        for (int i=1; i<=n; ++i) {
                n_egg[ccIdx[i]]+=(str[i-1]=='1');
        }

        int low=0, high=n;
        while (low<=high) {
                int x=low+high>>1;

                for (int i=1; i<=ncc; ++i) cnt[i]=0;

                int totEgg=0;
                for (int i=1; i<=x; ++i) {
                        if (++cnt[ccIdx[i]]<=n_egg[ccIdx[i]]) ++totEgg;
                }

                bool check=false;
                if (totEgg+k>=x) {
                        check=true; ret[x]=0;
                }
                else {
                        for (int i=x+1; i<=n; ++i) {
                                if (cnt[ccIdx[i-x]]--<=n_egg[ccIdx[i]]) --totEgg;
                                if (++cnt[ccIdx[i-x]]<=n_egg[ccIdx[i]]) ++totEgg;
                                if (totEgg+k>=x) {
                                        check=true; ret[x]=i-x; break;
                                }
                        }
                }

                if (check) low=x+1;
                else high=x-1;
        }

        if (low==0) {
                std::cout<<"-1"; return ;
        }
        std::cout<<ret[low-1]+1<<" "<<ret[low-1]+low-1;
}
