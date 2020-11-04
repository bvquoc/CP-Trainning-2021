#include<bits/stdc++.h>
using namespace std;

typedef long long Int;


int main()
{
	Int a, b, c;
	cin >> a >> b >> c;
	Int step = (c / 2) + c % 2;
	Int div_a = a / c, div_b = b / c;
	Int answer = 0;
	if (div_a < div_b) {
		Int trans = (c - a) / 2;
		a += 2 * trans;
		answer += trans;
		if (a == c) a++, answer++;
		div_a++;
//		cerr << "a to " << a << ", ans = " << answer << "\n";
	}
	answer += (div_b - div_a) * step;
	a += (div_b - div_a) * c;
//	cerr << "a to " << a << ", ans = " << answer << "\n";
	answer += (b - a) / 2 + (b - a) % 2;
	cout << answer;
}
