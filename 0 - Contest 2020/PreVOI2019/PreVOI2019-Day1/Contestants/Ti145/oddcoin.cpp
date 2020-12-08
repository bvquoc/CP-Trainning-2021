#include <bits/stdc++.h>
#define name "oddcoin"
#define Debug(x) cout<< #x << " = " << x << '\n'
using namespace std;
typedef pair <int ,int > ii;
typedef pair <ii, int> iii;
const int N=5*1e7+7;
int f[N],danhdau[N];
vector <int> g;
int t;
iii q[55];
ii kq[55];
void sub12(int z){
    danhdau[q[z-1].first.first]=0;
    f[q[z-1].first.first]=0;
    danhdau[q[z].first.first]=1;
    f[q[z].first.first]=1;
    int dau=q[z-1].first.first;

    if (q[z].first.first == q[z-1].first.first) dau=max(q[z-1].first.second,q[z].first.first);
    if (q[z].first.first>q[z-1].first.second) dau=q[z-1].first.second;
    int cuoi=q[z].first.second;
    if (dau <=q[z].first.first) danhdau[q[z].first.first]=0;
    for (int i=dau;i<=cuoi;i++){
        if (!danhdau[i]){
            int k=1e9;
            for (int j=1;j<=i/2+1;j++){
                k=min(k,f[j]+f[i-j]);
                if (f[j]+f[i-j]==0) {
                      //  Debug(i);
                       // Debug(i-j);
                      //  Debug(i-j);
                }
            }
            if (f[i]!=1)
            f[i]=k;

        }
    }
    kq[z]={q[z].second,f[cuoi]};
}
int main()
{
    freopen(name ".inp","r",stdin);
    freopen(name ".out","w",stdout);
    cin>>t;
    int x,y;
    for (int i=1;i<=t;i++){
        cin>>x>>y;
        q[i]={{x,y},i};
    }
    sort(q+1,q+1+t);
    for (int i=1;i<=50000;i*=10){
        for (int j=1;j<=5;j+=2){
            f[j*i]=1;
            danhdau[j*i]=1;

        }
    }
    for (int i=1;i<=t;i++){
        sub12(i);
    }
    sort(kq+1,kq+1+t);
    for (int i=1;i<=t;i++){
        cout<<kq[i].second<<'\n';
    }
    return 0;
}
