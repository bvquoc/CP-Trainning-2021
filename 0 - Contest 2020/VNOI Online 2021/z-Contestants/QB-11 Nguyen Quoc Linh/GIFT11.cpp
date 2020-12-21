// Jarvis's preparing code

#define DAILY_IO "GIFT11"
#define TASK_NAME ""
//#define TIME_CAL

// <---------------------------------------------------------------->
#ifndef Prepare
////////
#ifndef Preprocessor
#define _CRT_SECURE_NO_WARNINGS
#define enl "\n"
#define uLL unsigned long long int
#define LL long long int
#define IO_PRE std::cin.tie(0)->sync_with_stdio(0);
#define PT printf
#define SC(a) scanf("%d", &a);
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<long long int, long long int>
#define MOD 998244353
#define oo 1000111000
#define ooINT 2147483647           //2e31-1
#define ooULL 18446744073709551615 //2e64-1
#define uInt 2e32 - 1
#endif
////////
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <queue>
#include <stack>
#include <random>
#include <set>
#include <iomanip>
#include <map>
#include <math.h>
#include <limits>
#include <climits>
#include <bitset>
////////
using namespace std;
////////
void Input_Preparing() {}
////////
#endif
// <---------------------------------------------------------------->
int n, m;

int aws = 0;

vector<string>S;
vector<int>used, Odd, Eve;

void Reb(int x, int O, int E, int cur)
{
      if (x > n)
      {
            if ((O - E) % 11 == 0) ++aws;
            if(aws>=MOD) aws %= MOD;
            return;
      }
      FOR(i, 1, n)
      {
            if (!used[i])
            {
                  used[i] = 1;
                  if (cur & 1)
                        Reb(x + 1, O + Eve[i], E + Odd[i], cur + S[i].size());
                  else  Reb(x + 1, O + Odd[i], E + Eve[i], cur + S[i].size());
                  used[i] = 0;
            }
      }
}

void Solve()
{
      aws = 0;

      cin >> n;


      S.assign(n + 1, "");
      Odd.assign(n + 1, 0);
      Eve.assign(n + 1, 0);
      used.assign(n + 1, 0);

      FOR(i, 1, n)
      {
            cin >> S[i];

            FOR(j, 1, S[i].size())
            {
                  if (j & 1)
                  {
                        Odd[i] += (int)(S[i][j - 1] - '0');
                  }
                  else Eve[i] += (int)(S[i][j - 1] - '0');
            }
      }



      Reb(1, 0, 0, 0);

      cout << aws % MOD << enl;

}

void Processing()
{

      int t;
      cin >> t;
      while (t--)
      {
            Solve();
      }


}

////////
int main()
{
#ifdef TIME_CAL
      clock_t tStart = clock();
#endif
      ////////
      IO_PRE;
#ifndef ONLINE_JUDGE
      freopen(DAILY_IO ".INP", "r", stdin);
      freopen(DAILY_IO ".OUT", "w", stdout);
#endif
      Processing();
      ////////
#ifdef TIME_CAL
      printf("\nTime taken: %.3fs", (((double)clock() - tStart) / CLOCKS_PER_SEC));
#endif
      ////////
      return 0;
}