#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    int n,c,d=0;
    string s;
    char x,y;
    cin>>n;

    for (int i=1;i<=n;i++)
    {
        cin>>c;
            if (c==1){cin>>x;s+=x;d++;}
            if (c==2){cin>>x>>y;if (x!=y){for(int j=d;j>=1;j--)if (s[j]==x)s[j]=y;}}
    }
    cout<<s;
    return 0;
}
