#include <bits/stdc++.h>

#define maxn 100000
using namespace std;

int n, i;
long long d[maxn], a[maxn];
long long l = 0, h = 0;

int check(long long K)
{
  long long c = 0;
  int i;
  for (i = 0; i < n - 1; ++i)
  {
    long long x = a[i] + c;
    if(x < K)
        c = x - K - (d[i + 1] - d[i]);
    else
    {
      c = x - K - (d[i + 1] - d[i]);
      if (c < 0) c = 0;
    }
  }
  return (a[n - 1] + c) >= K;
}
void Enter()
{
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> d[i] >> a[i];
        if (h < a[i]) h = a[i];
    }

}
void Solve()
{
    while(l <= h)
    {
    long long mid = (l + h)/2;
    if (check(mid)) l = mid + 1;
    else
      h = mid - 1;
    }
   cout << h;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("RICE.INP","r", stdin);
  freopen("RICE.OUT", "w", stdout);
  Enter();
  Solve();

}
