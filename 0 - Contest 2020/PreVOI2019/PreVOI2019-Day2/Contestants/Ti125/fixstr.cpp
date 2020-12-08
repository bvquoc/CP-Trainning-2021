#include<bits/stdc++.h>
#define mn 1000006
using namespace std;
int n,m;
string s[mn];
struct tv{char c;int i,j;}a[mn];
//----------------------
int ok;
void nhap()
{
    cin>>s[0];
    n=s[0].size();
    s[0]=' '+s[0];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].c;
        if(a[i].c=='C')cin>>a[i].i;
        if(a[i].c=='Q')cin>>a[i].i>>a[i].j;
        if(a[i].c=='U'){cin>>a[i].i;ok=1;}
    }
}
char dao(char x)
{
    if(x=='(')return ')';
    else return '(';
}
void sub1()
{
    for(int i=1;i<=m;i++)
    {
        s[i]=s[i-1];
        if(a[i].c=='C')s[i][a[i].i]=dao(s[i][a[i].i]);
        if(a[i].c=='U')s[i]=s[a[i].i-1];
        if(a[i].c=='Q')
        {

            stack<char> st;
            for(int j=a[i].i;j<=a[i].j;j++)
            {
                if( st.empty()||(st.top()==')'&&s[i][j]=='(')||(st.top()==s[i][j]) )
                    st.push(s[i][j]);
                else
                    st.pop();
            }
            cout<<st.size()<<'\n';
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    nhap();
    sub1();
}
