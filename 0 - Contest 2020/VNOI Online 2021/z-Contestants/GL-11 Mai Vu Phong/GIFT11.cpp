#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#define endl '\n'
#define int ll
#define file "GIFT11"
#define MASK(i) (1 << (i))
#define BIT(mask, i) (((mask) >> (i)) & 1)

using namespace std;

typedef long long ll;

const int Pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
const int mod = 998244353;

ifstream fi(file".inp");
ofstream fo(file".out");
int _, n, F[MASK(20)][11], A[2001];

int dp(int i, int mask, int r)
{
	int &res = F[mask][r];
	if (res != -1) return res;
	if (i > n) return res = (r == 0);
	res = 0;
	for (int j = 1; j <= n; j++)
		if (!BIT(mask, j-1))
		{
			int nR = (r*Pow10[int(log10(A[j]))+1] + A[j])%11;
			res += dp(i+1, mask|MASK(j-1), nR);
			res %= mod;
		}
	return res;
}

void sub2()
{
	int even = 0, odd = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		while (A[i] != 0)
		{
			cnt++;
			if (cnt%2 == 0) even += A[i]%10;
			else odd += A[i]%10;
			A[i] /= 10;
		}
	}
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
		fact %= mod;
	}
	fo << ((even-odd)%11 == 0 ? fact : 0) << endl;
}

signed main()
{
	for (fi >> _; _--;)
	{
		fi >> n;
		for (int i = 1; i <= n; i++) fi >> A[i];
		if (n <= 20)
		{
			memset(F, -1, sizeof F);
			fo << dp(1, 0, 0) << endl;
			continue;
		}
		bool isSub2 = 1;
		for (int i = 1; i <= n; i++)
			if ((int(log10(A[i]))+1)%2 == 1)
			{
				isSub2 = 0;
				break;
			}
		if (isSub2)
		{
			sub2();
			continue;
		}
		
	}
}
/*
((_,...,_))    
   |o o|
   \   /
    ^_^   
*/
