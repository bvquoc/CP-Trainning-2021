#include <bits/stdc++.h>
#define name "mine"
#define Debug(x) cout<< #x << " = " << x << '\n'
using namespace std;
const int mod =1000003;
typedef pair <int ,int > ii;
typedef pair <ii, int> iii;
const int N=5*1e7+7;
stack <int > st;
long long kq=0;
int n,m;
int a[N];
void kt(int x, stack <int > c){

    for (int i=x-1;i<=n;i++){
        int z=c.top();
        c.pop();
        if (z<a[i]) return;
    }
    kq++;
}
void sub1(int i,int y){
    if (y==n+1){
        kt(i,st);
        return;
    }
    if (st.empty()){
        st.push(a[i]+m);
        sub1(i+1,y+1);
    } else{
        st.push(a[i]+m);
        sub1(i+1,y+1);
        st.pop();

        st.pop();
        sub1(i+1,y);
    }
}
void sub2(int x){
    int kq=1;
    for (int i=2;i<=x;i++){
        kq*=2;\
        kq%=mod;
    }
    cout<<kq;
}
int main()
{
    freopen(name ".inp","r",stdin);
    freopen(name ".out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
            cin>>a[i];
    }
    if (n<=10) {sub1(1,1); cout<<kq%mod;}
    if (n<200 && m == 1000000) sub2(n);
    return 0;
}


