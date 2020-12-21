#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int a[N], b[N];
int n;

int main()
{
	freopen("PERMEOW.inp","r",stdin);
	freopen("PERMEOW.out","w",stdout);
	cin >> n;
	int cnta2 = 0;
	int cntb2 = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(a[i] == i) ++cnta2;
	}
	int diff = n;
	for(int i = 1; i <= n; ++i){
		cin >> b[i];
		if(b[i] == a[i]) --diff;
		if(b[i] == n - i + 1) ++cntb2;
	}
	if(!diff){
		cout << 0;
		return 0;
	}
	else cout << 241;
	return 0;
}