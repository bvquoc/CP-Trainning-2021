#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define ll int
#define ii int
ll q[1000001], statt[21], ti[21], inn[11], outt[11], i, j, k, t, n, m, cur = 0, minn, a, b, conv[26];
vector<ll> mine;
char x[1000001],y[1000001],c;
string res="";
int main()
{
	freopen("PAINT.INP", "r", stdin);
	freopen("PAINT.OUT", "w", stdout);
	cin >> n;
	i = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> q[i];
		if (q[i] == 1) cin >> x[i];
		else cin >> x[i] >> y[i];
	}
	for (i = 0; i < 26; i++) conv[i] = i;
	for (i = n; i >= 1; i--)
	{
		if (q[i] == 2) conv[x[i] - 97] = conv[y[i] - 97];
		else if (q[i] == 1){ c = conv[x[i] - 97] + 97;
		res.push_back(c);
	}
		
	}
	m = res.length();
		for (i = m - 1; i >= 0; i--) cout << res[i];
	fclose(stdin);
	fclose(stdout);
}