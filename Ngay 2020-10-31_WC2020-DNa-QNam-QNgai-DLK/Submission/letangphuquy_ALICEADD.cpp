#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nTests;
	cin >> nTests;
	for ( ;nTests --> 0; ) {
		unsigned long long a, b;
		cin >> a >> b;
		string num_a, num_b;
		for (; a; a /= 10) num_a += (char) (a % 10 + '0');
		for (; b; b /= 10) num_b += (char) (b % 10 + '0');
		
		while (num_a.size() < num_b.size()) num_a += '0';
		while (num_b.size() < num_a.size()) num_b += '0';
		reverse(num_a.begin(), num_a.end());
		reverse(num_b.begin(), num_b.end());
		string result = "";
		int n = num_a.size(), rem = 0;
		for (int i = n - 1; i >= 0; i--) {
			int d_a = num_a[i] - '0', d_b = num_b[i] - '0';
			int d_r = (d_a + d_b + rem) % 10;
//			cerr << i << "-th digit = " << d_r << "\n";
			result += (char) d_r + '0';
			rem = (d_a + d_b + rem) / 10;
		}
		if (rem) result += "1";
		reverse(result.begin(), result.end());
		cout << result << "\n";
	}
}
