#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "PAINT"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int maxn = 1e6 + 100;
const int logn = log2(maxn) + 1;
const int mod = 1e6 + 3;

int painted[maxn];
int col[26];
int c[maxn];
int lab[maxn];
int n , k;
int FindLab(int u){
    return lab[u] < 0 ? u : lab[u] = FindLab(lab[u]);
}
void dsu(int u , int v){
    u = FindLab(u);v = FindLab(v);
    if(u == v)return;
    if(lab[u] > lab[v])swap(u,v);
    lab[u] += lab[v];
    lab[v] = u;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    cin >> n;
    fill_n(lab,maxn,-1);
    k = 0;
    for(int i = 1 ; i <= n ; ++i){
        int type;cin >> type;
        if(type == 1){
            ++k;
            char x;cin >> x;x -= 'a';
            if(c[x]){
                dsu(k,c[x]);
            }else{
                c[x] = k;
            }
            col[FindLab(k)] = x;
        }else{
            char x , y;cin >> x >> y;x -= 'a';y -= 'a';
            if(c[x] == 0)continue;
            if(c[y] == 0){
                c[y] = c[x];
                c[x] = 0;
                col[FindLab(c[y])] = y;
            }else{
                dsu(c[x],c[y]);
                c[x] = 0;
                col[FindLab(c[y])] = y;
            }
        }
    }
    for(int i = 1 ; i <= k ; ++i)cout << char('a' + col[FindLab(i)]);
}

