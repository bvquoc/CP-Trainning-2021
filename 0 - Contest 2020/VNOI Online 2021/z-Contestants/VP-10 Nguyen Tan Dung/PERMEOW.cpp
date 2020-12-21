#ifndef LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

#define taskname "PERMEOW"

const int mod=1000000007;
const int maxn=200000;

void up1();
void up2();
void up3();
void up();

int n;
int a[maxn+5], b[maxn+5];

int main()
{
        if (fopen(taskname".inp", "r")) {
                freopen(taskname".inp", "r", stdin);
                freopen(taskname".out", "w", stdout);
        }

        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        std::cin>>n;
        for (int i=1; i<=n; ++i) std::cin>>a[i];
        for (int i=1; i<=n; ++i) std::cin>>b[i];

        bool check01=true;
        for (int i=1; i<=n; ++i) {
                if (a[i]!=b[i]) {
                        check01=false; break;
                }
        }

        if (check01) up1();
        else {
                bool check02=true;
                for (int i=1; i<=n; ++i) {
                        if (a[i]!=i or a[i]!=b[n-i+1]) {
                                check02=false; break;
                        }
                }
                if (check02) up2();
                else up();
        }

        return 0;
}

void up1() {
        int ret=0;
        for (int i=2; i<=n; ++i) {
                for (int j=1; j<i; ++j) ret+=(a[i]<a[j]);
        }

        std::cout<<ret;
}

int dp[maxn+5];
int f[maxn+5];

void up2_brute() {
       int ret=0;
       int id[n+1];
       for (int i=1; i<=n; ++i) id[i]=i;

       do {
                for (int i=2; i<=n; ++i) {
                        for (int j=1; j<i; ++j) ret+=(id[i]<id[j]);
                }
       } while (std::next_permutation(id+1, id+n+1));

       std::cout<<"Brute: "<<ret;
}

void up2() {
        //up2_brute(); return ;
        dp[1]=0, f[1]=1;
        for (int i=2; i<=n; ++i) {
                dp[i]=((int64_t)dp[i-1]*i+(int64_t)(i*(i-1)/2)%mod*f[i-1])%mod;
                f[i]=(int64_t)f[i-1]*i%mod;
        }
        std::cout<<dp[n];
}

void up3() {
        up();
}

int pre[maxn+5];
int bit[maxn+5];

void update(int x, int delta) {
        for (; x>0; x&=x-1) bit[x]+=delta;
}

int get(int x) {
        int ret=0;
        for (; x<=n; x+=x&-x) ret+=bit[x];

        return ret;
}

void update2(int x, int delta) {
        for (; x<=n; x+=x&-x) bit[x]+=delta;
}

int get2(int x) {
        int ret=0;
        for (; x>0; x&=x-1) ret+=bit[x];

        return ret;
}

int calc(int a[], int n) {
        for (int i=1; i<=n; ++i) bit[i]=0;
        int id[n+1];
        for (int i=1; i<=n; ++i) {
                id[i]=a[i]-get2(a[i]);
                update2(a[i]+1, 1);
        }

        dp[1]=0;
        for (int i=2; i<=n; ++i) {
                dp[i]=((int64_t)(id[n-i+1]-1)*pre[i-1]+((int64_t)(id[n-i+1]-1)*(id[n-i+1])/2)%mod*f[i-1]+dp[i-1])%mod;
        }

        return dp[n];
}

void up() {
        int ret=0;
        int id[n+1];
        for (int i=1; i<=n; ++i) id[i]=b[i];
        std::prev_permutation(a+1, a+n+1);
        /*for (int i=1; i<=n; ++i) {
                ret+=get(a[i]);
                if (ret>=mod) ret-=mod;
                update(a[i]-1, 1);
        }*/

        pre[1]=0, f[1]=1;
        for (int i=2; i<=n; ++i) {
                pre[i]=((int64_t)pre[i-1]*i+((int64_t)i*(i-1)/2)%mod*f[i-1])%mod;
                f[i]=(int64_t)f[i-1]*i%mod;
        }

        //std::cout<<calc(b, n)<<"\n";
        //std::cout<<ret<<"\n";
        std::cout<<(calc(b, n)-calc(a, n)+mod)%mod;
}
