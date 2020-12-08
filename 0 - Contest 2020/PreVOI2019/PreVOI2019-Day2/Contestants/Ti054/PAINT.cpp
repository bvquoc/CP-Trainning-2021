#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=1e6;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int n,m,dad[N+5],col[N+5];
vector<int> q[30];
int getdad(int u) {if (dad[u]==u) return u; return dad[u]=getdad(dad[u]);}
void join(int x, int y)
{
    int px=getdad(x), qy=getdad(y);
    if (px==qy) return;
    dad[px]=qy;
    col[px]=col[qy];
    return;
}
int main()
{
	freopen("PAINT.inp","r",stdin);
	freopen("PAINT.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int type,vt,vt1,vt2;
	char c1,c2;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("\n");
        scanf("%d",&type);
        if (type==1)
        {
            c1=getchar(); c1=getchar();
            m++;
            dad[m]=m;
            vt=c1-'a';
            if (!q[vt].empty()) join(m,q[vt].back());
            col[m]=vt;
            q[vt].push_back(m);
        } else
        {
            c1=getchar(); c1=getchar(); c2=getchar(); c2=getchar();
            vt1=c1-'a'; vt2=c2-'a';
            if (vt1==vt2) continue;
            if (q[vt1].empty()) continue;
            if (!q[vt2].empty()) join(q[vt1][0],q[vt2].back()); else col[getdad(q[vt1][0])]=vt2;
            q[vt2].push_back(q[vt1][0]);
            q[vt1].clear();
        }
    }
    for (int i=1;i<=m;i++) putchar(char(col[getdad(i)]+'a'));
	return 0;
}
