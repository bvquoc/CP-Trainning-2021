#define taskname "fixstr"
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+100;
string s;
int n;
string t[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    cin>>s;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        t[i]=s;
        char q;
        cin>>q;
        if (q=='C')
        {
            int x;
            cin>>x;
            if (s[x-1]=='(') s[x-1]=')';
            else s[x-1]='(';
        }
        else if (q=='Q')
        {
            int x,y;
            cin>>x>>y;
            int sum=0, res=0;
            for(int i=x-1; i<=y-1; i++)
            {
                if (s[i]=='(') sum++;
                else
                {
                    if (sum==0) res++;
                    else sum--;
                }
            }
            res+=sum;
            cout<<res<<'\n';
        }
        else if (q=='U')
        {
            int x;
            cin>>x;
            s=t[x];
        }
    }
}
