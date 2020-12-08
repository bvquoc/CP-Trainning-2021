#include <bits/stdc++.h>
using namespace std;

int n;
int x=1;
char ans[1000006];
vector < int > tmp[30];
int id[30];
int res[1000006];

void sub1()
{
    for(int i=1; i<=n; ++i)
    {
        int loai;
        char a,b;
        scanf("%d ",&loai);

        if(loai==1)
        {
            scanf("%c ",&a);
            ans[x]=a;
            x++;
            tmp[a-'a'].push_back(x-1);
        }
        else
        {
            scanf("%c %c ",&a,&b);

            for(auto &v : tmp[a-'a'])
            {
                ans[v]=b;
                tmp[b-'a'].push_back(v);
            }

            tmp[a-'a'].clear();
        }
    }

    for(int i=1; i<x; ++i)
        printf("%c",ans[i]);
}

void sub2()
{
    int k=25;

    for(int i=0; i<=25; ++i)
        tmp[i].push_back(i),id[i]=i,ans[i]=i+'a';

    for(int i=1; i<=n; ++i)
    {
        int loai;
        char a,b;

        scanf("%d ",&loai);

        if(loai==1)
        {
            scanf("%c ",&a);
            res[x++]=id[a-'a'];
        }
        else
        {
            scanf("%c %c ",&a,&b);

            for(auto &v : tmp[a-'a'])
                tmp[b-'a'].push_back(v),ans[v]=b;

            tmp[a-'a'].clear();
            tmp[a-'a'].push_back(++k);
            ans[k]=a;
            id[a-'a']=k;
        }
    }

    for(int i=1; i<x; ++i)
        printf("%c",ans[res[i]]);
}

int main ()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);

    scanf("%d ",&n);

    if(n<=10000)
        sub1();
    else
        sub2();
}

