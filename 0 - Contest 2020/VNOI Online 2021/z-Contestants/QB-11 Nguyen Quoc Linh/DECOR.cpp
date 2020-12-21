// Jarvis's preparing code

#define DAILY_IO "DECOR"
#define TASK_NAME ""
#define TIME_CAL

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
#define MOD 1000000007
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
const int N = 100110;
int n, m, k;

vector<Pii> Change(1);

string A;

void Subtask1()
{

      int aws = 0, L = 0, R = 0, aR = -1, aL = -1;

      FOR(i, 0, A.size() - 1)
      {
            L = i;
            while (i < A.size() && A[i] == '1')
            {
                  R = i;
                  ++i;
            }
            if (R - L + 1 > aws && A[i - 1] == '1')
            {
                  aws = R - L + 1;
                  aR = R;
                  aL = L;
            }
      }

      if (R - L + 1 > aws)
      {
            aR = R;
            aL = L;
      }

      if (aR == -1 || aL == -1)
            cout << -1;
      else
            cout << aL + 1 << " " << aR + 1;
}

Pii Check()
{
      int aws = 0, L = 0, R = 0, aR = -1, aL = -1;

      FOR(i, 0, A.size() - 1)
      {
            L = i;
            while (i < A.size() && A[i] == '1')
            {
                  R = i;
                  ++i;
            }
            if (R - L + 1 > aws && A[i - 1] == '1')
            {
                  aws = R - L + 1;
                  aR = R;
                  aL = L;
            }
      }

      if (R - L + 1 > aws)
      {
            aR = R;
            aL = L;
      }

      return {aL + 1, aR + 1};
}

void Subtask2()
{

      //Push all position of '0' in vec
      vector<int> reb;
      FOR(i, 0, A.size() - 1)
      if (A[i] == '0')
            reb.pb(i);

      //try to (1->n-k) (1->k) and get rid of it

      int L = 0, R = k - 1;

      FOR(i, L, R)
      A[reb[i]] = '1';

      int aws = 0, oL = 0, oR = 0;

      FOR(i, 0, reb.size() - k - 1)
      {
            Pii Got = Check();
            if (Got.S - Got.F + 1 > aws && Got.S > 0 && Got.F > 0)
            {
                  aws = Got.S - Got.F + 1;
                  oL = Got.F;
                  oR = Got.S;
            }

            //cout<<reb[i]<<" "<<reb[i+k]<<enl;

            A[reb[i]] = '0';
            A[reb[i + k]] = '1';
      }

      Pii Got = Check();
      if (Got.S - Got.F + 1 > aws && Got.S > 0 && Got.F > 0)
      {
            aws = Got.S - Got.F + 1;
            oL = Got.F;
            oR = Got.S;
      }

      cout << oL << " " << oR << enl;
}

void Processing()
{

      cin >> n >> m >> k;

      cin >> A;

      FOR(i, 1, m)
      {
            int u, v;
            cin >> u >> v;
            Change.pb({u, v});
      }

      //Check if total ('0') <= k
      int Otot = 0;
      for (char c : A)
            if (c == '0')
                  ++Otot;

      if (Otot <= k)
      {
            cout << 1 << " " << n;
            exit(0);
      }

      //in case of m==0 and k==0, that's mean find the longest continue substr "1"

      if (m == 0 && k == 0)
      {
            Subtask1();
            exit(0);
      }

      if (m == 0)
      {
            Subtask2();
            exit(0);
      }

      cout<<1<<" "<<n;


}

////////
int main()
{
#ifdef TIME_CAL
      clock_t tStart = clock();
#endif
      ////////
      IO_PRE;
      //#ifndef ONLINE_JUDGE
      freopen(DAILY_IO ".INP", "r", stdin);
      freopen(DAILY_IO ".OUT", "w", stdout);
      //#endif
      Processing();
////////
#ifdef TIME_CAL
      printf("\nTime taken: %.3fs", (((double)clock() - tStart) / CLOCKS_PER_SEC));
#endif
      ////////
      return 0;
}