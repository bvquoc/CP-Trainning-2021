#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
long long prime[maxn];
bool danhdau[maxn];
long long cnt[maxn],check[maxn];
int demres = 0;
void erestothenes(){
    for (int i = 2; i <= maxn - 1;i++){
        prime[i] = -1;
    }
    for (int i = 2; i <= maxn - 1;i++){
        if(prime[i]==-1){
            prime[i] = i;
            for (int j = i; j <= maxn - 1;j+=i){
                prime[j] = i;
            }
        }
    }
}
void fact(long long x){
    while(x!=1){
        long long p = prime[x], dem = 0;
        while(x%p==0){
            x /= p;
            dem++;
        }
        if(danhdau[p]==false){
            demres++;
            check[demres]=p;
            danhdau[p]=true;
        }
        cnt[p]+=dem;
    } 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    erestothenes();
    while(t--){
        long long n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        fact(n);
        fact(n + 1);
        fact(n + 2);
        long long res = 1,resres=1;
        for (int i = 1; i <= demres;i++){
            res *= (cnt[check[i]]*2 + 1);
            resres *= (cnt[check[i]] + 1);
        }
        res =res/2+1;
        cout << res - resres<<'\n';   
    }
        return 0;
}