///EmperorD: @npd.28
#include <bits/stdc++.h>
#define EmperorD "FIXSTR"
#define ll long long
#define ull unsigned long long
#define el '\n'
#define fi first
#define se second
#define pll pair<long long, long long>
#define pii pair<int,int>
#define piii pair<int,pii>
#define mp make_pair
#define pb push_back
#define forinc(i,a,b) for(int i=a;i<=b;i++)
#define fordec(i,a,b) for(int i=a;i>=b;i--)
#define forv(a,b) for(auto &a:b)
#define reset(f,x) memset(f,x,sizeof(f))
#define mod 10000007
using namespace std;
const int oo=1e9+7;

int get()
{
    int tmp = 0;
    char x = getchar();
    bool Neg = false;
    while(x == ' ' || x == '\n')
        x = getchar();
    if(x == '-')
        Neg = true, x = getchar();
    while('0' <= x && x <= '9')
        tmp = tmp * 10 + (x - '0'), x = getchar();
    if(Neg)
        return -tmp;
    return tmp;
}
string s;
string tempS;
int m;
string history[1000009];
int f[10009][10009];
void input()
{
    cin >>s;
    s=" "+s;
    cin >>m;
    int N=s.length()+3;
    char type;
    int x,y,k;
    history[1]=s;
    int his=1;
    while (m--)
    {
        cin >>type;
        if (type=='C')
        {
            cin >>x;
            if (s[x]=='(')
                s[x]=')';
                       else if (s[x]=')')
                           s[x]='(';
                else if (s[x]='{')
                    s[x]='}';
                else
                    s[x]='{';
        }
        else if (type=='Q')
        {
            for (int i=0; i<=N; i++)
                for (int j=0; j<=N; j++) f[i][j]=0;
                    cin >>x>>y;
            int n=y-x+1;
            for (int i=y; i>=x; i--)
                for (int j=i; j<=y; j++)
                {
                    if (i==j)
                        f[i][j]=1;
                    else
                    {
                        f[i][j]=n;
                        if (s[i]=='(' || s[i]=='{')
                            f[i][j]=min(f[i][j],f[i+1][j]+1);
                        if (s[j]==')' || s[i]=='}')
                            f[i][j]=min(f[i][j],f[i][j-1]+1);
                        if (s[i]=='(' && s[j]==')')
                            f[i][j]=min(f[i][j],f[i+1][j-1]);
                        if (s[i]=='{' && s[j]=='}')
                            f[i][j]=min(f[i][j],f[i+1][j-1]);

                        for (int k=i; k<j; k++)
                            if (f[i][k]+f[k+1][j]<=f[i][j])
                            {
                                f[i][j]=f[i][k]+f[k+1][j];
                            }
                    }
                }
            cout <<f[x][y]<<el;
        }
        else if (type=='U')
        {
            cin >>k;
            s=history[k];
        }
        history[++his]=s;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen (EmperorD".inp","r",stdin);
    freopen (EmperorD".out","w",stdout);
    input();
    return 0;
}
