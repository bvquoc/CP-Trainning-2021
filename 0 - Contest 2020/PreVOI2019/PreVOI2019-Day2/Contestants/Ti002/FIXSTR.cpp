#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[1000006];
char ll[1005][1005];

void sub1()
{
    for(int i=1; i<=n; ++i)
        ll[0][i]=s[i];

    for(int i=1; i<=m; ++i)
    {
        char loai;
        int a,b;

        scanf("%c ",&loai);

        for(int j=1; j<=n; ++j)
            ll[i][j]=ll[i-1][j];

        if(loai=='C')
        {
            scanf("%d ",&a);

            if(ll[i][a]=='(')
                ll[i][a]=')';
            else
                ll[i][a]='(';
        }
        else if(loai=='Q')
        {
            scanf("%d %d ",&a,&b);

            int x=0;
            int ans=0;

            for(int j=a; j<=b; ++j)
            {
                if(ll[i][j]==')')
                    x--;
                else
                    x++;

                if(x<0)
                    x=0,ans++;
            }

            ans+=x;

            printf("%d\n",ans);
        }
        else
        {
            scanf("%d ",&a);

            for(int j=1; j<=n; ++j)
                ll[i][j]=ll[a-1][j];
        }
    }
}

void sub2()
{
    sub1();
}

int main ()
{
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);

    scanf("%s",s+1);

    n=strlen(s+1);

    scanf("%d ",&m);

    if(n<=1000&&m<=1000)
        sub1();
    else
        sub2();
}
