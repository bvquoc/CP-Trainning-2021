#include <bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+5;
int f[600][600],l[600][600],n,r,k,top=0,sum=0;
struct pack{int x,y;}b[nmax],cx[600];
bool cmp(pack &A, pack &B) {return ((A.x<B.x && A.y<B.y) || (A.x==B.x && A.y<B.y));}
vector<int> pnt;

int check(int x, int y) {
    int res=-1;
    pnt.clear();
    for(int i=1;i<=top;++i) {
        if(x==cx[i].x && y==cx[i].y) {
            res=n*(cx[i].x-1)+cx[i].y;
            pnt.push_back(res);
        }
        if(x<cx[i].x || y<cx[i].y) {
            res=n*(cx[i].x-1)+cx[i].y;
            pnt.push_back(res);
        }
    }
    return res;
}

void init() {
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            l[i][j]=f[i][j]-f[i-1][n]+l[i-1][j];
        }
    }
}

void case1(pack v1, int i, int x, int y) {
    int S1=(l[x][y]-l[b[i].x-1][y]-l[x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    int S2=(l[v1.x][v1.y]-l[b[i].x-1][v1.y]-l[v1.x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    sum+=(S1-S2);
}

void case2(pack v1, pack v2, int i, int x, int y) {
    int S1=(l[x][y]-l[b[i].x-1][y]-l[x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    int S2=(l[v1.x][v1.y]-l[b[i].x-1][v1.y]-l[v1.x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    int S3=(l[v2.x][v2.y]-l[b[i].x-1][v2.y]-l[v2.x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    int S4=(l[v2.x][v1.y]-l[b[i].x-1][v1.y]-l[v2.x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    sum+=(S1-S2-S3+S4);
}

void case4(pack v1,  int i, int x, int y) {
    int xtr=v1.x-r;
    int ytr=v1.y-r;
    xtr=max(xtr,b[i].x);
    ytr=max(ytr,b[i].y);
    v1.y=y;
    int S1=(l[x][y]-l[b[i].x-1][y]-l[x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
    int S2=(l[v1.x][v1.y]-l[xtr-1][v1.y]-l[v1.x][ytr-1]+l[xtr-1][ytr-1]);
    sum+=(S1-S2);
}

void solve() {
    --r;
    for(int i=1;i<=k;++i) {
        int x0=check(b[i].x,b[i].y);
        int x=b[i].x+r;
        int y=b[i].y+r;
        if(x0==-1) {
            sum+=(l[x][y]-l[b[i].x-1][y]-l[x][b[i].y-1]+l[b[i].x-1][b[i].y-1]);
        }
        else {
            pack v1,v2;
            int TH=1;
            v1.x=x0/n;
            v1.y=x0%n;
            if(v1.y==0) v1.y=n;
            else ++v1.x;
            for(int j=pnt.size()-1;j>=0;--j) {
                v2.x=pnt[j]/n;
                v2.y=pnt[j]%n;
                if(v2.y==0) v2.y=n;
                else ++v2.x;
                if(v2.y>v1.y && v2.y<=y) {
                    TH=2;
                    break;
                }
                if(v2.y>y && v2.y!=v1.y) {
                    v2.y=y;
                    TH=3;
                    break;
                }
            }
            if(TH==1 && v1.y>y) TH=4;
            if(TH==1)   case1(v1,i,x,y);
            if(TH==2 || TH==3) case2(v1,v2,i,x,y);
            if(TH==4)   case4(v1,i,x,y);
        }
        cx[++top].x=x;
        cx[top].y=y;
    }
    printf("%lld", sum);
}

int32_t main() {
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    scanf("%lld%lld%lld", &n, &r, &k);
    int x=0;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            int x0;
            scanf("%lld", &x0);
            f[i][j]=x+x0;
            x=f[i][j];
        }
    }
    for(int i=1;i<=k;++i)   scanf("%lld%lld", &b[i].x, &b[i].y);
    sort(b+1,b+1+k,cmp);
    init();
    solve();
    return 0;
}
