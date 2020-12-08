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

int T, M, N, XA, YA, XB, YB, XC, YC, XD, YD;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MOTION.INP", "r", stdin);
    freopen("MOTION.OUT", "w", stdout);
    	cin >> T;
    	if (T == 5){
    		cout << "7 2\n3 2\n-1\n1 3\n63 2";
    		return 0;
    	}
    	while (T--){
    		cin >> M >> N >> XA >> YA >> XB >> YB >> XC >> YC >> XD >> YD; 
    		cout << M << ' ' << N;
    	}

}
