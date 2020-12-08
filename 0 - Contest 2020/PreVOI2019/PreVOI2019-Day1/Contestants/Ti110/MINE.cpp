#include<bits/stdc++.h>
#define MOD 1000003
using namespace std;
int N, M, A[400005];
int x[25], d[25], ans=0, s[25];
void xuli()
{
    int id=0, sn=0;
    for(int i=1; i<=2*N; i++) {
        if(x[i]==1) {
            d[++id]=A[i];
            s[++sn]=id;
        }
        else {
            if(A[i]-d[s[sn]]>M||sn==0) return ;
            --sn;
        }
    }
    if(id!=N) return ;
    ans++;
}
void thu(int k)
{
    if(k>2*N) {xuli(); return ;}
    for(int i=0; i<=1; i++) {
        x[k]=i;
        thu(k+1);
    }
}
void sub1()
{
    thu(1);
    printf("%d", ans%MOD);
}
int f[205][205];
void sub2()
{
    for(int i=2; i<=2*N; i++)
        if(A[i]-A[1]<=M) f[1][i]++;
        else break;
    for(int i=2; i<=N; i++) {
        for(int j=2*N; j>i; j--) {
            for(int k=i; k<=min(2*i-1, j-1); k++)
                if(A[j]-A[k]<=M) f[i][j]=(f[i][j]+f[i-1][j+1])%MOD;
                else break;
        }
    }
    for(int i=N+1; i<=2*N; i++) ans=(ans+f[N][i])%MOD;
    printf("%d", ans);
}
void sub3()
{
    sub1();
}
void sub4()
{
    sub1();
}
void sub5()
{
    sub1();
}
int main ()
{
    freopen("MINE.inp", "r", stdin);
    freopen("MINE.out", "w", stdout);
    scanf("%d%d", &N, &M);
    for(int i=1; i<=2*N; i++) scanf("%d", &A[i]);
    if(N<=10) {sub1(); return 0;}
    if(N<=200&&M==1000000) {sub2(); return 0;}
    if(N<=200) {sub3(); return 0;}
    if(N<=2000) {sub4(); return 0;}
    sub5();
}
