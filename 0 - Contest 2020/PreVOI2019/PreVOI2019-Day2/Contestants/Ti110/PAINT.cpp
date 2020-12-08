#include<bits/stdc++.h>
using namespace std;
int N;
char s[1000005];
void sub1()
{
    int type;
    char c, d;
    int sl=0;
    for(int i=1; i<=N; i++) {
        scanf("%d", &type);
        if(type==1) {
            scanf(" %c ", &c);
            s[++sl]=c;
        }
        else {
            scanf(" %c %c ", &c, &d);
            for(int i=1; i<=sl; i++) if(s[i]==c) s[i]=d;
        }
    }
    for(int i=1; i<=sl; i++) printf("%c", s[i]);
}
char q[30][1000005];
int dd[30];
int nho[30][1000005], dd1[35][1000005];
char Solve(int c, int id)
{
    int u=lower_bound(nho[c]+1, nho[c]+dd[c]+1, id)-nho[c];
    if(dd1[c][u]) return q[c][u];
    if(u<1||u>dd[c]) return c+'a';
    if(u>=1&&u<=dd[c]) {
        dd1[c][u]=1;
        q[c][u]=Solve(q[c][u]-'a', nho[c][u]);
    }
    return q[c][u];
}
void sub2()
{
    int sl=0, type;
    char c, d;
    for(int i=1; i<=N; i++) {
        scanf("%d", &type);
        if(type==1) {
            scanf(" %c ", &c);
            s[++sl]=c;
        }
        else {
            scanf(" %c %c ", &c, &d);
            nho[c-'a'][++dd[c-'a']]=sl;
            q[c-'a'][dd[c-'a']]=d;
        }
    }
    for(int i=1; i<=sl; i++) {
        printf("%c", Solve(s[i]-'a', i));
    }
}
int main ()
{
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    scanf("%d", &N);
    if(N<=10000) {sub1(); return 0;}
    sub2();
}
