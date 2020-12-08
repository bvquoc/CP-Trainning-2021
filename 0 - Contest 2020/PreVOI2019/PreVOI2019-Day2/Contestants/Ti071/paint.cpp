#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define add push
#define renew(f,x) memset(f,x,sizeof(f))
using namespace std;
int n;
char x[1000100];
queue<int> A[10001];
int tg;
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("paint.inp","r",stdin);
    freopen("paint.out","w",stdout);
}
void inp()
{
    cin>>n;
}
void proc()
{
    tg=0;
    for(int i=1; i<=n; i++)
    {
        int kind;
        cin>>kind;
        if(kind==1)
        {
            tg++;
            char x;
            cin>>x;
            A[x].push(tg);
        }
        else
        {
            char x,y;
            cin>>x>>y;
            while(!A[x].empty())
            {
                int B=A[x].front();
                A[x].pop();
                A[y].push(B);
            }
        }
    }
    for(char i ='a'; i<='z'; i++)
    {
        while(!A[i].empty())
        {
            int B=A[i].front();
            A[i].pop();
            x[B]=i;
        }
    }
    for(int i=1;i<=tg;i++)
    {
        cout<<x[i];
    }
}
int main()
{
    io();
    inp();
    proc();
    return 0;
}
