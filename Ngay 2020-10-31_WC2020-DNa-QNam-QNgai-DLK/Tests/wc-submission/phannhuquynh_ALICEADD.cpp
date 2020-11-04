#include <bits/stdc++.h>
using namespace std;
int test;
string a, b;

void swapString(string a, string b){
    	string tmp = a;
    	a = b;
    	b = tmp;
}

string add(string a, string b)
{
		if (a.size() > b.size()) swapString(a, b);
		while (a.size() < b.size()) a = '0' + a;
		int n = a.size();
		string s = "";
		int rem = 0;
		for(int i = n - 1; i >= 0; i--){
				int x = a[i] - '0';
				int y = b[i] - '0';
				int z = (x + y + rem) % 10;
				rem = (x + y + rem) / 10;
				s = (char)(z + '0') + s;
		}
		if (rem > 0) s = char(rem + '0') + s;
		return s;
}

int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
//		freopen("aliceadd.inp", "r", stdin);
//		freopen("aliceadd.out", "w", stdout);
		
		cin >> test; 
		while (test -- ){
				cin >> a >> b;
				cout << add(a, b) << '\n';
		}
}
