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

struct data {
	char TYPE;
	int L, R, K;
};

string S;
int N, M;
int A[2000000];
int SUM[10000000];
string SAVE[20000];
data Q[2000000];

void sub1(){
	string s = S;
	s = ' ' + s; 
	SAVE[0] = s;
	for (int m = 1; m <= M; ++m){
		char type;
		int l, r, k, res = 0, q = 0;
		type = Q[m].TYPE;

		switch(type){
			case 'C':
				l = Q[m].L;
				if (s[l] == ')') s[l] = '(';
					else s[l] = ')';
				break;

			case 'Q':
				l = Q[m].L;
				r = Q[m].R;

				for (int i = l; i <= r; ++i){
					if (s[i] == '('){
						++q;
					}
					else {
						--q;
						if (q < 0) {
							++res;
							++q;
						}
					}
				}
				res += q;
				cout << res << '\n';

				break;

			case 'U':
				k = Q[m].K;
				s = SAVE[k - 1];
				break;
		}
		SAVE[m] = s;
	}

	exit(0);
}

void build(int id, int l, int r){
	if (l == r){
		SUM[id] = A[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	SUM[id] = SUM[2 * id] + SUM[2 * id + 1];
}

void update(int id, int l ,int r, int i){
	if (l > i || r < i){
		return;
	}
	if (l == r){
		SUM[id] = 1 - SUM[id];
		return;
	}
	int mid = (l + r) / 2;
	update(2 * id, l, mid, i);
	update(2 * id + 1, mid + 1, r, i);
	SUM[id] = SUM[2 * id] + SUM[2 * id + 1];
}

int get(int id, int l, int r, int u, int v){
	if (l > v || r < u){
		return 0;
	}
	if (l >= u && r <= v){
		return SUM[id];
	}
	int mid = (l + r) / 2;
	int g1 = get(2 * id, l, mid, u, v);
	int g2 = get(2 * id + 1, mid + 1, r, u, v);
	return g1 + g2;
}

void sub2(){
	build(1, 1, N);
 	for (int m = 1; m <= M; ++m){
		char type;
		int l, r, k;
		type = Q[m].TYPE;

		switch(type){
			case 'C':
				l = Q[m].L;
				update(1, 1, N, l);
				break;

			case 'Q':
				l = Q[m].L;
				r = Q[m].R;
				int g1 = get(1, 1, N, l, r);
				int g2 = (r - l + 1) - g1;
				cout << abs(g1 - g2) << '\n';
				break;

		}
	}
	exit(0);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FIXSTR.INP", "r", stdin);
    freopen("FIXSTR.OUT", "w", stdout);
    	cin >> S;

    	for (int i = 0; i < S.size(); ++i){
    		if (S[i] == ')') A[i + 1] = 1;
    	}
    	N = S.size();

    	int dd = 0;
    	cin >> M;
    	for (int m = 1; m <= M; ++m){
			char type;
			int l, r, k;
			data p;
			cin >> type;

			switch(type){
				case 'C':
					cin >> l;
					p.TYPE  = type;
					p.L     = l;
					p.R     = 0;
					p.K     = 0;
					Q[m] = p;
					
					break;

				case 'Q':
					cin >> l >> r;
					p.TYPE  = type;
					p.L     = l;
					p.R     = r;
					p.K     = 0;
					Q[m] = p;

					break;

				case 'U':
					++dd;
					cin >> k;
					p.TYPE  = type;
					p.L     = 0;
					p.R     = 0;
					p.K     = k;
					Q[m] = p;

					break;

			}
		}
		if (N <= 1000 && M <= 1000) sub1();
    	if (!dd) sub2();
    	sub1();
}
