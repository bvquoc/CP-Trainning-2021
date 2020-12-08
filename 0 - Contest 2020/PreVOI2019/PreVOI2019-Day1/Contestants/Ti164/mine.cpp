#include<bits/stdc++.h>

#define foru(i,d,c) for(int i=d;i<=c;++i)
#define ford(i,c,d) for(int i=c;i>=d;--i)
#define fi first
#define se second
#define ii pair<int,int>
#define pb push_back
void Read(int &res) {
    res=0; bool am=false;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-') c = getchar();
    if (c=='-') {am = true;c = getchar();}
    while(c>='0' && c<='9'){res = res * 10 + c - 48;c = getchar();}
    if(am) res = -res;
}
typedef long long ll;
const int oo = 1e9 + 5;
const ll mod = 1e6 + 3;
const int maxN = 100005;
using namespace std;

int n,m;
int mo = 0, dong = 0;
int x[maxN];
int a[maxN];
int res = 0;
int f[405][205][205];


void Check(){
    stack<int> s;
    foru(i,1,2*n)
        if(x[i] == 0)
            s.push(i);
        else{
            int k = s.top();
            s.pop();
            if(a[i] - a[k] > m) return;
        }
    ++res;
}


void Try(int i){
    x[i] = 0;
    ++mo;
    if(mo <= n)
        if(i == 2*n) Check();
        else Try(i+1);
    --mo;

    x[i] = 1;
    ++dong;
    if(dong <= min(mo,n))
        if(i == 2*n) Check();
        else Try(i+1);
    --dong;
}

void sub1(){
    Try(1);
    cout << res;
}

int calc(int i, int j, int k){

    if(f[i][j][k] != -1) return f[i][j][k];

    if(k > j) return 0;
    if(k + j != i) return 0;
    if(i == 1) return 1;

    return f[i][j][k] = ( calc(i-1,j-1,k) + calc(i-1,j,k-1) )  % mod;
}

void sub2(){
    foru(i,0,n*2)
        foru(j,0,n)
            foru(k,0,n)
                f[i][j][k] = -1;
    cout << calc(2*n,n,n) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    #define name "mine."
    freopen(name"inp","r",stdin);
    freopen(name"out","w",stdout);
    #endif

    cin >> n >> m;
    foru(i,1,n*2)
        cin >> a[i];

    if(n <= 10) sub1();
    else
        sub2();



    return 0;
}


































