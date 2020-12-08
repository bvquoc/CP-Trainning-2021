#include <bits/stdc++.h>

using namespace std;
int n;
string s="";
vector<int>f[26];
void sub1()
{
    while(n--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            char x;
            cin>>x;
            s+=x;
            f[x-'a'].push_back(s.size()-1);
        }
        else
        {
            char x,y;
            cin>>x>>y;
            for(auto vt:f[x-'a'])
            {
                f[y-'a'].push_back(vt);
                s[vt]=y;
            }
            f[x-'a'].clear();
        }
    }
    cout<<s;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>n;
    sub1();
    return 0;
}
