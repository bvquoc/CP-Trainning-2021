#include <bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int, int>
#define FI first
#define SE second
#define a(i, j) aa[(i - 1) * N + j]  

using namespace std;

const int oo = 1e18;
const int eps = 1e-9;

struct data {
	int TYPE;
	char X, Y;
};

int N;
char A[2000000];
int CON[2000000];
data SAVE[2000000];
vector <int> ANS;

void sub1(){
	int d = 0;
	while (N--){
		int type;
		char x, y;
		cin >> type;
		switch(type){
			case 1:
				cin >> x;
				++d;
				A[d] = x;
				break;

			case 2:
				cin >> x >> y;
				for (int i = 1; i <= d; ++i){
					if (A[i] == x) A[i] = y;
				}
				break;
		}
	}

	for (int i = 1; i <= d; ++i){
		cout << A[i];
	}
	exit(0);
}

int DFS(int x){
	int DD = 0;
	while (CON[x] != -1){
		++DD;
		if (DD > 50) return x;
		x = CON[x];
	}
	return x;
}

void sub2(){
	memset(CON, -1, sizeof(CON));
	int d = 0;
	for (int i = 1; i <= N; ++i){
		int type; 
		char x, y;
		data p;
		cin >> type;
		switch(type){
			case 1:
				cin >> x;
				++d;
				A[d] = x;
				p.TYPE  = type;
				p.X     = x;
				p.Y     = 0;
				SAVE[i] = p;
				break;

			case 2:
				cin >> x >> y;
				p.TYPE  = type;
				p.X     = x;
				p.Y     = y;
				SAVE[i] = p;
				break;
		}
	}

	for (int i = N; i >= 1; --i){
		if (SAVE[i].TYPE == 2){
			CON[SAVE[i].X] = SAVE[i].Y;
		}	
		else {
			ANS.push_back(DFS(A[d]));
			--d;
		}
	}

	for (int i = ANS.size() - 1; i >= 0; --i){
		cout << char(ANS[i]);
	}
	exit(0);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    	cin >> N;
    	if (N <= 15000) sub1();
    	sub2();
}
