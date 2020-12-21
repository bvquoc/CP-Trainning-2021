#include <iostream>
#include <fstream>
#include <algorithm>

#define endl '\n'
#define int ll
#define file "PERMEOW"

using namespace std;

typedef long long ll;

const int maxN = 2e5;
const int mod = 1e9+7;

ifstream fi(file".inp");
ofstream fo(file".out");
int n, A[maxN+1], B[maxN+1], F[maxN+1], Fact[maxN+1];

bool isSub1()
{
	bool is1 = 1;
	for (int i = 1; i <= n; i++)
		if (A[i] != B[i])
		{
			is1 = 0;
			break;
		}
	return is1 && n <= 3000;
}

void sub1()
{
	int res = 0;
	for (int i = n; i > 0; i--)
		for (int j = 1; j < i; j++)
			if (A[j] > A[j+1])
			{
				res++;
				swap(A[j], A[j+1]);
			}
	fo << res;
}

bool isSub2()
{
	bool is2 = 1;
	for (int i = 1; i <= n; i++)
		if (A[i] != B[n-i+1])
		{
			is2 = 0;
			break;
		}
	return is2;
}

signed main()
{
	fi >> n;
	for (int i = 1; i <= n; i++) fi >> A[i];
	for (int i = 1; i <= n; i++) fi >> B[i];
	if (isSub1()) return sub1(), 0;
	Fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		Fact[i] = Fact[i-1]*i;
		Fact[i] %= mod;
		// cout << Fact[i] << endl;
	}
	F[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		F[i] = F[i-1]*i%mod + Fact[i-1]*(i*(i-1)/2%mod)%mod;
		F[i] %= mod;
	}
	if (isSub2()) return fo << F[n], 0;
	
}
/*
((_,...,_))    
   |o o|
   \   /
    ^_^   
*/
