#include <bits/stdc++.h>
#define oo 1e9+7
using namespace std;

char a[505],b[505],c[505];
int a1,b1,c1;
int f[505][505][505];
int pre[505][505][505];
char s[1005];
int sn=0;
int id[5][5][5];
int e1[15],e2[15],e3[15];
int ok=0;

void sub1()
{
    if(a[1]==c[1]||b[1]==c[1])
    {
        printf("TRETRAU");
        return;
    }

    if(a[1]==b[1])
        putchar('1');
    else
        putchar('2');

    putchar('\n');

    putchar(a[1]);
    if(a[1]!=b[1])
    putchar(b[1]);
}

void sub2()
{
    for(int i=0;i<=1;++i)
    for(int j=0;j<=1;++j)
    for(int z=0;z<=1;++z)
    id[i][j][z]=++ok,
    e1[ok]=i,e2[ok]=j,e3[ok]=z;

    for(int i=0;i<=a1;++i)
    for(int j=0;j<=b1;++j)
    for(int z=0;z<=c1;++z)
    f[i][j][z]=oo;

    f[0][0][0]=0;

    for(int i=0;i<=a1;++i)
    for(int j=0;j<=b1;++j)
    for(int z=0;z<=c1;++z)
    if(f[i][j][z]!=oo)
    {
        int i1,j1,z1;

        if(i<a1)
        {
            i1=i+1;

            if(j<b1&&a[i1]==b[j+1])
            j1=j+1;
            else
            j1=j;

            if(z<c1&&a[i1]==c[z+1])
            z1=z+1;
            else
            z1=z;

            if(f[i1][j1][z1]>f[i][j][z]+1)
            f[i1][j1][z1]=f[i][j][z]+1,pre[i1][j1][z1]=id[i1-i][j1-j][z1-z];
        }

        if(j<b1)
        {
            if(i<a1&&a[i+1]==b[j+1])
            i1=i+1;
            else
            i1=i;

            j1=j+1;

            if(z<c1&&b[j+1]==c[z+1])
            z1=z+1;
            else
            z1=z;

            if(f[i1][j1][z1]>f[i][j][z]+1)
            f[i1][j1][z1]=f[i][j][z]+1,pre[i1][j1][z1]=id[i1-i][j1-j][z1-z];
        }
    }

    int ans=oo;
    int vt;

    for(int z=0;z<c1;++z)
    if(ans>f[a1][b1][z])
        ans=f[a1][b1][z],vt=z;

    if(ans==oo)
        printf("TRETRAU");
    else
    {
        printf("%d\n",ans);

        int i1=a1;
        int j1=b1;
        int z1=vt;

        while(i1>0||j1>0||z1>0)
        {
            char k;

            int x=pre[i1][j1][z1];

            if(e1[x]==1)
                s[++sn]=a[i1];
            else
                s[++sn]=b[j1];

            i1-=e1[x];
            j1-=e2[x];
            z1-=e3[x];
        }

        for(int i=sn;i>=1;--i)
        putchar(s[i]);
    }
}

int main ()
{
    freopen("XCKLT.inp","r",stdin);
    freopen("XCKLT.out","w",stdout);

    scanf("%s ",a+1);
    scanf("%s ",b+1);
    scanf("%s ",c+1);

    a1=strlen(a+1);
    b1=strlen(b+1);
    c1=strlen(c+1);

    if(a1==1&&b1==1&&c1==1)
        sub1();
    else
        sub2();
}
