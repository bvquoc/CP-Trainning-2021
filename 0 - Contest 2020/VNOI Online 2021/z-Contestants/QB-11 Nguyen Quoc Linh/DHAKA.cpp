// Jarvis's preparing code

        #define DAILY_IO "DHAKA"
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
struct Piil{
      int u,v;
      LL w;
};vector<Piil>Edge(1);

vector<int>E[100110];
vector<LL> V[100110];

vector<int>HaveUseEdge;
///
const int N = 100110;
int n,m,k,l;
vector<int>s;
vector<vector<int> >a;
///
vector<int>thisIsAble(10);
///
vector<int>Used(10);

LL aws = -1;

void DFS(int u,int pa,LL cost)
{

      if(u==n)
      {
            int cnt = 0;
            
            FOR(i,1,k)
                  if(Used[i])
                        ++cnt;

            if(cnt>=l)
            {
                  if(cost < aws || aws==-1)
                  {
                        aws = cost;
                  }
            }
            //return;
      }

      FOR(i,1,s[u])
      {
            Used[a[u][i]]++;
            
      }
      ////
      for(int i=1;i<=m;++i)
      {
            if(Edge[i].u == u && HaveUseEdge[i]<2)
            {
                  HaveUseEdge[i]++;
                  DFS(Edge[i].v,u,cost + Edge[i].w);
                  HaveUseEdge[i]--;
            }
            if(Edge[i].v == u && HaveUseEdge[i]<2)
            {
                  HaveUseEdge[i]++;
                  DFS(Edge[i].u,u,cost + Edge[i].w);
                  HaveUseEdge[i]--;
            }
      }

      ///
      FOR(i,1,s[u])
      {
            Used[a[u][i]]--;
      }



}

void Dijkstra()//Sub2 || l == 0, shortest path
{
      priority_queue<Pll>Queue;

      vector<LL>d(n+1,-1);

      d[1]=0;

      Queue.push({0,1});

      while(Queue.size())
      {
            Pii Top = Queue.top(); Queue.pop();
            //
            LL du = -Top.first;
            int u  = Top.second;

            if(du!=d[u])
                  continue;

            FOR(i,0,E[u].size()-1)
            {
                  int v = E[u][i];
                  LL c = V[u][i];

                  if(d[u] + c < d[v] || d[v]==-1)
                  {
                        d[v] = d[u] + c;

                        Queue.push({-d[v],v});
                  }
            }



      }

      aws = d[n];


}

void SubTask2()
{
      FOR(i,1,m)
      {
            int u,v,t;
            cin>>u>>v>>t;
            E[u].pb(v);
            V[u].pb(t);

            E[v].pb(u);
            V[v].pb(v);
      }

      Dijkstra();


      cout<<aws;


}

bool CMP(const Piil & left,const Piil &right)
{
      if(left.w==right.w)
      {
            if(left.u==right.u)
                  return left.v<right.v;
            return left.u<right.u;
      }return left.w<right.w;
}

void Processing()
{
      cin>>n>>m>>k>>l;


      //n contry, m edge, k type of watermelon, l is the choose

      s.resize(n+1);
      a.resize(n+1);
      HaveUseEdge.resize(m+1);

      FOR(i,1,n)
      {
            cin>>s[i];
            
            a[i].resize(s[i]+1);

            FOR(j,1,s[i])
            {
                  cin>>a[i][j];

                  thisIsAble[a[i][j]]=1;
            }
      }

      //Need info for edge, edge list

      if(l==0 || k==1 || (n>100 && m>100))
      {
            SubTask2();
            exit(0);
      }

      FOR(i,1,m)
      {
            int u,v,w;
            cin>>u>>v>>w;

            Edge.pb({u,v,w});
      }

      sort(Edge.begin()+1,Edge.begin()+1+m,CMP);
      
      int AmoutOfWT=0;
      FOR(i,1,k)
            if(thisIsAble[i])
                  ++AmoutOfWT;
      if(AmoutOfWT < l) 
      {
            cout<<-1;
            return;
      }


      DFS(1,0,0);



      cout<<aws;

      
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
      freopen(DAILY_IO".INP", "r", stdin);
      freopen(DAILY_IO".OUT", "w", stdout);
      //#endif
      Processing();
      ////////
      #ifdef TIME_CAL
      printf("\nTime taken: %.3fs",(((double)clock()-tStart)/CLOCKS_PER_SEC));
      #endif
      ////////
      return 0;
}