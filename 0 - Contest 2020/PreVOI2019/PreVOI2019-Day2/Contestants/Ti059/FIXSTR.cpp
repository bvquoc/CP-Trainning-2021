#include <bits/stdc++.h>

using namespace std;
string s;
string p[1000001];
int y[1000001];
int m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    cin >> s;
    cin >> m;
    for(int i=1;i<=m;i++)
    {
        char x;
        int z;
        cin >> x;
        if(x=='C')
        {
            cin >> y[i];
            if(s[y[i]-1]=='(') s[y[i]-1]=')';
                else s[y[i]-1]='(';
            p[i]=s;
        }
        if(x=='Q')
        {
            p[i]=s;
            cin >> y[i] >> z;
            int sl=0;
            int j=y[i]-1;
            while(s[j]==')' && j<s.length())
            {
                sl++;
                j++;
            }
            for(int k=j;k<z;k++)
                if(s[k]=='(') sl++;
                    else sl--;
            cout << abs(sl) << endl;
        }
        if(x=='U')
        {
            cin >> y[i];
            s=p[y[i]-1];
        }
    }
    return 0;
}
