// Jarvis's preparing code

        #define DAILY_IO "PERMEOW"
        #define TASK_NAME ""
        //#define TIME_CAL

// <---------------------------------------------------------------->
#ifndef Prepare
////////
#ifndef Preprocessor
#define _CRT_SECURE_NO_WARNINGS
#define enl "\n"
#define uLL unsigned long long int
#define LL  long long int
#define IO_PRE std::cin.tie(0)->sync_with_stdio(0);
#define PT    printf
#define SC(a) scanf("%d",&a);
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define pb  push_back
#define eb  emplace_back
#define mp  make_pair
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<long long int, long long int>
#define MOD   1000000007
#define oo    1000111000
#define ooINT 2147483647           //2e31-1
#define ooULL 18446744073709551615 //2e64-1
#define uInt 2e32-1
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

int aws=0;
int n;
vector<int>a,b;



void Processing()
{
      int n;
      cin>>n;

      a.resize(n+1);
      b.resize(n+1);

      FOR(i,1,n)cin>>a[i];
      FOR(i,1,n)cin>>b[i];

      bool safeA=1,safeB;
      FOR(i,2,n)
            if(a[i]>a[i-1])
                  safeA=0;
     
      FOR(i,2,n)
            if(b[i]>b[i-1])
                  safeB=0;

      if(safeA&&safeB)
            cout<<0;

      
      bool isCan=0;
      int tot=0;
      FOR(i,1,n)
      {
            if(a[i]!=b[i])
                  isCan=1;
            
            if(isCan)break;

            if(a[i]!=i)
                  ++tot;
      }

      if(!isCan)
      {
            cout<<tot-1;
      }
      else {
            int cA=0,cB=0;
            FOR(i,1,n)
                  if(a[i]!=i)
                        cA++;
            FOR(i,1,n)
                  if(b[i]!=i)
                        cB++;

            cout<<(cA-1)+(cB-1);
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
      freopen(DAILY_IO".INP", "r", stdin);
      freopen(DAILY_IO".OUT", "w", stdout);
      #endif
      Processing();
      ////////
      #ifdef TIME_CAL
      printf("\nTime taken: %.3fs",(((double)clock()-tStart)/CLOCKS_PER_SEC));
      #endif
      ////////
      return 0;
}