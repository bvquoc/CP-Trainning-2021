//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) short(x.size())
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
#define pii pair<short, short>

using namespace std;

short n, m, cntgo, cntback;
pii a[maxn*8];
short ago[maxn], aback[maxn];
short res[maxn][maxn];

short root[maxn];

short get_root(short u){
    return root[u] ? root[u] = get_root(root[u]) : u;
}

void Init(){
    reset(root); ago[0] = 0;
    for (short i = 1; i <= m; i++){
        short p = get_root(a[i].F);
        short q = get_root(a[i].S);
        if (p - q){
            root[p] = q;
            ago[++cntgo] = i;
        }
    }

    reset(root);
    for (short i = m; i; i--){
        short p = get_root(a[i].F);
        short q = get_root(a[i].S);
        if (p - q){
            root[p] = q;
            aback[++cntback] = i;
        }
    }
    //reverse(aback, aback[cntback)
	//return;
    sort(aback+1, aback+cntback+1);
    aback[0] = -1;
    for (short i = 0; i <= cntgo; i++){
        reset(root);
        for (short j = 1; j <= i; j++) root[get_root(a[ago[j]].F)] = get_root(a[ago[j]].S);
        short cur = res[i][cntback+1] = n-i; 
		short x = lower_bound(aback, aback + cntback + 1, ago[i]) - aback;
		//continue;
        for (short j = cntback; j >= x; j--){
			short pos = aback[j];
            short p = get_root(a[pos].F);
            short q = get_root(a[pos].S);
            if (p-q){
                root[p] = q;
                res[i][j] = --cur;				
            } else res[i][j] = cur;
        }
    }
}

void Calc(){
    int ntest = 0, l, r;
    cin >> ntest;
    while (ntest--){
        cin >> l >> r;
        short u = lower_bound(ago+1, ago+cntgo+1, l) - ago - 1;
        short v = upper_bound(aback+1, aback+cntback+1, r) - aback;
        cout << res[u][v] << "\n";
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m;
    for (short i = 1; i <= m; i++) cin >> a[i].F >> a[i].S;
    Init();
    Calc();
    return 0;
}

