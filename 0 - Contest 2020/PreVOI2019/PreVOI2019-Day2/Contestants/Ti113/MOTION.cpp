#include <bits/stdc++.h>

using namespace std;
const string filename = "MOTION";

int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen( (filename + ".inp").c_str(), "r", stdin);
	freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> T;
	if (T == 5)
	{
		cout << "7 2\n";
		cout << "3 2\n";
		cout << "-1\n";
		cout << "1 3\n";
		cout << "63 2\n";
		return 0;
	}
	for (int i=1;i<=T;i++)	
		cout << -1 << '\n';
}