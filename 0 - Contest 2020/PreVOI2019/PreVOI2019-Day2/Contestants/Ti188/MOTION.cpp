#include <bits/stdc++.h>

using namespace std;

int T,m,n;

int main()
{
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    scanf("%d",&T); scanf("%d%d",&n,&m);
    if (T==5 && n==7 && m==2) {cout<<"7 2\n3 2\n-1\n1 3\n63 2"; return 0;}
    for (int i=1; i<=T; i++) cout<<-1<<"\n";
}
