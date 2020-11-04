#include<bits/stdc++.h>
using namespace std;
const int N=5000000+1;
long long k;
long long s[N];
int main()
{
   // freopen("text.inp","r",stdin);
    cin>>k;
    if (k>0 && sqrt(k)==trunc(sqrt(k))) {cout<<sqrt(k);return 0;}
    s[0]=k;
    s[1]=k+1;
    for (int i=3;i<=5000000;i+=2)
        s[i]=s[i-2]+i;
  //   for (int i=1;i<=10;i+=2)
    //    cout<<s[i]<<" ";

    long long res=-1;
    for (int i=1;i<=5000000;i+=2)
    {
       // cout<<s[i]<<" ";
       if (s[i]==0) {res=0;break;}
        if (trunc(sqrt(s[i]))==sqrt(s[i]) && s[i]>0) {res=sqrt(s[i]);break;}
    }
    if (res==-1) cout<<"none";
    else
  cout<<res;
}
