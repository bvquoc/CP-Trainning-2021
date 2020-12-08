#include<bits/stdc++.h>

#define file "fixstr"
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 1000006

using namespace std;
string s;
int m, n, a[maxn], t[maxn*4], mt[maxn*4], b[1003][1003];
struct query
{
    char t;
    int a, b;
}q[maxn];
void sub1()
{
    f1 (i, n) b[0][i]=a[i];
    //f1 (i, n) cout << a[i] << ' '; el;
    f1 (i, m)
    {
        //f1 (j, n) if (a[j]==1) cout << '('; else cout << ')'; el;
        if (q[i].t=='C') a[q[i].a]=-a[q[i].a];
        if (q[i].t=='Q')
        {
            int mi=1e6, ma=0, ans=0;
            int s=0;
            for (int j=q[i].a; j<=q[i].b; j++)
                s+=a[j], mi=min(mi, s);
            s=0;
            for (int j=q[i].b; j>=q[i].a; j--)
                s+=a[j], ma=max(ma, s);
            //cout << mi << ' ' << ma << ' ';
            cout << max(ma, 0)-min(mi, 0); el;
        }
        if (q[i].t=='U') f1 (j, n) a[j]=b[q[i].a-1][j];
        f1 (j, n) b[i][j]=a[j];
    }
    //f1 (i, m) {f1 (j, n) if (b[i][j]==1) cout << '('; else cout << ')' ;el;}
}
void init(int id, int l, int r)
{
    if (l==r)
    {
        t[id]=a[l];
        mt[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    init(id*2, l, mid);
    init(id*2+1, mid+1, r);
    t[id]=t[id*2]+t[id*2+1];
    mt[id]=min(t[id], min(mt[id*2], mt[id*2+1]));
    //cout << l << ' ' << r << ' ' << t[id] << '\n';
}
int get(int id, int l, int r, int u, int v, int type)
{
    //cout << l << ' ' << r << ' ' << mt[id]; el;
    if (u>r||v<l)
    {
        if (type) return 1e9;
        return 0;
    }
    if (u<=l&&r<=v)
    {
        if (type) return mt[id];
        return t[id];
    }
    int mid=(l+r)>>1;
    int t1=get(id*2, l, mid, u, v, 0);
    int t2=get(id*2+1, mid+1, r, u, v, 0);
    //if (type) return min(t1+t2, min(t1, t2));
    if (type) return min(mt[id*2], mt[id*2+1]);
    return t1+t2;
}
void up(int id, int l, int r, int pos)
{
    if (pos < l||pos > r) return;
    if (l==r)
    {
        a[l]=-a[l];
        t[id]=a[l];
        mt[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    up(id*2, l, mid, pos);
    up(id*2+1, mid+1, r, pos);
    t[id]=t[id*2]+t[id*2+1];
    mt[id]=min(t[id], min(t[id*2], t[id*2+1]));
}
void sub2()
{
    init(1, 1, n);
    f1 (i, m)
    {
        if (q[i].t=='C') up(1,1,n,q[i].a);
        if (q[i].t=='Q')
        {
            int mi=1e6, ma=0, ans=0;
            int s=0;
            for (int j=q[i].a; j<=q[i].b; j++)
                s+=a[j], mi=min(mi, s);
            s=0;
            for (int j=q[i].b; j>=q[i].a; j--)
                s+=a[j], ma=max(ma, s);
            //cout << mi << ' ' << ma << ' ';
            cout << max(ma, 0)-min(mi, 0); el;
        }
    }
}
void sub3()
{

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> s >> m;
    n=s.length();
    s=' '+s;
    f1 (i, n) if (s[i]=='(') a[i]=1; else a[i]=-1;
    bool s1=1;
    f1 (i, m)
    {
        cin >> q[i].t >> q[i].a;
        if (q[i].t=='Q') cin >> q[i].b;
        if (q[i].t=='U') s1=0;
    }
    sub1();
    return 0;
}
