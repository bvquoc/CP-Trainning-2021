#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=x;i<y;i++)
#define frd(i,x,y) for(int i=y;i>=x;i--)
#define ii pair<int,int>
#define in freopen("fixstr.inp","r",stdin)
#define out freopen("fixstr.out","w",stdout)
#define fi first
#define se second
#define add push_back
#define ad push
#define ll long long
using namespace std;
long long n,m,j,u,v,dem1,ans;
string tv;
string s,kp[1000001];

void solve1()
{
    for(int i=1; i<=m; i++)
    {
        cin>>tv;
        if(tv=="C")
        {
            cin>>j;
            if(s[j]=='(')
            {
                s[j]=')';
            }
            else
                s[j]='(';
        }
        if(tv=="Q")
        {
            cin>>u>>v;
            ans=0;
            dem1=0;
            for(int j=u; j<=v; j++)
            {
                if(s[j]=='(')
                    dem1++;
                else
                {
                    if(dem1==0)
                    {
                        dem1++;
                        ans++;
                    }
                    dem1--;
                }
            }
            cout<<ans+dem1<<endl;
        }
        if(tv=="U")
        {
            cin>>j;
            s=kp[j-1];
        }
        kp[i]=s;
    }
}

int main()
{
    in;
    out;
    cin>>s;
    s=" "+s;
    cin>>m;
    solve1();
    return 0;
}
