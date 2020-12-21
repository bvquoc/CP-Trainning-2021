#include <bits/stdc++.h>
using namespace std;
#define maxn 505
int ac[maxn][maxn];
int ab[maxn][maxn];
int bc[maxn][maxn];
int main(){
    freopen("XCKLT.inp","r",stdin);
    freopen("XCKLT.out","w",stdout);
    string A,B,C;
    cin>>A>>B>>C;
    if(A.size()==1 && B.size()==1 && C.size()==1){
        if(A[0]!=C[0] && B[0]!=C[0]){
            if(A[0]!=B[0]) {
                cout<<2<<'\n';
                cout<<A[0]<<B[0];
            }
            else{
            cout<<1<<'\n';
             cout<<A[0];
            }
        }else cout<<"TRETRAU";
    }else{
      // ab doi chieu A va B
      // bc doi chieu B va C
      // ac doi chieu A va C
      int m=A.size();
      int n=B.size();
      int k=C.size();
      A=" "+A;
      B=" "+B;
      C=" "+C;
      // ac m k
      for(int i=1;i<=m;++i)
      for(int j=1;j<=k;++j){
        ac[i][j]=max(ac[i-1][j],ac[i][j-1]);
        if(A[i]==C[j]) ac[i][j]=max(ac[i][j],ac[i-1][j-1]+1);
      }
      // bc n k
      for(int i=1;i<=n;++i)
        for(int j=1;j<=k;++j){
        bc[i][j]=max(bc[i-1][j],bc[i][j-1]);
        if(B[i]==C[j]) bc[i][j]=max(bc[i][j],bc[i-1][j-1]+1);
        }
    if(ac[m][k]==k || bc[n][k]==k){
        cout<<"TRETRAU";
    }else{
       for(int i=1;i<=m;++i)
       for(int j=1;j<=n;++j){
         ab[i][j]=max(ab[i-1][j],ab[i][j-1]);
         if(A[i]==B[j]) ab[i][j]=max(ab[i][j],ab[i-1][j-1]+1);
       }
       cout<<m+n-ab[m][n];
    }
    }


}
