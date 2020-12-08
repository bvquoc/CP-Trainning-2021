#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define name "paint"
#define ll long long
#define maxn 1000006

using namespace std;

int n,a[maxn],fa[maxn],vt[30];
char cl[maxn];
bool xd[maxn];
queue<int> q;

int getfa(int x)
{
    if(fa[x]==0)
    {
        return x;
    }
    fa[x]=getfa(fa[x]);
    return fa[x];
}
void add(int x,int y)
{
    x=getfa(x);
    y=getfa(y);
    if(x==y)
    {
        return;
    }
    cl[x]=cl[y];
    fa[x]=y;
}

void sub1()
{
    f(i,1,n)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            char y;
            cin>>y;
            f(j,1,n)
            {
                if(xd[j]==0)
                {
                    xd[j]=1;
                    cl[j]=y;
                    break;
                }
            }
        }
        else
        {
            char y,z;
            cin>>y>>z;
            f(j,1,n)
            {
                if(xd[j]==0)
                {
                    break;
                }
                else if(cl[j]==y)
                {
                    cl[j]=z;
                }
            }
        }
    }
    f(i,1,n)
    {
        if(xd[i]==0)
        {
            break;
        }
        else
        {
            cout<<cl[i];
        }
    }
}
void sub2()
{
    f(i,1,n)
    {
        q.push(i);
        int x;
        cin>>x;
        if(x==1)
        {
            char y;
            cin>>y;
            int z=q.front();
            q.pop();
            xd[z]=1;
            if(vt[y-'a'+1]==0)
            {
                vt[y-'a'+1]=z;
                cl[z]=y;
            }
            else
            {
                add(z,vt[y-'a'+1]);
            }
        }
        else
        {
            char y,z;
            cin>>y>>z;
            int m1=vt[y-'a'+1];
            if(m1!=0)
            {
                int m2=vt[z-'a'+1];
                vt[y-'a'+1]=0;
                vt[z-'a'+1]=m1;
                if(m2==0)
                {
                    cl[m1]=z;
                }
                else
                {
                    add(m1,m2);
                }
            }
        }
    }
    f(i,1,n)
    {
        if(xd[i]==0)
        {
            return;
        }
        else
        {
            int x=getfa(i);
            cout<<cl[x];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>n;
    if(n<=10000)
    {
        sub1();
    }
    else
    {
        sub2();
    }

}
