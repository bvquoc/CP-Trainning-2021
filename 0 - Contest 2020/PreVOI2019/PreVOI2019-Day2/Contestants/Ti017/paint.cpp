#include<bits/stdc++.h>
using namespace std;
const int mn=1e6+5;
int n,sl;
vector<int> g[33];
char a[mn];
void lam()
{
    for(int i=1;i<=n;i++)
    {
        int tv;
        cin>>tv;
        if(tv==1)
        {
            char c;
            cin>>c;
            a[++sl]=c;
            g[c-'0'].push_back(sl);
        }
        else
        {
            char c,b;
            cin>>b>>c;
            for(int v:g[b-'0'])
            {
                a[v]=c;
                g[c-'0'].push_back(v);
            }
            g[b-'0'].clear();
        }
    }
    for(int i=1;i<=sl;i++)cout<<a[i];
}
char f[33][mn];

int join(int x,int i,char aa)
{
    if(f[x][i]!=a[0]&&f[x][i]!=aa&&f[x][i]!=x+'a')
    {
        f[x][i]=aa;
        return f[x][i]-'a';
    }
    f[x][i]=aa;
    return x;
}
int jo(int x,int i,char aa)
{
    if(f[x][i]!=a[0]&&f[x][i]!=aa&&f[x][i]!=x+'a')
    {
        f[x][i]=jo(f[x][i]-'a',i,aa)+'a';
        return f[x][i]-'a';
    }
    f[x][i]=x+'a';
    return x;
}
char x[mn],y[mn];
void Do()
{
    for(int i=1;i<=n;i++)
    {
        int tv;
        cin>>tv;
        if(tv==1)
        {
            char c;
            cin>>c;
            a[++sl]=c;
        }
        else
        {
            char c,b;
            cin>>b>>c;
            f[b-'a'][sl]=c;
            join(c-'a',sl,c);
        }
    }
    for(int i=sl-1;i>=1;i--)
    {
        for(int j='a';j<='z';j++)if(f[j-'a'][i+1]!=a[0])f[j-'a'][i]=f[j-'a'][i+1];
    }
    for(int i=1;i<=sl;i++)
    cout<<f[jo(a[i]-'a',i,a[i])][i];
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>n;
    if(n<=10000){lam();return 0;}
    Do();
    return 0;
}
