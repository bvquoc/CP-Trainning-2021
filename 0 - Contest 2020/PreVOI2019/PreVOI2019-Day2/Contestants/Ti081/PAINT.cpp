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
#define maxn 1000001
using namespace std;
int n, cnt;
stack<int> c[50];
char res[maxn];

void online_judge()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
}

void solve()
{
    cin>>n;
    char x, y; int q, u, v;
    cnt = 0;
    upfor(i,1,n)
    {
        cin>>q;
        if(q == 1)
        {
            cin>>x;
            cnt++;
            res[cnt] = x;
            u = x - 'a' + 1;
            c[u].push(cnt);
        }
        if(q == 2)
        {
            cin>>x>>y;
            if(x != y)
            {
                u = x - 'a' + 1;
                v = y - 'a' + 1;
                while(!c[u].empty())
                {
                    int w = c[u].top();
                    c[u].pop();
                    res[w] = y;
                    c[v].push(w);
                }
            }
        }
    }
    upfor(i,1,cnt) cout<<res[i];
}

int main()
{
    fastread
    online_judge();
    solve();
    return 0;
}
