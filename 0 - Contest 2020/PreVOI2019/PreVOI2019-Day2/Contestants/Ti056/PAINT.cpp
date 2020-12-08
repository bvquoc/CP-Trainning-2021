#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
int p[27],id[N],res[N],n;
set<int>now;

struct T
{
    int type;
    char x,y;
};
T q[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) now.insert(i);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>q[i].type>>q[i].x;
        if(q[i].type==2) cin>>q[i].y;
        if(q[i].type==1)
        {
            cnt++;
            int cur=*now.begin();
            id[i]=cur;
            now.erase(cur);
        }
    }
    for(int i=0;i<26;i++) p[i]=i;
    for(int i=n;i>=1;i--)
    {
        if(q[i].type==1) res[id[i]]=p[q[i].x-'a'];
        else p[q[i].x-'a']=p[q[i].y-'a'];
    }
    for(int i=1;i<=cnt;i++) cout<<char(res[i]+'a');
}

