// Jarvis's preparing code

#define DAILY_IO "SOCKS"
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
int n, m;
const int N = 500001;
vector<int>a, Deg(N);
vector<int>Edge[N];

vector<bool>Change;
vector<int>used, vis(N);

int aws = 0, last = 0;

void DFS(int u, int deep)
{
      vis[u] = 1;
      if (a[u] && deep > last)
      {
            Change[u] = 1;
            last = deep;
            //++aws;
            return;
      }
      for (int v : Edge[u])
      {
            if (!vis[v])
            {
                  DFS(v, deep + 1);
            }
      }
      vis[u] = 0;
}

int Cal()
{
      aws = 0;
      last = 0;
      Change.assign(n + 1, 0);
      vis.assign(n + 1, 0);

      int tot = 0;
      FOR(i, 1, n)
            if (a[i])
                  ++tot;

      FOR(i,1,n)
            if (!Change[i] && a[i])
            {
                  Change[i] = 1;
                  DFS(i,0);
                  //++aws;
            }

      return aws;

}

int Subtask1()
{
      int tot = 0;
      FOR(i, 1, n)
            if (a[i])
                  ++tot;
      if (tot >= 2)return 1;
      return 0;
}

void Processing()
{

      cin >> n >> m; a.resize(n + 1);
      FOR(i, 1, n)
            cin >> a[i];

      FOR(i, 1, n - 1)
      {
            int u, v;
            cin >> u >> v;
            Edge[u].pb(v);
            Edge[v].pb(u);
            ++Deg[u];
            ++Deg[v];
      }

      //duong thang
      bool isroad = 1;
      FOR(i, 1, n)
            if (Deg[i] > 2)
                  isroad = 0;

      if (isroad)
      {
            int tot = 0;
            FOR(i, 1, n)
                  if (a[i])
                        ++tot;
            if (tot >= 2)
                  cout << 1 << enl;
            else cout << 0 << enl;

            FOR(i, 1, m)
            {
                  int x; cin >> x;
                  if (a[x])a[x] = 0;
                  else a[x] = 1;

                  cout << Subtask1() << enl;

            }

            return;
      }

      FOR(i, 1, n)
      {
            aws = max(aws, Deg[i]);
      }

      cout << aws << enl;
      FOR(i, 1, m)
            cout << aws << enl;







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
      printf("\nTime taken: %.3fs", (((double)clock() - tStart) / CLOCKS_PER_SEC));
#endif
      ////////
      return 0;
}