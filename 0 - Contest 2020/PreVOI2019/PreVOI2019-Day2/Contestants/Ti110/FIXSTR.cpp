#include<bits/stdc++.h>
#define ft first
#define sc second
using namespace std;
typedef pair<int, int> II;
int M;
char s[1000005];
II d[1000005];
char q[1000005];
int c[1005][1005];
void sub1()
{
    int N=strlen(s+1);
    for(int i=1; i<=N; i++) c[i][0]=(s[i]=='(') ? 1 : -1;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) c[j][i]=c[j][i-1];
        if(q[i]=='C') {
            c[d[i].ft][i]=-c[d[i].ft][i];
        }
        if(q[i]=='Q') {
            int sum=0, ans=0;
            for(int j=d[i].ft; j<=d[i].sc; j++) {
                sum+=c[j][i];
                if(sum<0) ans++, sum=0;
            }
            printf("%d\n", ans+sum);
        }
        if(q[i]=='U') {
            for(int j=1; j<=N; j++) c[j][i]=c[j][d[i].ft-1];
        }
    }
}
int dt1[4000005], it1[4000005];
void update1(int r, int k, int l, int u, int v, int val)
{
    if(u>l||v<k) return ;
    if(u<=k&&l<=v) {
        dt1[r]+=val;
        return ;
    }
    int g=(k+l)/2;
    dt1[2*r]+=dt1[r];
    dt1[2*r+1]+=dt1[r];
    dt1[r]=0;
    update1(2*r, k, g, u, v, val);
    update1(2*r+1, g+1, l, u, v, val);
    it1[r]=it1[2*r]+dt1[r]*(k-g+1)+it1[2*r+1]+dt1[2*r+1]*(l-g);
}
int get1(int r, int k, int l, int u, int v)
{
    if(u>l||v<k) return 0;
    if(u<=k&&l<=v) return it1[r]+dt1[r]*(l-k+1);
    dt1[2*r]+=dt1[r];
    dt1[2*r+1]+=dt1[r];
    dt1[r]=0;
    int g=(k+l)/2;
    int t1=get1(2*r, k, g, u, v);
    int t2=get1(2*r+1, g+1, l, u, v);
    it1[r]=it1[2*r]+dt1[r]*(k-g+1)+it1[2*r+1]+dt1[2*r+1]*(l-g);
    return t1+t2;
}
int it2[4000005];
void update2(int r, int k, int l, int u, int v, int val)
{
    if(u>l||v<k) return ;
    if(k==l) {
        it2[r]+=val;
        return ;
    }
    int g=(k+l)/2;
    update2(2*r, k, g, u, v, val);
    update2(2*r+1, g+1, l, u, v, val);
    it2[r]=max(it2[2*r], it2[2*r+1]);
}
int get2(int r, int k, int l, int u, int v)
{
    if(u>l||v<k) return -1;
    if(u<=k&&l<=v) return it2[r];
    int g=(k+l)/2;
    int t1=get2(2*r, k, g, u, v);
    int t2=get2(2*r+1, g+1, l, u, v);
    it2[r]=max(it2[2*r], it2[2*r+1]);
    return max(t1, t2);
}
int op[1000005], en[1000005];
void sub2()
{
    int N=strlen(s+1);
    for(int i=1; i<=N; i++) {
        op[i]=op[i-1];
        if(s[i]=='(') op[i]++;
        en[i]=en[i-1];
        if(s[i]==')') en[i]++;
    }
    for(int i=1; i<=N; i++) {
        update1(1, 1, N, i, i, en[i]-op[i]);
        update2(1, 1, N, i, i, en[i]-op[i]);
    }
    for(int i=1; i<=M; i++) {
        if(q[i]=='C') {
            int id=d[i].ft;
            if(s[id]=='(') {
                s[id]=')';
                update1(1, 1, N, id, N, 2);
                update2(1, 1, N, id, N, 2);
            }
            else {
                s[id]='(';
                update1(1, 1, N, id, N, -2);
                update2(1, 1, N, id, N, -2);
            }
        }
        else {
            int L=d[i].ft, R=d[i].sc;
            int S=get1(1, 1, N, L-1, L-1);
            int u=get2(1, 1, N, L, R);
            int v=get1(1, 1, N, R, R);
            int ans=2*max(u-S, 0)-(v-S);
            printf("%d\n", ans);
        }
    }
}
void sub3()
{
    sub1();
}
int main ()
{
    freopen("FIXSTR.inp", "r", stdin);
    freopen("FIXSTR.out", "w", stdout);
    scanf("%s", s+1);
    int N=strlen(s+1);
    scanf("%d", &M);
    bool ok=true;
    for(int i=1; i<=M; i++) {
        scanf(" %c ", &q[i]);
        if(q[i]=='Q') {
            scanf("%d%d", &d[i].ft, &d[i].sc);
        }
        if(q[i]=='C') {
            scanf("%d", &d[i].ft);
        }
        if(q[i]=='U') {
            scanf("%d", &d[i].ft);
            ok=false;
        }
    }
    if(N<=1000&&M<=1000) {sub1(); return 0;}
    if(ok) {sub2(); return 0;}
    sub3();
}
