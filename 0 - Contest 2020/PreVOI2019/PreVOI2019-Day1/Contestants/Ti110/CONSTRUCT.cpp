#include<bits/stdc++.h>
using namespace std;
int N, M, A[100005];
int B[100005];
int const oo=1e9;
void sub1()
{
    int type, L, R, x;
    while(M--) {
        scanf("%d", &type);
        if(type==1) {
            scanf("%d%d%d", &L, &R, &x);
            for(int i=L; i<=R; i++) A[i]+=x;
        }
        else {
            int ans=0;
            scanf("%d%d", &L, &R);
            for(int i=L; i<=R; i++) B[i]=A[i];
            while(1) {
                int tmp=oo, pos=0, start=0;
                for(int i=L; i<=R; i++) {
                    if(B[i]&&!start) start=i;
                    if(B[i]!=0) tmp=min(B[i], tmp);
                    else if(tmp!=oo) {pos=i; break;}
                    if(i==R) pos=i+1;
                }
                if(tmp==oo) break;
                ans+=tmp;
                for(int i=start; i<pos; i++) B[i]-=tmp;
            }
            printf("%d\n", ans);
        }
    }
}
int main ()
{
    freopen("CONSTRUCT.inp", "r", stdin);
    freopen("CONSTRUCT.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++) scanf("%d", &A[i]);
        //for(int i=1; i<=N; i++) update(1, 1, N, i, i, A[i]);
        sub1();
    }
}
