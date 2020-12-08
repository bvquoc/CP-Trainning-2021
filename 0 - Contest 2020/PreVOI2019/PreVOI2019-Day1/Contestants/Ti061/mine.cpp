/** Hien Jeony **/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define getbit(n,i) ((n>>(i-1))&1)
#define offbit(n,i) (n^(1<<(i-1)))
#define onbit(n,i) (n|(1<<(i-1)))
#define cntone(x) (__builtin_popcount(x))
const int mod=1e9+3;
using namespace std;
ll n,m,a[500010],res=0,np[500010],th[500010];
bool dx[500010];
ll gt[1000010];
stack<int> st;
template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}
void check(){
    while(st.size()) st.pop();
    memset(dx,0,sizeof(dx));
    int cnt=0;
    for(int i=1;i<=n;i++)
        dx[th[i]]=1;
    for(int i=1;i<=2*n;i++){
        if(dx[i]){
            cnt++;
      //      dd[a[i]]=cnt;
        }
    }
    int cou=0;
    for(int i=1;i<=2*n;i++){
        if(dx[i]){
            st.push(a[i]);
        }
        else{
            if(!st.size())
                return;

            if(a[i]-st.top()>m)
                return;
            st.pop();
        }
    }
    if(st.size())
        return;
    res++;
  //  cout<<res<<endl;
}
void duyet(int k){
    if(k>n){
        check();
        return;
    }
    for(int i=th[k-1]+1;i<=2*n;i++){
        th[k]=i;
        duyet(k+1);
    }
}
void trau(){
    duyet(1);
        cout<<res;
}
ll power(ll x,ll y){
    if(y==0)
        return 1;
    if(y==1)
        return x%mod;
    ll k=power(x,y/2);
    k=k*k%mod;
    if(y%2==1)
        k=k*x%mod;
    return k;
}
ll C(ll k, ll aa) {
    if (k == 0 || k == aa) return 1;
    if (k == 1) return aa;
    return (C(k - 1, aa - 1) + C(k, aa - 1))%mod;
}
void test(){
    gt[0]=1;
    for(int i=1;i<=1000000;i++)
        gt[i]=gt[i-1]*i%mod;
    cout<<C(n,n*2)-C(2,n*2-1)-C(1,n*2-2);
}
int main()
{
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    read(n); read(m);
    for(int i=1;i<=2*n;i++)
        read(a[i]);
    if(n<=10)
        trau();
    else
        test();
}
