#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

vector <string> a[2005];
int cnt1;
int mark[10];
int s[10];

void ql(int x, const vector<string> &a)
{
   if(x == a.size()){
      int tong[2] = {0, 0};
      int fl = 0;
      //for(int i = 0; i < a.size(); ++i) cerr << s[i] << ' ';
      //cerr << '\n';
      for(int i = 0; i < a.size(); ++i)
         for(int j = 0; j < a[s[i]].size(); ++j) tong[fl] += a[s[i]][j] - '0', fl = !fl;
      //cerr << tong[0] - tong[1] + 11 << '\n';
      if((tong[0] - tong[1] + 11) % 11 == 0) ++cnt1;
      return;
   }
   for(int i = 0; i < a.size(); ++i){
      if(mark[i] == 0){
         mark[i] = 1;
         s[x] = i;
         ql(x + 1, a);
         mark[i] = 0;
      }
   }
}

int kt(int a)
{
   int cnt = 0;
   while(a > 0){
      a /= 10;
      ++cnt;
   }
   return (cnt & 1);
}

int giaithua(int n)
{
   int res = 1;
   for(int i = 1; i <= n; ++i) res *= i;
   return res;
}

void sub2(const vector<string> &a)
{
   int tong[2] = {0, 0};
   int fl = 0;
   for(int i = 0; i < a.size(); ++i)
      for(int j = 0; j < a[i].size(); ++j) tong[fl] += (a[i][j] - '0'), fl = !fl;

   if((tong[0] - tong[1] + 11) % 11 == 0) cout << giaithua(a.size()) << '\n';
   else cout << 0 << '\n';
}

int main()
{
   freopen("gift11.inp","r",stdin);
   freopen("gift11.out","w",stdout);

   int chan = 0, le = 0;
   int tc;
   cin >> tc;
   int res = 0;
   for(int q = 1; q <= tc; ++q){
      int n;
      cin >> n;
      for(int i = 0; i < n; ++i){
         string s; cin >> s;
         a[q].push_back(s);
         if(s.size() % 2 == 1) ++le;
         else ++chan;
      }
      res += n;
   }

   if(chan == res){
      for(int q = 1; q <= tc; ++q) sub2(a[q]);
   }
   if(res <= 9){
      for(int q = 1; q <= tc; ++q){
         cnt1 = 0;
         memset(mark, 0, sizeof mark);
         ql(0, a[q]);
         cout << cnt1 << '\n';
      }
   }
   return 0;
}
