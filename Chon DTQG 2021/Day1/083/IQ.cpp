#include <bits/stdc++.h>
using namespace std;
int64_t n,a[100000000],b[100000000],cou=0;
void nhap()
{
      cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];

}
void cre_heap(int64_t a[],int64_t n, int64_t pos)
 {
     int larn=pos,ln=pos*2,rn=ln+1;
     if ( ln<=n && a[ln]>a[larn] ) larn=ln;
     if ( rn<=n && a[rn]>a[larn] ) larn=rn;

     if (larn != pos )
     {
         swap (a[larn],a[pos]);
         cre_heap(a,n,larn);
     }
 }
void heapsort (int64_t a[], int64_t n)
 {
     int n2=n-1;
     for (int i=n/2;i>=1;i--)
        cre_heap(a,n,i);
        swap(a[1],a[n]);
        for (n2;n2>=1;n2--)
        {
            cre_heap(a,n2,1);
            swap(a[1],a[n2]);
        }
 }
 int main()
 {
    freopen("IQ.INP","r",stdin);
    freopen("IQ.OUT","w",stdout);
     nhap();
    heapsort(a,n);
    heapsort(b,n);
    int la=1,lb=1;

    while (la <= n   &&  lb <= n)
    {
        if (b[lb]>a[la]) {    cou++; la++; lb++;   }
        else lb++;
    }
    cout<<cou;
     return 0;
 }
