#include <bits/stdc++.h>

using namespace std;
vector <int> m[27];
int q,t;
char x,y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    cin>>q;
    string s=" ";
    while (q--)
    {
        cin>>t;
        if (t==1)
        {
            cin>>x;
            s+=x;
            m[x-'a'+1].push_back(s.size()-1);
        }
        else
        {
            cin>>x>>y;
            for (int i=0;i<m[x-'a'+1].size();i++)
            {
                m[y-'a'+1].push_back(m[x-'a'+1][i]);
                s[m[x-'a'+1][i]]=y;
            }
            m[x-'a'+1].clear();
        }
    }
    for (int i=1;i<s.size();i++)
        cout<<s[i];
    return 0;
}
