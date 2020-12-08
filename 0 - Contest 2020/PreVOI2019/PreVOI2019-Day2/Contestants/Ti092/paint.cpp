#include <bits/stdc++.h>

using namespace std;
char dd[1000011];
vector<int> a[30];
int n,vt;
int main()
{
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    vt=1;
    for (int i=1;i<=n;i++)
    {
        int tt;cin>>tt;
        if (tt==1)
        {
            char c;
            cin>>c;
            a[c-'a'].push_back(vt);vt++;
        }
        else
        {
            char x,y;
            cin>>x>>y;
            for (int j=0;j<a[x-'a'].size();j++)
                a[y-'a'].push_back(a[x-'a'][j]);
            a[x-'a'].clear();
        }
    }
    for (int i=0;i<26;i++)
    {
        for (int j=0;j<a[i].size();j++) dd[a[i][j]]=char(i+'a');
    }
    for (int i=1;i<vt;i++) cout<<dd[i];
}
