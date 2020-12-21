#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#define int long long
using namespace std;
const int inf=1e9;
const int nax=2005;
const int M=998244353;
int t,n;
vector<int>v1,v2;
int dp1[nax][nax][11],p[nax],dp2[nax][nax][11],c[nax][nax];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    p[0]=1;
    for(int i=1;i<nax;i++)
    {
        p[i]=p[i-1]*i;
        p[i]%=M;
    }
    c[0][0]=1;
    for(int n=1;n<nax;n++)
    {
        for(int k=0;k<=n;k++)
        {
            if(k-1>=0)c[k][n]=c[k-1][n-1]+c[k][n-1];else c[k][n]=c[k][n-1];
            c[k][n]%=M;
        }
    }
    cin>>t;
    while(t)
    {
        t--;
        v1.clear();
        v2.clear();
        v1.push_back(0);
        v2.push_back(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int b;
            cin>>b;
            int tmp=0,st=1;
            stack<int>s;
            while(b)
            {
                s.push(b%10);
                b/=10;
            }
            while(!s.empty())
            {
                tmp+=s.top()*st;
                s.pop();
                st*=-1;
            }
            if(st==1)v2.push_back(tmp);else v1.push_back(tmp);
        }
        int sz=v1.size()/2;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<=sz;j++)
            {
                for(int z=0;z<11;z++)
                {
                    dp1[i][j][z]=0;
                }
            }
        }
        dp1[0][0][0]=1;
        for(int i=0;i+1<v1.size();i++)
        {
            for(int j=0;j<=sz;j++)
            {
                for(int r=0;r<11;r++)
                {
                    int cur=dp1[i][j][r];
                    dp1[i+1][j][(r+v1[i+1])%11]+=cur;
                    dp1[i+1][j][(r+v1[i+1])%11]%=M;;
                    dp1[i+1][j+1][((r-v1[i+1])%11+11)%11]+=cur;
                    dp1[i+1][j+1][((r-v1[i+1])%11+11)%11]%=M;
                }
            }
        }
        for(int i=0;i<v2.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                for(int z=0;z<11;z++)
                {
                    dp2[i][j][z]=0;
                }
            }
        }
        for(int i=0;i<11;i++)
        {
            dp2[0][0][i]=dp1[v1.size()-1][sz][i]*p[sz]%M*p[v1.size()-1-sz]%M;
        }
        int sz2=v1.size()-sz;
        for(int i=0;i+1<v2.size();i++)
        {
            for(int j=0;j<v2.size();j++)
            {
                for(int r=0;r<11;r++)
                {
                    int cur=dp2[i][j][r];
                    dp2[i+1][j][(r+v2[i+1])%11]+=cur;
                    dp2[i+1][j][(r+v2[i+1])%11]%=M;;
                    dp2[i+1][j+1][((r-v2[i+1])%11+11)%11]+=cur;
                    dp2[i+1][j+1][((r-v2[i+1])%11+11)%11]%=M;
                }
            }
        }
        int ans=0;
        for(int i=0;i<v2.size();i++)
        {
            int j=v2.size()-1-i;
            ans+=dp2[v2.size()-1][i][0]*c[i][max(sz+i-1,0ll)]%M*p[i]%M*c[j][max(sz2+j-1,0ll)]%M*p[j]%M;
        }
        cout<<ans<<endl;
    }
    return 0;
}
