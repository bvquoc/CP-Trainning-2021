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
#define int long long

int t;
int n,m;
int a[maxN];
int h[maxN];

void sub1(){
    foru(i,1,n)
        cin >> a[i];

    int bit,l,r,k;
    while(m--)
    {
        cin >> bit >> l >> r;

        if(bit == 1){
            cin >> k;
            foru(i,l,r)
                a[i] += k;
        }

        if(bit == 2){
            int dem = 0;
            int tmp = 0;
            int res = 0;

            foru(i,l,r)
                h[i] = a[i];

            int it = l;

            while(it <= r){

                if(!h[it]) {++it;continue;}


                int it2 = r+1;


                int Min = 1e18+5;
                foru(i,it,r)
                    if(!h[i]){
                        it2 = i;
                        break;
                    }
                    else
                        Min = min(Min, h[i]);
                res += Min;

                foru(i,1,it2-1)
                    h[i] -= Min;
            }
            cout << res <<"\n";

        }
    }
}


main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    #define name "construct."
    freopen(name"inp","r",stdin);
    freopen(name"out","w",stdout);
    #endif

    cin >> t;

    while(t--){
        cin >> n >> m;
        if(n <= 1000 && m <= 1000)
            sub1();
    }


    return 0;
}
















