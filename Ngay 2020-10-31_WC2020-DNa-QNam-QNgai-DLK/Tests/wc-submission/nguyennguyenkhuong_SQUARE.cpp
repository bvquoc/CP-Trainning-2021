#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
long long k;
int main()
{
    cin>>k;
    for(int i=0; i<=N; i++)
    {
        long double temp=(long double)(sqrt((double)(i)*(double)(i)+(double)(k)));
        if (temp==(long long)(temp)) {cout<<temp; exit(0);}
    }
    cout<<"none";
}
