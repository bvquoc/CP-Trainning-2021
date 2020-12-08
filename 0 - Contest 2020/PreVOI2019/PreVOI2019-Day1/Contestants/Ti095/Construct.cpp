#include <bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int, int>
#define X first
#define Y second
#define a(i, j) aa[(i - 1) * N + j]  

using namespace std;

const int oo = 1e18;
const int eps = 1e-9;

int T, N, M, L, R, K;
int A[2000000], SUM[4 * 2000000], LAZY[4 * 2000000];
int gg[2000000];

void BUILD(int id, int l, int r){
    if (l == r){
        SUM[id] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    BUILD(2 * id, l, mid);
    BUILD(2 * id + 1, mid + 1, r);
    SUM[id] = SUM[2 * id] + SUM[2 * id + 1];
}

void FIX(int id, int l, int r){
    if (!LAZY[id]) return;
    SUM[id] += LAZY[id] * (r - l + 1);
    if (l != r){
        LAZY[2 * id] += LAZY[id];
        LAZY[2 * id + 1] += LAZY[id];
    }
    LAZY[id] = 0;
}

void UPDATE(int id, int l ,int r, int u, int v, int k){
    FIX(id, l, r);
    if (l > v || r < u){
        return;
    }
    if (l >= u && r <= v){
        LAZY[id] = k;
        FIX(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    UPDATE(2 * id, l, mid, u, v, k);
    UPDATE(2 * id + 1, mid + 1, r, u, v, k);
    SUM[id] = SUM[2 * id] + SUM[2 * id + 1];
}

int GET(int id, int l, int r, int u, int v){
    FIX(id, l , r);
    if (l > v || r < u){
        return 0;
    }
    if (l >= u && r <= v){
        return SUM[id];
    }
    int mid = (l + r) / 2;
    int g1 = GET(2 * id, l, mid, u, v);
    int g2 = GET(2 * id + 1, mid + 1, r, u, v);
    return g1 + g2;
}


int GD(){
    int s = GET(1, 1, N, L, L);
    gg[L] = s;

    for (int i = L + 1; i <= R; ++i){
        gg[i] = GET(1, 1, N, i, i);
        if (gg[i] > gg[i - 1]) s += gg[i] - gg[i - 1];
    }
    return s;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("Construct.inp", "r", stdin);
    freopen("Construct.out", "w", stdout);
    	cin >> T;
    	while (T--){
    		cin >> N >> M;
    		for (int i = 1; i <= N; ++i){
    			cin >> A[i];
    		}
            BUILD(1, 1, N);

    		for (int i = 1; i <= M; ++i){
    			int type;
    			cin >> type;
    			switch(type){
    				case 1:
                        cin >> L >> R >> K;
                        UPDATE(1, 1, N, L, R, K);
    				    break;
                        
    				case 2:
                        cin >> L >> R;
                        cout << GD() << '\n';
    				    break;
    			}
    		}
    	}
}
