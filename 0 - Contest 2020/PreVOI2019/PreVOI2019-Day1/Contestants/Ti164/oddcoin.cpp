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
const ll mod = 1e9 + 7;
const int maxN = 100005;
using namespace std;

int n = 14;
int f[100005];
int g[100005];
int a[15] = {1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int q;
int x,t;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    #define name "oddcoin."
    freopen(name"inp","r",stdin);
    freopen(name"out","w",stdout);
    #endif

    foru(i,1,10005)
        f[i] = i;

    f[0] = 0;
    foru(i,1,14)
        foru(j,a[i],10005)
            f[j] = min(f[j], f[j-a[i]] + 1);

    cin >> q;
    while(q--){
        cin >> x >> t;
        if(t < x) {cout << f[t] <<"\n";continue;}
        if(t == x) {cout << 1 <<"\n";continue;}

        if(t >= 10000) {
            int tmp1 = oo,tmp2 = oo;
            ford(i,14,0)
                if(t % a[i] == 0){
                    tmp1 = t / a[i];
                    break;
                }
            if(t % x == 0)
                tmp2 = t / x;

            if(min(tmp1,tmp2) == oo){
                int MAX1,MAX2;
                int dem = 0;
                vector<int> tam;
                tam.pb(50000);
                tam.pb(10000);
                tam.pb(x);
                sort(tam.begin(), tam.end());
                dem += t / tam[2];
                t = t % tam[2];
                dem += t / tam[1];
                t = t % tam[1];
                dem += t / tam[0];
                t = t % tam[0];
                dem += f[t];
                cout << dem << "\n";
            }

            else
                cout << min(tmp1,tmp2) <<"\n";
            continue;
        }


        foru(i,1,t)
            g[i] = f[i];
        foru(i,x,t)
            g[i] = min(g[i], g[i-x] + 1);

        cout << g[t] <<"\n";
    }









    return 0;
}
















