#include<bits/stdc++.h>
#include<bits/stdc++.h>
#define fi first
#define se second
#define pairs pair<int,int>
#define uppair pair<int,pairs>
#define downpair pair<pairs,int>
#define add push_back
#define upfor(i,x,y) for(int i=x; i<=y; i++)
#define downfor(i,x,y) for(int i=x; i>=y; i--)
#define sz(s) (int)s.size()
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define maxm 200001
#define maxn 1000001
using namespace std;
string s;
int m;
string rsave[maxn];
void online_judge()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
}
void solve()
{
    cin>>s;
    s = " " + s;
    rsave[0] = s;
    char q;
    int u, v, cnt, ans;
    cin>>m;
    upfor(i,1,m)
    {
        cin>>q;
        if(q == 'C')
        {
            cin>>u;
            if(s[u] == '(') s[u] = ')';
            else s[u] = '(';
        }
        if(q == 'Q')
        {
            cin>>u>>v;
            cnt = 0, ans = 0;
            upfor(i,u,v)
            {
                if(s[i] == ')')
                {
                    cnt--;
                    if(cnt < 0)
                    {
                        ans++;
                        cnt++;
                    }
                }
                else cnt++;
            }
            if(cnt > 0) ans+=cnt;
            cout<<ans<<'\n';
        }
        if(q == 'U')
        {
            cin>>u;
            s = rsave[u-1];
        }
        rsave[i] = s;
    }
}

int main()
{
    fastread
    online_judge();
    solve();
    return 0;
}
