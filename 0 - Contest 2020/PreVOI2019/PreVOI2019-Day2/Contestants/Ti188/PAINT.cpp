#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n,dem=0;
char a[maxn];
int dd[27][100005];

void xuly1()
{
    char s1; cin>>s1;
    a[++dem]=s1; dd[s1-'a'][0]++; dd[s1-'a'][dd[s1-'a'][0]]=dem;
    //cerr<<s1<<"\n";
}

void xuly2()
{
    char s1,s2; cin>>s1>>s2;
    //cerr<<s1<<" "<<s2<<" => "; for (int i=1; i<=dem; i++) cerr<<a[i]; cerr<<"\n";
    int m=dd[s1-'a'][0]; dd[s1-'a'][0]=0;
    for (int i=1; i<=m; i++)
    {
        a[dd[s1-'a'][i]]=s2; dd[s2-'a'][0]++;
        dd[s2-'a'][dd[s2-'a'][0]]=dd[s1-'a'][i];
    }
    //for (int i=1; i<=dem; i++) cerr<<a[i]; cerr<<"\n";
}

void xulytrau()
{
    for (int i=1; i<=n; i++)
    {
        int key; cin>>key;
        if (key==1)
        {
            char s1; cin>>s1;
            a[++dem]=s1;
        }
        if (key==2)
        {
            char s1,s2; cin>>s1>>s2;
            for (int j=1; j<=dem; j++)
                if (a[j]==s1) a[j]=s2;
        }
    }
    for (int i=1; i<=dem; i++) cout<<a[i];
}

int main()
{
    freopen("PAINT.inp","r",stdin);
    freopen("PAINT.out","w",stdout);
    scanf("%d",&n);
    if (n<=10000) {xulytrau(); return 0;}
    for (int i=1; i<=n; i++)
    {
        int key; cin>>key;
        if (key==1) xuly1(); else xuly2();
    }
    for (int i=1; i<=dem; i++) cout<<a[i];
}
