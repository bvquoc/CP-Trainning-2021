/*input
4
2
1 1
3
1 31 12
3
12345 67 84
9
1 2 3 4 5 6 7 8 9
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)
#define all(x) begin(x), end(x)
#define vi vector<int>
#define eb emplace_back
#define ii pair<int, int>
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define bitCnt __builtin_popcountll

const int maxN = 2005, base = 11, mod = 998244353;

int T, N, even, odd, Even[maxN], Odd[maxN], ans;
int dp[maxN][maxN][base];
int oddSum[base], evenSum[base];
void add(int &a, int b)
{
	a = (a + b + mod) % mod;
}

string toStr(int x) {
	string ret; while (x > 0) {
		ret += char(x % 10 + '0');
		x /= 10;
	}
	if (ret.empty()) ret = "0";
	reverse(ret.begin(), ret.end());
	return ret;
}
bool checkEven(int x)
{
	return toStr(x).size() % 2 == 0;
}
int getRem(int x)
{
	string s = toStr(x);
	int nowCoef = 1, re = 0;
	while (!s.empty())
	{
		re = (re + nowCoef * (s.back() - '0')) % base;
		s.pop_back();
		nowCoef *= -1;
	}
	return (re + base) % base;
}
signed main()
{
	freopen("GIFT11.inp", "r", stdin);
	freopen("GIFT11.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		even = 0;
		odd = 0;
		ans = 0;
		loop(rem, 0, base - 1) oddSum[rem] = evenSum[rem] = 0;
		loop(i, 1, N)
		{
			int t;
			cin >> t;
			if (checkEven(t))
			{
				Even[++even] = getRem(t);
			}
			else
			{
				Odd[++odd] = getRem(t);
			}
		}
		loop(i, 0, odd)
		{
			loop(j, 0, odd)
			{
				loop(k, 0, base - 1)
				{
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][0] = 1;
		loop(rema, 0, odd)
		{
			loop(reve, 0, odd)
			{
				loop(rem, 0, base - 1)
				{
					int num = rema + reve;
					if (num < 0 or num > odd) continue;
					if (num == odd and (rema == reve or rema == reve + 1))
					{
						add(oddSum[rem], dp[rema][reve][rem]);
					}
					else
					{
						int remaRem = (rem + Odd[num + 1]) % base,
						    reveRem = (rem - Odd[num + 1] + base) % base;
						add(dp[rema + 1][reve][remaRem], ((rema + 1) * dp[rema][reve][rem]) % mod);
						add(dp[rema][reve + 1][reveRem], ((reve + 1) * dp[rema][reve][rem]) % mod);
					}
				}
			}
		}
		loop(i, 0, even)
		{
			loop(j, 0, even)
			{
				loop(k, 0, base - 1)
				{
					dp[i][j][k] = 0;
				}
			}
		}
		int startRemaPos = 0, startRevePos =  0;
		loop(pos, 0, odd)
		{
			if (pos & 1) startRevePos++;
			else startRemaPos++;
		}
		dp[0][0][0] = 1;
		loop(rema, 0, even)
		{
			loop(reve, 0, even)
			{
				loop(rem, 0, base - 1)
				{
					int num = rema + reve;
					if (num < 0 or num > even) continue;
					if (num == even)
					{
						add(evenSum[rem], dp[rema][reve][rem]);
					}
					else
					{
						int remaRem = (rem + Even[num + 1]) % base,
						    reveRem = (rem - Even[num + 1] + base) % base;
						int remaPos = startRemaPos + rema, revePos = startRevePos + reve;
						add(dp[rema + 1][reve][remaRem],  (remaPos * dp[rema][reve][rem]) % mod);
						add(dp[rema][reve + 1][reveRem],  (revePos * dp[rema][reve][rem]) % mod);
					}
				}
			}
		}
		loop(oddRem, 0, base - 1)
		{
			loop(evenRem, 0, base - 1)
			{
				if ((oddRem + evenRem) % base == 0)
				{
					add(ans, (oddSum[oddRem] * evenSum[evenRem]) % mod);
				}
			}
		}
		cout << ans << endl;
	}
}