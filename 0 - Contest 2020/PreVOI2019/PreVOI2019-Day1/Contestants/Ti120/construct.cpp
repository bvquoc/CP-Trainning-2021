#include <bits/stdc++.h>
#define maxn 100009
#define ll long long
#define hqm "construct"

using namespace std;

int Cin(){
    int x=0;
    char c=getchar();
    while(c<'0' || c>'9')c=getchar();
    while(c>='0' && c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
ll t[maxn][3],b[maxn];
int n,m,a[maxn];
void add(int x, ll gt,int y){
    for(;x<=n; x+=x&-x)t[x][y]+=gt;
}

ll get(int x, int y){
    ll res=0;
    for(;x;x-=x&-x)res+=t[x][y];
    return res;
}

void xuli(){
    n=Cin();
    m=Cin();
    for(int i=1; i<=n; ++i)a[i]=Cin(),t[i][0]=t[i][1]=0;
    for(int i=1; i<=n; ++i){
        b[i]=a[i]-a[i-1];
        add(i,b[i],1);
        if(b[i]>0){
            add(i,b[i],0);
        }
    }
    while(m--){
        int loai,x,y,z;
        loai=Cin();
        x=Cin();
        y=Cin();
        if(loai==1){
            z=Cin();
            if(b[x]>0)add(x,-b[x],0);
            b[x]+=z;add(x,z,1);
            if(b[x]>0)add(x,b[x],0);
            if(y+1<=n){
                x=y+1;
                if(b[x]>0)add(x,-b[x],0);
                b[x]-=z;add(x,-z,1);
                if(b[x]>0)add(x,b[x],0);
            }
        }
        else{
            //cout << get(x,1) <<' '<< get(y,0) <<' '<< get(x,0) <<endl;
            cout << get(x,1)+get(y,0)-get(x,0)<<'\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(hqm".inp", "r", stdin);
    freopen(hqm".out", "w", stdout);
    int t=Cin();
    while(t--)xuli();
    return 0;
}
