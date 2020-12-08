#define taskname "MINE"
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int maxn=2e5+2;
int n, m, a[maxn*2], ans=0, b[maxn*2], mod=1e9+3, dp[202][202];


void Prepare()
{
    dp[1][1]=1;
    for(int i=2; i<=200; i++)
        for(int j=1; j<=i; j++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            dp[i][j-1]=(dp[i][j-1]+dp[i-1][j])%mod;
        }
}


void Enter()
{
    cin>>n>>m;
    for(int i=1; i<=2*n; i++)
        cin>>a[i];
    if(m==1e9)
    {
        ans=0;
        int dem=0;
        for(int i=1; i<=n*2; i++)
        {
            if(i%2==1)
                dem++;
            else
            {
                ans=(ans+dp[2*n-i][dem+1])%mod;
                dem--;
            }
        }
        cout<<ans+1;
    }
    else
    {
        for(int i=1; i<(1<<(2*n)); i++)
        {
            int dem=0;
            for(int j=0; j<2*n; j++)
            {
                b[j+1]=0;
                if((i>>j&1)==1)
                {
                    dem++;
                    b[j+1]=1;
                }
            }
            if(dem!=n)
                continue;
            bool kt=true;
            vector<int> v;
            for(int j=1; j<=2*n; j++)
            {
                if(b[j]==1)
                    v.push_back(j);
                else
                {
                    if(v.size()==0)
                    {
                        kt=false;
                        break;
                    }
                    else
                    {
                        if(a[j]-a[v.back()]>m)
                        {
                            kt=false;
                            break;
                        }
                        v.pop_back();
                    }
                }
            }
            if(kt&&v.size()==0)
                ans++;
        }
        cout<<ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    Prepare();
    Enter();
}
