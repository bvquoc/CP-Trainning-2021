#include <bits/stdc++.h>
#define X first
#define Y second
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f0(i,n) for (int i = 0; i < n; i++)
#define N 100005

using namespace std;

typedef pair<int,int> ii;
int n, k, m, l;
vector<int> c[N];
vector<ii> a[N];
int d[N];
int A[11][11],DanhDau[11],L[11],C,D,ans=INT_MAX;

bool minimize(int &a, int b){ if (a > b) a = b; else return false; return true; }

int dijkstra(int Start, int Target){
    priority_queue<ii> qu;
    qu.push(ii(0, Start));
    f1(i, n) d[i] = 0x44445555;
    d[Start] = 0;
    
    while (qu.size()){
        ii top = qu.top(); qu.pop();
        int u = top.Y, du = -top.X;
        if (du != d[u]) continue;
        if (u == Target) return d[u];
        
        for (int i = 0, v; v = a[u][i].Y; i++)
        if (minimize(d[v], d[u] + a[u][i].X))
        qu.push(ii(-d[v], v));
    }
    return -1;
}
void InDuongDi(int SoCanh) {

   int cnt = 0;
   int check[6];
   f1(i,n) check[i] = 0;
   for (int i = 0; i < c[D+1].size(); i++) check[c[D+1][i]] = 1;

   for (int i = 1; i < SoCanh; i++)
        for (int j = 0;j < c[L[i]+1].size(); j++) check[c[L[i]+1][j]] = 1;
   f1(i,5) if (check[i] == 1) cnt++;
   if (cnt >= l)
   {
       int cur = 0;
       f0(i,SoCanh) cur += A[L[i]][L[i+1]];
       if (cur < ans) ans = cur;
   }
}
void TimKiem(int SoCanh) {
   if(L[SoCanh-1] == C)   
    InDuongDi(SoCanh);
   else {   
    for(int i = 0; i<n; i++)
      if( A[L[SoCanh-1]][i]>0 && DanhDau[i] == 0 ){
         L[SoCanh] = i;     
         DanhDau[i] = 1;      
         TimKiem(SoCanh+1);  
         L[SoCanh] = 0;      
         DanhDau[i] = 0;      
      }
   }
}

int main()
{
    ifstream fi("DHAKA.INP"); ofstream fo("DHAKA.OUT");
    fi >> n >> m >> k >> l;
    f1(i,n) a[i].clear();
    f0(i,n) f0(j,n) A[i][j] = 0;
    f1(i, n)
    {
        int t;
        fi >> t;
        f1(j, t) 
        {
            int x;
            fi >> x;
            c[i].push_back(x);
        }
    }
    f1(i, m)
    {
        int u, v, w;
        fi >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
        if (n <= 10) A[u-1][v-1] = A[v-1][u-1] = w;
    }
    f1(i,n) a[i].push_back(ii());
    if (l == 0) ans = dijkstra(1, n);
    else
    {
        C = n - 1; D = 0;
        for (int i = 0; i<n; i++) {   
      DanhDau[i] = 0;
      L[i] = 0;
   }
        DanhDau[D] = 1;
        L[0] = D;
        TimKiem(1);
        if (ans == INT_MAX) fo << -1;
        else fo << ans << endl;
    }
    system("pause");
    return 0;
}