#include<bits/stdc++.h>
using namespace std;
ifstream fi("PERMEOW.inp");
ofstream fo("PERMEOW.out");
const int nmax=2e5+5;
int n,a[nmax],b[nmax],x[nmax],them[nmax];
bool kt[nmax];
void hv(int j)
{
    if(j>n)
    {
        for(int i=1;i<=n;++i) fo<<x[i]<<" ";
        fo<<"\n";
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(kt[i]==true)
        {
            kt[i]=false;
            x[j]=i;
            hv(j+1);
            kt[i]=true;
        }
    }
}
void vet()
{
    them[4]=3;
    for(int i=5;i<=200000;++i)
    {
        them[i]=them[i-1]+i-1;
    }
    for(int i=1;i<=10;++i) fo<<them[i]<<"\n";
}
int main()
{
    fi>>n;
    //for(int i=1;i<=n;++i) fi>>a[i];
    //for(int i=1;i<=n;++i) fi>>b[i];
    for(int i=1;i<=n;++i) kt[i]=true;
    hv(1);
    vet();
}
