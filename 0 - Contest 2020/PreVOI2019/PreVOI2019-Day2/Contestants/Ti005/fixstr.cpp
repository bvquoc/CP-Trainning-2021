#include <bits/stdc++.h>
#define nmax 1000042
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define task "fixstr"

using namespace std;
const int MOD=1e9+7;

string s,res[nmax];
int m;

char dao(char c)
{
    char res;
    if(c=='(')
        res=')';
    else
        res='(';
    return res;
}

void xl1(int u,int v)
{
    int cnt(0),dem(0);
    for(int i=u; i<=v; i++)
    {
        if(s[i]=='(')
            dem++;
        else
            dem--;
        if(dem<0)
            cnt=abs(dem),dem=0;
    }
    cout<<cnt+dem<<"\n";
}

void sub1()
{
    for(int i=1; i<=m; i++)
    {
        char c;
        int u,v;
        cin>>c>>u;
        if(c=='C')
        {
            s[u]=dao(s[u]);
            res[i]=s;
        }
        else if(c=='Q')
        {
            cin>>v;
            res[i]=s;
            xl1(u,v);
        }
        else
            s=res[u-1],res[i]=s;
    }
}


void sub2()
{
     for(int i=1; i<=m; i++)
    {
        char c;
        int u,v;
        cin>>c>>u;
        if(c=='C')
        {
            s[u]=dao(s[u]);
            res[i]=s;
        }
        else if(c=='Q')
        {
            cin>>v;
            res[i]=s;
            xl1(u,v);
        }
        else
            s=res[u-1],res[i]=s;
    }
}

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>s>>m;
    int n=s.length();
    s=" "+s;
    res[0]=s;
    if(m<=1e4 && n<=1e4)
        sub1();
    else sub2();

    return 0;
}
