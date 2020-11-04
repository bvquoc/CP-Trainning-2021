#include<bits/stdc++.h>
using namespace std;
int A[1000005];
void phantich(int n)
{
    //int A[1000005];
    long long t=sqrt(n);
    for(int i=2;i<=t;i++)
    {
        //A[i]=0;
        while(n%i==0)
        {
            A[i]++;
            n/=i;
        }
    }
    if(n>1) A[n]++;
    return;
}
void test()
{
    long long n;
    cin>>n;
    //int A[1000005];
    for(int i=1;i<=n+2;i++) A[i]=0;
    phantich(n);
    //cout<<endl;
    phantich(n+1);
    //cout<<endl;
    phantich(n+2);
    //cout<<endl;
    long long t=1;
    for(int i=2;i<=n+2;i++)
        if(A[i]%2==1) t*=2;
    cout<<t-1<<endl;
 }
 int main()
 {
     long long n;
     cin>>n;
     for(int i=1;i<=n;i++) test();
 }
