///GIFT11
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;
const int T = 10;
const int N = 2003;
const int mod = 998244353;
int NumT, NumN, f[N];
string s[N];
inline void Mod(int &x)
{
    ++x;
    if(x >= mod) x -= mod;
}

void sub1()
{
    int cnt = 0;
    int id[N];
    for(int i = 1; i <= NumN; ++i) id[i] = i;
    do
    {
        string x;
        x = s[id[1]];
        for(int i = 2; i <= NumN; ++i)
            x = x + s[id[i]];
        int a = x[0] - '0';
        for(int i = 1; i < x.size(); ++i) a = a*10 + (x[i] - '0');
        if(a % 11 == 0) Mod(cnt);
    }while(next_permutation(id + 1, id + 1 + NumN) );
    printf("%d\n",cnt);
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    scanf("%d",&NumT);
    f[1] = 1;
    for(int i = 2; i <= N; ++i)
    {
        f[i] = f[i-1] * i;
        if(f[i] >= mod) f[i] -= mod;
    }
    while(NumT--)
    {
        scanf("%d",&NumN);
        for(int i = 1; i <= NumN; ++i)
            cin >> s[i];
        if(NumN <= 8)
            sub1();
        else printf("%d\n",f[NumN]);
    }
    return 0;
}
