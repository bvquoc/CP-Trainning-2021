#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mse(x) memset((x),0,sizeof(x))
#define sfo(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);++(i))
#define bfo(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);--(i))
#define oo 1000000007
#define mod(x) if(x>oo) x-=oo
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,char> pic;
typedef pair<ii,int> iii;
typedef map<ii,int> miii;
// IT
const int N=(int)1e6+5;
int n,m;
char a[N];
pic quer[N];

void opf()
{
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void sub1()
{
    char type;
    int p,u,v;
    sfo(i,1,m)
    {
        cin>>type;
        if(type=='C')
        {
            cin>>p;
            quer[i]=pic(p,a[p]);
            if(a[p]=='(')
                a[p]==')';
            else a[p]='(';
        }
        else if(type=='U')
        {
            cin>>p;
            a[quer[p].fi]=quer[p].se;
        }
        else
        {
            cin>>u>>v;
            stack<char> S;
            sfo(j,u,v)
            {
                if(S.size()&&S.top()=='(' && a[j]==')')
                    S.pop();
                else S.push(a[j]);
            }
            cout<<S.size()<<'\n';
        }
    }
}

int main()
{
    opf();
    string read;
    cin>>read;  n=read.size();
    sfo(i,1,read.size()) a[i]=read[i-1];
    cin>>m;
    sub1();
    return 0;
}
