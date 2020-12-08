#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 2e6 + 55;

int n;
vector<char> a;

void sub1(){
	for(int iter = 0; iter < n; iter++){
		int tp;	cin >> tp;
		if(tp == 1){
			char c;	cin >> c;
			a.push_back(c);
		} else if(tp == 2){
			char x, y;	cin >> x >> y;
			for(int i = 0, L = (int)a.size(); i < L; i++){
				if(a[i] == x){
					a[i] = y;
				}
			}
		}
	}

	for(int i = 0, L = (int)a.size(); i < L; i++){
		cout << a[i];
	}
	cout << '\n';
}

int par[maxN], id[300];
char val[maxN];

int getRoot(int u){
	if(par[u] == u){
		return u;
	}

	return par[u] = getRoot(par[u]);
}

void sub2(){
	for(int i = 1; i < maxN; i++){
		par[i] = i;
	}
	
	int i = 0;
	for(int iter = 0; iter < n; iter++){
		int tp;	cin >> tp;
		if(tp == 1){
			i++;	char c;	cin >> c;
			if(!id[c]){
				id[c] = getRoot(i);
				val[i] = c;
			}

			par[i] = getRoot(id[c]);
		} else {
			char x, y;	cin >> x >> y;
			if(x == y){
				continue;
			}

			if(id[x] == 0){
				continue;
			}

			int xx = getRoot(id[x]);
			if(id[y] == 0){
				id[y] = xx;
				val[xx] = y;
				id[x] = 0;
				continue;	
			}

			int yy = getRoot(id[y]);
			par[xx] = yy;
			id[x] = 0;
		}
	}
	
	int k = i;
	for(i = 1; i <= k; i++){
		cout << val[getRoot(i)];
	}
	cout << '\n';
}

void testGen(){
	srand(time(NULL));
	freopen("PAINT.INP", "w", stdout);
	
	int N; N = 100;
	cout << N << '\n';
	cout << "1 " << (char)(rand() % 26 + 'a') << '\n';
	for(int j = 1; j <= N - 1; j++){
		char fr = (char)(rand() % 26 + 'a');
		char to = (char)(rand() % 26 + 'a');
		int tp = rand() % 2 + 1;
		cout << tp << ' ';
		if(tp == 1){
			cout << fr << '\n';
		} else {
			cout << fr << ' ' << to << '\n';
		}
	}

	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	//testGen();

	freopen("PAINT.INP", "r", stdin);
	freopen("PAINT.OUT", "w", stdout);
	
	cin >> n;

	if(n <= 10000){
		sub1();
		return 0;
	}

	sub2();

	return 0;
}