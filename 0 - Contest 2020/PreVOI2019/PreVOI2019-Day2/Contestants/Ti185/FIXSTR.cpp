///Bankai: Getsuga Tenshou
#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
ll n,m,x,y,kq;
char kt;
string s,xet,mangs[1000006];
stack<int> st,sts;
bool kttf(string ss)
{
    int vt;
    while(!st.empty()) st.pop();
    for(int i=0;i<ss.size();i++)
    {
        vt=i;
        if(ss[i]=='(') st.push(i);
        if(ss[i]==')')
        {
            if(!st.empty()) st.pop();
            else break;
        }
    }
    if(!st.empty() || vt<ss.size()-1) return false;
    else if((vt==ss.size()-1) && st.empty()) return true;
}
int sua(string ss)
{
    int vt;
    ll res=0;
    while(!sts.empty()) sts.pop();
    for(int i=0;i<ss.size();i++)
    {
        vt=i;
        if(ss[i]=='(') sts.push(i);
        if(ss[i]==')')
        {
            if(!sts.empty()) sts.pop();
            else res++;
        }
    }
    if(!sts.empty()) res+=sts.size();
    else if(vt<ss.size()-1) res+=ss.size()-vt+1;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    cin>>s>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>kt;
        if(kt=='C')
        {
            cin>>x;
            if(s[x-1]=='(') s[x-1]=')';
            else s[x-1]='(';
            mangs[i]=s;
        }
        else if(kt=='Q')
        {
            cin>>x>>y;
            kq=1e6;
            xet.clear();
            xet=s.substr(x-1,y-x+1);
            if(kttf(xet)==true) kq=0;
            else kq=sua(xet);
            mangs[i]=s;
            cout<<kq<<'\n';
        }
        else
        {
            cin>>x;
            s=mangs[x-1].substr(0,mangs[x-1].size());
            mangs[i]=s;
        }

    }
    return 0;
}
