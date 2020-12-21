#include <bits/stdc++.h>

using namespace std;
long long n,res=0; long long MOD=1000000007;
vector<long long> a,b;
long long sub_task_1()
{
    if(a.empty())  return res;
  vector<long long>::iterator it;
    it=max_element(a.begin(),a.end());
    int pos=it-a.begin();
    res+=(a.size()-(pos+1))%MOD;
    res%=MOD;
    a.erase(it);
    sub_task_1();
}
int main()
{
 freopen("PERMEOW.INP","r",stdin);
 freopen("PERMEOW.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
      {
          int x; cin>>x; a.push_back(x);
      }
    for(int i=1; i<=n; i++)
      {
          int x; cin>>x; b.push_back(x);
      }
   sub_task_1();

return 0;
}
