#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define pii pair<int,int>
#define dulieu pair<int,vector<int>>
using namespace std;
const int N=2e5+1,mod=1000003;
int n,m,a[N];
map<dulieu,int> dp;
int F(int i,vector<int> vt)
{
    if(i==2*n+1)
        return (vt.empty());
    if(dp.find({i,vt})!=dp.end()) return dp[{i,vt}];
    int tmp=0;
    vector<int> vt1=vt;
    vt1.push_back(i); // thoi diem vao
    tmp+=F(i+1,vt1);
    if(!vt.empty())
    {
        vt1=vt;
        int x=vt1.back();
        vt1.pop_back();
        if(a[i]-a[x]<=m)
            tmp+=F(i+1,vt1);
    }
    return dp[{i,vt}]=tmp%mod;
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    forinc(i,1,2*n) cin>>a[i];
    vector<int> kt;
    cout<<F(1,kt);
}
