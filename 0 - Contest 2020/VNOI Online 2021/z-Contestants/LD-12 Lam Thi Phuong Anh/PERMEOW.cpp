#include <bits/stdc++.h>

using namespace std;
const int Sz = 2e5 + 5;
int n;
int a[Sz];
int b[Sz];
void sub1(){
	map<int,int> f;
	int res = 0;
	bool sw = true;
	while(sw){
		sw = false;
		for(int i = 1; i < n; i++){
			if(a[i] > a[i + 1]){
				res++;
				sw = true;
				swap(a[i], a[i + 1]);
			}
		}
	}
	cout << res;
}

int main(){

	freopen("PERMEOW.INP", "r", stdin);
	freopen("PERMEOW.OUT", "w", stdout);

	cin >> n;

	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];

	sub1();

	return 0;
}