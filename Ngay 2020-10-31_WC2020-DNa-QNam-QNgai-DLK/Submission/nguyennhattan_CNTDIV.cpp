#include <bits/stdc++.h>

using namespace std;

bool kt[1001000],kt2[1001000];
int u[1001000],p[1001000],d[1001000],demu[1001000];
int du;

void snt()
{
    int i=2;
    kt[0]=true;
    kt[1]=true;
    while (i<=1000)
    {
        int j=i*i;
        kt[j]=true;
        p[j]=i;
        while (j+i<=1000000)
        {
           j+=i;
           kt[j]=true;
           p[j]=i;
        }
        i++;
        while (kt[i]==true) i++;
    }
    for (int i=2; i<=1000000; i++)
        if (kt[i]==false)
            {
                p[i]=i;
            }
}

void tinh(int x)
{
    while (x!=1)
    {
        d[p[x]]++;
        if (kt2[p[x]]==false)
        {
        du++;
        u[du]=p[x];
        }
        kt2[p[x]]=true;
        x=x/p[x];
    }
}

int main()
{
    int q;
    int n[100000];
    cin>>q;
    snt();
    for (int i=1; i<=q; i++)
        cin>>n[i];
    for (int i=1; i<=q; i++)
    {
        du=0;
        tinh(n[i]);
        tinh(n[i]+1);
        tinh(n[i]+2);
        int dut=1;
        int dut2=1;
        for (int j=1; j<=du; j++)
        {
            dut=dut*(d[u[j]]+1);
            dut2=dut2*(2*(d[u[j]])+1);
           // cout<<u[j]<<" "<<d[u[j]]<<endl;
            kt2[u[j]]=false;
            d[u[j]]=0;
        }
        cout<<((dut2 + 1)/2)-dut<<endl;
    }
}
