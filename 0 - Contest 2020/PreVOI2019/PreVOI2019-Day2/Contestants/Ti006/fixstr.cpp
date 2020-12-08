#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    string s,save[10009];
    save[1]=s;
    char c;
    int n,m,x,y,d=1,lui=0;
    cin>>s;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        lui++;
        cin>>c;

        if (c=='c'){cin>>x;if (s[x-1]==')')s[x-1]='(';else s[x-1]=')';d++;save[d]=s;}
        if (c=='u'){cin>>x;s=save[lui-x];}
        if (c=='q')
            {
                cin>>x>>y;
        int r=y,l=x,res=0;
        while (y-x>=1)
        {
            if ((s[x-1]=='(')&&(s[y-1]==')')){x++;y--;res+=2;}else
            {if ((s[x-1]=='(')&&(s[y-1]=='('))y--;else {if ((s[x-1]==')')&&(s[y-1]==')'))x++;
        else {if((s[x-1]==')')&&(s[y-1]=='(')){x++;y--;}}}}
        }
        cout<<(r-l+1)-res<<"\n";
    }
    }
    return 0;
}
