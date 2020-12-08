///EmperorD: @npd.28
#include <bits/stdc++.h>
#define EmperorD "construct"
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
int T;
int n,m;
int a[1009];
int b[1009];
bool check[1009];
int type;
void type2()
{
    int l,r;
    l=get();
    r=get();
    for (int i=l; i<=r; i++)
        b[i]=a[i];
    int k=r-l+1;
    int i=l;
    int res=0;
    int j;
    while (k>0 && i<=r)
    {
        while (check[i]==1)
            i++;
        if (i>r) break;
        for (int t=i; t<=r; t++)
            if (check[t]==0)
                j=t;
            else
                break;
        for (int t=i; t<=j; t++)
            if (b[t]>0)
        {
            b[t]--;
            if (b[t]==0)
            {
                check[t]=1;
                k--;
            }
        }
        res++;
    }
    cout <<res<<el;
}
void input()
{
    T=get();
    while (T--)
    {
        reset(a,0);
        n=get();
        m=get();
        for(int i=1; i<=n; i++)
            a[i]=get();
        while(m--)
        {
            type=get();
            if (type==1)
            {
                int l,r,k;
                l=get();
                r=get();
                k=get();
                for (int i=l; i<=r; i++)
                    a[i]+=k;
            }
            else
            {
                reset(check,0);
                type2();
            }
        }
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
