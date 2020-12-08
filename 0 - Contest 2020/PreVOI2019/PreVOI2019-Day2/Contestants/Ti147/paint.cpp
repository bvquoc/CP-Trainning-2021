#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
const int maxn=1000010;

int a[maxn];
int n;
int rt[maxn],des[maxn];
int c[100];
int root(int u)
{
    if (rt[u]==0) return u;
    else return  root(rt[u]);
}
void unite(int aa,int bb)
{
    int rt1=root(aa),rt2=root(bb);
    if (rt1!=rt2)
    {
        if (des[rt1]>des[rt2])
        {
            des[rt1]+=des[rt2];
            rt[rt2]=rt1;
        }
        else
        {
            des[rt2]+=des[rt1];
            rt[rt1]=rt2;
        }
    }
}

void solve()
{
    cin>>n;
    int pos=1;
    int tv;
    char col,r;
    _for(i,1,n+1) des[i]=1;
    _for(i,0,n)
    {
        cin>>tv;
        if (tv==1)
        {
            cin>>col;
            if (c[col - 'a'+1]==0)
                c[col - 'a'+1]=pos;
            else
                {
                    unite(root(c[col - 'a'+1]),pos);
                    c[col - 'a'+1]=root(c[col - 'a'+1]);
                }
            ++pos;
        }
        else
        {
            cin>>r>>col;
            if (c[r - 'a'+1]!=0 && r!=col)
            {
                if (c[col - 'a'+1]==0)
                {
                    c[col - 'a'+1]=c[r - 'a'+1];
                    c[r - 'a'+1]=0;
                }
                  else {
                    int rt1=root(c[r - 'a'+1]),rt2=root(c[col - 'a'+1]);
                    if (rt1!=rt2)
                            unite(rt1,rt2);
                    c[col - 'a'+1]=root(c[col - 'a'+1]);
                    c[r - 'a'+1]=0;
                   }
            }
        }
    }
    _for(i,1,27)
    {
        a[c[i]]=i;
    }
    _for(i,1,pos)
    {
        if (a[i]==0) a[i]=a[root(i)];
        cout<<char(a[i]+'a'-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
    solve();
}
