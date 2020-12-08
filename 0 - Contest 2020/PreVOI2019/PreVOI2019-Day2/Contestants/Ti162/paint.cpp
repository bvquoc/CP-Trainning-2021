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
int n ;
string s ;
vector <int> vt[30];
void inp()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("paint.inp","r",stdin) ;
    freopen("paint.out","w",stdout);
    cin>>n ;
}
void sub()
{
    fr(i,1,n)
    {
        int u ;
        cin>>u ;
        char v1,v2;
        if (u==1)
        {
            cin>>v1;
            s+=v1 ;
            vt[v1-'a'].pb((int)s.size()-1);
        }
        else
        {
            cin>>v1>>v2 ;
            if (vt[v1-'a'].size()!=0)
                fr(i,0,vt[v1-'a'].size()-1)
            {
                s[vt[v1-'a'][i]]=v2;
                vt[v2-'a'].pb(vt[v1-'a'][i]) ;
            }
            vt[v1-'a'].clear();
        }
    }
    cout<<s ;
}
int main()
{
    inp() ;
    sub() ;
}
