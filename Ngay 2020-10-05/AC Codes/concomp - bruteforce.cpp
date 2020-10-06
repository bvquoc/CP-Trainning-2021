//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "concomp"
#define maxn 4005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>

using namespace std;

int n, m, cntgo, cntback;
pii a[maxn*8];
int ago[maxn], aback[maxn];
int res[maxn][maxn];

int root[maxn];

int get_root(int u){
    return root[u] ? root[u] = get_root(root[u]) : u;
}

void Init(){
    reset(root); ago[0] = 0;
    for (int i = 1; i <= m; i++){
        int p = get_root(a[i].F);
        int q = get_root(a[i].S);
        if (p - q){
            root[p] = q;
            ago[++cntgo] = i;
        }
    }

    reset(root);
    for (int i = m; i; i--){
        int p = get_root(a[i].F);
        int q = get_root(a[i].S);
        if (p - q){
            root[p] = q;
            aback[++cntback] = i;
        }
    }

//    sort(aback+1, aback+cntback+1);
  /*  aback[0] = -1;
    for (int i = 0; i <= cntgo; i++){
        reset(root);
        for (int j = 1; j <= i; j++) root[get_root(a[ago[j]].F)] = get_root(a[ago[j]].S);
        res[i][cntback+1] = n-i;
        for (int j = cntback; aback[j] > ago[i]; j--){
            int pos = aback[j];
            int p = get_root(a[pos].F);
            int q = get_root(a[pos].S);
            if (p-q){
                root[p] = q;
                res[i][j] = res[i][j+1] - 1;
            } else res[i][j] = res[i][j+1];
        }
    }*/
}

void Calc(){
    int ntest = 0, l, r;
    cin >> ntest;
    while (ntest--){
        cin >> l >> r;
        int ans = n;
        reset(root);
        for (int i = 1; i <= m; i++)
            if (i < l || i > r) {
                int p = get_root(a[i].F);
                int q = get_root(a[i].S);
                if (p - q){
                    root[p] = q;
                    ans--;
                }
        }
        cout << ans << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].F >> a[i].S;
    Init();
    Calc();
    return 0;
}
