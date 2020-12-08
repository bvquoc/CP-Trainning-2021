#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6+7;
pair <int,int> save[MAXN];
int m,n;
string s;
void Input()
{
    cin>>s>>m;
    char tes;
    for(int i=1; i<=m; i++)
    {
        cin>>tes;
        if(tes=='C')
        {
            cin>>save[i].first;
            save[i].second=-1;
            continue ;
        }
        if(tes=='Q')
        {
            cin>>save[i].first>>save[i].second;
            continue ;
        }
        cin>>save[i].first;
        save[i].second=-2;
    }
}
void Running(int pos)
{
    int fin=save[pos].first;
    for(int i=pos; i>=fin; i--)
    {
        if(save[i].second==-2)
        {
            fin=min(fin,save[i].first);
            continue ;
        }
        if(save[i].second==-1)
        {
            int po=save[i].first;
            if(s[po]==')')
                s[po]='(';
            else
                s[po]=')';
        }
    }
}
void sub1()
{
    stack <int> pq;
    s=" "+s;
    for(int i=1; i<=m; i++)
    {
        //cerr<<s<<'\n';
        if(save[i].second==-1)
        {
            int po=save[i].first;
            if(s[po]==')')
                s[po]='(';
            else
                s[po]=')';
            continue ;
        }
        if(save[i].second>0)
        {
            while(!pq.empty())
                pq.pop();
            for(int j=save[i].first; j<=save[i].second; j++)
            {
                if(s[j]=='(')
                    pq.push(0);
                else
                {
                    if(pq.empty())
                        pq.push(1);
                    else if(pq.top()==0)
                        pq.pop();
                }
            }
            cout<<(int)pq.size()<<'\n';
            continue ;
        }
        Running(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    Input();
    sub1();
    return 0;
}
