#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define maxN 5001
#define fi first
#define se second
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m;
string s[maxN];
char t;
int Solve(string &st, int &l, int &r)
{
    int tmp = 0;
    stack<int>stk;
    For(i,l,r)
    {
        if(st[i] == '(')stk.push(0);
        else
        {
            if(stk.empty())tmp++;
            else
                stk.pop();
        }
    }
    while(!stk.empty())
    {
        stk.pop();
        tmp++;
    }
    return tmp;
}
void Sub1()
{
    For(i,1,m)
    {
        s[i] = s[i - 1];
        cin>>t;
        if(t == 'C')
        {
            int x;
            cin>>x;
            if(s[i][x] == '(')s[i][x] = ')';
            else
                s[i][x] = '(';
        }
        else
        {
            if(t == 'U')
            {
                int k;
                cin>>k;
                s[i] = s[k - 1];
            }
            else
            {
                int u, v;
                cin>>u>>v;
                cout<<Solve(s[i], u, v)<<"\n";
            }
        }
    }
}
int main()
{
    freopen("fixstr.inp", "r", stdin);
    freopen("fixstr.out", "w", stdout);
    fast_read;
    cin>>s[0];
    cin>>m;
    s[0] = '?' + s[0];
    n = s[0].size();
    Sub1();
}
