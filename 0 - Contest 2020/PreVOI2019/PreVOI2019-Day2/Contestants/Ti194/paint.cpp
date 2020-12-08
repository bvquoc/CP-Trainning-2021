#include<bits/stdc++.h>

#define file "paint"
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 1000006
#define fi first
#define se second

using namespace std;
int n, a[maxn], top, nxt[300];
struct query
{
    int t;
    char a, b;
}q[maxn];
void sub1()
{
    f1 (i, n)
    {
        if (q[i].t==1) a[++top]=q[i].a;
        else
        {
            f1 (j, top)
                if (a[j]==q[i].a) a[j]=q[i].b;
        }
    }
    f1 (i, top) cout << (char) a[i];
}
void sub2()
{
    for (int i='a'; i<='z'; i++) nxt[i]=i;
    for (int i=n; i; i--)
    {
        if (q[i].t==1) a[++top]=nxt[q[i].a];
        else
        {
            nxt[q[i].a]=nxt[q[i].b];
        }
    }
    for (int i=top; i; i--) cout << (char) a[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n;
    f1 (i, n)
    {
        cin >> q[i].t >> q[i].a;
        if (q[i].t==2) cin >> q[i].b;
    }
    if (n<=10000) sub1();
    else sub2();
    return 0;
}
