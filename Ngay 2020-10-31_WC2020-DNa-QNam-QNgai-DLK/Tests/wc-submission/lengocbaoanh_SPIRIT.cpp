#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long res,a,b,c,point,lastpoint;
	cin >> a >> b >> c;
	if(a / c == b / c) {
		cout << (b - a + 1) / 2;
		return 0;
	}
	point = a / c + 1;
	point *= c;
	res = (point + 1 - a + 1) / 2;
	lastpoint = b / c; lastpoint *= c;
	res += ((c % 2) ? (c / 2 + 1) : (c/ 2)) * (lastpoint - point) / c + (b - lastpoint) / 2;
	cout << res;
}
//1 2 3 4 5
