#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<char,char>
using namespace std;
const int N=1e6+1,N1=1e4+1;
vector<int> cl[30];
vector<pii> change[N];
int n;
char mau[N],ht[N];
void trau()
{
    int cur=0;
    forinc(i,1,n)
    {
        int tp; cin>>tp;
        if(tp==1)
        {
            ++cur;
            char a;
            cin>>a;
            cl[a-'a'].push_back(cur);
            mau[cur]=a;
        }
        else
        {
            char a,b;
            cin>>a>>b;
            for(int j:cl[a-'a'])
            {
                cl[b-'a'].push_back(j);
                mau[j]=b;
            }
            cl[a-'a'].clear();
        }
    }
    forinc(i,1,cur) cout<<mau[i];
    exit(0);
}
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    if(n<N1) trau();
    int cur=0;
    forinc(i,1,n)
    {
        int type; cin>>type;
        if(type==1)
        {
            char color;
            cin>>color;
            ++cur;
            mau[cur]=color;
            ht[color-'a']=color;
        }
        else
        {
            char a,b;
            cin>>a>>b;
            change[cur].push_back({a,b});
        }
    }
    fordec(i,cur,1)
    {
        int sz=change[i].size();
        if(sz>0) for(int j=sz-1;j>=0;--j)
        {
            char a=change[i][j].first;
            char b=change[i][j].second;
            ht[a-'a']=ht[b-'a'];
        }
        mau[i]=ht[mau[i]-'a'];
    }
    forinc(i,1,cur) cout<<mau[i];
}
