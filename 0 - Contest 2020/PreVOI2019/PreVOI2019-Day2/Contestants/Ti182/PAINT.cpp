#include <bits/stdc++.h>
using namespace std;

long n;

void sub1()
{
    string s;
    for(long i=1;i<=n;++i)
    {
        int w; cin>>w;
        if(w==1)
        {
            char x; cin>>x;
            s.push_back(x);
        }
        else
        {
            char x,y; cin>>x>>y;
            for(long j=0;j<s.size();++j)
            {
                if(s[j]==x) s[j]=y;
            }
        }
    }
    cout<<s;
}
void sub2()
{
    vector<list<long> > vl(26);
    long pos=0;
    for(long i=1;i<=n;++i)
    {
        int w; cin>>w;
        if(w==1)
        {
            char x; cin>>x;
            vl[int(x-'a')].insert(vl[int(x-'a')].end(),pos);
            pos++;
        }
        else
        {
            char x,y; cin>>x>>y;
            vl[int(y-'a')].merge(vl[int(x-'a')]);
        }
    }
    vector<int> s(n);
    list<long>::iterator it;
    for(int i=0;i<26;++i)
    {
        for(it=vl[i].begin();it!=vl[i].end();++it)
        {
            s[*it]=i;
        }
    }
    for(long i=0;i<pos;++i)
    {
        cout<<char(s[i]+'a');
    }
}
int main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    if(n<=10000) sub1();
    else
        sub2();
    return 0;
}
