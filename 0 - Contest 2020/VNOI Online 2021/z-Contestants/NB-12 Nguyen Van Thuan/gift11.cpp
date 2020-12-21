#include <bits/stdc++.h>
#define maxn 100005
#define ft first
#define sc second
using namespace std;
typedef pair<int,int> ii;
vector<int> g;
const int base=998244353;
ii b[maxn];
int a[maxn],T,n,c[maxn];
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        long long sl=0;
        g.clear();
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            string s;
            stringstream u;
            u << a[i];
            u >> s;
            int tle=0;
            int tchan=0;
            for(int j=0; j<s.length(); j++ )
            {
                int x;
                stringstream u1;
                u1<<s[j];
                u1 >> x;
                if (j%2==0) tle+=x;
                else tchan+=x;
            }
            b[i].ft=tle;
            b[i].sc=tchan;
            if(s.length()%2==0) c[i]=0;
            else c[i]=1;
            g.push_back(i);
        }
        do
        {
            int  cs=0;
            int tongchan=0;
            int tongle=0;
            bool ok;
            for(auto x:g)
            {
                ++cs;
                if(cs==1)
                {
                    tongchan+=b[x].sc;
                    tongle+=b[x].ft;
                    if(c[x]==1) ok=true;
                    else ok=false;
                }
                if(cs>=2)
                {
                    if(ok==true)
                    {
                        tongle+=b[x].sc;
                        tongchan+=b[x].ft;
                        if(c[x]==0) ok=true;
                        else ok=false;
                    }
                    else
                    {
                        tongle+=b[x].ft;
                        tongchan+=b[x].sc;
                        if(c[x]==1) ok=true;
                        else ok=false;
                    }
                }
            }
            if(abs(tongchan-tongle)%11==0)++sl;
            if(sl>base) sl=sl-base;
        }
        while(next_permutation(g.begin(),g.end()));
   printf("%d\n",sl);
    }
}
