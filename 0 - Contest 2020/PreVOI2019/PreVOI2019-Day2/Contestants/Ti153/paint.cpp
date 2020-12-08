///HELLO EVERYONE! TODAY I FEEL SO GOOD :)
#include <bits/stdc++.h>
using namespace std;
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Task "paint"
#define maxn 1000005
#define MOD 1000000007
#define pii pair<int, int>
#define endl "\n"
int n,dd[30],co[maxn],cur=1,root[maxn];
int getroot(int u)
{
    return root[u] ? root[u]=getroot(root[u]) : u;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Task".inp", "r", stdin);
    //freopen(Task".out", "w", stdout);
    cin >> n;
    while(n--)
    {
        int type,x,y;
        string a,b;
        cin >> type;
        if(type==1)
        {
            cin >> a;
            x=a[0]-'a' + 1;
            if(!dd[x])
            {
                dd[x]=cur;
            }
            else root[cur]=dd[x];
            cur++;
        }
        else
        {
            cin >> a;
            cin >> b;
            x=a[0]-'a' + 1;
            y=b[0]-'a' + 1;
            if(x==y || !dd[x]) continue;
            if(!dd[y])
            {
                dd[y]=dd[x];
                dd[x]=0;
            }
            else
            {
                if(dd[y] < dd[x])
                {
                    root[dd[x]]=dd[y];
                    dd[x]=0;
                }
                else
                {
                    root[dd[y]]=dd[x];
                    dd[y]=dd[x];
                    dd[x]=0;
                }
            }
        }
    }
    for(int i=1; i<=26; ++i)
      co[dd[i]]=i;
    for(int i=1; i<cur; ++i)
    {
        int p=getroot(i);
        cout<<char(co[p]+96);
    }
}
