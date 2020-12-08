//--------HUNGPOGBA---------
#include <bits/stdc++.h>
#define  HUNGPOGBA "FIXSTR"
#define ii pair<int,int>
#define memset(f, a) memset(f, 0, sizeof(f))
#define forr(i, a, b) for(int i= a; i<= b; i++)
#define ford(i, a, b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define ll long long
#define pub push_back
#define pob pop_back
#define llu unsigned long long
#define mp make_pair
#define ld long double
#define sz(s) int(s.size())

using namespace std;
mt19937 Rand(time(0));

const int maxn=1e6+5;
const ll maxc=1e9+7;
string s ;
int m ;
vector<string> v ;
struct query
{
    char type ;
    int F,S ;
} q[maxn];
void inp()
{
    cin>>s >>m ;
    forr(i,1,m)
    {
        cin>>q[i].type ;
        if(q[i].type=='C' ||q[i].type=='U')
            cin>>q[i].F ;
        else cin>>q[i].F >>q[i].S ;
    }
}

void solve1()
{
    forr(i,1,m)
    {
        char type  ;
        type=q[i].type ;
        v.pub(s) ;
        if(type=='C')
        {
            int j=q[i].F ;
            --j ;
            if(s[j]==')')
                s[j]='(' ;
            else s[j]=')' ;
        }
        if(type=='U')
        {
            int k=q[i].F ;
            s=v[k-1] ;
        }
        if(type=='Q')
        {
            int l,r,ans=0 ;
            l=q[i].F,r=q[i].S ;
            stack<int> st ;
            forr(k,l,r)
            if(s[k-1]=='(') st.push(k) ;
            else
            {
                if(st.empty()) ++ans ;
                else st.pop() ;
            }
            cout<<ans+st.size()<<"\n" ;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(HUNGPOGBA".inp", "r", stdin);
    freopen(HUNGPOGBA".out", "w", stdout);
    inp() ;
   // if(int(s.size())*m<=1e6)
       solve1() ;
    return 0;
}
