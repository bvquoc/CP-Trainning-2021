#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=150000;
const int oo=2e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

vector<int> q={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int get(int k)
{
    int tmp=0;
    for (int i=q.size()-1;i>=0;i--)
    {
        tmp+=k/q[i];
        k%=q[i];
    }
    if (k) return oo;
    return tmp;
}
int f[N+5];
int main()
{
	freopen("oddcoin.inp","r",stdin);
	freopen("oddcoin.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int nq;
	int x,t,res,g;
    cin>>nq;
    while (nq--)
    {
        cin>>x>>t;
        g=trunc(sqrt(t));
        res=oo;
        if (x>g)
        {
            for (int j=0;j<=t/x;j++) res=min(res,j+get(t-x*j));
            cout<<res<<'\n';
        } else
        {
            for (int i=1;i<=N;i++)
            {
                f[i]=oo;
                for (int j=0;j<15;j++) if (q[j]<=i) f[i]=min(f[i],f[i-q[j]]+1); else break;
                if (x<=i) f[i]=min(f[i],f[i-x]+1);
            }
            if (t<=N) cout<<f[t]<<'\n'; else
            {
                for (int i=1;i<=N;i++) res=min(res,f[i]*(t/i)+f[t%i]);
                cout<<res<<'\n';
            }
        }
    }
	return 0;
}
