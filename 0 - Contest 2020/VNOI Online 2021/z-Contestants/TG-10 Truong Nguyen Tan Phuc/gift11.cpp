#include <iostream>
#include <fstream>
#include <cmath>// SAI
using namespace std;
const long BASE=998244353;

int a[10000];
int n, kq=0, SC=0, SL=0, L=2;
struct Radix
{
    int Sochan;
    int Sole;
    int SCS;
};
Radix A[100000];
void xuly(int n, int i)
{
    int a=0, b=0, j=0;
    do
    {
        j++;
        if (j%2) a+=n%10;
        if (!j%2) b+=n%10;
        n=n/10;
    }
    while (n!=0);
    if (j%2)
    {
        A[i].Sole  =a;
        A[i].Sochan=b;
        A[i].SCS=1;
    }
    else
    {
        A[i].Sole  =b;
        A[i].Sochan=a;
        A[i].SCS=2;
    }
}
void Try(int i)
{
    for (int j=1; j<=2; j++)
    {
        int Lt=L, SCt=SC, SLt=SL, ASC=A[i].Sochan, ASL=A[i].Sole;
        if (j==1)
        {
            if (A[i].SCS==1)
            {
                if (L==1) L=2;
                else L=1;
                swap(SC, SL);
            }
        }
        if (j==2)
        {
            if (L==1)
            {
                if (A[i].SCS==1) L=2;
                else L=1;
                swap(A[i].Sochan, A[i].Sole);
            }
            else if (A[i].SCS==1) L=1;
        }
        SL+=A[i].Sole;
        SC+=A[i].Sochan;
        if (i<n) Try(i+1);
        if (i==n)
        {
            int m=abs(SL-SC);
            if (m%11==0) kq=(kq+1)&BASE;
        }
        L=Lt;
        SC=SCt;
        SL=SLt;
        A[i].Sochan=ASC;
        A[i].Sole=ASL;
    }
}
int main()
{
    freopen("Gift11.inp", "r", stdin);
    freopen("Gift11.out", "w", stdout);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++)
    {
        kq=0, SC=0, SL=0, L=2;
        cin >> n;
        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
            xuly(a[i], i);
        }
        Try(1);
        cout << kq << endl;
    }


    return 0;
}
