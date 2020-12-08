#define taskname "paint"
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+100;
int n;
int lab[N],t[N];
char res[N];
int cnt;

int root(int x)
{
    return lab[x]<0? x:lab[x]=root(lab[x]);
}

void union1(int s, int r, int g)
{
    if (lab[s]<lab[r]) swap(s,r);
    lab[r]+=lab[s];
    lab[s]=r;
    t[g]=r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    cin>>n;
    memset(lab,-1,sizeof(lab));
    for(int i=1; i<=n; i++)
    {
        int q;
        cin>>q;
        if (q==1)
        {
            char x;
            cin>>x;
            cnt++;
            if (t[x-'a']==0) t[x-'a']=cnt;
            else union1(t[x-'a'],cnt,x-'a');
        }
        else
        {
            char x,y;
            cin>>x>>y;
            union1(t[x-'a'],t[y-'a'],y-'a');
            t[x-'a']=0;
        }
    }
    for(int i='a'; i<='z'; i++)
        res[t[i-'a']]=char(i);
    for(int i=1; i<=cnt; i++)
        cout<<res[root(i)];
}
