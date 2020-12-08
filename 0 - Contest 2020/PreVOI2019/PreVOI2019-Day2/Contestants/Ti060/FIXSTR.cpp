#include <bits/stdc++.h>
const int N=1000005;
using namespace std;
int n,m;
string s;
int solve(int l,int r,string x)
{
    stack<int>st;
    int res=0;
    for(int i=l; i<=r; ++i)
    {
        if(!st.size())
        {
            st.push(i);
            continue;
        }
        if(x[i]==')'&&x[st.top()]=='(')
        {
            res+=2;
            st.pop();
        }
        else
            st.push(i);
    }
    return r-l+1-res;
}
void sub1()
{
    string a[m+1];
    a[0]=s;
    for(int i=1; i<=m; ++i)
    {
        char type;
        cin>>type;
        if(type=='U')
        {
            int pos;
            cin>>pos;
            a[i]=a[pos-1];
        }
        else
            a[i]=a[i-1];
        if(type=='C')
        {
            int pos;
            cin>>pos;
            a[i][pos]=(a[i][pos]==')')?'(':')';
        }
        if(type=='Q')
        {
            int l,r;
            cin>>l>>r;
            printf("%d\n",solve(l,r,a[i]));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s;
    cin>>m;
    sub1();
    return 0;
}
