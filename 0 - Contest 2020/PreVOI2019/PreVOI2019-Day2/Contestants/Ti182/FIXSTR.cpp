#include <bits/stdc++.h>
using namespace std;


void sub1(string tg,int m)
{
    vector<string> s(m+1);
    s[0]=tg;
    for(int i=1;i<=m;++i)
    {
        char w; cin>>w;
        if(w=='C')
        {
            int pos; cin>>pos;
            s[i]=s[i-1];
            if(s[i][pos-1]=='(') s[i][pos-1]=')';
            else s[i][pos-1]='(';
        }
        else if(w=='U')
        {
            int pos; cin>>pos;
            s[i]=s[pos-1];
        }
        else
        {
            s[i]=s[i-1];
            int x,y,tt=0,kq=0;
            cin>>x>>y;
            for(int j=x-1;j<y;++j)
            {
                if(s[i][j]==')') if(tt==0) kq++; else --tt;
                else tt++;
            }
            kq+=tt;
            cout<<kq<<endl;
        }
    }
}
void sub2(string s,long m)
{
    for(int i=1;i<=m;++i)
    {
        char w; cin>>w;
        if(w=='C')
        {
            int pos; cin>>pos;
            if(s[pos-1]=='(') s[pos-1]=')';
            else s[pos-1]='(';
        }
        else
        {
            int x,y,tt=0,kq=0;
            cin>>x>>y;
            for(int j=x-1;j<y;++j)
            {
                if(s[j]==')') if(tt==0) kq++; else --tt;
                else tt++;
            }
            kq+=tt;
            cout<<kq<<endl;
        }
    }
}
int main()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    string tg; long m;
    getline(cin,tg);
    cin>>m;
    if(m<=1000) sub1(tg,m);
    else
        sub2(tg,m);
    return 0;
}
