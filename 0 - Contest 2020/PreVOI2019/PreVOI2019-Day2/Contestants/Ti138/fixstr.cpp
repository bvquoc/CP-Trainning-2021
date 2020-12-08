#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m,i,j,k;
string s,trc[maxn];
void sub1()
{
    for(int h=1;h<=m;h++)
    {
        char c;
        cin >> c;
        trc[h]=s;
        if(c=='C')
        {
            int i;
            cin >> i;
            if(s[i-1]=='(') s[i-1]=')';
            else s[i-1]='(';
        }
        else if(c=='Q')
        {
            int i,j;
            cin >> i >> j;
            int sl=0,ans=0;
            for(int k=i-1;k<=j-1;k++)
                if(s[k]=='(') sl++;
                else
                {
                    sl--;
                    if(sl<0) ans++,sl=0;
                }
            if(sl<0) ans++;
            else ans+=sl;
            cout << ans << '\n';
        }
        else
        {
            int k;
            cin >> k;
            s=trc[k];
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    cin >> s;
    cin >> m;
    sub1();

}

