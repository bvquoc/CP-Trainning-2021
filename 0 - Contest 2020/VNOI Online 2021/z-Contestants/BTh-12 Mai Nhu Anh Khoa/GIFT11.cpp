#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const ll MM=998244353;
const int maxN=2005;

ll f[maxN][15][maxN];
int n;
ll a[maxN];
int get(int cl, int X){
    if (X<=0) return 0;
    vector<int> tmp;
    int dem[2]={0, 0};
    while (X>0){
        tmp.pb(X%10);
        X/=10;
    }
    for (int i=tmp.size()-1; i>=0; --i){
        dem[cl]+=tmp[i];
        cl^=1;
    }
    return (dem[1]-dem[0]+11*11*11)%11;
}
int Count(int X){
    if (X<=0) return 0;
    int cnt=0;
    while (X>0){
        ++cnt;
        X/=10;
    }
    return cnt;
}
ll dp(int I, int du, int odd){
    if (I>n) return (du==0);
    if (f[I][du][odd]!=-1) return f[I][du][odd];
    ll tmp=0;
    tmp+=odd*dp(I+1, (du+get(1, a[I]))%11, odd+1);
    tmp+=(I-odd)*dp(I+1, (du+get(0, a[I]))%11, odd);
    return f[I][du][odd]=tmp;
}
void Set_up(){
    memset(f, -1, sizeof f);
}
ll Sub1(){
    ll gt=1, res=0;
    int id[50];
    for (int i=1; i<=n; ++i) {id[i]=i;gt*=i;}
    for (int i=1; i<=gt; ++i){
        int riv=1;
        int tmp=0;
        for (int j=1; j<=n; ++j){
            tmp=(tmp+get(riv, a[id[j]]))%11;
            riv=(riv+Count(a[id[j]]))%2;
        }
        if (tmp==0) ++res;
        next_permutation(id+1, id+n+1);
    }
    return res;
}
ll Sub2(){
    return dp(1, 0, 1);
}
int main()
{
    ifstream cin("GIFT11.INP");
    ofstream cout("GIFT11.OUT");
    int Q;
    cin >> Q;
    while (Q--){
        cin >> n;
        for (int i=1; i<=n; ++i) cin >> a[i];
        if (n<10){
            cout << Sub1() << endl;
        }
        else{
            Set_up();
            cout << Sub2() << endl;
        }
    }
    return 0;
}
