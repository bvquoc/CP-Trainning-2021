#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define add push
#define renew(f,x) memset(f,x,sizeof(f))
using namespace std;
string s[100010];
string S;
int m;
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
}
void inp()
{
    cin>>S;
//    S=" "+S;
    s[0]=S;
}
int check(int i, int j)
{
    int res=0;
    int dem=0;
    string tk=S.substr(i,j-i+1);
    for(int i=0;i<tk.size();i++)
    {
        if(tk[i]==')')
        {
            dem--;
        }
        else
            dem++;
        if(dem<0) {res++;dem++;}
    }
    if(dem>0) res+=dem;
    return res;
}
void proc()
{
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        char kind;
        cin>>kind;
        if(kind=='C')
        {
            int x;
            cin>>x;
            x--;
            string A=S.substr(0,x);
            string B=S.substr(x,1);
            string C=S.substr(x+1,S.size()-x);
            if(B=="(")
                B=")";
            else
                B="(";
            S=A+B+C;
        }
        if(kind=='Q')
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            cout<<check(x,y)<<"\n";
        }
        if(kind=='U')
        {
            int x;
            cin>>x;
            S=s[x-1];
        }
        s[i]=S;
    }
}
int main()
{
    io();
    inp();
    proc();
    return 0;
}
