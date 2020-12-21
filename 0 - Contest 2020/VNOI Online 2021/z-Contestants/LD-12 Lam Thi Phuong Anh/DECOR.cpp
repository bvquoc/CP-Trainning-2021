#include<bits/stdc++.h>

using namespace std;
const int Sz = 5e5 + 5;
string s;
int n, m, k;
void sub1(){
	int i = 1;
	int res = 0;
	int l = 0;

	while(i < int(s.size())){
		if(s[i] == '0'){
			i++;
			continue;
		}
		int j = i;
		while(j < int(s.size()) && s[j] == '1') j++;
		if(j - i > res){
			res = j - i;
			l = i;
		}
		i = j;
	}
	if(res == 0){
		cout << "-1\n";
		return ;
	}
	cout << l << " " << l + res - 1 << "\n";
}
int Sum[Sz];
map<int, int> f;
// sum[r] - r == sum[l - 1] - l + 1 - k
void sub2(){
	Sum[0] = 0;
	for(int i = 1; i < int(s.size()); i++) Sum[i] = Sum[i - 1] + s[i] - 48;
	int l = 0;
	int r = -1;
	for(int i = 1; i <= n; i++){
		if(Sum[i] + k >= i && i > r - l + 1){
			l = 1;
			r = i;
		}
		int d = Sum[i] - i;
		if(f[d] != 0 && i - f[d] + 1 > r - l + 1){
			l = f[d];
			r = i;
		}
		if(f[Sum[i - 1] - l + 1 - k] == 0)f[Sum[i - 1] - l + 1 - k] = i;
	}
	if(r == -1){
		cout <<"-1\n";
		return ;
	}
	cout << l << " " << r << "\n";
}
vector<int> check;
vector<int> G[Sz];
int dp(int pos, int cnt){
	if(pos > n) return n;
	int res = pos - 1;
	if(s[pos] == '1' && !check[pos]){
		check[pos] = true;
		res = max(res, dp(pos + 1, cnt));
		check[pos] = false;
	}
	if(cnt) res = max(res, dp(pos + 1, cnt - 1));

	for(int i : G[pos]){
		if(!check[i] && s[i] == '1'){
			check[i] = true;
			res = max(res, dp(pos + 1, cnt));
			check[i] = false;
		}
	}
	return res;
}
int main(){
	freopen("DECOR.INP", "r", stdin);
	freopen("DECOR.OUT", "w", stdout);
	cin >> n >> m >> k;

	cin >> s;
	s = " " + s;

	if(m == 0 && k == 0){
		sub1();
		return 0;
	}
	if(m == 0){
		sub2();
		return 0;
	}
	while(m--){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int l = 0;
	int r = -1;
	check.resize(n + 1, false);
	for(int i = 1; i <= n; i++){
		int j = dp(i, k);
		if(j - i + 1 > r - l + 1){
			l = i;
			r = j;
		}
	}

	if(r == -1){
		cout << "-1\n";
		return 0;
	}

	cout << l << " " << r << "\n";

	return 0;
}
