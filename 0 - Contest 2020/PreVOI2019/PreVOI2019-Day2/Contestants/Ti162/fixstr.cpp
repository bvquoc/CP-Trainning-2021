#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <int,int>
#define pl pair <ll,ll>
#define fr(i,x,y) for (int i=x;i<=y;i++)
#define ft(i,x,y) for (int i=y;i>=x;i--)
#define N 100005
using namespace std ;
string s;
int n,m;
vector <string> k;
void inp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("fixstr.inp","r",stdin) ;
    freopen("fixstr.out","w",stdout);
    cin>>s;
    n = s.size();
    s=" "+s ;
    cin>>m ;
}
int xuli(int u,int v)
{
    string ans = s.substr(u,v-u+1);
    int res=0;
    int l=0 ;
    int dem = 0 ;
    while (ans[l]==')')
    {
        l++ ;
        res++ ;
    }
    int r = ans.size()-1;
    while(ans[r]=='(')
    {
        r-- ;
        res++ ;
    }
    fr(i,l,r)
    {
        if (ans[i]=='(') dem++ ;
        else
            dem-- ;
    }
    res+=abs(dem) ;
    return res ;
}
void sub()
{
    k.pb(s) ;
    fr(i,1,m)
    {
        char t;
        int u,v ;
        cin>>t ;
        if (t=='C')
        {
            cin>> u  ;
            if (s[u]=='(') s[u]=')' ;
            else s[u]='(' ;
        }
        if (t=='U')
        {
            cin>>u ;
            s = k[u-1];

        }
        k.pb(s);
        if (t=='Q')
        {
            cin>>u>>v;
            cout<<xuli(u,v)<<"\n";
        }
    }
}
int main()
{
    inp() ;
    sub() ;
}
