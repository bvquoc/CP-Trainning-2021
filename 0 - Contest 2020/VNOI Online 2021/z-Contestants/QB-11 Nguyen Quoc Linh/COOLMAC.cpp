// Jarvis's preparing code

#define DAILY_IO "COOLMAC"
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
int n, m, MIN = oo, aws = 0;
vector<Pii> Mac(100010);


bool CMP(const Pii&left,const Pii&right)
{
      return 1;
}

void Processing()
{

      cin >> m;
      FOR(i, 1, m)
      {
            cin >> Mac[i].F >> Mac[i].S;
      }

      cin >> n;
      FOR(i, 1, n)
      {
            int x;
            cin >> x;
            MIN = min(MIN, x);
      }
      
      
      bool safe=0;
      FOR(i,1,m)
      {
            if(MIN >= Mac[i].F)
                  safe = 1;
      }

      if(!safe){
            cout<<-1;
            return;
      }safe = 0;

      FOR(i,1,m)
      {
            if(100000<= Mac[i].S)
                  safe = 1;
      }

      if(!safe){
            cout<<-1;
            return;
      }
      
      
      
      int last = 100000;
      vector<bool>used(m+1);




      FOR(i,1,m)
      {
            //sort(Mac.begin()+1,Mac.begin()+1+m,CMP);

            ++aws;

            int j = 0,now = oo;

            FOR(l,1,m)
            {
                  if(!used[l] && last <= Mac[l].S && now > Mac[l].F)
                  {
                        now = Mac[l].F;
                        j = l;
                  }
            }

            if(now<=MIN)
            {
                  cout<<aws;
                  return;
            }

            if(j==0)
            {
                  cout<<-1;
                  return;
            }

            last = now;
            used[j] = 1;


      }

      cout<<-1;


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